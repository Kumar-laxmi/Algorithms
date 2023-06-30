#include <iostream>
using namespace std;
// Function to swap two elements
void swap(int& a,int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// Stooge Sort function
void stoogeSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    // If the first element is greater than the last element, swap them
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    // If there are more than 2 elements in the array
    if (high - low + 1 > 2) {
        int t = (high - low + 1) / 3;
        // Sort the first two-thirds of the array
        stoogeSort(arr, low, high - t);
        // Sort the last two-thirds of the array
        stoogeSort(arr, low + t, high);
        // Sort the first two-thirds of the array again
        stoogeSort(arr, low, high - t);
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Driver Code
int main() {
    int arr[] = { 10, 5, 8, 2, 1, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, size);
    stoogeSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}