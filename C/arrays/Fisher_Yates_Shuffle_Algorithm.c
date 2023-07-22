#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Fisher-Yates shuffle
void fisherYatesShuffle(int arr[], int n) {
    srand(time(NULL)); // Seed the random number generator

    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); // Generate a random index between 0 and i (inclusive)
        
        // Swap the elements at indices i and j
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Create an array of integers
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* numbers = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &numbers[i]);
    }

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Shuffle the array using Fisher-Yates shuffle
    fisherYatesShuffle(numbers, size);

    // Print the shuffled array
    printf("Shuffled array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
