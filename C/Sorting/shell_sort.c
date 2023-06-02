#include <stdio.h>

void shellSort(int array[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order.
        // Keep adding one more element until the entire array is gap sorted.
        for (int i = gap; i < n; i += 1) {
            // Add array[i] to the elements that have been gap sorted.
            // Save array[i] in temp and make a hole at position i.
            int temp = array[i];
            int j;
  
            // Shift earlier gap-sorted elements up until the correct location for array[i] is found.
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];
              
            // Put temp (the original array[i]) in its correct location.
            array[j] = temp;
        }
    }
}

void displayArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
}

int main() {
    int array[] = {9, 8, 1, 7, 4, 3};
    int n = sizeof(array) / sizeof(array[0]);
  
    printf("Array before sorting:\n");
    displayArray(array, n);
  
    shellSort(array, n);
  
    printf("\nArray after sorting:\n");
    displayArray(array, n);
  
    return 0;
}

