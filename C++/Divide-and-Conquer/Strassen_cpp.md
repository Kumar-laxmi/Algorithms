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

#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int nextpowerof2(int k){
    return pow(2, int(ceil(log2(k))));
}

void display(vector< vector<int>> &matrix, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j != 0){
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void Strassen_algorithmA(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    //base case
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int new_size = size / 2;
        vector<int> z(new_size);
        vector<vector<int>>
            a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
            b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
            c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
            p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
            p5(new_size, z), p6(new_size, z), p7(new_size, z),
            aResult(new_size, z), bResult(new_size, z);

int i, j;

//dividing the matrices into sub-matrices:
for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_size];
                a21[i][j] = A[i + new_size][j];
                a22[i][j] = A[i + new_size][j + new_size];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_size];
                b21[i][j] = B[i + new_size][j];
                b22[i][j] = B[i + new_size][j + new_size];
            }
}

// Calculating p1 to p7:

        add(a11, a22, aResult, new_size);     // a11 + a22
        add(b11, b22, bResult, new_size);    // b11 + b22
        Strassen_algorithmA(aResult, bResult, p1, new_size); 
        // p1 = (a11+a22) * (b11+b22)

        add(a21, a22, aResult, new_size); // a21 + a22
        Strassen_algorithmA(aResult, b11, p2, new_size);
        // p2 = (a21+a22) * (b11)

        sub(b12, b22, bResult, new_size);      // b12 - b22
        Strassen_algorithmA(a11, bResult, p3, new_size);
        // p3 = (a11) * (b12 - b22)

        sub(b21, b11, bResult, new_size);       // b21 - b11
        Strassen_algorithmA(a22, bResult, p4, new_size); 
        // p4 = (a22) * (b21 - b11)

        add(a11, a12, aResult, new_size);      // a11 + a12
        Strassen_algorithmA(aResult, b22, p5, new_size);
        // p5 = (a11+a12) * (b22)

        sub(a21, a11, aResult, new_size);      // a21 - a11
        add(b11, b12, bResult, new_size);               
        // b11 + b12
        Strassen_algorithmA(aResult, bResult, p6, new_size);
        // p6 = (a21-a11) * (b11+b12)

        sub(a12, a22, aResult, new_size);      // a12 - a22
        add(b21, b22, bResult, new_size);                
        // b21 + b22
        Strassen_algorithmA(aResult, bResult, p7, new_size);
        // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        add(p3, p5, c12, new_size); // c12 = p3 + p5
        add(p2, p4, c21, new_size); // c21 = p2 + p4

        add(p1, p4, aResult, new_size);       // p1 + p4
        add(aResult, p7, bResult, new_size);  // p1 + p4 + p7
        sub(bResult, p5, c11, new_size); // c11 = p1 + p4 - p5 + p7

        add(p1, p3, aResult, new_size);       // p1 + p3
        add(aResult, p6, bResult, new_size);  // p1 + p3 + p6
        sub(bResult, p2, c22, new_size); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + new_size] = c12[i][j];
                C[i + new_size][j] = c21[i][j];
                C[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}
void Strassen_algorithm(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b)
{  
/* Check to see if these matrices are already square and have dimensions of a power of 2. If not,
 * the matrices must be resized and padded with zeroes to meet this criteria. */
    int k = max({m, n, a, b});

    int s = nextpowerof2(k);

    vector<int> z(s);
    vector<vector<int>> Aa(s, z), Bb(s, z), Cc(s, z);

    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < a; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }
    Strassen_algorithmA(Aa, Bb, Cc, s);
    vector<int> temp1(b);
    vector<vector<int>> C(m, temp1);
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
    display(C, m, b);
}



int main() {
    // Your code goes here;
    vector<vector<int>> a = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> b = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
    Strassen_algorithm(a, b, 3, 3, 3, 3);
    return 0;
}
	
•COMPLEXITY:

1)Worst case time complexity: Θ(n^2.8074)
2)Best case time complexity: Θ(1)
3)Space complexity: Θ(logn)

•APPLICATIONS:

Generally, Strassen’s Method is not preferred for practical applications for the following reasons.

1)The constants used in Strassen’s method are high and for a typical application Naive method works better.
2)For Sparse matrices, there are better methods especially designed for them.
3)The submatrices in recursion take extra space.


