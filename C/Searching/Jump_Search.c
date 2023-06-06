// C++ implementation of Jump Search Algorithm
#include <stdio.h>
#include <math.h>

int jumpSearch(int array[], int size, int key)
{
    int start = 0;
    int end = sqrt(size); // the square root of array length

    while (array[end] <= key && end < size)
    {
        start = end; // if it is not the correct block then shift block
        end += sqrt(size);
        if (end > size - 1)
        {
            end = size; // if right exceeds then bound the range
        }
    }

    // perform linear search in selected block
    for (int i = start; i < end; i++)
    {
        if (array[i] == key)
        {
            return i; // the correct position of the key
        }
    }
    return -1;
}

int main()
{
    // taking input of number of elements and key
    int n, key;
    scanf("%d %d", &n, &key);
    int arr[n]; // create an array of size n
    // taking input of array elements
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // function call
    int ind = jumpSearch(arr, n, key);

    if (ind >= 0) // key is present in the array
    {
        printf("Key found at location: %d\n", ind);
    }
    else // key is not present in the array
    {
        printf("Key not found in the array\n");
    }
    return 0;
}