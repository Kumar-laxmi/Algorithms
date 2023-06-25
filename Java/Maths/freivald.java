
// Given three matrices A, B and C, find if C is a product of A and B.
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

class freivald {
    static int n; // Number of rows in matrix A and C
    static int m; // Number of columns in matrix A, number of rows in matrix B
    static int k; // Number of columns in matrix B and C

    // Function to perform matrix-vector multiplication
    static int[] matrixVectorMultiply(int[][] matrix, int[] vector) {
        int[] result = new int[matrix.length];
        Arrays.fill(result, 0);
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }

    // Function to check if the product of A and B equals C
    static String checkProduct(int[][] A, int[][] B, int[][] C) {
        Random random = new Random();
        int[] x = new int[m]; // vector length should be m

        for (int i = 0; i < m; i++) {
            x[i] = random.nextInt(2); // Generating random vector x with 0s and 1s
        }

        int[] y = matrixVectorMultiply(A, matrixVectorMultiply(B, x)); // y = A * (B * x)
        int[] z = matrixVectorMultiply(C, x); // z = C * x

        for (int i = 0; i < n; i++) {
            if (y[i] - z[i] != 0) {
                return "Product is incorrect.";
            }
        }
        return "Product is correct.";
    }

    // Function to read matrix values from user input
    static int[][] readMatrixFromInput(int rows, int cols) {
        Scanner scanner = new Scanner(System.in);
        int[][] matrix = new int[rows][cols];

        System.out.println("Enter matrix values row-wise:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        return matrix;
    }

    // Driver code
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows in matrix A and C: ");
        n = scanner.nextInt();
        System.out.print("Enter the number of columns in matrix A and rows in matrix B: ");
        m = scanner.nextInt();
        System.out.print("Enter the number of columns in matrix B and C: ");
        k = scanner.nextInt();

        int[][] A = readMatrixFromInput(n, m);
        int[][] B = readMatrixFromInput(m, k);
        int[][] C = readMatrixFromInput(n, k);

        System.out.println(checkProduct(A, B, C));
    }
}
