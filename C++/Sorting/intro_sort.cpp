#include <bits/stdc++.h>
using namespace std;

void swapValue(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    return;
}

void InsertionSort(int arr[], int *begin, int *end)
{
    int left = begin - arr;
    int right = end - arr;

    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return;
}

// return partition point
int *Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (arr + i + 1);
}
// find middle element of values pointed by pointers a, b, c
int *MedianOfThree(int *a, int *b, int *c)
{
    if (*a < *b && *b < *c)
        return (b);

    if (*a < *c && *c <= *b)
        return (c);

    if (*b <= *a && *a < *c)
        return (a);

    if (*b < *c && *c <= *a)
        return (c);

    if (*c <= *a && *a < *b)
        return (a);

    if (*c <= *b && *b <= *a)
        return (b);
}

// A Utility function to perform intro sort
void IntrosortUtil(int arr[], int *begin,
                   int *end, int depthLimit)
{
    // Count the number of elements
    int size = end - begin;
    // if size is less, do INSERTION SORT
    if (size < 16)
    {
        InsertionSort(arr, begin, end);
        return;
    }
    // If depth is 0, do HEAP SORT
    if (depthLimit == 0)
    {
        make_heap(begin, end + 1);
        sort_heap(begin, end + 1);
        return;
    }

    // Else use a median-of-three concept to find a good pivot
    int *pivot = MedianOfThree(begin, begin + size / 2, end);

    // Swap the values pointed by the two pointers
    swapValue(pivot, end);

    // Perform Quick Sort
    int *partitionPoint = Partition(arr, begin - arr, end - arr);
    IntrosortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);

    return;
}

/* Intro Sort */
void Introsort(int arr[], int *begin, int *end)
{
    int depthLimit = 2 * log(end - begin);
    IntrosortUtil(arr, begin, end, depthLimit);
    return;
}

int main()
{
    cout << "Enter the length of array" << endl;
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Original array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    Introsort(a, a, a + n - 1);
    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete (a);
    return 0;
}