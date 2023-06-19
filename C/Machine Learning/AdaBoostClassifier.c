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

void fit(AdaBoostClassifier *adaboost, double X[][2], int *y, int nSamples, int nFeatures) {
    adaboost->classes = (double *)malloc(nSamples * sizeof(double));
    int nClasses = 0;

    // Find unique class labels
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
    for (int i = 0; i < nSamples; i++) {
        weights[i] = 1.0 / nSamples;
    }

    for (int t = 0; t < adaboost->numClassifiers; t++) {
        WeakClassifier *classifier = &(adaboost->classifiers[t]);

        // Find best weak classifier based on weighted error
        double bestError = INFINITY;

        for (int feature = 0; feature < nFeatures; feature++) {
            double *uniqueValues = (double *)malloc(nSamples * sizeof(double));
            int numUniqueValues = 0;

            for (int i = 0; i < nSamples; i++) {
                double value = X[i][feature];
                int found = 0;
                for (int j = 0; j < numUniqueValues; j++) {
                    if (uniqueValues[j] == value) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
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

                // Calculate weighted error
                double weightedError = 0.0;
                for (int i = 0; i < nSamples; i++) {
                    if (y[i] != prediction[i]) {
                        weightedError += weights[i];
                    }
                }

                if (weightedError < bestError) {
                    bestError = weightedError;
                    classifier->feature = feature;
                    classifier->threshold = threshold;

                    if (classifier->prediction != NULL) {
                        free(classifier->prediction);
                    }
                    classifier->prediction = prediction;
                } else {
                    free(prediction);
                }
            }

            free(uniqueValues);
        }

        // Calculate classifier weight (alpha)
        classifier->alpha = 0.5 * log((1.0 - bestError) / (bestError + 1e-10));

        // Update weights
        double sumWeights = 0.0;
        for (int i = 0; i < nSamples; i++) {
            weights[i] *= exp(-classifier->alpha * y[i] * classifier->prediction[i]);
            sumWeights += weights[i];
        }

        // Normalize weights
        for (int i = 0; i < nSamples; i++) {
            weights[i] /= sumWeights;
        }

        adaboost->alphas[t] = classifier->alpha;
    }

    free(weights);
}

int *predict(AdaBoostClassifier *adaboost, double X[][2], int nSamples, int nClasses) {
    double **scores = (double **)malloc(nSamples * sizeof(double *));
    for (int i = 0; i < nSamples; i++) {
        scores[i] = (double *)calloc(nClasses, sizeof(double));
    }

    for (int t = 0; t < adaboost->numClassifiers; t++) {
        WeakClassifier *classifier = &(adaboost->classifiers[t]);
        double alpha = adaboost->alphas[t];

        for (int i = 0; i < nSamples; i++) {
            double prediction = X[i][classifier->feature] < classifier->threshold ? -1.0 : 1.0;

            for (int j = 0; j < nClasses; j++) {
                if (adaboost->classes[j] == prediction) {
                    scores[i][j] += alpha;
                }
            }
        }
    }

    int *predictions = (int *)malloc(nSamples * sizeof(int));
    for (int i = 0; i < nSamples; i++) {
        double maxScore = -INFINITY;
        int maxIndex = -1;

        for (int j = 0; j < nClasses; j++) {
            if (scores[i][j] > maxScore) {
                maxScore = scores[i][j];
                maxIndex = j;
            }
        }

        predictions[i] = (int)round(adaboost->classes[maxIndex]);
    }

    for (int i = 0; i < nSamples; i++) {
        free(scores[i]);
    }
    free(scores);

    return predictions;
}

void printPredictions(int *predictions, int nSamples) {
    printf("Predictions: ");
    for (int i = 0; i < nSamples; i++) {
        printf("%d ", predictions[i]);
    }
    printf("\n");
}

void destroyPredictions(int *predictions) {
    free(predictions);
}

int main() {
    double X[6][2] = {{1, 2}, {2, 1}, {3, 4}, {4, 3}, {1, 3}, {4, 2}};
    int y[6] = {0, 0, 1, 2, 1, 2};
    int nSamples = 6;
    int nFeatures = 2;
    int nClasses = 3;

    AdaBoostClassifier *adaboost = createAdaBoostClassifier(3);
    fit(adaboost, X, y, nSamples, nFeatures);

    double XTest[2][2] = {{1, 1}, {3, 3}};
    int *predictions = predict(adaboost, XTest, 2, nClasses);
    printPredictions(predictions, 2);
    destroyPredictions(predictions);

    destroyAdaBoostClassifier(adaboost);

    return 0;
}
