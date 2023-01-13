#include <iostream>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y)
{

    
   /* Checking if there is a queen in the same column. */
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }
    
   /* Checking if there is a queen in the left diagonal. */
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    
    /* Checking if there is a queen in the right diagonal. */
    i = x;
    j = y;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printBoard(int n, int board[][20])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * We are trying to place a queen in every row, and for every queen we place, we are trying to place
 * the next queen in the next row. 
 * 
 * If we are able to place all the queens, we have found a solution. 
 * 
 * If we are not able to place all the queens, we backtrack and try to place the queen in the next
 * column. 
 * 
 * If we are not able to place the queen in any column, we backtrack and try to place the queen in the
 * next column in the previous row. 
 * 
 * If we are not able to place the queen in any column in the previous row, we backtrack and try to
 * place the queen in the next column in the previous row. 
 * 
 * And so on.
 * 
 * Args:
 *   n (int): The size of the board.
 *   board (int): The chess board.
 *   i (int): row number
 * 
 * Returns:
 *   a boolean value.
 */
bool solveNQueen(int n, int board[][20], int i)
{
    // base case
    if (i == n)
    {
        // Print the board
        printBoard(n, board);
        return true;
    }

    // rec case
    // try to place a queen in every row
    for (int j = 0; j < n; j++)
    {
        // whether the current i,j is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);
            if (success)
            {
                return true;
            }
            // backtrack
            board[i][j] = 0;
        }
    }
    return false;
}
/**
 * If the current queen can be placed safely in current column, mark this column as part of the
 * solution and recursively check if placing a queen in the next column leads to a solution
 * 
 * Returns:
 *   The number of solutions to the N-Queen problem.
 */
int main()
{
    int board[20][20] = {0};
    int n;
    cout<<"Number of Queens you want to place : ";
    cin >> n;
    solveNQueen(n, board, 0);
    return 0;
}