#include <stdio.h>
#include <stdlib.h>

void display(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void beadSort(int *arr, size_t len) {
    int i, j, max, sum;
    unsigned char *beads;

    for (i = 1, max = arr[0]; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    beads = calloc(1, max * len);

    for (i = 0; i < len; i++) {
        for (j = 0; j < arr[i]; j++) {
            beads[i * max + j] = 1;
        }
    }

    for (j = 0; j < max; j++) {
        for (sum = i = 0; i < len; i++) {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }
        for (i = len - sum; i < len; i++) {
            beads[i * max + j] = 1;
        }
    }

    for (i = 0; i < len; i++) {
        for (j = 0; j < max && beads[i * max + j]; j++) {
        }
        arr[i] = j;
    }
    free(beads);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);

    beadSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    free(arr);
    return 0;
}
