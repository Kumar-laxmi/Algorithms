#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (arr[j] <= x) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

int Randomized_partition(int arr[], int p, int r) {
    int i = p + rand() % (r - p + 1);
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return Partition(arr, p, r);
}

void Randomized_quicksort(int arr[], int p, int r) {
    if (p < r) {
        int q = Randomized_partition(arr, p, r);
        Randomized_quicksort(arr, p, q - 1);
        Randomized_quicksort(arr, q + 1, r);
    }
}

int main() {
    int arr[] = {78, 9, 10, -1, 2, -45, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    srand(time(0));
    Randomized_quicksort(arr, 0, n - 1);
    printf("Sorted array using Randomized quicksort is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
