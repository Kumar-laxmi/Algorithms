#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int feature;
    double threshold;
    int *prediction;
    double alpha;
} WeakClassifier;

typedef struct {
    int numClassifiers;
    WeakClassifier *classifiers;
    double *alphas;
    double *classes;
} AdaBoostClassifier;

AdaBoostClassifier *createAdaBoostClassifier(int numClassifiers) {
    AdaBoostClassifier *adaboost = (AdaBoostClassifier *)malloc(sizeof(AdaBoostClassifier));
    adaboost->numClassifiers = numClassifiers;
    adaboost->classifiers = (WeakClassifier *)malloc(numClassifiers * sizeof(WeakClassifier));
    adaboost->alphas = (double *)malloc(numClassifiers * sizeof(double));
    adaboost->classes = NULL;
    return adaboost;
}

void destroyAdaBoostClassifier(AdaBoostClassifier *adaboost) {
    if (adaboost != NULL) {
        free(adaboost->classifiers);
        free(adaboost->alphas);
        free(adaboost->classes);
        free(adaboost);
    }
}

void initializeWeights(double *weights, int nSamples) {
    for (int i = 0; i < nSamples; i++) {
        weights[i] = 1.0 / nSamples;
    }
}

int isValueFound(double *values, int numValues, double value) {
    for (int j = 0; j < numValues; j++) {
        if (values[j] == value) {
            return 1;
        }
    }
    return 0;
}

void calculateWeightedError(double *weights, int *y, int *prediction, int nSamples, double *bestError) {
    double weightedError = 0.0;
    for (int i = 0; i < nSamples; i++) {
        if (y[i] != prediction[i]) {
            weightedError += weights[i];
        }
    }

    if (weightedError < *bestError) {
        *bestError = weightedError;
    }
}

void updateWeights(double *weights, int *y, int *prediction, int nSamples, double alpha) {
    double sumWeights = 0.0;
    for (int i = 0; i < nSamples; i++) {
        weights[i] *= exp(-alpha * y[i] * prediction[i]);
        sumWeights += weights[i];
    }

    for (int i = 0; i < nSamples; i++) {
        weights[i] /= sumWeights;
    }
}

int getPredictionClass(double *classes, double *scores, int nClasses, int index) {
    double maxScore = -INFINITY;
    int maxIndex = -1;

    for (int j = 0; j < nClasses; j++) {
        if (scores[index * nClasses + j] > maxScore) {
            maxScore = scores[index * nClasses + j];
            maxIndex = j;
        }
    }

    return (int)round(classes[maxIndex]);
}

void fit(AdaBoostClassifier *adaboost, double X[][2], int *y, int nSamples, int nFeatures) {
    adaboost->classes = (double *)malloc(nSamples * sizeof(double));
    int nClasses = 0;

    for (int i = 0; i < nSamples; i++) {
        double label = (double)y[i];
        int found = 0;
        for (int j = 0; j < nClasses; j++) {
            if (adaboost->classes[j] == label) {
                found = 1;
                break;
            }
        }
        if (!found) {
            adaboost->classes[nClasses++] = label;
        }
    }

    double *weights = (double *)malloc(nSamples * sizeof(double));
    initializeWeights(weights, nSamples);

    for (int t = 0; t < adaboost->numClassifiers; t++) {
        WeakClassifier *classifier = &(adaboost->classifiers[t]);

        double bestError = INFINITY;

        for (int feature = 0; feature < nFeatures; feature++) {
            double *uniqueValues = (double *)malloc(nSamples * sizeof(double));
            int numUniqueValues = 0;

            for (int i = 0; i < nSamples; i++) {
                double value = X[i][feature];
                if (!isValueFound(uniqueValues, numUniqueValues, value)) {
                    uniqueValues[numUniqueValues++] = value;
                }
            }

            for (int k = 0; k < numUniqueValues; k++) {
                double threshold = uniqueValues[k];
                int *prediction = (int *)malloc(nSamples * sizeof(int));

                for (int i = 0; i < nSamples; i++) {
                    if (X[i][feature] < threshold) {
                        prediction[i] = -1;
                    } else {
                        prediction[i] = 1;
                    }
                }

                calculateWeightedError(weights, y, prediction, nSamples, &bestError);

                if (bestError == 0.0) {
                    classifier->feature = feature;
                    classifier->threshold = threshold;
                    classifier->prediction = prediction;
                    classifier->alpha = INFINITY;
                    break;
                }

                free(prediction);
            }

            free(uniqueValues);
        }

        if (bestError != 0.0) {
            classifier->alpha = 0.5 * log((1.0 - bestError) / (bestError + 1e-10));
            updateWeights(weights, y, classifier->prediction, nSamples, classifier->alpha);
        }

        adaboost->alphas[t] = classifier->alpha;
    }

    free(weights);
}

void predict(AdaBoostClassifier *adaboost, double X[][2], int nSamples, int nClasses, int *predictions) {
    double *scores = (double *)malloc(nSamples * nClasses * sizeof(double));

    for (int t = 0; t < adaboost->numClassifiers; t++) {
        WeakClassifier *classifier = &(adaboost->classifiers[t]);
        double alpha = adaboost->alphas[t];

        for (int i = 0; i < nSamples; i++) {
            double prediction = X[i][classifier->feature] < classifier->threshold ? -1.0 : 1.0;

            for (int j = 0; j < nClasses; j++) {
                if (adaboost->classes[j] == prediction) {
                    scores[i * nClasses + j] += alpha;
                }
            }
        }
    }

    for (int i = 0; i < nSamples; i++) {
        predictions[i] = getPredictionClass(adaboost->classes, scores, nClasses, i);
    }

    free(scores);
}

void printPredictions(int *predictions, int nSamples) {
    printf("Predictions: ");
    for (int i = 0; i < nSamples; i++) {
        printf("%d ", predictions[i]);
    }
    printf("\n");
}

int main() {
    int nSamples = 8;
    int nFeatures = 2;
    double X[][2] = {{1, 2}, {2, 3}, {4, 2}, {3, 5}, {2, 2}, {6, 7}, {7, 1}, {3, 1}};
    int y[] = {-1, -1, -1, -1, 1, 1, 1, -1};
    int nClasses = 2;
    int *predictions = (int *)malloc(nSamples * sizeof(int));

    AdaBoostClassifier *adaboost = createAdaBoostClassifier(3);
    fit(adaboost, X, y, nSamples, nFeatures);
    predict(adaboost, X, nSamples, nClasses, predictions);
    printPredictions(predictions, nSamples);

    destroyAdaBoostClassifier(adaboost);
    free(predictions);

 return 0;
}