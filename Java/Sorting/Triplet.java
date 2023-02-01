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
class Triplet 
{
	// returns true if there is triplet with sum equal
	// to 'sum' present in A[]. Also, prints the triplet
	boolean Trip (int A[], int arr_size, int sum)
	{
		int x, y;
		// Sort the elements
		quickSort(A, 0, arr_size - 1);
		//Fixed the first element and find all other element
		for (int i = 0; i < arr_size - 2; i++) 
		{
            // for other two elements, start two index variables from two corners of the array and move them toward each other
			x = i + 1; // index of the first element in the
			y = arr_size - 1; // index of the last element
			while (x < y) 
			{
				if (A[i] + A[x] + A[y] == sum) 
				{
					System.out.print("Triplet is " + A[i] + ", " + A[x] + ", " + A[y]);
					return true;
				}
				else if (A[i] + A[x] + A[y] < sum)
					x++;
				else
					y--;
			}
		}
		// No triplet was found
		return false;
	}
	int partition(int A[], int si, int ei)
	{
		int x = A[ei];
		int i = (si - 1);
		int j;
		for (j = si; j <= ei - 1; j++) 
		{
			if (A[j] <= x) 
			{
				i++;
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		int temp = A[i + 1];
		A[i + 1] = A[ei];
		A[ei] = temp;
		return (i + 1);
	}
	// Implementation of Quick Sort
	void quickSort(int A[], int si, int ei)
	{
		int pi;
		// Partitioning index
		if (si < ei) 
		{
			pi = partition(A, si, ei);
			quickSort(A, si, pi - 1);
			quickSort(A, pi + 1, ei);
		}
	}
	// Main Function
	public static void main(String[] args)
	{
		Triplet triplet = new Triplet();
		int A[] = { 1, 4, 45, 6, 10, 8 };
		int sum = 22;
		int arr_size = A.length;
		triplet.Trip(A, arr_size, sum);
	}
}