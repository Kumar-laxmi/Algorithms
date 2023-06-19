/**----------------------------------------------Introduction---------------------------------------------------------------------------
 * The Exponential_search class provides an implementation of the exponential search algorithm in Java.
 * It can be used to search for an element in a sorted array.
 */

 /*----------------------------------------------Algorithm------------------------------------------------------------------------------
  * The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until 
  last element of a subarray is not greater. Once we find an index i (after repeated doubling of i), we know that the
   element must be present between i/2 and i
  */

#include <iostream>
#include <algorithm>
using namespace std;


 /* Performs binary search within a specified range of a sorted array.
 *
 *    The sorted array to be searched.
 *  The element to be searched for.
 *    The left boundary of the search range.
 *   The right boundary of the search range.
 *  The index of the target element if found, otherwise -1.
 */
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
/**
 * Searches for a target element in a sorted array using exponential search.
 *
 *  arr    The sorted array to be searched.
 *  size   The size of the array.
 *  target The element to be searched for.
 * The index of the target element if found, otherwise -1.
 */


int exponentialSearch(int arr[], int size, int target) {
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

    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    cout << "Enter the target element: ";
    cin >> target;

    int result = exponentialSearch(arr, size, target);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}