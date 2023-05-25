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




    vector<vector<int>> ae = strassen_matrix_multiplication(a, e);
    vector<vector<int>> bg = strassen_matrix_multiplication(b, g);
    vector<vector<int>> af = strassen_matrix_multiplication(a, f);
    vector<vector<int>> bh = strassen_matrix_multiplication(b, h);
    vector<vector<int>> ce = strassen_matrix_multiplication(c, e);
    vector<vector<int>> dg = strassen_matrix_multiplication(d, g);
    vector<vector<int>> cf = strassen_matrix_multiplication(c, f);
    vector<vector<int>> dh = strassen_matrix_multiplication(d, h);

    vector<vector<int>> c11 = add_matrix(ae, bg);
    vector<vector<int>> c12 = add_matrix(af, bh);
    vector<vector<int>> c21 = add_matrix(ce, dg);
    vector<vector<int>> c22 = add_matrix(cf, dh);
    
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
