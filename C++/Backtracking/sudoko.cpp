
// PROBLEM STATEMENT
/*
Fill in a 9x9 grid of numbers such that each row, column, 
and 3x3 sub-grid contains all the numbers from 1 to 9.
*/

#include <iostream>
using namespace std;

const int N = 9;

// check if we can place num in (row, col)
bool isSafe(int grid[N][N], int row, int col, int num) {
    // check in row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // check in col
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // check in 3x3 grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// solve sudoku
bool solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    if (solveSudoku(grid, 0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
