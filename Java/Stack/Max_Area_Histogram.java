/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
//Problem Statement To determine the largest area in a given histogram.
// Java program to find maximum rectangular area in linear
import java.util.Stack;
public class Max_Area_Histogram 
{
	// The main function to find the maximum rectangular area under given histogram with n bars
	static int MaxArea(int hist[], int n)
	{
		// Creating an empty stack. The stack holds indexes of hist[] array The bars stored in stack are always in increasing order of their heights.
		Stack<Integer> s = new Stack<>();
		int max_a = 0; // Initialize max area
		int t; // To store top value of stack
		int area_with_top; // To store area with top bar as the smallest bar
		// Run through all bars of given histogram
		int i = 0;
		while (i < n) {
			// If this bar is higher than the bar on top stack, push it to stack
			if (s.empty() || hist[s.peek()] <= hist[i])
				s.push(i++);
			// If this bar value is lower than top of the stack, then calculate area of rectangle with stack top as the smallest (or minimum height) bar.
			else {
				t = s.peek(); // store the top index value of stack
				s.pop(); // pop the top element
				// Calculate the area with hist[t] stack as smallest bar
				area_with_top
					= hist[t]
					* (s.empty() ? i : i - s.peek() - 1);
				// update maximum area
				if (max_a < area_with_top)
					max_a = area_with_top;
			}
		}
		// Now pop out the remaining bars from stack and
		while (s.empty() == false) 
        {
			t = s.peek();
			s.pop();
			area_with_top
				= hist[t]
				* (s.empty() ? i : i - s.peek() - 1);
			if (max_a < area_with_top)
				max_a = area_with_top;
		}
		return max_a;
	}
	// Main function
	public static void main(String[] args)
	{
		int hist[] = { 5, 4, 1, 6, 3, 2, 2 };
		// Function call
		System.out.println("Max area of given histogram is : "
						+ MaxArea(hist, hist.length));
	}
}