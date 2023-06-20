#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

struct WeakClassifier {
    int feature;
    double threshold;
    std::vector<int> prediction;
    double alpha;
};

struct AdaBoostClassifier {
    int numClassifiers;
    std::vector<WeakClassifier> classifiers;
    std::vector<double> alphas;
    std::vector<double> classes;
};

AdaBoostClassifier createAdaBoostClassifier(int numClassifiers) {
    AdaBoostClassifier adaboost;
    adaboost.numClassifiers = numClassifiers;
    adaboost.classifiers.resize(numClassifiers);
    adaboost.alphas.resize(numClassifiers);
    return adaboost;
}

void destroyAdaBoostClassifier(AdaBoostClassifier& adaboost) {
    adaboost.classifiers.clear();
    adaboost.alphas.clear();
    adaboost.classes.clear();
}

std::vector<double> findUniqueValues(double X[][2], int nSamples, int nFeatures, int feature) {
    std::vector<double> uniqueValues;
    uniqueValues.reserve(nSamples);

    for (int i = 0; i < nSamples; i++) {
        double value = X[i][feature];
        bool found = false;
        for (const double& uniqueValue : uniqueValues) {
            if (uniqueValue == value) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueValues.push_back(value);
        }
    }

    return uniqueValues;
}

double calculateWeightedError(int* y, std::vector<int>& prediction, std::vector<double>& weights, int nSamples) {
    double weightedError = 0.0;
    for (int i = 0; i < nSamples; i++) {
        if (y[i] != prediction[i]) {
            weightedError += weights[i];
        }
    }
    return weightedError;
}

void updateWeights(AdaBoostClassifier& adaboost, int* y, std::vector<int>& prediction, std::vector<double>& weights, double alpha, int nSamples) {
    double sumWeights = 0.0;
    for (int i = 0; i < nSamples; i++) {
        weights[i] *= exp(-alpha * y[i] * prediction[i]);
        sumWeights += weights[i];
    }

    for (int i = 0; i < nSamples; i++) {
        weights[i] /= sumWeights;
    }
}

void fit(AdaBoostClassifier& adaboost, double X[][2], int* y, int nSamples, int nFeatures) {
    std::vector<double> weights(nSamples, 1.0 / nSamples);
    adaboost.classes.clear();
    int nClasses = 0;

    // Find unique class labels
    for (int i = 0; i < nSamples; i++) {
        double label = static_cast<double>(y[i]);
        bool found = false;
        for (int j = 0; j < nClasses; j++) {
            if (adaboost.classes[j] == label) {
                found = true;
                break;
            }
        }
        if (!found) {
            adaboost.classes.push_back(label);
            nClasses++;
        }
    }

    for (int t = 0; t < adaboost.numClassifiers; t++) {
        WeakClassifier& classifier = adaboost.classifiers[t];

        // Find best weak classifier based on weighted error
        double bestError = INFINITY;

        for (int feature = 0; feature < nFeatures; feature++) {
            std::vector<double> uniqueValues = findUniqueValues(X, nSamples, nFeatures, feature);

            for (const double& threshold : uniqueValues) {
                std::vector<int> prediction(nSamples);

                for (int i = 0; i < nSamples; i++) {
                    if (X[i][feature] < threshold) {
                        prediction[i] = -1;
                    } else {
                        prediction[i] = 1;
                    }
                }

                double weightedError = calculateWeightedError(y, prediction, weights, nSamples);

                if (weightedError < bestError) {
                    bestError = weightedError;
                    classifier.feature = feature;
                    classifier.threshold = threshold;
                    classifier.prediction = prediction;
                }
            }
        }

        classifier.alpha = 0.5 * log((1.0 - bestError) / (bestError + 1e-10));

        updateWeights(adaboost, y, classifier.prediction, weights, classifier.alpha, nSamples);

        adaboost.alphas[t] = classifier.alpha;
    }
}

std::vector<std::vector<double>> calculateScores(AdaBoostClassifier& adaboost, double X[][2], int nSamples, int nClasses) {
    std::vector<std::vector<double>> scores(nSamples, std::vector<double>(nClasses, 0.0));

    for (int t = 0; t < adaboost.numClassifiers; t++) {
        WeakClassifier& classifier = adaboost.classifiers[t];
        double alpha = adaboost.alphas[t];

        for (int i = 0; i < nSamples; i++) {
            double prediction = X[i][classifier.feature] < classifier.threshold ? -1.0 : 1.0;

            for (int j = 0; j < nClasses; j++) {
                if (adaboost.classes[j] == prediction) {
                    scores[i][j] += alpha;
                }
            }
        }
    }
    return scores;
}

std::vector<int> predict(AdaBoostClassifier& adaboost, double X[][2], int nSamples, int nClasses) {
    std::vector<std::vector<double>> scores = calculateScores(adaboost, X, nSamples, nClasses);

    std::vector<int> predictions(nSamples);
    for (int i = 0; i < nSamples; i++) {
        double maxScore = -INFINITY;
        int maxIndex = -1;

        for (int j = 0; j < nClasses; j++) {
            if (scores[i][j] > maxScore) {
                maxScore = scores[i][j];
                maxIndex = j;
            }
        }

        predictions[i] = static_cast<int>(round(adaboost.classes[maxIndex]));
    }

    return predictions;
}

void printPredictions(const std::vector<int>& predictions) {
    std::cout << "Predictions: ";
    for (const int& prediction : predictions) {
        std::cout << prediction << " ";
    }
    std::cout << std::endl;
}

int main() {
    double X[6][2] = {{1, 2}, {2, 1}, {3, 4}, {4, 3}, {1, 3}, {4, 2}};
    int y[6] = {0, 0, 1, 2, 1, 2};
    int nSamples = 6;
    int nFeatures = 2;
    int nClasses = 3;

    AdaBoostClassifier adaboost = createAdaBoostClassifier(3);
    fit(adaboost, X, y, nSamples, nFeatures);

    double XTest[2][2] = {{1, 1}, {3, 3}};
    std::vector<int> predictions = predict(adaboost, XTest, 2, nClasses);
    printPredictions(predictions);

    destroyAdaBoostClassifier(adaboost);

 return 0;
}