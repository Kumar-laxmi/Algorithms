// Path: C++\Searching\quick_select.cpp
// C++ program to kth smallest element using quickSelect Algorithm.
// Time-Complexity: O(N^2), where N is the size of array.

#include <iostream>
#include <vector>
#include <cstdlib>

// Function to swap two elements in the vector
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to rearrange elements around the pivot
int partition(std::vector<int> &vec, int left, int right, int pivotIndex) {
    int pivotValue = vec[pivotIndex];
    swap(vec[pivotIndex], vec[right]); // Move pivot to the end
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (vec[i] < pivotValue) {
            swap(vec[i], vec[storeIndex]);
            storeIndex++;
        }
    }
    swap(vec[storeIndex], vec[right]); // Move pivot to its final place
    return storeIndex;
}

// Quickselect function
int quickSelect(std::vector<int> &vec, int left, int right, int k) {
    if (left == right)
        return vec[left];

    int pivotIndex = left + (rand() % (right - left + 1));
    pivotIndex = partition(vec, left, right, pivotIndex);

    if (k == pivotIndex)
        return vec[k];
    else if (k < pivotIndex)
        return quickSelect(vec, left, pivotIndex - 1, k);
    else
        return quickSelect(vec, pivotIndex + 1, right, k);
}

int main() {
    std::vector<int> vec = {3, 8, 2, 5, 1, 4, 7, 6};
    int k = 4; // Find the 4th smallest element

    int result = quickSelect(vec, 0, vec.size() - 1, k - 1);
    std::cout << "The " << k << "-th smallest element is: " << result << std::endl;

    return 0;
}
