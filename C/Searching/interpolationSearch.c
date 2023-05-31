#include <stdio.h>

int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the sorted elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int index = interpolationSearch(arr, size, target);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}