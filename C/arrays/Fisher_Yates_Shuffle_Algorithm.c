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
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Shuffle the array using Fisher-Yates shuffle
    fisherYatesShuffle(numbers, n);

    // Print the shuffled array
    printf("Shuffled array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
