/*

=================================  PROBLEM STATEMENT =================================

Write a program to multiply two matrices using Strassen's algorithm.
Strassen's algorithm for matrix multiplication is a divide and conquer algorithm.

=================================  SOLUTION =================================

    1. Divide the matrices A and B in 4 sub-matrices of size N/2 x N/2 as shown in the below diagram.

                       MATRIX 1              MATRIX 2
                    +-----+-----+         +-----+-----+ 
                    |  a  |  b  |         |  e  |  f  | 
                    +-----+-----+         +-----+-----+ 
                    |  c  |  d  |         |  g  |  h  | 
                    +-----+-----+         +-----+-----+ 

    2. Calculate following values recursively.
                p1 = a(f - h)
                p2 = (a + b)h
                p3 = (c + d)e
                p4 = d(g - e)
                p5 = (a + d)(e + h)
                p6 = (b - d)(g + h)
                p7 = (a - c)(e + f)

    3. Calculate following:-
            c11 = p5 + p4 - p2 + p6
            c12 = p1 + p2
            c21 = p3 + p4
            c22 = p1 + p5 - p3 - p7

    4. merge c11, c12, c21, c22 as given below

                    +-----------+-----------+
                    |    c11    |    c12    |       
                    +-----------+-----------+
                    |    c21    |    c22    |
                    +-----------+-----------+

=================================  COMPLEXITY =================================

Time Complexity: O(n^2.8074)
Space Complexity: O(n^2)

=================================  EXAMPLES =================================

Input: 1 2 3 4
       5 6 7 8
       9 10 11 12
       13 14 15 16
       1 2 3 4
       5 6 7 8
       9 10 11 12
       13 14 15 16
Output: 90 100 110 120
        202 228 254 280
        314 356 398 440
        426 484 542 600



*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void print_matrix(vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> add_matrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int row = matrix1.size();
    int col = matrix1[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0 ; j < col; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

vector<vector<int>> sub_matrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int row = matrix1.size();
    int col = matrix1[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0 ; j < col; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

vector<vector<int>> strassen_matrix_multiplication(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int row = matrix1.size();
    int col = matrix1[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));
    if (row == 1 && col == 1) {
        result[0][0] = matrix1[0][0] * matrix2[0][0];
        return result;
    }
    int new_row = row / 2;
    int new_col = col / 2;
    vector<vector<int>> a(new_row, vector<int>(new_col, 0));
    vector<vector<int>> b(new_row, vector<int>(new_col, 0));
    vector<vector<int>> c(new_row, vector<int>(new_col, 0));
    vector<vector<int>> d(new_row, vector<int>(new_col, 0));
    vector<vector<int>> e(new_row, vector<int>(new_col, 0));
    vector<vector<int>> f(new_row, vector<int>(new_col, 0));
    vector<vector<int>> g(new_row, vector<int>(new_col, 0));
    vector<vector<int>> h(new_row, vector<int>(new_col, 0));
    for (int i = 0; i < new_row; i++) {
        for (int j = 0; j < new_col; j++) {
            a[i][j] = matrix1[i][j];
            b[i][j] = matrix1[i][j + new_col];
            c[i][j] = matrix1[i + new_row][j];
            d[i][j] = matrix1[i + new_row][j + new_col];
            e[i][j] = matrix2[i][j];
            f[i][j] = matrix2[i][j + new_col];
            g[i][j] = matrix2[i + new_row][j];
            h[i][j] = matrix2[i + new_row][j + new_col];
        }
    }


    vector<vector<int>> ts1 = sub_matrix(f, h);
    vector<vector<int>> ts2 = add_matrix(a, b);
    vector<vector<int>> ts3 = add_matrix(c, d);
    vector<vector<int>> ts4 = sub_matrix(g, e);
    vector<vector<int>> ts5 = add_matrix(a, d);
    vector<vector<int>> ts6 = add_matrix(e, h);
    vector<vector<int>> ts7 = sub_matrix(b, d);
    vector<vector<int>> ts8 = add_matrix(g, h);
    vector<vector<int>> ts9 = sub_matrix(a, c);
    vector<vector<int>> ts10 = add_matrix(e, f);

    vector<vector<int>> p1 = strassen_matrix_multiplication(a,ts1);
    vector<vector<int>> p2 = strassen_matrix_multiplication(ts2,h);
    vector<vector<int>> p3 = strassen_matrix_multiplication(ts3,e);
    vector<vector<int>> p4 = strassen_matrix_multiplication(d,ts4);
    vector<vector<int>> p5 = strassen_matrix_multiplication(ts5,ts6);
    vector<vector<int>> p6 = strassen_matrix_multiplication(ts7,ts8);
    vector<vector<int>> p7 = strassen_matrix_multiplication(ts9,ts10);

    vector<vector<int>> tempA1 = add_matrix(p5,p4);
    vector<vector<int>> tempA2 = sub_matrix(tempA1,p2);
    vector<vector<int>> c11 = add_matrix(tempA2,p6);
    vector<vector<int>> c12 = add_matrix(p1,p2);
    vector<vector<int>> c21 = add_matrix(p3,p4);
    vector<vector<int>> tempA3 = add_matrix(p5,p1);
    vector<vector<int>> tempA4 = sub_matrix(tempA3,p3);
    vector<vector<int>> c22 = sub_matrix(tempA4,p7);
    
    for (int i = 0; i < new_row; i++) {
        for (int j = 0; j < new_col; j++) {
            result[i][j] = c11[i][j];
            result[i][j + new_col] = c12[i][j];
            result[i + new_row][j] = c21[i][j];
            result[i + new_row][j + new_col] = c22[i][j];
        }
    }
    return result;
}

int main(void) {
    /*
    
        Input format:

        First enter an integer n denoting size of the 2 matrices of size N x N.
        Then enter n*n integers for matrix1.
        Then enter n*n integers for matrix2.
    
    
    
    */

    int n;
    cout << "enter size of matrix: "<< endl;
    cin >> n;

    vector<vector<int>> matrix1(n, vector<int>(n, 0));
    vector<vector<int>> matrix2(n, vector<int>(n, 0));

    cout << "enter matrix1: " << endl;
    for (auto &row : matrix1) {
        for (auto &col : row) {
            cin >> col;
        }
    }

    cout << "enter matrix2: " << endl;
    for (auto &row : matrix2) {
        for (auto &col : row) {
            cin >> col;
        }
    }

    vector<vector<int>> result = strassen_matrix_multiplication(matrix1, matrix2);
    
    cout << "result: " << endl;
    print_matrix(result);
    return 0;
}
