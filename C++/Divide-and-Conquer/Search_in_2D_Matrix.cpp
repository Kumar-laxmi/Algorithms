/*---------------------------------------------- Divide and Conquer --------------------------------------------------------
---------------------------------------------- Problem Statement --------------------------------------------------------
    Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    * Integers in each row are sorted in ascending from left to right.
    * Integers in each column are sorted in ascending from top to bottom.
    
    Example 1:
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true
    
    Example 2:
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false
    
    

 ---------------------------------------------- Constraints --------------------------------------------------------
    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -10^9 <= matrix[i][j] <= 10^9
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -10^9 <= target <= 10^9

 ------------------------------------------------- Complexities ----------------------------------------------------------

    Time Complexity  :- BigO(m+n) where m is the number of rows in the matrix and n is the number of columns.
    Space Complexity :- BigO(1)
*/


#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& v, int target) {
    int rows = v.size(); // Get the number of rows in the matrix

    int cols = v[0].size(); // Get the number of columns in the matrix

    int i = 0; // first row

    int j = cols - 1; // last column

    while (i <= (rows - 1) && j >= 0) { // base condtion row alway smaller than total_rows & col always greater than 0
        if (v[i][j] == target) // If the current element is equal to the target, return true
            return true;
        else if (v[i][j] > target) // If the current element is greater than the target, move left in the current row
            j--;
        else // If the current element is less than the target, move down to the next row
            i++; 
    }
    return false; // If the target is not found, return false
}


int main() {
 
  

   
    vector<vector<int>>V {{1,4,7,11,15}, {2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int  target = 5;
    cout<<searchMatrix(V ,target);

    
    return 0;
}