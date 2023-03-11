#include <stdio.h>

int main()
{
    float x[100], y[100];                               // arrays to store input values
    int n;                                              // number of input values
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0; // variables to store sum of input values and their products
    float slope, intercept;                             // variables to store regression coefficients

    printf("Enter the number of data points: ");
    scanf("%d", &n); // read in the number of input values

    printf("Enter the x and y values separated by a space:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]); // read in each x and y value
        sum_x += x[i];                // add each x value to the sum of x values
        sum_y += y[i];                // add each y value to the sum of y values
        sum_xy += x[i] * y[i];        // add the product of each x and y value to the sum of their products
        sum_x2 += x[i] * x[i];        // add the square of each x value to the sum of squared x values
    }

    // calculate the regression coefficients
    slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    intercept = (sum_y - slope * sum_x) / n;

    printf("Regression equation: y = %fx + %f\n", slope, intercept); // print the regression equation

    return 0;
}
