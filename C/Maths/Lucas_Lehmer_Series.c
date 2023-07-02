/*
------------------------------------- Lucas Lehmer Series -------------------------------------

Approach
1. In this series, 4 is the starting term i.e., 0th term

2. By considering 4 as the 0th terms, then calculate the nth term of lucas-lehmer series.

3. To calculate the nth term use the formula, ``` nextTerm = currentTerm * currentTerm - 2 ```

4. Using this formula, we can find the nth term of lucas-lehmer series.

Below is the implementation of lucas-lehmer series in C
*/

// Program starts
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the series up to the nth term
void LucasLehmer(int n) {
    // The 0th term of the series is 4.
    unsigned long long currentTerm = 4;

    // Create an array to store the terms.
    unsigned long long *series = (unsigned long long *)malloc((n + 1) * sizeof(unsigned long long));

    // Compute each term and add it to the array.
    series[0] = currentTerm;
    for (int i = 0; i < n; i++) {
        currentTerm = currentTerm * currentTerm - 2;
        series[i + 1] = currentTerm;
    }

    // Print out the terms one by one.
    for (int i = 0; i <= n; i++) {
        printf("Term %d: %llu\n", i, series[i]);
    }

    printf("\n");

    // Free the dynamically allocated memory
    free(series);
}

// Main driver function
int main() {
    // nth term up to which the user wants to display the Lucas-Lehmer series
    int n;

    // Taking input from the user
    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    printf("\n######## Lucas-Lehmer Series ########\n\n");

    // Function triggered to calculate the Lucas-Lehmer series up to the nth term
    LucasLehmer(n);

    return 0;
}

// This code is contributed by Avdhesh Varshney (https://github.com/Avdhesh-Varshney)
