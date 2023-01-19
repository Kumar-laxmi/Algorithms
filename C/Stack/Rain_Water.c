/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
Problem Description
Program to find the maximum trap water by using stack.
Examples:
 1] INPUT: {1, 1, 5, 2, 1, 8 , 1, 0, 2, 1, 2, 6};
    OUTPUT 31 */
// Implementation in C of the above approach
#include <stdio.h>
// Creating MAX function
#define max(x, y) (((x) > (y)) ? (x) : (y))
// Creating MIN function
#define min(x, y) (((x) < (y)) ? (x) : (y))
// Creating a Function that returns the maximum water
int RainWater(int arr[], int x)
{
	// left[i] contains height of wall
	// left of ith wall
	int left[x];
	// Right [i] contains height of wall
	// right of ith wall
	int right[x];
	// Initialize the result
	int water = 0;
	// Filled the left array
	left[0] = arr[0];
	for (int i = 1; i < x; i++) 
	{
		left[i] = max(left[i - 1], arr[i]);
	}
	// Filled the right array
	right[x - 1] = arr[x - 1];
	for (int i = x - 2; i >= 0; i--) {
		right[i] = max(right[i + 1], arr[i]);
	}
	// Calculate the accumulated water element by element consider the amount of water on i'th bar, the amount of water accumulated on this particular
	// bar will be equal to min(left[i], right[i]) - arr[i]
	for (int i = 1; i < x - 1; i++) {
		int var = min(left[i - 1], right[i + 1]);
		if (var > arr[i]) {
			water += var - arr[i];
		}
	}
	return water;
}
// Main Function
int main()
{
	int arr[] = {1, 1, 5, 2, 1, 8 , 1, 0, 2, 1, 2, 6};
	int m = sizeof(arr) / sizeof(arr[0]);
	printf("%d", RainWater(arr, m));
	return 0;
}