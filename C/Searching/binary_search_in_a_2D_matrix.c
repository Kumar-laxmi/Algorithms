//C code to search for an element in a 2d matrix using binary search

/*
    Binary Search is usally done on a 1D array but there can be multiple approaches to conduct a binary search in a 2D array. For eg,
    1. Convert the 2D array into a 1D array and conduct the search. 
        Time Complexity: O(Logm+Logn)
        Space Complexity: O(m+n)
    2. Another efficient approach is to virtualize the 2D array into a 1D array by using % and / operators to determine the indexes, and then 
        apply Binary Search in that virtual 1D array. 
        The following code follows this approach.
        Time Complexity: O(Logmn)
        Space Complexity : O(1).
*/
#include <stdio.h>
#define ROWS 3
#define COLS 4
 
int binSearchOnMatrix(int matrix[][COLS], int value);
int main()
{
  int twodarr[ROWS][COLS]; //two dimensional array
  int key; //search key
  int i, j; //counter variable
  int searchStatus; //1 if key is found, 0 otherwise.
 
  //read array
  printf("Enter %d x %d matrix in ascending order: ", ROWS, COLS);
  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++)
      scanf("%d", &twodarr[i][j]);
 
  printf("\nEnter search key: ");
  scanf("%d", &key);
 
  searchStatus = binSearchOnMatrix(twodarr, key);
  printf("Key (%d) is found: %d\n", key, searchStatus);
}
 
int binSearchOnMatrix(int matrix[][COLS], int key)
{
  int start = 0;//Initializing start and end index variables
  int mid, row, col, value;
  int end = ROWS * COLS - 1;
  while (start <= end)
  {
    mid = start + (end - start) / 2;//Preventing integer overflow
    row = mid / COLS;
    col = mid % COLS;
    value = matrix[row][col];//[mid/c][mid%cols] will give the middle index of the virtual 1D array
 
    if (value == key)
      return 1;//If found return true
    if (value > key)
      end = mid - 1;// Target is in the upper half of the matrix so ending index updates.
    else
      start = mid + 1;//Target is in the lower half of the matrix so starting index updates.
  }
  return 0;
}