#include <iostream>
using namespace std;

int main()
{
    int nrows, mcols;
    cout << "Enter the number of rows and columns:" << endl;
    cin >> nrows >> mcols;
    int matrix[nrows][mcols];

    // Taking input from the user:
    cout << "Enter the elements of the matrix:" << endl;
    for (int row = 0; row < nrows; row++)
    {
        for (int col = 0; col < mcols; col++)
        {
            cin >> matrix[row][col];
        }
    }

    // Printing the elements of the matrix:
    cout << "The 2D array is:" << endl;
    for (int row = 0; row < nrows; row++)
    {
        for (int col = 0; col < mcols; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    int startingRow = 0;
    int endingCol = mcols - 1;
    int endingRow = nrows - 1;
    int startingCol = 0;

    int count = 0;             // count is a variable which stores the number of elements that have been printed.
    int total = nrows * mcols; // total is a variable which stores the total number of elements in the matrix.

    cout << "Spiral traversal of the given matrix will be:" << endl;
    while (count < total)
    {
        // Printing starting row:
        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            cout << matrix[startingRow][index] << " ";
            count++;
        }
        startingRow++;

        // Printing ending column:
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            cout << matrix[index][endingCol] << " ";
            count++;
        }
        endingCol--;

        // Printing ending row:
        for (int index = endingCol; count < total && index >= startingCol; index--)
        {
            cout << matrix[endingRow][index] << " ";
            count++;
        }
        endingRow--;

        // Printing starting column:
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            cout << matrix[index][startingCol] << " ";
            count++;
        }
        startingCol++;
    }

    return 0;
}