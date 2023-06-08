/*

/*

=================================  PROBLEM STATEMENT =================================

Write a program to multiply two matrices using Strassen's algorithm.
Strassen's algorithm for matrix multiplication is a divide and conquer algorithm.

=================================  SOLUTION =================================

    1. Divide the matrices A and B in 4 sub-matrices of size N/2 x N/2 as shown in the below diagram.

                       MATRIX 1              MATRIX 2
                    +-----+-----+         +-----+-----+ 
                    |  a  |  b  |         |  e  |  f  | 
                    +-----+-----+         +-----+-----+ 
                    |  c  |  d  |         |  g  |  h  | 
                    +-----+-----+         +-----+-----+ 

    2. Calculate following values recursively.
                p1 = a(f - h)
                p2 = (a + b)h
                p3 = (c + d)e
                p4 = d(g - e)
                p5 = (a + d)(e + h)
                p6 = (b - d)(g + h)
                p7 = (a - c)(e + f)

    3. Calculate following:-
            c11 = p5 + p4 - p2 + p6
            c12 = p1 + p2
            c21 = p3 + p4
            c22 = p1 + p5 - p3 - p7

    4. merge c11, c12, c21, c22 as given below

                    +-----------+-----------+
                    |    c11    |    c12    |       
                    +-----------+-----------+
                    |    c21    |    c22    |
                    +-----------+-----------+

=================================  COMPLEXITY =================================

Time Complexity: O(n^2.8074)
Space Complexity: O(n^2)

=================================  EXAMPLES =================================

Input: 1 2 3 4
       5 6 7 8
       9 10 11 12
       13 14 15 16
       1 2 3 4
       5 6 7 8
       9 10 11 12
       13 14 15 16
Output: 90 100 110 120
        202 228 254 280
        314 356 398 440
        426 484 542 600



*/



import java.util.Scanner;


public class strassen_matrix_multiplication{


    public int[][] add_matrix(int[][] A, int[][] B){
            int N = A.length;
            int[][] C = new int[N][N];
    
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            return C;
    }

    public int[][] subtract_matrix(int[][] A, int[][] B){
            int N = A.length;
            int[][] C = new int[N][N];
    
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            return C;
    }

    public void print_matrix(int[][] A){
        int n = A.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }

    public int[][] matrix_multiplication(int[][] A,int[][] B){

        int row = A.length;
        int col = A[0].length;


        

        int[][] C = new int[row][col];

        if (row == 1 && col == 1) {
            C[0][0] = A[0][0] * B[0][0];
            return C;
        }

        int nRow = row/2;
        int nCol = col/2;

        int[][] a = new int[nRow][nCol];
        int[][] b = new int[nRow][nCol];
        int[][] c = new int[nRow][nCol];
        int[][] d = new int[nRow][nCol];
        int[][] e = new int[nRow][nCol];
        int[][] f = new int[nRow][nCol];
        int[][] g = new int[nRow][nCol];
        int[][] h = new int[nRow][nCol];

        for (int i = 0; i<nRow; i++){
            for (int j = 0; j<nCol; j++){
                a[i][j] = A[i][j];
                b[i][j] = A[i][j+nCol];
                c[i][j] = A[i+nRow][j];
                d[i][j] = A[i+nRow][j+nCol];

                e[i][j] = B[i][j];
                f[i][j] = B[i][j+nCol];
                g[i][j] = B[i+nRow][j];
                h[i][j] = B[i+nRow][j+nCol];
            }
        }


        int[][] ts1 = subtract_matrix(f,h);
        int[][] ts2 = add_matrix(a,b);
        int[][] ts3 = add_matrix(c,d);
        int[][] ts4 = subtract_matrix(g,e);
        int[][] ts5 = add_matrix(a,d);
        int[][] ts6 = add_matrix(e,h);
        int[][] ts7 = subtract_matrix(b,d);
        int[][] ts8 = add_matrix(g,h);
        int[][] ts9 = subtract_matrix(a,c);
        int[][] ts10 = add_matrix(e,f);

        int[][] p1 = matrix_multiplication(a,ts1);
        int[][] p2 = matrix_multiplication(ts2,h);
        int[][] p3 = matrix_multiplication(ts3,e);
        int[][] p4 = matrix_multiplication(d,ts4);
        int[][] p5 = matrix_multiplication(ts5,ts6);
        int[][] p6 = matrix_multiplication(ts7,ts8);
        int[][] p7 = matrix_multiplication(ts9,ts10);

        int[][] c11 = add_matrix(p5,p4);
        c11 = subtract_matrix(c11,p2);
        c11 = add_matrix(c11,p6);

        int[][] c12 = add_matrix(p1,p2);

        int[][] c21 = add_matrix(p3,p4);

        int[][] c22 = add_matrix(p5,p1);
        c22 = subtract_matrix(c22,p3);
        c22 = subtract_matrix(c22,p7);



        

        for(int i=0;i<nRow;i++){
            for(int j=0;j<nCol;j++){
                C[i][j] = c11[i][j];
                C[i][j+nCol] = c12[i][j];
                C[i+nRow][j] = c21[i][j];
                C[i+nRow][j+nCol] = c22[i][j];
            }
        }

        return C;


    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the order of matrix: ");

        int n = sc.nextInt();

        int[][] A = new int[n][n];
        int[][] B = new int[n][n];

        strassen_matrix_multiplication obj = new strassen_matrix_multiplication();

        System.out.println("Enter the elements of matrix A: ");

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j] = sc.nextInt();
            }
        }



        System.out.println("Enter the elements of matrix B: ");

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                B[i][j] = sc.nextInt();
            }
        }

        obj.print_matrix(A);
        

        int[][] c = obj.matrix_multiplication(A,B);

        System.out.println("The result matrix is: ");

        

        obj.print_matrix(c);

        
    }
}