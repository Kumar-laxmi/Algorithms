// Given three matrices A, B and C, find if C is a product of A and B.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to multiply a matrix by a vector
void matrixVectorMultiply(const int **matrix, const int *vector, int *result, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        result[i] = 0;
        for (int j = 0; j < cols; ++j)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

// Function to generate a random vector with entries 0 or 1
void generateRandomVector(int *vector, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        vector[i] = rand() % 2;
    }
}

// Function to input a matrix from the user
void inputMatrix(int **matrix, int rows, int cols)
{
    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < rows; ++i)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < cols; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main()
{
    int n, m, k;
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &n);
    printf("Enter the number of columns for matrix A (the no. of column of A = no. of Rows in matrix B) ");
    scanf("%d", &m);
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        A[i] = (int *)malloc(m * sizeof(int));
    }
    inputMatrix(A, n, m);

    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &k);
    int **B = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i)
    {
        B[i] = (int *)malloc(k * sizeof(int));
    }
    inputMatrix(B, m, k);

    int **C = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        C[i] = (int *)malloc(k * sizeof(int));
    }
    printf("For Matrix C \n");
    inputMatrix(C, n, k);

    int *x = (int *)malloc(m * sizeof(int));
    generateRandomVector(x, m);

    int *temp1 = (int *)malloc(n * sizeof(int));
    int *temp2 = (int *)malloc(k * sizeof(int));

    matrixVectorMultiply(B, x, temp1, m, k);
    matrixVectorMultiply(A, temp1, temp2, n, m);

    matrixVectorMultiply(C, x, temp1, n, k);

    int isCorrect = 1;
    for (int i = 0; i < n; ++i)
    {
        if (temp1[i] - temp2[i] != 0)
        {
            isCorrect = 0;
            break;
        }
    }

    if (isCorrect)
    {
        printf("Product is correct.\n");
    }
    else
    {
        printf("Product is incorrect.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; ++i)
    {
        free(A[i]);
    }
    free(A);

    for (int i = 0; i < m; ++i)
    {
        free(B[i]);
    }
    free(B);

    for (int i = 0; i < n; ++i)
    {
        free(C[i]);
    }
    free(C);

    free(x);
    free(temp1);
    free(temp2);

    return 0;
}
