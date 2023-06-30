/*

Problem:
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area
 
Approach:
1. Initialize a variable `maxSide` to 0 to store the maximum side length of the square.
2. Check if the given matrix is empty, if so, return 0.
3. Create a dynamic programming array `dp` with dimensions (rows + 1) x (cols + 1), where `rows` and `cols` are the dimensions of the matrix.
4. Traverse through the matrix starting from index (1, 1) to (rows, cols).
5. For each cell, if the value is '1', calculate the side length of the square by taking the minimum of the values from the top, left, and diagonal cells in the `dp` array, and add 1.
6. Update the `maxSide` variable with the maximum side length found so far.
7. Finally, return the area of the largest square by multiplying `maxSide` with itself.

Time Complexity: O(m*n), where m is the number of rows and n is the number of columns in the matrix.

Space Complexity: O(m*n), as we use an additional dp array of the same dimensions as the matrix.

Sample Input:
char[][] matrix = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'}
};


Sample Output:
4

Note:
In the given sample input, the largest square containing only 1's has a side length of 2, so the area is 4.
*/

public class LargestSquare {
    public int maximalSquare(char[][] matrix) {
        int maxSide = 0; // variable to store the maximum side length of the square
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return maxSide; // return 0 if the matrix is empty
        }

        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] dp = new int[rows + 1][cols + 1]; // create a dynamic programming array to store the side length of the square

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1') { // if current cell is 1
                    dp[i][j] = Math.min(Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1; // calculate the side length of the square based on top, left, and diagonal cells
                    maxSide = Math.max(maxSide, dp[i][j]); // update the maximum side length
                }
            }
        }

        return maxSide * maxSide; // return the area of the largest square
    }
}
