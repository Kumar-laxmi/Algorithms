#include <bits/stdc++.h>

using namespace std;

// Function that performs the sorting operation
void merge(vector<int>& v, int l, int mid, int r){
    int i = l, j = mid+1;
    vector<int> b;
    // Compares the elements of the two arrays and sorts them
    while (i<=mid && j<=r)
    {
        if (v[i]>v[j]){
            b.push_back(v[j]);
            j++;
        }
        else{
            b.push_back(v[i]);
            i++;
        }
    }
    // If the 1st array is exhausted, then copies the remaining elements of the 2nd array to the 1st array
    while (j<=r){
        b.push_back(v[j]);
        j++;
    }
    // If the 2nd array is exhausted, then copies the remaining elements of the 1st array to the 2nd array
    while (i<=mid){
        b.push_back(v[i]);
        i++;
    }
    // Copies all the elements of the array 'b' to array 'arr'
    for (int i = l; i <= r; i++){
        v[i] = b[i-l];
    }
    return ;
}

// Function that divides the array into half at each step and sorts them
void mergeSort(vector<int>& v, int l, int r){
    if (l<r)
    {
        int mid = l + (r-l)/2;
        // Sorts the left array
        mergeSort(v, l, mid);
        // Sorts the right array
        mergeSort(v, mid+1, r);
        // Merges the left and the right array
        merge(v, l, mid, r);
    }
}

int main()
{
    // Total number of elements in vector
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    mergeSort(v, 0, n-1);
    cout << "After sorting:\n";
    for(auto i: v){
        cout << i << " ";
    }
    return 0;
}
