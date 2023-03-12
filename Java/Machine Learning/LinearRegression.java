/*Linear regression is a statistical method for modeling the relationship between a dependent variable 
and one or more independent variables . The goal of linear regression is to find the line  that best fits the observed data points.
*/
import java.util.Scanner;

public class LinearRegression {
    private double slope; //slope of the regression line, which represents the change in y for a one-unit increase in x.
    private double intercept; //the intercept  represents the value of y when x is zero

    public LinearRegression(double[] x, double[] y) {
        if (x.length != y.length) {
            throw new IllegalArgumentException("x and y must have the same length");
        }

        double xSum = 0;
        double ySum = 0;
        double xSquaredSum = 0;
        double xySum = 0;

        for (int i = 0; i < x.length; i++) {
            xSum += x[i];
            ySum += y[i];
            xSquaredSum += x[i] * x[i];
            xySum += x[i] * y[i];
        }

        double n = x.length;
        double denominator = n * xSquaredSum - xSum * xSum;
        if (denominator == 0) {
            throw new IllegalArgumentException("The x-values must be distinct");
        }
         //The formula for slope and intercept , to view in "mathematical" way please view my pull request for the same
        this.slope = (n * xySum - xSum * ySum) / denominator;
        this.intercept = (ySum - this.slope * xSum) / n;
    }
    //Returns  the slope of the regression line.
    public double getSlope() {
        return slope;
    }
    //Rturns the intercept of the regression line.
    public double getIntercept() {
        return intercept;
    }
    //returns the predicted value of y for a given value of x, using the equation y = slope * x + intercept.
    public double predict(double x) {
        return slope * x + intercept;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of data points: ");
        int n = scanner.nextInt();

        double[] x = new double[n];
        double[] y = new double[n];

        for (int i = 0; i < n; i++) {
            System.out.printf("Enter x[%d]: ", i);
            x[i] = scanner.nextDouble();

            System.out.printf("Enter y[%d]: ", i);
            y[i] = scanner.nextDouble();
        }

        LinearRegression lr = new LinearRegression(x, y);
        System.out.printf("Linear Regression Model: y = %.2fx + %.2f\n", lr.getSlope(), lr.getIntercept());
        System.out.println("Slope: " + lr.getSlope());
        System.out.println("Intercept: " + lr.getIntercept());
        System.out.print("Enter a value of x to predict y: ");
        double input = scanner.nextDouble();
        System.out.println("For x = " + input + " the value of y is " + lr.predict(input));
    }
}
