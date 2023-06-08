#include <iostream>
#include <vector>
#include <random> // Required for random number generation
using namespace std;
// Function to perform Fisher-Yates shuffle
void fisherYatesShuffle(vector<int>& arr) {
    int n = arr.size();
    random_device rd; // Obtain a random seed from hardware
    mt19937 rng(rd()); // Initialize a random number generator

    for (int i = n - 1; i > 0; --i) {
        uniform_int_distribution<int> dist(0, i); // Define a random distribution
        int j = dist(rng); // Generate a random index between 0 and i (inclusive)
        
        // Swap the elements at indices i and j
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Create an array of integers
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Print the original array
    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << std::endl;

    // Shuffle the array using Fisher-Yates shuffle
    fisherYatesShuffle(numbers);

    // Print the shuffled array
    cout << "Shuffled array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
