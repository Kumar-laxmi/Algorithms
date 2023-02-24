/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
// Problem Statement: C++ program to find find the minimum number of jumps to reach the other end of the array starting from the 0th index. And if the end isn’t reachable, return -1 as the output.
//Example:
1] INPUT: int arr[] = { 1, 9, 4, 7, 3, 7, 2, 1, 8, 9, 5 };
OUTPUT: Minimum number of jumps to reach the other end is 2 */
// C program for Minimum number of jumps to reach end
#include <limits.h>
#include <stdio.h>
int mini(int p, int q) { return (p < q) ? p : q; }
// Return minimum number of jumps to reach arr[n-1] from arr[0]
int minJump(int arr[], int n)
{  // jump[n-1] will contain the result
	int jump[n];
	int i, j;
	if (n == 0 || arr[0] == 0)
		return INT_MAX;
	jump[0] = 0;
	// Find the minimum number of jumps to reach arr[i]  from arr[0], and assign the value to jump[i]
	for (i = 1; i < n; i++) {
		jump[i] = INT_MAX;
		for (j = 0; j < i; j++) {
			if (i <= j + arr[j] && jump[j] != INT_MAX) {
				jump[i] = mini(jump[i], jump[j] + 1);
				break;
			}
		}
	}
	return jump[n - 1];
}
// Main function
int main()
{
	int array[] = { 1, 9, 4, 7, 3, 7, 2, 1, 8, 9, 5 };
	int size = sizeof(array) / sizeof(int);
	printf("Minimum number of jumps to reach end is %d ",
		minJump(array, size));
	return 0;
}