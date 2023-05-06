/*Name :  Suriyaprakash.C
Github username : suriyarichard
Repositary name : Algorithms
*/

// Problem Statement : 
// Write a program that finds the sum of all elements in an array using concurrent threads. The array is divided into equal parts, and each thread calculates the sum of its assigned portion.

#include <iostream>
#include <thread>

// Function to be executed concurrently by multiple threads
void calculateSum(int* arr, int start, int end, int& partialSum) {
    partialSum = 0;
    for (int i = start; i <= end; i++) {
        partialSum += arr[i];
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const int NUM_THREADS = 4;
    std::thread threads[NUM_THREADS];
    int partialSums[NUM_THREADS] = {0};

    // Divide the array into equal parts and assign each part to a thread
    int partSize = SIZE / NUM_THREADS;
    int start = 0;
    int end = partSize - 1;
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i] = std::thread(calculateSum, arr, start, end, std::ref(partialSums[i]));
        start = end + 1;
        end += partSize;
    }

    // Wait for all threads to finish their execution
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }

    // Calculate the total sum by combining the partial sums
    int totalSum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        totalSum += partialSums[i];
    }

    std::cout << "The sum of all elements in the array is: " << totalSum << std::endl;

    return 0;
}
