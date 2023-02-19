/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
// Problem Statement: C++ program to find find the minimum number of jumps to reach the other end of the array starting from the 0th index. And if the end isn’t reachable, return -1 as the output.
//Example:
1] INPUT: int arr[] = { 1, 9, 4, 7, 3, 7, 2, 1, 8, 9, 5 };
OUTPUT: Minimum number of jumps to reach the other end is 2 */
// JAVA Code for Minimum number of jumps to reach end
import java.io.*;
public class Min_Jump {
	private static int minJump(int[] arr, int n)
	{   // jump[n-1] will contain the result
		int jump[] = new int[n];
		int i, j;
		// if first element is 0,
		if (n == 0 || arr[0] == 0)
			return Integer.MAX_VALUE;
		// end cannot be reached
		jump[0] = 0;
        // Find the minimum number of jumps to reach arr[i]  from arr[0], and assign the value to jump[i]
		for (i = 1; i < n; i++) {
			jump[i] = Integer.MAX_VALUE;
			for (j = 0; j < i; j++) {
				if (i <= j + arr[j]
					&& jump[j] != Integer.MAX_VALUE) {
					jump[i]
						= Math.min(jump[i], jump[j] + 1);
					break;
				}
			}
		}
		return jump[n - 1];
	}
	// Main function
	public static void main(String[] args)
	{
		int array[] = { 1, 9, 4, 7, 3, 7, 2, 1, 8, 9, 5 };
		System.out.println(
			"Minimum number of jumps to reach end is : "
			+ minJump(array, array.length));
	}
}