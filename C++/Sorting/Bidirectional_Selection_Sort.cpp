#include <iostream>
#include <vector>
using namespace std;

void bidirectionalSelectionSort(vector<int>& arr, int size) {
    int left = 0, right = size;

    while (left < right) {
        int minimum = arr[left];
        int maximum = arr[right];
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; i++) {
            if (arr[i] < minimum) {
                minimum = arr[i];
                minIndex = i;
            }
            if (arr[i] > maximum) {
                maximum = arr[i];
                maxIndex = i;
            }
        }

        if (minIndex == right) {
            swap(arr[left], arr[minIndex]);
        } else {
            swap(arr[left], arr[minIndex]);
            swap(arr[right], arr[maxIndex]);
        }

        left++;
        right--;
    }
}

int main() {
    vector<int> array;
    int n;
    cout<<"Enter number of elements in array : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        int element; cin>>element; array.emplace_back(element);
    }

    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    bidirectionalSelectionSort(array,n);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
