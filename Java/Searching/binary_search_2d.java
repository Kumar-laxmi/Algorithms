import java.util.*;

public class binary_search_2d{

    public static int[] search(int[][] matrix, int target){
        int row = 0;
        int col = matrix.length - 1;

        while(row < matrix.length && col >= 0){
            if(matrix[row][col] == target){
                return new int[]{row, col};
            }
            if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }
        //if not found in the matrix, return [-1, -1]
        return new int[]{-1, -1};
    }
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int [][] matrix= {
            {10, 20, 30, 40},
            {15, 25, 35, 45},
            {28, 29, 37, 49},
            {33, 34, 38, 50}
        };
        System.out.print("Enter the number to be searched in the 2D Matrix : ");
        int n = sc.nextInt();
        System.out.println(Arrays.toString(search(matrix, n)));
        sc.close();
    }
}