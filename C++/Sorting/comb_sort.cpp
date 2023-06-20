#include<bits/stdc++.h>
using namespace std;
int getNextGap(int gap)
{
	gap = (gap*10)/13;
	if (gap < 1)
		return 1;
	return gap;
}
void combSort(int a[], int n)
{
	int gap = n;
	bool swapped = true;
	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);
		swapped = false;
		for (int i=0; i<n-gap; i++)
		{
			if (a[i] > a[i+gap])
			{
				swap(a[i], a[i+gap]);
				swapped = true;
			}
		}
	}
}

int main()
{
        cout << "Enter the length of array" << endl;
    int n;
    cin >> n;
    int *a = new int(n);
    // Getting elements of array
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Original array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
	combSort(a, n);

    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete (a);
    return 0;
}
