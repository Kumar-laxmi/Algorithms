#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the sorted elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int index = interpolationSearch(arr, size, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
