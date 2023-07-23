#include <iostream>
#include <vector>

using namespace std;
// Reverses the array from index 0 to i
void flip(vector<int> &arr, int i)
{
    int start = 0;
    while (start < i)
    {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}
// Finds the index of the maximum element in the array
int findMaxIndex(vector<int> &arr, int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        // If the current element is greater than the maximum element so far,
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(vector<int> &arr)
{
    int n = arr.size();
    for (int currSize = n; currSize > 1; currSize--)
    {
        // Below line of code will find the index of the maximum element in the current subvector
        int maxIndex = findMaxIndex(arr, currSize);
        // If the maximum element is not alreay at the end of thee subvector,
        // perform the flipping operations to move that to  correct position
        if (maxIndex != currSize - 1)
        {
            flip(arr, maxIndex);
            flip(arr, currSize - 1);
        }
    }
}

int main()
{
    vector<int> arr = {6, 3, 9, 2, 5};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    pancakeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// //General steps we followed
// -->Start with the given unsorted array.
// -->Set the current size of the array as the total number of elements (n).
// -->Repeat the following steps until the current size becomes 1:
//      --> Find the index of the maximum element in the subarray from index 0 to the current size minus 1. Let's call this index 'mi' (maxIndex).
//      --> Flip the subarray from index 0 to 'mi', which will move the maximum element to the beginning of the array.
//      --> Flip the entire subarray from index 0 to the current size minus 1, which will move the maximum element to its correct position at the end of the array.
// -->Once all the iterations are completed, the array will be sorted in ascending order.