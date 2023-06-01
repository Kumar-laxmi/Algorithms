#include <stdio.h>
#include <limits.h>

// Function to calculate the minimum number of multiplications needed for matrix chain multiplication
int matrixChainMultiplication(int dimensions[], int n) {
    // Create a 2D array to store the minimum number of multiplications
    int m[n][n];

    // Initialize the array with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }

    // Calculate the minimum number of multiplications for each chain length
    for (int chainLength = 2; chainLength < n; chainLength++) {
        for (int i = 1; i < n - chainLength + 1; i++) {
            int j = i + chainLength - 1;
            m[i][j] = INT_MAX;

            // Find the minimum cost of multiplying matrices in the given chain length
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    // Return the minimum number of multiplications needed for the entire chain
    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[n + 1];
    printf("Enter the dimensions of matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dimensions[i]);
    }

    int minMultiplications = matrixChainMultiplication(dimensions, n + 1);

    printf("Minimum number of multiplications: %d\n", minMultiplications);

    return 0;
}
