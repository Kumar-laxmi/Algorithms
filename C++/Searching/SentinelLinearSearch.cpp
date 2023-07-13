#include <iostream>
using namespace std;

// Function to search x in the given array
void sentinelSearch(int arr[], int n, int key)
{
    // Last element of the array
    int last = arr[n - 1];
    // Element to be searched and placed at the last index
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key)
        i++;
    // Putting the last element back
    arr[n - 1] = last;
    if ((i < n - 1) || (arr[n - 1] == key))
    {
        cout << key << " present at the index " << i << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    sentinelSearch(arr, n, key);
    return 0;
}
