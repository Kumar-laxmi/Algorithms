import java.util.Arrays;

public class LinearRegression {
    private double[] x;
    private double[] y;
    private double slope;
    private double intercept;

    public LinearRegression(double[] x, double[] y) {
        if (x.length != y.length) {
            throw new IllegalArgumentException("Input arrays must have the same length.");
        }
        this.x = x;
        this.y = y;
        fit();
    }

    public void fit() {
        int n = x.length;
        double sumX = Arrays.stream(x).sum();
        double sumY = Arrays.stream(y).sum();
        double sumXY = 0;
        double sumXX = 0;

        for (int i = 0; i < n; i++) {
            sumXY += x[i] * y[i];
            sumXX += x[i] * x[i];
        }

        double xBar = sumX / n;
        double yBar = sumY / n;

        slope = (sumXY - n * xBar * yBar) / (sumXX - n * xBar * xBar);
        intercept = yBar - slope * xBar;
    }

    public double predict(double input) {
        return slope * input + intercept;
    }

    public static void main(String[] args) {
        // Example usage
        double[] x = {1, 2, 3, 4, 5};
        double[] y = {2, 4, 5, 4, 5};

        LinearRegression lr = new LinearRegression(x, y);
        System.out.println("Slope: " + lr.slope);
        System.out.println("Intercept: " + lr.intercept);

        double input = 6;
        double prediction = lr.predict(input);
        System.out.println("Prediction for input " + input + ": " + prediction);
    }
}
