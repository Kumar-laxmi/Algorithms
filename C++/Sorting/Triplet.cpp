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
// C++ program to find a triplet
#include <bits/stdc++.h>
using namespace std;
// function that  prints triplets
bool Triplet(int A[], int arr_size, int sum)
{
	int x, y;
	// Sort the elements
	sort(A, A + arr_size);
	//Fixed the first element and find all other element
	for (int i = 0; i < arr_size - 2; i++) 
	{
		// for other two elements, start two index variables from two corners of the array and move them toward each other
		x = i + 1; // index of the first element of the remaining elements
		y = arr_size - 1; // index of last element
		while (x < y) {
			if (A[i] + A[x] + A[y] == sum) 
			{
				printf("Triplet is %d, %d, %d", A[i], A[x],A[y]);
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
// Main function
int main()
{
	int A[] = { 7, 10, 6, 14, 4, 9 };
	int sum = 25;
	int arr_size = sizeof(A) / sizeof(A[0]);
	Triplet(A, arr_size, sum);
	return 0;
}