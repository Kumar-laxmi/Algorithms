// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <stdio.h>

int search(int arr[], int N, int x)
{
	int i;
	for (i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Driver's code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	int result = search(arr, N, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}
