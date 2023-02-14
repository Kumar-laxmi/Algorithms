/*
  ------------------------------------------- The Problem Statement ------------------------------------------------------

    Given a unsorted array of size "n" we have to sort the array using Gnome sort.
    The first line of input is the size of the array going to be given and second line represents the array elements of size "n"

       INPUT :-  4
                  [5,3,4,2]

       OUTPUT :-  [2,3,4,5]

  ----------------------------------------------- Gnome Algorithm --------------------------------------------------------

    Gnome Algorithm will be as insertion sort but not the exact same.

    Firstly sorting an array in ascending order means the elements on the left side of an element should be less than the
    element we choosen.

    Lets take a pointer "pointer" which will be used to iterate the array whose current position is 0

    1) since there is no element on left side we can move to next element by incrementing pointer by 1
       to compare to say whether the array is sorted or not.

          if(pointer==0) { pointer++; }

    2) If the element on the left side is greater than the pointer element we need to swap.

           if(array[pointer] < array[pointer-1]) { swap(array[pointer] < array[pointer-1]); pointer--; }

    3) If the pointer element is equal or greater than the left side element we have to do nothing with the array just
       increment the pointer by 1, so it points to the next element.

            if(array[pointer] >= array[pointer-1]) { pointer++; }

    In this java program I have implemented the gnome sort by "recursively" calling the function, you can do with simple while loop too with the above three conditions.
    Since first and third conditions are doing the same job we can combine it as a single if block to reduce the code redundancy like this,

            if(pointer == 0 || array[pointer] < array[pointer-1]) { pointer++; }

    We can use "Ternary Operator" to implement the above if statement too.

   ----------------------------------------------- Complexities ----------------------------------------------------------

       Time Complexity  :- BigO(n^2)
       Space Complexity :- BigO(1)
       Space Complexity :- BigO(n) --> If you used recursion for sorting.

 */


//Importing Scanner Class to get input from the user.
import java.util.Scanner;
public class Gnome_Sorting
{
    public static void main(String[] args)
    {
        // Initializing the Scanner Class
        Scanner sc = new Scanner(System.in);

        // Reading the size of the array to be sorted
        System.out.print("Enter Size of the Array = ");
        int size_of_array = sc.nextInt();

        // Initializing the gnome_sort array
        int gnome_sort[] = new int[size_of_array];

        // Reading elements from user using for loop and putting it into the gnome_sort array
        for(int i=0;i<size_of_array;i++)
        {
            System.out.print("Enter the array element " + (i+1) + " = ");
            gnome_sort[i]= sc.nextInt();
        }

        // Since no input needed after this,so we are closing the scanner class.
        sc.close();

        // Printing the array elements before sorting.
        System.out.println("\nBefore Gnome sorting the array elements are");
        for (int i=0;i<size_of_array;i++)
        {
            System.out.print(gnome_sort[i] + " ");
        }

        // For iterating the gnome_sort array we need a variable that is called as pointer variable
        int pointer = 0;

        // Calling the Gnome_Sorting function which performs the GNOME sort recursively and storing the sorted array in the result array
        int result[] = Gnome_Sorting(gnome_sort,pointer);

        // Printing the array elements after gnome sorting
        System.out.println("\nAfter Gnome Sorting the array Elements are");
        for (int i=0;i<size_of_array;i++)
        {
            System.out.print(result[i]+ " ");
        }
    }

    // Function which performs the Gnome Sort
    // To keep the function safe and accessible inside this class only, I declared it as private you can declare it as public too.
    private static int[] Gnome_Sorting (int recursive_gnome[],int position)
    {
        // BASE CASE of recursion
        if(position< recursive_gnome.length)
        {
            // position == 0 --> It is the starting of the array so no elements on left side of the array it is the greatest we can increment.
            // recursive_gnome[position] >= recursive_gnome[position-1] --> The elements are already in sorted position so no need to swap, we can increment.
            if(position==0 || recursive_gnome[position] >= recursive_gnome[position-1])
            {
                // Recursively calling the Gnome_Sorting function
                Gnome_Sorting(recursive_gnome,position+1);
            }
            else
            {
                // Swapping the elements because the array element in left side is higher than the right side.
                int temp = recursive_gnome[position];
                recursive_gnome[position] = recursive_gnome[position-1];
                recursive_gnome[position-1] = temp;

                // Recursively calling the Gnome_Sorting function
                Gnome_Sorting(recursive_gnome,position-1);
            }
        }

        // Returning the sorted array by gnome sorting.
        return recursive_gnome;
    }
}
