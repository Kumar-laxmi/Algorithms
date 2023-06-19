#include <stdio.h>

// Function to reverse an array from index 0 to i
void reverseArray(int arr[], int i) {
    int start = 0;
    while (start < i) {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

// Function to find the index of the maximum element in the given array
int findMaxIndex(int arr[], int n) {
    int maxIndex = 0;
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to perform Pancake Sort
void pancakeSort(int arr[], int n) {
    int i;
    for (i = n; i > 1; i--) {
        // Find the index of the maximum element in the unsorted part of the array
        int maxIndex = findMaxIndex(arr, i);

        // If the maximum element is not at the beginning, flip the array to bring it to the beginning
        if (maxIndex != i - 1) {
            // Flip the maximum element to the beginning
            reverseArray(arr, maxIndex);
            
            // Flip the whole array to move the maximum element to the end
            reverseArray(arr, i - 1);
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pancakeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
