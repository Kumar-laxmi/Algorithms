#include <stdio.h>

void flip(int arr[], int i)
{
    int start = 0;
    while (start < i)
    {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMaxIndex(int arr[], int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(int arr[], int n)
{
    for (int currSize = n; currSize > 1; currSize--) // Reduces the size of the array by 1 in each iteration
    {
        int maxIndex = findMaxIndex(arr, currSize);
        if (maxIndex != currSize - 1)
        {
            flip(arr, maxIndex);
            flip(arr, currSize - 1);
        }
    }
}

int main()
{
    int arr[] = {6, 3, 9, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pancakeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
