#include <bits/stdc++.h>
using namespace std;
  
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
  
int quickselect(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
  
        if (index - l == k - 1)
            return arr[index];
  
        if (index - l > k - 1) 
            return quickselect(arr, l, index - 1, k);
  
        return quickselect(arr, index + 1, r, k - index + l - 1);
    }
  
    return INT_MAX;
}
  
int main()
{
    int arr[] = { 7, 4, 6, 3, 9, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "k'th smallest element is "<< quickselect(arr, 0, n - 1, k)<<"\n";
    return 0;
}