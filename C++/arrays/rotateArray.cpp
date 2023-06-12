#include <iostream>
using namespace std;

// Function to reverse an array
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate an array by 'rotateBy' positions
void rotateArray(int arr[], int size, int rotateBy)
{
    // Handle negative rotateBy values
    rotateBy = rotateBy % size;
    if (rotateBy < 0)
    {
        rotateBy = rotateBy + size;
    }

    // Reverse the first part of the array
    reverseArray(arr, 0, rotateBy - 1);

    // Reverse the second part of the array
    reverseArray(arr, rotateBy, size - 1);

    // Reverse the entire array
    reverseArray(arr, 0, size - 1);
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int rotateBy;
    cout << "Enter the number of positions to rotate: ";
    cin >> rotateBy;

    cout << "Original array: ";
    printArray(arr, size);

    rotateArray(arr, size, rotateBy);

    cout << "Rotated array: ";
    printArray(arr, size);

    delete[] arr;

    return 0;
}
