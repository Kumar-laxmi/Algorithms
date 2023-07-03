// Author : G Meghana Reddy
// Github username : meghanareddy1808
// Problem Statement: Matrix Chain Multiplication
// Problem Description
// Matrix chain multiplication is a problem where we have a sequence of matrices and we want to find the most efficient way to multiply them together.
//The efficiency is measured by the minimum number of scalar multiplications required.

// Write a function matrix_chain_multiplication(int dimensions[], int n) that takes two arguments, dimensions array and the size of that array.

// Input : Dimensions is an integer array that represents the dimensions of a sequence of matrices. 
//Each element of the array corresponds to the number of columns of one matrix and the number of rows of the next matrix in the chain.
// 
// Output :
// Minimum number of scalar multiplications to multiply the matrices in the most efficient way.



public class MatrixChainMultiplication {

    // Function to calculate the minimum number of multiplications required for matrix chain multiplication
    public static int matrixChainMultiplication(int[] dimensions) {
        int n = dimensions.length;
        int[][] m = new int[n][n]; // Matrix to store the minimum number of multiplications

        // Initializing the diagonal elements to 0
        for (int i = 1; i < n; i++) {
            m[i][i] = 0;
        }

        // Calculating the minimum number of multiplications for different chain lengths
        for (int length = 2; length < n; length++) {
            for (int i = 1; i < n - length + 1; i++) {
                int j = i + length - 1;
                m[i][j] = Integer.MAX_VALUE;

                // Finding the minimum number of multiplications for the chain (i, j)
                for (int k = i; k < j; k++) {
                    int cost = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];

                    if (cost < m[i][j]) {
                        m[i][j] = cost;
                    }
                }
            }
        }

       // Returning the minimum number of multiplications for the entire chain
       return m[1][n - 1]; 
    }

    public static void main(String[] args) {
        int[] dimensions = {3, 4, 5, 6, 7, 8};
        int result = matrixChainMultiplication(dimensions);
        System.out.println("Minimum number of multiplications is " + result);
    }
}
