#include <iostream>
using namespace std;
const int N = 3;  // size of the matrices

// function to multiply two matrices
void multiply(int a[][N], int b[][N], int c[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
int main()
{
    int a[N][N] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int b[N][N] = {{9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1}};
    int c[N][N];  //empty matrix to store the result

    multiply(a, b, c);
    // print the result
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}