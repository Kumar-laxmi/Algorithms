#include <stdio.h>
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
	prefixSum[0] = arr[0];
	for (int i = 1; i < n; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i];
}
int main()
{
	int arr[] = { 10, 4, 16, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int prefixSum[n];
	fillPrefixSum(arr, n, prefixSum);
	for (int i = 0; i < n; i++)
		printf("%d ", prefixSum[i]);
}

