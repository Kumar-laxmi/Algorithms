/*
 ---------------------------------------------- Problem Statement --------------------------------------------------------

    First line of input consist of number of rows and the second line consist of number of column the third line is the
    matrix elements. We have to print it in diagonal print pattern.

    INPUT :- 3
             3
             1 2 3
             4 5 6
             7 8 9

    OUTPUT :- 1 2 4 7 5 3 6 8 9

 ------------------------------------------------- Complexities ----------------------------------------------------------

    Time Complexity  :- BigO(n*m) --> where n is the number of rows and m is the number of columns
    Space Complexity :- BigO(1)

 */
#include<stdio.h>
#include <stdbool.h>
// Declaring the  global variables so that we can use anywhere in the functions 
int row;
int column;
// Function to print in diagnol pattern.
diagonalprint(int mat[row][column])
{
	// A boolean variable to switch directions
	bool isUp = true;
	// Setting the value of i and j to zero, since it is changed in the for loops.
	int i=0,j=0,k;
	for (k = 0; k < row*column;) 
	{	
		// If isUp = true then iterate from downward to upward
        if (isUp) 
		{
        	// Loop for printing the values from downward to upward
            for (; i >= 0 && j < column; j++, i--) 
			{
                printf("%d ",mat[i][j]);
                k++;
            }
			// Set i and j according to isUp value (ie, according to direction)
            if (i < 0 && j <= row - 1)
            {
            	i = 0;
			}
            if (j == row)
            {
            	i = i + 2;
				j--;
			}
        }
        // if isUp is false then traverse upwards to downwards
        else 
		{
        	// Loop for printing the values from upward to downward
            for (; j >= 0 && i < column; i++, j--)
			{
                printf("%d ",mat[i][j]);
                k++;
            }
			// Set i and j according to isUp value (ie, according to direction)
            if (j < 0 && i <= row - 1)
            {
            	j = 0;
			}
            if (i == row)
            {
                j = j + 2;
				i--;
			}
        }
        // Changing the value of isUp according to the direction.
        isUp = !isUp;
    }
}
int main()
{
	// Reading the number of rows from the user
	printf("Enter row value = ");
	scanf("%d",&row);
	// Reading the number of columns from the user
	printf("Enter column value = ");
	scanf("%d",&column);
	// Declaring the matrix of size rows and columns
	int matrix[row][column];
	// Declaring the iterating variables and putting their value to 0
	int i=0,j=0;
	// Reading the matrix values from the user
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("Enter matrix values = ");
			scanf("%d",&matrix[i][j]);
		}
	}
	// Printing the matrix
	printf("The matrix is,\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("Printing matrix in diagnol form,\n");
	diagonalprint(matrix);
}
