public class Linear_Regression {
    private double[] slopes; // Array to store the slopes of the regression line for each variable
    private double intercept; // Intercept of the regression line

    public void train(double[][] x, double[] y) {
        // Calculate the means of each variable in x and y
        double[] xMeans = calculateMeans(x); // Calculate the means of each variable in x
        double yMean = calculateMean(y); // Calculate the mean of y

        // Calculate the slopes (beta1) and intercept (beta0) of the regression line
        slopes = new double[x[0].length]; // Initialize the slopes array with the length of variables in x
        double[] numerators = new double[x[0].length]; // Array to store the numerators of the slopes calculation
        double[] denominators = new double[x[0].length]; // Array to store the denominators of the slopes calculation

        // Iterate over each variable in x
        for (int i = 0; i < x[0].length; i++) {
            // Iterate over each data point in x and y
            for (int j = 0; j < x.length; j++) {
                numerators[i] += (x[j][i] - xMeans[i]) * (y[j] - yMean); // Calculate the numerator of the slope
                denominators[i] += Math.pow((x[j][i] - xMeans[i]), 2); // Calculate the denominator of the slope
            }
            slopes[i] = numerators[i] / denominators[i]; // Calculate the slope (beta1) for the current variable
        }

        intercept = yMean - dotProduct(xMeans, slopes); // Calculate the intercept (beta0) of the regression line
    }

    public double predict(double[] x) {
        // Predict the value of y for a given set of x values using the regression line equation
        return dotProduct(x, slopes) + intercept; // Calculate the predicted y value
    }

    private double calculateMean(double[] values) {
        // Calculate the mean of an array of values
        double sum = 0.0;
        for (double value : values) {
            sum += value;
        }
        return sum / values.length; // Return the mean
    }

    private double[] calculateMeans(double[][] values) {
        // Calculate the means of each variable in a 2D array of values
        double[] means = new double[values[0].length]; // Array to store the means

        // Iterate over each variable in the 2D array
        for (int i = 0; i < values[0].length; i++) {
            double sum = 0.0;

            // Iterate over each data point for the current variable
            for (double[] row : values) {
                sum += row[i]; // Add the value to the sum
            }
            means[i] = sum / values.length; // Calculate the mean for the current variable
        }
        return means; // Return the array of means
    }

    private double dotProduct(double[] a, double[] b) {
        // Calculate the dot product of two arrays
        double result = 0.0;

        // Iterate over the elements of the arrays and calculate the dot product
        for (int i = 0; i < a.length; i++) {
            result += a[i] * b[i]; // Multiply the corresponding elements and add to the result
        }
        return result; // Return the dot product
    }

    public static void main(String[] args) {
        // Example usage
        double[][] x = {
            {1.0, 2.0},
            {2.0, 3.0},
            {3.0, 4.0},
            {4.0, 5.0},
            {5.0, 6.0},
            {6.0, 7.0},
            {7.0, 8.0},
            {8.0, 9.0},
            {9.0, 10.0},
            {10.0, 11.0},
            {11.0, 12.0},
            {12.0, 13.0},
            {13.0, 14.0},
            {14.0, 15.0},
            {15.0, 16.0},
            {16.0, 17.0},
            {17.0, 18.0},
            {18.0, 19.0},
            {19.0, 20.0},
            {20.0, 21.0}
        };
        double[] y = {
            3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0,
            25.0, 27.0, 29.0, 31.0, 33.0, 35.0, 37.0, 39.0, 41.0
        };

        Linear_Regression regression = new Linear_Regression(); // Create an instance of Linear_Regression
        regression.train(x, y); // Train the regression model using the input data

        double[] newX = {21.0, 22.0};
        double predictedY = regression.predict(newX); // Make a prediction for the new input values
        System.out.println("Predicted Y for newX: " + predictedY); // Print the predicted value of y
    }
}
