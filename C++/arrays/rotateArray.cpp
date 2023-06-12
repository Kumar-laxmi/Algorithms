#include <iostream>
using namespace std;

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

void rotateArray(int arr[], int size, int rotateBy)
{
    rotateBy = rotateBy % size;
    if (rotateBy < 0)
    {
        rotateBy = rotateBy + size;
    }

    reverseArray(arr, 0, rotateBy - 1);

    reverseArray(arr, rotateBy, size - 1);

    reverseArray(arr, 0, size - 1);
}

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
