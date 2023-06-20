#include<bits/stdc++.h>
using namespace std;

// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n)
{
	bool isSorted = false;

	while (!isSorted)
	{
		isSorted = true;

		// Perform Bubble sort on odd indexed element
		for (int i=1; i<=n-2; i=i+2)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
		}

		// Perform Bubble sort on even indexed element
		for (int i=0; i<=n-2; i=i+2)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
		}
	}

	return;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
for (int i=0; i < n; i++)
	cout << arr[i] << " ";
cout << "\n";
}

// Driver program to test above functions.
int main()
{
	int arr[] = {50, 7, 3, 1, 0, -2, -5};
	int n = sizeof(arr)/sizeof(arr[0]);

	oddEvenSort(arr, n);
	printArray(arr, n);

	return (0);
}