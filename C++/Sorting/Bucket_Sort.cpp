// C++ program to sort an array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    vector<float> bucket[n];

    // Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int ind = n * arr[i]; // Index in bucket
        bucket[ind].push_back(arr[i]);

        int j = bucket[ind].size() - 2; // index of the second last element of current bucket
        float key = bucket[ind][j + 1]; // element that is currently added

        // Move elements of bucket[ind][0..j], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

int main()
{
    int n;
    cin >> n; // taking input of number of elements in the array
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // taking input of float numbers in the array
    }

    // function call
    bucketSort(arr, n);

    // printing array
    cout << "Sorted array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
