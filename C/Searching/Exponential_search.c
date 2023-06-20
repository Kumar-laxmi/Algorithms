//----------------------------------------------Introduction---------------------------------------------------------------------------
// The Exponential_search class provides an implementation of the exponential search algorithm in C.
// It can be used to search for an element in a sorted array.

//----------------------------------------------Algorithm------------------------------------------------------------------------------
// The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until 
// the last element of a subarray is not greater. Once we find an index i (after repeated doubling of i), we know that the
// element must be present between i/2 and i

#include <stdio.h>

//method to find min
#define min(a, b) (((a) < (b)) ? (a) : (b))

//Searches for a target element in a sorted array using binary search.
int binary_search(int arr[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

//Searches for a target element in a sorted array using exponential search.
int exponential_search(int arr[], int size, int target) {
    if (arr[0] == target) {
        return 0;
    }

    int i = 1;
    while (i < size && arr[i] <= target) {
        i *= 2;//jumps to the two timed index.
    }

    return binary_search(arr, target, i / 2, min(i, size - 1));
}

int main() {
    int arr[100];
    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size ; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int result = exponential_search(arr, size, target);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
