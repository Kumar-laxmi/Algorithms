# Matrix Chain Multiplication 
### Implementation of the Matrix Chain Multiplication algorithm in Java. The algorithm calculates the minimum number of multiplications required to multiply a chain of matrices.

### Problem Statement:- 
Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.

### Example:- 

~~~
Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
Let the input 4 matrices be A, B, C and D.
The minimum number of  multiplications are obtained by 
putting parenthesis in following way (A(BC))D.
The minimum is 20*30*10 + 40*20*10 + 40*10*30
~~~

### Source Code:- 

~~~

import sys

def matrix_chain_multiplication(p, n):
    m = [[0 for _ in range(n)] for _ in range(n)]  # Matrix to store the minimum number of multiplications

    # Initializing the diagonal elements to 0
    for i in range(1, n):
        m[i][i] = 0

    # Calculating the minimum number of multiplications for chains of length L
    for L in range(2, n):
        for i in range(1, n - L + 1):
            j = i + L - 1
            m[i][j] = sys.maxsize  # Initializing with a large value

            # Finding the minimum number of multiplications for the chain (i, j)
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q

    return m[1][n - 1]  # Returning the minimum number of multiplications for the entire chain

arr = [10, 20, 30, 40, 30]
size = len(arr)

result = matrix_chain_multiplication(arr, size)

print("Minimum number of multiplications is", result)


~~~
