#include <bits/stdc++.h>
using namespace std;

// In order agnostic binary search, we check whether elements are in increasing
// or descreaing order and based on that we perform binary search. The best way
// to check whether array is in increasing or decreasing order is by checking
// 1st and last elements.

// Time complexity is O(logn)
// Space complexity is O(n)

int orderAgnosticBinarySearch(vector<int> &A,int size,int element) {
    int l=0,mid,r=size-1;
    
    if (A[0] <= A[size-1]) {
        // Array is in increasing order
        while (l<=r) {
            mid = (l+r)/2;
            if (A[mid] > element) r = mid-1;
            else if (A[mid] < element) l = mid+1;
            else return mid; // returning index of element if found
        }
        return -1;
    }

    // Else Array is in decreasing order
    while (l<=r) {
        mid = (l+r)/2;
        if (A[mid] > element) l = mid+1;
        else if (A[mid] < element) r = mid-1;
        else return mid; // returning index of element if found
    }
    return -1; // returning -1 if element not found
}

int main() {
    int n,x;
    cout<<"Enter no of elements: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Enter elements in either descreasing or increasing order: ";
    for (int i=0;i<n;i++) cin>>A[i];
    cout<<"Enter element to search: ";
    cin>>x;
    cout<<"Element is at "<<orderAgnosticBinarySearch(A,n,x)<<"\n";
    return 0;
}