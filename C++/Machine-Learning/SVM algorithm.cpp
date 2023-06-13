#include<bits/stdc++.h>
// SVM class
class SVM {
public:
    SVM(double learning_rate, int num_iterations, double C) : 
        learning_rate(learning_rate), num_iterations(num_iterations), C(C) {}

    void fit(const std::vector<std::vector<double>>& X, const std::vector<int>& y) {
        int n_samples = X.size();
        int n_features = X[0].size();

        // Initialize parameters
        W = std::vector<double>(n_features, 0.0);
        b = 0.0;

        // Gradient descent
        for (int iter = 0; iter < num_iterations; iter++) {
            for (int i = 0; i < n_samples; i++) {
                double y_pred = predict(X[i]);
                if (y[i] * y_pred >= 1) {
                    // Update weights for non-support vectors
                    for (int j = 0; j < n_features; j++) {
                        W[j] -= learning_rate * 2 * C * W[j];
                    }
                } else {
                    // Update weights for support vectors
                    for (int j = 0; j < n_features; j++) {
                        W[j] -= learning_rate * (2 * C * W[j] - y[i] * X[i][j]);
                    }
                    b -= learning_rate * y[i];
                }
            }
        }
    }

    double predict(const std::vector<double>& x) const {
        double wx = 0.0;
        for (int i = 0; i < x.size(); i++) {
            wx += W[i] * x[i];
        }
        return wx - b;
    }

private:
    double learning_rate;
    int num_iterations;
    double C;
    std::vector<double> W;
    double b;
};

int main() {
    // Generate a larger dataset
    const int n_samples = 1000;
    const int n_features = 10;
    std::vector<std::vector<double>> X(n_samples, std::vector<double>(n_features, 0.0));
    std::vector<int> y(n_samples, 0);

    srand(42);
    for (int i = 0; i < n_samples; i++) {
        for (int j = 0; j < n_features; j++) {
            X[i][j] = (double)rand() / RAND_MAX;
        }
        y[i] = (std::accumulate(X[i].begin(), X[i].end(), 0.0) > n_features / 2) ? 1 : -1;
    }

    // Split the dataset into training and testing sets
    double split_ratio = 0.8;
    int split_index = static_cast<int>(split_ratio * n_samples);

    std::vector<std::vector<double>> X_train(X.begin(), X.begin() + split_index);
    std::vector<int> y_train(y.begin(), y.begin() + split_index);

    std::vector<std::vector<double>> X_test(X.begin() + split_index, X.end());
    std::vector<int> y_test(y.begin() + split_index, y.end());

    // Train the SVM model
    SVM svm(0.01, 1000, 1.0);
    svm.fit(X_train, y_train);

    // Make predictions on the testing set
    for (int i = 0; i < X_test.size(); i++) {
        double prediction = svm.predict(X_test[i]);
        std::cout << "Prediction for sample " << i << ": " << prediction << std::endl;
    }

    return 0;
}

// #Support Vector Machine (SVM) Algorithm - C++

// ##Features

// Pure C++ implementation without relying on any machine learning libraries.
// Provides a basic implementation of the SVM algorithm with a linear kernel.
// Demonstrates the usage of classes and functions in C++.
// Supports larger datasets compared to the Python implementation due to improved performance.


// ##Dependencies

// C++ compiler (supporting C++11 or later)


// ##How to Build and Run

// Open the svm_algorithm.cpp file in a C++ IDE or text editor.
// Ensure that you have a C++ compiler installed on your system.
// Compile the code using your preferred C++ compiler.
// Run the resulting executable file.
// The program will generate a larger dataset and split it into training and testing sets.
// It will then train the SVM model using the training set and make predictions on the testing set.
// The predicted values for each sample will be displayed in the console.