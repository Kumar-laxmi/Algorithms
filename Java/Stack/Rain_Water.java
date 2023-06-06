/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
Problem Description
Program to find the maximum trap water by using stack .
Examples:
 1] INPUT: {1, 1, 5, 2, 1, 8 , 1, 0, 2, 1, 2, 6};
    OUTPUT 31 */
import java.io.*;
import java.util.*;
// Java implementation of the approach
public class Rain_Water {
	// Function to return the maximum
	// water that can be stored
	public static int RainWater(int[] height)
	{
		// Stores the indices of the bars
		Stack<Integer> stack = new Stack<>();
		// size of the array
		int n = height.length;
		// Stores the final result
		int ans = 0;
		// Loop through the each bar
		for (int i = 0; i < n; i++) {
			// Remove bars from the stack
			// until the condition holds
			while ((!stack.isEmpty())
				&& (height[stack.peek()] < height[i])) {
				// store the height of the top
				// and pop it.
				int pop_height = height[stack.peek()];
				stack.pop();
				// If the stack does not have any
				// bars or the popped bar
				// has no left boundary
				if (stack.isEmpty())
					break;
				// Get the distance between the
				// left and right boundary of
				// popped bar
				int distance = i - stack.peek() - 1;
				// Calculate the min. height
				int min_height
					= Math.min(height[stack.peek()],
							height[i])
					- pop_height;

				ans += distance * min_height;
			}
			// If the stack is either empty or
			// height of the current bar is less than
			// or equal to the top bar of stack
			stack.push(i);
		}
		return ans;
	}
	// Driver code
	public static void main(String[] args)
	{
		int arr[] = {1, 1, 5, 2, 1, 8 , 1, 0, 2, 1, 2, 6};
		System.out.print(RainWater(arr));
	}
}