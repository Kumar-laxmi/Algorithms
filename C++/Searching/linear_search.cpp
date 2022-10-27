#include <bits/stdc++.h>

using namespace std;

/*
<----------------------------------PROBLEM------------------------------------>
Given an array arr[] of n elements, write a function to search a given element el in arr[].

Variables used:
n = total number of elements in array
v = vector (dynamic array initialized with the input size)
el = element to be searched in the array. 
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int el;
    cin >> el;

    // Flag variable to keep a check if the element is found till then.
    bool flag=false;
    for(int i=0; i<n; i++){
        if(v[i]==el){
            flag=true;
        }
    }
    if(flag){
        cout << "Element found:)";
    }
    else{
        cout << "Element not found:(\n";
    }
    return 0;
}
