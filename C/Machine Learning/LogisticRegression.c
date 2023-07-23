#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define ALPHA 0.01

// Function to calculate the sigmoid function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Function to perform logistic regression
void logisticRegression(double X[][2], double y[], int m, int n, double theta[]) {
    int i, j, iterations;
    double h, gradient[2], cost;

    // Gradient descent algorithm
    for (iterations = 0; iterations < MAX_ITERATIONS; iterations++) {
        // Initialize gradients and cost
        gradient[0] = gradient[1] = 0;
        cost = 0;

        // Calculate gradients and cost
        for (i = 0; i < m; i++) {
            h = sigmoid(theta[0] + theta[1] * X[i][1]);
            gradient[0] += (h - y[i]);
            gradient[1] += (h - y[i]) * X[i][1];
            cost += (y[i] * log(h) + (1 - y[i]) * log(1 - h));
        }

        // Update theta using gradients and learning rate
        theta[0] -= ALPHA * gradient[0] / m;
        theta[1] -= ALPHA * gradient[1] / m;

        // Calculate cost function
        cost = -cost / m;

        // Print cost for every 100 iterations
        if (iterations % 100 == 0) {
            printf("Iteration %d: Cost = %lf\n", iterations, cost);
        }
    }

    // Print final theta values
    printf("\nFinal Theta: %lf, %lf\n", theta[0], theta[1]);
}

int main() {
    int m, n, i;
    double X[][2] = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};
    double y[] = {0, 0, 0, 1, 1};
    double theta[] = {0, 0};

    m = sizeof(X) / sizeof(X[0]);
    n = sizeof(X[0]) / sizeof(X[0][0]);

    printf("Logistic Regression Implementation\n\n");
    printf("Number of training examples: %d\n", m);
    printf("Number of features: %d\n\n", n);

    logisticRegression(X, y, m, n, theta);

    return 0;
}
