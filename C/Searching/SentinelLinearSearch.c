#include <stdio.h>

// Function to perform sentinel linear search
void sentinelSearch(int arr[], int n, int key) {
    // Last element of the array
    int last = arr[n - 1];
    // Element to be searched and placed at the last index
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key)
        i++;
    // Putting the last element back
    arr[n - 1] = last;
    if ((i < n - 1) || (arr[n - 1] == key)) {
        printf("%d present at the index %d\n", key, i);
    } else {
        printf("Element not found\n");
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
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    sentinelSearch(arr, n, key);
    return 0;
}
