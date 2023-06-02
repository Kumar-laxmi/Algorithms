#include <iostream>

// Interpolation Search algorithm
int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = (n - 1);
 
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        // Estimate the position of x in the array
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
 
        // If x is found at position pos
        if (arr[pos] == x)
            return pos;
 
        // If x is greater, ignore the left half
        if (arr[pos] < x)
            low = pos + 1;
        // If x is smaller, ignore the right half
        else
            high = pos - 1;
    }
 
    // Element not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 14;
    
    // Perform interpolation search
    int result = interpolationSearch(arr, n, x);
    
    // Check if the element was found or not
    if (result == -1)
        std::cout << "Element not found." << std::endl;
    else
        std::cout << "Element found at index " << result << "." << std::endl;
 
    return 0;
}
