#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void combSort(int arr[], int n) {
    int gap = n;
    float shrinkFactor = 1.3;
    bool sorted = false;
    
    while (!sorted) {
        gap = gap / shrinkFactor;
        if (gap > 1) {
            sorted = false;
        } else {
            gap = 1;
            sorted = true;
        }
        
        int i = 0;
        while (i + gap < n) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                sorted = false;
            }
            i++;
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    combSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
