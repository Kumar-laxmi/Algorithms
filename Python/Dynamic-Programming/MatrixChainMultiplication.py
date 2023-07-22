'''
Author : G Meghana Reddy
Github username : meghanareddy1808
Problem Statement: Matrix Chain Multiplication
Problem Description
Matrix chain multiplication is a problem where we have a sequence of matrices and we want to find the most efficient way to multiply them together.
The efficiency is measured by the minimum number of scalar multiplications required.

Write a function matrix_chain_multiplication(int dimensions[], int n) that takes two arguments, dimensions array and the size of that array.

Input : Dimensions is an integer array that represents the dimensions of a sequence of matrices. 
Each element of the array corresponds to the number of columns of one matrix and the number of rows of the next matrix in the chain.

Output :Minimum number of scalar multiplications to multiply the matrices in the most efficient way.
'''



def matrix_chain_multiplication(dimensions):
    n = len(dimensions)
    # Matrix to store the minimum number of multiplications
    m = [[0] * n for _ in range(n)]  

    # Initializing the diagonal elements to 0
    for i in range(1, n):
        m[i][i] = 0

    # Calculating the minimum number of multiplications for different chain lengths
    for length in range(2, n):
        for i in range(1, n - length + 1):
            j = i + length - 1
            m[i][j] = float('inf')

            # Finding the minimum number of multiplications for the chain (i, j)
            for k in range(i, j):
                cost = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j]

                if cost < m[i][j]:
                    m[i][j] = cost

    return m[1][n - 1]  # Returning the minimum number of multiplications for the entire chain


dimensions = [3, 4, 5, 6, 7, 8]
result = matrix_chain_multiplication(dimensions)

print("Minimum number of multiplications is", result)
