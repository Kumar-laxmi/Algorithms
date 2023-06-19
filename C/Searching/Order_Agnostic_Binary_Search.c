/*
PROBLEM STATEMENT : Perform an order-agnostic binary search on a sorted array. The only way it is different from a regular binary search is that we don't know whether the array is sorted in sorted in descending or ascending order.

INPUT FROM USER :
 * arr -> The sorted array to search in.
 * n -> The total number of elements inside the array.
 * key -> The value to search for.

OUTPUT :
* Print the index of the key value in the array if found, -1 otherwise. 


PREREQUISITE : The function assumes that the input array is sorted in either ascending or descending order. If the array is not sorted , the program may not produce correct results.

COMPLEXITY :
*Time Complexity : O(log(n))
*Space Complexity : O(1)

PSEUDOCODE :
1. Input the array from the user.
2. Input the key to be searched inside the array.
3. Call the function order_agnostic_binary_search() with the array, size of the array and the key as the parameters.
4. The function order_agnostic_binary_search() will determine whether the array is sorted in ascending or descending order and then call the appropriate function for each case.
5.(A) The function ascending_binary_search() will perform binary search on the array if it is sorted in ascending order.
5.(B) The function descending_binary_search() will perform binary search on the array if it is sorted in descending order.
6. Store the result returned by the function order_agnostic_binary_search() in a variable 'result'.
7. If the value of 'result' is -1, print "Target value not found in the array.".
8. Else print the index at which the key to search for is found in the array.
*/


#include<stdio.h>
#include<stdlib.h>

int order_agnostic_binary_search(int arr[], int size, int target);
int ascending_binary_search(int arr[], int size, int target);
int descending_binary_search(int arr[], int size, int target);

int main()
{
	int n,i,key;
	printf("enter the total number of elements in array: ");
	scanf("%d",&n);
	int *arr = (int*)malloc(n*sizeof(int));
	printf("enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the key to be searched: ");
	scanf("%d",&key);
    int result = order_agnostic_binary_search(arr, n, key);
    if (result == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index: %d\n", result);
    }

	return 0;
}

int order_agnostic_binary_search(int arr[], int size, int target) {
    /*
     * @param arr The sorted array to search in.
     * @param size The size of the array.
     * @param target The value to search for.
     * @return The index of the target value in the array if found, -1 otherwise.
    */
    // Determine the order (ascending or descending) based on the first and last elements of the array
    int is_ascending = (arr[0] <= arr[size - 1]);

        if (is_ascending) {
            //Code to perform binary search on ascending sorted array
            return ascending_binary_search(arr, size, target);
        } else {
            //Code to perform binary search on descending sorted array
            return descending_binary_search(arr, size, target);
        }
}

int ascending_binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        // Calculating the value of middle.
        int mid = left + (right - left) / 2;

        // If the searched value at the index middle we have to return it.
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target value not found in the array
}

int descending_binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        // Calculating the value of middle.
        int mid = left + (right - left) / 2;

        // If the searched value at the index middle we have to return it.
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1; // Target value not found in the array
}
