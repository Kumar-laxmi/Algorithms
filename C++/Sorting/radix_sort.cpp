//  Radix sort is a sorting algorithm that sorts the elements by first grouping the individual digits of the same place value. Then, sort the elements according to their increasing/decreasing order.
//  Time Complexity
// Best	:O(n+k)
// Worst :O(n + k)
// Average: O(n + k)
// Space Complexity : O(max)

#include <iostream>
        using namespace std;

// function to find largest value of the array
int largest(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

// A function to do counting sort of arr[] according to  the digit represented by exp.
void countSort(int arr[], int size, int place)
{
    const int max = 10;
    int output[100];
    int count[max];
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }
    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / place) % 10]++;
    }
    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}
// Radix Sort Function
void radixsort(int arr[], int size)
{
    // Get maximum element
    int max = largest(arr, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countSort(arr, size, place);
}
// main function
int main()
{
    int arr[] = {121, 432, 564, 23, 1, 45, 788};
    int size = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, size);
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}