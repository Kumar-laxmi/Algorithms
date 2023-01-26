#include <iostream>
using namespace std;
int binarysearch(int arr[], int n, int key)
{
    int s = 0; /*here we will take starting point as s and
     ending point as e */
    int e = n; /* here n is the size of the array*/
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key) /*if key is equal to the middle term*/
        {
            return mid;
        }
        else if (arr[mid] > key) /*if the key lies in first half */
        {
            e = mid - 1;
        }
        else /*if key lies in the second half of the array*/
        {
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n; /*taking an input array*/
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    cout << binarysearch(arr, n, key) << endl;
    return 0;
}