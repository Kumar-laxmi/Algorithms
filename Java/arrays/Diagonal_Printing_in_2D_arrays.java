/*
 ---------------------------------------------- Problem Statement --------------------------------------------------------

    First line of input consist of number of rows and the second line consist of number of column the third line is the
    matrix elements. We have to print it in diagonal print pattern.

    INPUT :- 3
             3
             1 2 3
             4 5 6
             7 8 9

    OUTPUT :- 1 2 4 7 5 3 6 8 9

 ------------------------------------------------- Complexities ----------------------------------------------------------

    Time Complexity  :- BigO(n*m) --> where n is the number of rows and m is the number of columns
    Space Complexity :- BigO(1)

 */
import java.util.Scanner; // Importing scanner class to get input from user.
public class Diagonal_Printing_in_2D_arrays
{
    // Declaring static variables so that  we can use anywhere else in the program
    static int i=0;
    static int j=0;
    static int [][] matrix;
    static boolean[][] visited;
    static int row=0;
    static int column =0;
    public static void main(String[] args)
    {
        // Initializing the scanner class
        Scanner sc = new Scanner(System.in);
        // Reading the number of rows from user
        System.out.print("Enter number of rows = ");
        row = sc.nextInt();
        // Reading the number of columns from user
        System.out.print("Enter number of columns = ");
        column = sc.nextInt();
        // Initializing the matrix with number of rows and columns
        matrix = new int[row][column];
        // Boolean matrix to say whether the element is already visited or not.
        visited = new boolean[row][column];
        // Reading the matrix elements from the user.
        for (int k=0;k<row;k++)
        {
            for(int l=0;l<column;l++)
            {
                System.out.print("Enter matrix elements = ");
                matrix[k][l] = sc.nextInt();
                visited[k][l] = false;
            }
        }
        // Printing the matrix
        System.out.println("Before printing in diagonal form the matrix is,");
        for (int k=0;k<row;k++)
        {
            for(int l=0;l<column;l++)
            {
                System.out.print(matrix[k][l] + " ");
            }
            System.out.println();
        }
        System.out.println("Printing the matrix in diagonal form,");
        // Diagonal printing starts,
        DiagonalForm();
    }

    private static void DiagonalForm()
    {
        // Printing the starting element or the zeroth row and zeroth column element
        System.out.print(matrix[i][j] + " ");
        // Calling the function to change to downward direction.
        downwardbend();
    }
    // Function which performs downward bend
    private static void downwardbend()
    {
        // If the last element reaches then we have to stop it by using this if condition.
        if(i== row -1 && j == column -1)
        {
            System.out.print(matrix[i][j] + " ");
            System.exit(0);
        }
        // The downward function of first half is only by incrementing the value of j by 1;
        j++;
        // If the value of j is = column then we have to increment i by 1 and decrement j by 1
        // This state reaches when the increasing part of diagonal is finished and reducing its size.
        if( j==column)
        {
            j--;
            i++;
        }
        else if(j>column)
        {
            j=j-2;
            i=i+2;
        }
        // Calling the function to print elements going in downward diagonal.
        downdiagnol();
    }

    private static void downdiagnol()
    {
        // If the last element reaches then we have to stop it by using this if condition.
        if(i== row -1 && j == column -1)
        {
            System.out.print(matrix[i][j] + " ");
            System.exit(0);
        }
        // Printing the diagonal elements with the while loop
        while (i>=0 && j>=0 && i<row && j<column)
        {
            // Checking whether the element is already visited or not.
            // If it is already visited we don't need to print it again.
            if(!visited[i][j])
            {
                System.out.print(matrix[i][j]+ " ");
                visited[i][j] = true;
            }
            // Changing to the next diagonal elements
            i++;
            j--;
        }
        // When j is reached to 0 the while loop prints and in next iteration it reduces it again to -1, so we have to
        // increment it once to maintain running the loop.
        if(j<=0)
        {
            j++;
        }
        // Calling the function to turn into upward direction
        upwardbend();
    }

    private static void upwardbend()
    {
        // If the last element reaches then we have to stop it by using this if condition.
        if(i== row -1 && j == column -1)
        {
            System.out.print(matrix[i][j] + " ");
            System.exit(0);
        }
        // If the value of i is = row then we have to decrement i by 1 and increment j by 1
        // This state reaches when the increasing part of diagonal is finished and reducing its size.
        if(i==row)
        {
            i--;
            j++;
        }
        // Calling the function to print elements in upward direction
        upwarddiagnol();
    }

    private static void upwarddiagnol()
    {
        // If the last element reaches then we have to stop it by using this if condition.
        if(i== row -1 && j == column -1)
        {
            System.out.print(matrix[i][j] + " ");
            System.exit(0);
        }
        // Printing the diagonal elements with the while loop
        while (i>=0 && j>=0 && i<row && j<column)
        {
            // Checking whether the element is already visited or not.
            //If it is already visited we don't need to print it again.
            if(!visited[i][j])
            {
                System.out.print(matrix[i][j]+ " ");
                visited[i][j] = true;
            }
            // Changing to the next diagonal elements
            i--;
            j++;
        }
        // When i is reached to 0 the while loop prints and in next iteration it reduces it again to -1, so we have to
        // increment it once to maintain running the loop.
        if (i<=0)
        {
            i++;
            j--;
        }
        // Calling the function to change to downward direction.
        downwardbend();
    }
}