class MatrixMultiplication {
    static final int N = 3;  // size of the matrices

    // function to multiply two matrices
   public static void multiply(int[][] a, int[][] b, int[][] c)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < N; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    public static void main(String[] args)
    {
        int[][] a = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
        int[][] b = {{9, 8, 7},{6, 5, 4},{3, 2, 1}};
        int[][] c = new int[N][N];  // empty matrix to store the result

        multiply(a, b, c);
        // print the result
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                System.out.print(c[i][j] + " ");
            }
            System.out.println();
        }
    }
}
