//The time complexity of Cocktail sort is O(n^2) in the worst case and O(n) in the best case
//The space complexity of Cocktail sort is O(1)

#include <iostream>
#include <vector>

using namespace std;

// Function to perform Cocktail sort
void cocktailSort(vector<int> &arr) {
    // Set the flag to true
    bool flag = true;
    int start = 0;
    int end = arr.size() - 1;

    while (flag) {
        // Reset the flag to false
        flag = false;

        // Move the end pointer to the left
        for (int i = end; i > start; i--) {
            // Swap elements if they are out of order
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                flag = true;
            }
        }

        // Move the start pointer to the right
        for (int i = start; i < end; i++) {
            // Swap elements if they are out of order
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
    }
}

// The main function starts from here

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cocktailSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
