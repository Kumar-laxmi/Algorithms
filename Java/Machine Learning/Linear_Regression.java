import org.apache.commons.math3.stat.regression.OLSMultipleLinearRegression;
// This line imports the 'OLSMultipleLinearRegression' class from the Apache Commons Math library, which provides functionality for multiple linear regression.

public class Linear_Regression {
    public static void main(String[] args) {
        // These lines define a Java class named Linear_Regression and its main method, where the execution of the program starts.

        OLSMultipleLinearRegression regression = new OLSMultipleLinearRegression();
        //This line creates an instance of the OLSMultipleLinearRegression class, which represents the linear regression model.

        //This code defines a 2D array x that represents the input data matrix for the independent variables. Each row represents a data point, 
        //and each column represents a different independent variable. In this case, we have four data points with two independent variables each.
        double[][] x = {
            {1.0, 2.0}, // First data point with two independent variables
            {2.0, 3.0}, // Second data point with two independent variables
            {3.0, 4.0}, // Third data point with two independent variables
            {4.0, 5.0}  // Fourth data point with two independent variables
        };

        // Define the output vector (dependent variable)
        double[] y = {3.0, 5.0, 7.0, 9.0}; //This line defines a 1D array y that represents the output vector,which contains the dependent variable values corresponding to each data point.

        // Fit the regression model with the data
        regression.newSampleData(y, x); //This line fits the regression model using the newSampleData() method of the OLSMultipleLinearRegression class. It takes the output vector y and the input data matrix x as arguments to train the model.

        // Get the estimated parameters (intercept and slopes)
        double[] beta = regression.estimateRegressionParameters(); //This line retrieves the estimated parameters of the regression model, which include the intercept and slopes for each independent variable. The estimateRegressionParameters() method is called on the regression instance.

        // Print the estimated parameters
        double intercept = beta[0]; // Extract the intercept from the estimated parameters
        double slope1 = beta[1];    // Extract the slope for the first independent variable
        double slope2 = beta[2];    // Extract the slope for the second independent variable
        
        // These lines print the values of the intercept and slopes to the console.

        System.out.println("Intercept: " + intercept);
        System.out.println("Slope 1: " + slope1);
        System.out.println("Slope 2: " + slope2);

        // Predict values using the regression model
        double[] newX = {5.0, 6.0}; //This line defines a new array newX that represents new input values for prediction. In this case, we have two independent variables with values 5.0 and 6.0.
        double predictedY = regression.predict(newX); //This line predicts the value of the dependent variable (y) for the new input values (newX) using the predict() method of the OLSMultipleLinearRegression class.
        System.out.println("Predicted Y for newX: " + predictedY); //This line prints the predicted value of the dependent variable for the new input values to the console.
    }
}
