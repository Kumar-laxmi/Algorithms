#include <iostream>
#include <vector>
#include <random> // Required for random number generation

// Function to perform Fisher-Yates shuffle
void fisherYatesShuffle(std::vector<int>& arr) {
    int n = arr.size();
    std::random_device rd; // Obtain a random seed from hardware
    std::mt19937 rng(rd()); // Initialize a random number generator

    for (int i = n - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i); // Define a random distribution
        int j = dist(rng); // Generate a random index between 0 and i (inclusive)
        
        // Swap the elements at indices i and j
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Create an array of integers
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<int> numbers(size);

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }

    // Print the original array
    std::cout << "Original array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Shuffle the array using Fisher-Yates shuffle
    fisherYatesShuffle(numbers);

    // Print the shuffled array
    std::cout << "Shuffled array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
