import java.util.Scanner;

public class Strassen_Matrix_Multiplication {
    public static int[][] multiply(int[][] A, int[][] B) {
        int n = A.length;

        int[][] result = new int[n][n];

        if (n <= 1) {
            // if order of matrix is less than 1
            // then just return normal multiplication

            result[0][0] = A[0][0] * B[0][0];
        } else {
            // creating sub parts matrix to store the
            // divided matrix
            int[][] a11 = new int[n / 2][n / 2];
            int[][] a12 = new int[n / 2][n / 2];
            int[][] a21 = new int[n / 2][n / 2];
            int[][] a22 = new int[n / 2][n / 2];
            int[][] b11 = new int[n / 2][n / 2];
            int[][] b12 = new int[n / 2][n / 2];
            int[][] b21 = new int[n / 2][n / 2];
            int[][] b22 = new int[n / 2][n / 2];

            // Now divide the matrixA into 4 halves
            split(A, a11, 0, 0);
            split(A, a12, 0, n / 2);
            split(A, a21, n / 2, 0);
            split(A, a22, n / 2, n / 2);

            // Now Divid the matrixB into 4 halves
            split(B, b11, 0, 0);
            split(B, b12, 0, n / 2);
            split(B, b21, n / 2, 0);
            split(B, b22, n / 2, n / 2);

            // Now using the formula of Strassen
            // M1 = (a1 + a3) x( b1 + b2)

            int[][] M1 = multiply(add(a11, a22), add(b11, b22));

            // M2 = ( a2 + a4)x(b3+b4)
            int[][] M2 = multiply(add(a21, a22), b11);

            // M3 = (a1-a4)x(b1+a4)
            int[][] M3 = multiply(a11, sub(b12, b22));

            // M4 = a1x(b2-b4)
            int[][] M4 = multiply(a22, sub(b21, b11));

            // M5 = (a2+a4)x(b1)
            int[][] M5 = multiply(add(a11, a12), b22);

            // M6 = (a1+a2)x(b4)
            int[][] M6 = multiply(sub(a21, a11), add(b11, b12));

            // M7 = a4x(b3 - b1)
            int[][] M7 = multiply(sub(a12, a22), add(b21, b22));

            // P = M2+M3-M6-M7
            int[][] p = add(sub(add(M1, M4), M5), M7);

            // Q = M4+M6
            int[][] q = add(M3, M5);

            // R = M5+M7
            int[][] r = add(M2, M4);

            // S = M1-M3-M4-M5
            int[][] s = add(sub(add(M1, M3), M2), M6);

            // Join 4 halves into one result matrix
            join(p, result, 0, 0);
            join(q, result, 0, n / 2);
            join(r, result, n / 2, 0);
            join(s, result, n / 2, n / 2);
        }

        return result;
    }

    public static void split(int[][] P, int[][] C, int iB, int jB) {

        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
 
            // Inner loop for columns
            for (int j1 = 0, j2 = jB; j1 < C.length;
                 j1++, j2++)
 
                C[i1][j1] = P[i2][j2];
    }

    public static int[][] add(int[][] A, int[][] B)
    {
        int n = A.length;
        // Creating a 2D square matrix
        int[][] C = new int[n][n];
        // Outer loop for rows
        for (int i = 0; i < n; i++)        
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
        return C;
    }

    public static int[][] sub(int[][] A, int[][] B)
    {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
        return C;
    }

    public static void join(int[][] C, int[][] P, int iB, int jB)
    {
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for (int j1 = 0, j2 = jB; j1 < C.length;
                 j1++, j2++)
 
                P[i2][j2] = C[i1][j1];
    }

    public static void main(String[] args) {
        System.out.println("*********Strassen Multiplication Algorithm*********");

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of an matrix: ");
        int N = sc.nextInt();

        int[][] A = { { 1, 2, 3, 4 },
                      { 4, 3, 0, 1 },
                      { 5, 6, 1, 1 },
                      { 0, 2, 5, 6 } };
 
        
        int[][] B = { { 1, 0, 5, 1 },
                      { 1, 2, 0, 2 },
                      { 0, 3, 2, 3 },
                      { 1, 2, 1, 2 } };

        int[][] C = multiply(A, B);

        System.out.println("\n Product of matrices A and B : ");

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                System.out.print(C[i][j] + " ");
            }
            System.out.println();
        }
    }
}
