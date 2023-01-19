•PROBLEM STATEMENT:

First I would like to mention the general method of matrix multiplication and later I will tell how Strassen’s matrix multiplication algorithm is better than tradional matrix multiplication method.Let us consider two matrices X and Y. We want to calculate the resultant matrix Z by multiplying X and Y.First, we will discuss naïve method and its complexity. Here, we are calculating Z = X × Y. Using Naïve method, two matrices (X and Y) can be multiplied if the order of these matrices are p × q and q × r. Following is the algorithm.

                  Algorithm: Matrix-Multiplication (X, Y, Z) 
                  for i = 1 to p do 
                     for j = 1 to r do 
                        Z[i,j] := 0 
                        for k = 1 to q do 
                           Z[i,j] := Z[i,j] + X[i,k] × Y[k,j]


There are three for loops in this algorithm and one is nested in other. Hence, the algorithm takes O(n3) time to execute.This is very high time complexity and it needs to be improved some how.

•INTRODUCTION:

Strassen matrix is the one which by using divide and conquer technique reduces the overall complexity for multiplication two matrices. This happens by decreasing the total number if multiplication performed at the expenses of a slight increase in the number of addition.

•PROCEDURE:

1)Divide a matrix of order of 2*2 recursively till we get the matrix of 2*2.
2)Use the previous set of formulas to carry out 2*2 matrix multiplication.
3)In this eight multiplication and four additions, subtraction are performed.
4)Combine the result of two matrixes to find the final product or final matrix.

•PSEUDOCODE:

1)Divide matrix A and matrix B in 4 sub-matrices of size N/2 x N/2 as shown in the above diagram.

2)Calculate the 7 matrix multiplications recursively.

3)Compute the submatrices of C.

4)Combine these submatricies into new matrix C.


•FORMULA'S FOR STRASSEN MULTIPLICATION:

![image](https://user-images.githubusercontent.com/59620280/213373015-29949323-20b3-4d2e-a729-69cd65e2bd30.png)

In Strassen's matrix multiplication there are seven multiplication and four addition, subtraction in total.


•CODE FOR STARSSEN MATRIX MULTIPLICATION:


	
•COMPLEXITY:

1)Worst case time complexity: Θ(n^2.8074)
2)Best case time complexity: Θ(1)
3)Space complexity: Θ(logn)

•APPLICATIONS:

Generally, Strassen’s Method is not preferred for practical applications for the following reasons.

1)The constants used in Strassen’s method are high and for a typical application Naive method works better.
2)For Sparse matrices, there are better methods especially designed for them.
3)The submatrices in recursion take extra space.


