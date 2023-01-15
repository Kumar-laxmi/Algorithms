// A Java program for merging overlapping intervals
/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
//Problem Statement : Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
//and return an array of the non-overlapping intervals that cover all the intervals in the input.
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
public class MergeOverlappingIntervals {
	// The main function that takes a set of intervals, merges
	// overlapping intervals and prints the result
	public static void mergeIntervals(Interval arr[])
	{
		// Test if the given set has at least one interval
		if (arr.length <= 0)
			return;
		// Create an empty stack of intervals
		Stack<Interval> stack=new Stack<>();
		// sort the intervals in increasing order of start time
		Arrays.sort(arr,new Comparator<Interval>(){
			public int compare(Interval i1,Interval i2)
			{
				return i1.start-i2.start;
			}
		});
		// push the first interval to stack
		stack.push(arr[0]);
		// Start from the next interval and merge if necessary
		for (int i = 1 ; i < arr.length; i++)
		{
			// get interval from stack top
			Interval top = stack.peek();
			// if current interval is not overlapping with stack top,
			// push it to the stack
			if (top.end < arr[i].start)
				stack.push(arr[i]);
			// Otherwise update the ending time of top if ending of current
			// interval is more
			else if (top.end < arr[i].end)
			{
				top.end = arr[i].end;
				stack.pop();
				stack.push(top);
			}
		}
		// Print contents of stack
		System.out.print("The Merged Intervals are: ");
		while (!stack.isEmpty())
		{
			Interval t = stack.pop();
			System.out.print("["+t.start+","+t.end+"] ");
		}
	}
	public static void main(String args[]) {
		Interval arr[]=new Interval[4];
		arr[0]=new Interval(1,3);
		arr[1]=new Interval(2,6);
		arr[2]=new Interval(8,10);
		arr[3]=new Interval(15,18);
		mergeIntervals(arr);
	}
}
class Interval
{
	int start,end;
	Interval(int start, int end)
	{
		this.start=start;
		this.end=end;
	}
}

