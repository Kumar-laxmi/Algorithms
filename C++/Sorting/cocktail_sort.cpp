#include <iostream>
using namespace std;

// Function to perform Cocktail Sort
void cocktailSort(int arr[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;

        // traverse the array from left to right
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                // swap if the element found is greater than the next element
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted.
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it can be used in the next stage
        swapped = false;

        // move the end point back by one, because the last element is in its rightful spot
        --end;

        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }

        // move the starting point forward by one, because the first element is in its rightful spot
        ++start;
    }
}


// here's the main function to test the implementation
int main()
{
    int arr[] = {5, 1, 4, 2, 8, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cocktailSort(arr, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

