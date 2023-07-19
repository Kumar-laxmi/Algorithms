// Path: C\Searching\quick_select.c
// C program to kth smallest element using quickSelect Algorithm.
// Time-Complexity: O(N^2), where N is the size of array.

#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to rearrange elements around the pivot
int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]); // Move pivot to the end
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[right]); // Move pivot to its final place
    return storeIndex;
}

// Quickselect function
int quickSelect(int arr[], int left, int right, int k) {
    if (left == right)
        return arr[left];

    int pivotIndex = left + (rand() % (right - left + 1));
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return quickSelect(arr, left, pivotIndex - 1, k);
    else
        return quickSelect(arr, pivotIndex + 1, right, k);
}

int main() {
    int arr[] = {3, 8, 2, 5, 1, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4; // Find the 4th smallest element

    int result = quickSelect(arr, 0, n - 1, k - 1);
    printf("The %d-th smallest element is: %d\n", k, result);

    return 0;
}
