#include <stdio.h>

void pigeonholeSort(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max - min + 1;
    int* pigeonholes = (int*)malloc(range * sizeof(int));
    memset(pigeonholes, 0, range * sizeof(int));

    for (int i = 0; i < n; i++) {
        pigeonholes[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (pigeonholes[i] > 0) {
            arr[index++] = i + min;
            pigeonholes[i]--;
        }
    }

    free(pigeonholes);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pigeonholeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
