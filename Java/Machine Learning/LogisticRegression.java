import java.util.Arrays;

public class LogisticRegression {

    private static final int MAX_ITERATIONS = 1000;
    private static final double ALPHA = 0.01;

    // Function to calculate the sigmoid function
    private static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    // Function to perform logistic regression
    public static void logisticRegression(double[][] X, double[] y, int m, int n, double[] theta) {
        int iterations;
        double h, cost;
        double[] gradient = new double[n];

        // Gradient descent algorithm
        for (iterations = 0; iterations < MAX_ITERATIONS; iterations++) {
            // Initialize gradients and cost
            Arrays.fill(gradient, 0);
            cost = 0;

            // Calculate gradients and cost
            for (int i = 0; i < m; i++) {
                h = sigmoid(theta[0] + theta[1] * X[i][1]);
                gradient[0] += (h - y[i]);
                gradient[1] += (h - y[i]) * X[i][1];
                cost += (y[i] * Math.log(h) + (1 - y[i]) * Math.log(1 - h));
            }

            // Update theta using gradients and learning rate
            theta[0] -= ALPHA * gradient[0] / m;
            theta[1] -= ALPHA * gradient[1] / m;

            // Calculate cost function
            cost = -cost / m;

            // Print cost for every 100 iterations
            if (iterations % 100 == 0) {
                System.out.println("Iteration " + iterations + ": Cost = " + cost);
            }
        }

        // Print final theta values
        System.out.println("\nFinal Theta: " + theta[0] + ", " + theta[1]);
    }

    public static void main(String[] args) {
        int m, n;
        double[][] X = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};
        double[] y = {0, 0, 0, 1, 1};
        double[] theta = {0, 0};

        m = X.length;
        n = X[0].length;

        System.out.println("Logistic Regression Implementation\n");
        System.out.println("Number of training examples: " + m);
        System.out.println("Number of features: " + n + "\n");

        logisticRegression(X, y, m, n, theta);
    }
}
