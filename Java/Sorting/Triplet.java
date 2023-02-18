/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
// Problem Statement: C++ program to find find the minimum number of jumps to reach the other end of the array starting from the 0th index. 
// And if the end isn’t reachable, return -1 as the output.
//Example:Given an array and a value, find if there is a triplet in the array whose sum is equal to the given value. 
If there is such a triplet present in the array, then print the triplet and return true. Else return false.
EXAMPLES:
1] Input: array = { 7, 10, 6, 14, 4, 9 }, sum = 25;
Output: Triplet is 4, 7, 14 */
// Java program to find a triplet
import java.util.*;
public class Triplet 
{
    // function that prints triplets
    public static boolean findTriplet(int A[], int arr_size, int sum) 
	{
        int x, y;
        // Sort the elements of the array in ascending order
        Arrays.sort(A);
        // Fix the first element of the triplet and find all other possible elements
        for (int i = 0; i < arr_size - 2; i++) {
            // For the other two elements, start two index variables from two ends of the array and move them toward each other
            x = i + 1; // index of the first element of the remaining elements
            y = arr_size - 1; // index of the last element
            while (x < y) {
                // If the triplet's sum equals the given sum, print it and return true
                if (A[i] + A[x] + A[y] == sum) {
                    System.out.println("Triplet is " + A[i] + ", " + A[x] + ", " + A[y]);
                    return true;
                }
                // If the triplet's sum is less than the given sum, move the left pointer to the right
                else if (A[i] + A[x] + A[y] < sum)
                    x++;
                // If the triplet's sum is greater than the given sum, move the right pointer to the left
                else
                    y--;
            }
        }
        // If no triplet is found, return false
        return false;
    }
    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] A = new int[n];
        System.out.println("Enter " + n + " integers in the array:");
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        System.out.print("Enter the sum value: ");
        int sum = sc.nextInt();
        int arr_size = A.length;
        boolean found = findTriplet(A, arr_size, sum);
        if (!found) {
            System.out.println("No triplet found with the given sum.");
        }
    }
}