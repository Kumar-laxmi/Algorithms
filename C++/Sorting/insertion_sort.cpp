#include<iostream>
#include <stdio.h>
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
		cout<<a[i]<<" ";
	cout<<"\n";
}

int main()
{
	int arr[] = {45, 55, 20, 3, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, n);
	return 0;
}
