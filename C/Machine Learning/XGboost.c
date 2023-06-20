/*Implementation of a XGBoost algorithm.
Author - Phalesh Kolpe*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define MAX_ITERATIONS 100
#define LEARNING_RATE 0.1

// Define the XGBoost model structure
typedef struct {
    double* weights;
} XGBoostModel;

// Define the XGBoost training function
void trainXGBoost(double X[][2], double* y, int num_samples, int num_features, XGBoostModel* model) {
    // Initialize the model weights
    model->weights = (double*)malloc((num_features + 1) * sizeof(double));
    for (int i = 0; i <= num_features; i++) {
        model->weights[i] = 0.0;
    }

    // Iterate through the training data
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // Compute predictions
        double* predictions = (double*)malloc(num_samples * sizeof(double));
        for (int i = 0; i < num_samples; i++) {
            double prediction = model->weights[0];  // Bias term

            for (int j = 0; j < num_features; j++) {
                prediction += model->weights[j + 1] * X[i][j];
            }

            predictions[i] = prediction;
        }

        // Compute gradients and update weights
        double* gradients = (double*)malloc(num_samples * sizeof(double));
        for (int i = 0; i < num_samples; i++) {
            gradients[i] = 2.0 * (predictions[i] - y[i]);
        }

        model->weights[0] -= LEARNING_RATE * gradients[0];  // Update bias term

        for (int j = 0; j < num_features; j++) {
            double gradient_sum = 0.0;
            for (int i = 0; i < num_samples; i++) {
                gradient_sum += gradients[i] * X[i][j];
            }

            model->weights[j + 1] -= LEARNING_RATE * gradient_sum;
        }

        // Clean up memory
        free(predictions);
        free(gradients);
    }
}

// Example usage
int main() {
    // Define the training data
    double X_train[5][2] = {
        {1.0, 1.0},
        {2.0, 3.0},
        {4.0, 5.0},
        {6.0, 7.0},
        {8.0, 9.0}
    };
    double y_train[5] = {3.0, 7.0, 9.0, 13.0, 17.0};

    // Create the model
    XGBoostModel model;

    // Train the model
    trainXGBoost(X_train, y_train, 5, 2, &model);

    // Print the learned weights
    printf("Learned Weights:\n");
    for (int i = 0; i <= 2; i++) {
        printf("Weight %d: %lf\n", i, model.weights[i]);
    }

    // Clean up memory
    free(model.weights);

    return 0;
}
