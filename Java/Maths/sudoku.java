import java.util.Scanner;

public class SudokuSolver {
    
    // Function to check if a number can be placed in the Sudoku grid at a particular position
    public static boolean canPlace(int[][] mat, int i, int j, int n, int no) {
        // Checking if the number already exists in the same row or column
        for (int x = 0; x < n; x++) {
            if (mat[x][j] == no || mat[i][x] == no) {
                return false;
            }
        }

        // Determining the starting index of the current sub-grid
        int rn = (int) Math.sqrt(n);
        int sx = (i / rn) * rn;
        int sy = (j / rn) * rn;

        // Checking if the number already exists in the sub-grid
        for (int x = sx; x < sx + rn; x++) {
            for (int y = sy; y < sy + rn; y++) {
                if (mat[x][y] == no) {
                    return false;
                }
            }
        }

        return true;
    }

    // Function to solve the Sudoku puzzle
    public static boolean solveSudoku(int[][] mat, int i, int j, int n) {
        // Base case: If we have reached the last row, print the Sudoku solution
        if (i == n) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    System.out.print(mat[x][y] + " ");
                }
                System.out.println();
            }
            return true; // Return true to indicate a solution is found
        }

        // If we have reached the last column, move to the next row
        if (j == n) {
            return solveSudoku(mat, i + 1, 0, n);
        }

        // If the current cell already contains a number, move to the next column
        if (mat[i][j] != 0) {
            return solveSudoku(mat, i, j + 1, n);
        }

        // Try placing numbers from 1 to n in the current empty cell
        for (int no = 1; no <= n; no++) {
            if (canPlace(mat, i, j, n, no)) {
                mat[i][j] = no; // Place the number in the current cell

                // Recursively solve the Sudoku puzzle for the next cell
                boolean could = solveSudoku(mat, i, j + 1, n);
                if (could) {
                    return true; // Return true if a solution is found
                }
            }
        }

        // If no number can be placed in the current cell, backtrack
        mat[i][j] = 0;
        return false;
    }

    public static void main(String[] args) {
        int[][] mat = new int[9][9];
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Input the Sudoku grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = scanner.nextInt();
            }
        }

        solveSudoku(mat, 0, 0, n); // Solve the Sudoku puzzle
    }
}
