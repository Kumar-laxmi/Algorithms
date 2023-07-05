#include <iostream>
#include <vector>
using namespace std;

void bidirectionalSelectionSort(vector<int>& arr, int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        int minimum = arr[left];
        int maximum = arr[left];
        int minIndex = left;
        int maxIndex = left;

        for (int i = left + 1; i <= right; i++) {
            if (arr[i] < minimum) {
                minimum = arr[i];
                minIndex = i;
            }
            if (arr[i] > maximum) {
                maximum = arr[i];
                maxIndex = i;
            }
        }

        if (minIndex != left) {
            swap(arr[left], arr[minIndex]);
            if (maxIndex == left)
                maxIndex = minIndex;
        }

        if (maxIndex != right)
            swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    vector<int> array;
    cout<<"Enter the number of elements : ";
    int n;
    cin >> n;
    cout<<"Enter the elements : ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        array.emplace_back(element);
    }

    bidirectionalSelectionSort(array, n);

    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
