#include <iostream>
#include <algorithm>
using namespace std;

// Reverses the array from index 0 to i
void flip(int arr[], int i)
{
    int start = 0;
    while (start < i) {
        swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

// Returns the index of the maximum element in the array
int findMax(int arr[], int n)
{
    int max = 0, i;
    for (i = 0; i < n; i++)
        if (arr[i] > arr[max])
            max = i;
    return max;
}

// Sorts the array using Pancake Sort
void pancakeSort(int arr[], int n)
{
    for (int curr_size = n; curr_size > 1; --curr_size) {
        int max = findMax(arr, curr_size);

        if (max != curr_size - 1) {
            flip(arr, max);
            flip(arr, curr_size - 1);
        }
    }
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program
int main()
{
    int arr[] = { 23, 10, 20, 11, 12, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    pancakeSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
