#include <iostream>

#include <math.h>
using namespace std;

void Sort(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
	// Inputing array from user
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	Sort(arr, n);

	return 0;
}