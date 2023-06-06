#include <bits/stdc++.h>

using namespace std;

/*
<----------------------------------PROBLEM------------------------------------>
Given a sorted array arr[] of n elements, write a function to search a given 
element x in arr[] and return the index of x in the array.

Variables used:
n = total number of elements in array.
v = vector (dynamic array initialized with the input size).
el = element to be searched in the array.
lt = left-most index of the search space.
rt = right-most index of the search space. 
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    //Enter sorted array - binary search always works on sorted array 
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int el;
    cin >> el;

    int lt=0, rt=n-1;
    while(lt<=rt){
        // in order to prevent overflow of `int`, it has been written lt + (rt-lt)/2 instead of (lt+rt)/2;
        int mid = lt + (rt-lt)/2;
        // element is equal to mid, return the index
        if(v[mid]==el){
            cout << "Element found:)\n";
            return 0;
        }
        // element is larger than mid, then shift search space to right.
        else if(v[mid]<el){
            lt=mid+1;
        }
        // element is smaller than mid, then shift search space to left.
        else{
            rt=mid-1;
        }
    }
    cout << "Element not found:(\n";
    return 0;
}
