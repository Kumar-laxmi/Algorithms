import java.util.*;

public class spiralPrint {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter number of rows : "); // Take the input of number of rows and columns
        int rows = s.nextInt();
        System.out.print("Enter number of columns: ");
        int cols = s.nextInt();
        int mat[][] = new int[rows][cols]; // Declare a 2D array to store the elements
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("Enter element : "); // Input the matrix elements
                mat[i][j] = s.nextInt();
            }
        }
        System.out.println("Spiral order of elements is : ");
        
        // Declare and initialize variables to store the starting and ending row and column indices of the matrix
        // Row start always points to the first row which is to be traversed , Row end points to the last row to be traversed //
        // Similarly Column start points to the first column to be traversed and Column end points to the last column to be traversed
        
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = rows - 1;
        int colEnd = cols - 1;
        while (rowStart <= rowEnd && colStart <= colEnd) {

            // Traverse the matrix in spiral form till the condition becomes false i.e all
            // the elements of the matrix have been traversed

            // Traverse the first row from the remaining rows through all the columns till the columns end and print the elements
            
            for (int col = colStart; col <= colEnd; col++) {
                System.out.print(mat[rowStart][col] + " ");
            }
            rowStart++; // Increment the starting row index as we traversed the first row

            // Traverse the last column from the remaining columns through all the rows till the rows end and print the elements
            
            for (int row = rowStart; row <= rowEnd; row++) {
                System.out.print(mat[row][colEnd] + " ");
            }
            colEnd--; // Decrement the ending column index as we traversed the last column

            // Traverse the last row from the remaining rows through all the columns till the columns start and print the elements
            
            for (int col = colEnd; col >= colStart && rowStart <= rowEnd; col--) {
                System.out.print(mat[rowEnd][col] + " ");
            }
            rowEnd--; // Decrement the ending row index as we traversed the last row

            // Traverse the first column from the remaining columns through all the rows till the rows start and print the elements
            
            for (int row = rowEnd; row >= rowStart && colStart <= colEnd; row--) {
                System.out.print(mat[row][colStart] + " ");
            }
            colStart++; // Increment the starting column index as we traversed the first column
        
        }
        s.close();
    }
}
