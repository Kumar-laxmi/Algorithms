// Given three matrices A, B and C, find if C is a product of A and B.
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Function to generate a random vector with entries 0 or 1
vector<int> generateRandomVector(int size)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    vector<int> randomVector(size);
    for (int i = 0; i < size; ++i)
    {
        randomVector[i] = dis(gen);
    }

    return randomVector;
}

// Function to multiply a matrix with a vector
vector<int> matrixVectorMultiply(const vector<vector<int>> &matrix, const vector<int> &vector)
{
    int n = matrix.size();
    int m = matrix[0].size();
    ::vector<int> result(n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    return result;
}

// Function to check if matrices A * B = C using modified Freivald's algorithm
string checkMatrixEquality(const vector<vector<int>> &A, const vector<vector<int>> &B, const vector<vector<int>> &C)
{
    int n = A.size();
    int m = B.size();
    int k = C[0].size();

    vector<int> x = generateRandomVector(m);

    vector<int> Bx = matrixVectorMultiply(B, x);
    vector<int> y = matrixVectorMultiply(A, Bx);

    vector<int> z = matrixVectorMultiply(C, x);

    for (int i = 0; i < n; ++i)
    {
        y[i] -= z[i];
    }

    // Checking if the resulting vector has all 0s
    for (int i = 0; i < n; ++i)
    {
        if (y[i] != 0)
        {
            return "Product is incorrect.";
        }
    }

    return "Product is correct.";
}

// Function to input a matrix from the user
vector<vector<int>> inputMatrix(int rows, int cols)
{
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "enter matrix elements row by row:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

int main()
{
    int n, m, k;
    // entering values for Matrix A
    cout << "Enter the number of rows for matrix A: ";
    cin >> n;
    cout << "Enter the number of columns for matrix A: ";
    cin >> m;
    cout << "For matrix A ";
    vector<vector<int>> A = inputMatrix(n, m);

    // entering values for Matrix B
    cout << "Enter the number of columns for matrix B: ";
    cin >> k;
    cout << "For matrix B ";
    vector<vector<int>> B = inputMatrix(m, k);
    // entering values for Matrix C
    cout << "For matrix C ";
    vector<vector<int>> C = inputMatrix(n, k);

    string result = checkMatrixEquality(A, B, C);
    cout << result << endl;

    return 0;
}
