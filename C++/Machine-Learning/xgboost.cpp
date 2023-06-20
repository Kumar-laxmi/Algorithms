/*Implementation of a XGBoost algorithm.
Author - Phalesh Kolpe*/
#include <iostream>
#include <vector>
#include <cmath>

// Define the XGBoost model parameters
const int numIterations = 10;  // Number of boosting iterations
const double learningRate = 0.3;  // Learning rate
const int maxDepth = 6;  // Maximum tree depth

// Define the sigmoid function
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// Define the XGBoost training function
void trainXGBoost(const std::vector<std::vector<double>>& features, const std::vector<double>& labels, std::vector<double>& weights) {
    int numInstances = features.size();
    int numFeatures = features[0].size();

    // Initialize the weights
    weights.resize(numInstances, 1.0);

    // Start the boosting iterations
    for (int iter = 0; iter < numIterations; ++iter) {
        // Calculate the gradients and Hessians
        std::vector<double> gradients(numInstances, 0.0);
        std::vector<double> hessians(numInstances, 0.0);
        for (int i = 0; i < numInstances; ++i) {
            double prediction = 0.0;
            for (int j = 0; j < numFeatures; ++j) {
                prediction += features[i][j] * weights[j];
            }
            double prob = sigmoid(prediction);
            gradients[i] = prob - labels[i];
            hessians[i] = prob * (1.0 - prob);
        }

        // Fit a tree to the gradients and Hessians
        std::vector<double> treeWeights(numFeatures, 0.0);
        for (int j = 0; j < numFeatures; ++j) {
            double numerator = 0.0;
            double denominator = 0.0;
            for (int i = 0; i < numInstances; ++i) {
                numerator += features[i][j] * gradients[i];
                denominator += features[i][j] * hessians[i];
            }
            if (denominator != 0.0) {
                treeWeights[j] = -numerator / (denominator + 1e-6);
            }
        }

        // Update the weights
        for (int j = 0; j < numFeatures; ++j) {
            weights[j] += learningRate * treeWeights[j];
        }
    }
}

// Define the XGBoost prediction function
double predictXGBoost(const std::vector<double>& features, const std::vector<double>& weights) {
    double prediction = 0.0;
    int numFeatures = features.size();
    for (int j = 0; j < numFeatures; ++j) {
        prediction += features[j] * weights[j];
    }
    return sigmoid(prediction);
}

int main() {
    // Sample data
    std::vector<std::vector<double>> trainFeatures = {{0.5, 0.8}, {-1.0, 0.3}, {2.0, -0.1}};
    std::vector<double> trainLabels = {1.0, 0.0, 1.0};
    std::vector<double> weights;

    // Train the XGBoost model
    trainXGBoost(trainFeatures, trainLabels, weights);

    // Predict using the trained model
    std::vector<double> testFeatures = {1.2, 0.4};
    double prediction = predictXGBoost(testFeatures, weights);

    // Print the prediction
    std::cout << "Prediction: " << prediction << std::endl;

    return 0;
}
