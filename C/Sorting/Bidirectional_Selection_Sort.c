#include <stdio.h>

void bidirectionalSelectionSort(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        int minimum = arr[left];
        int maximum = arr[right];
        int minIndex = left;
        int maxIndex = right;

        for (int i = left+1; i <= right; i++) {
            if (arr[i] < minimum) {
                minimum = arr[i];
                minIndex = i;
            }
            if (arr[i] > maximum) {
                maximum = arr[i];
                maxIndex = i;
            }
        }

        if (minIndex == right) {
            int temp = arr[left];
            arr[left] = arr[minIndex];
            arr[minIndex] = temp;
        } else {
            int temp = arr[left];
            arr[left] = arr[minIndex];
            arr[minIndex] = temp;

            temp = arr[right];
            arr[right] = arr[maxIndex];
            arr[maxIndex] = temp;
        }

        left++;
        right--;
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bidirectionalSelectionSort(array, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
