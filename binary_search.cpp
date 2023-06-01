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

//FUNCTION TO RETURN THE INDEX OF THE ELEMENT TO BE SEARCHED:
int returnIndex(vector<int>& v,int el)
{
    int n=v.size();
    int lt=0, rt=n-1;
    while(lt<=rt){
        // in order to prevent overflow of `int`, it has been written lt + (rt-lt)/2 instead of (lt+rt)/2;
        int mid = lt + (rt-lt)/2;
        // element is equal to mid, return the index
        if(v[mid]==el){
            return mid;
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
    return -1;
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF ELEMENTS IN THE ARRAY/VECTOR:"<<endl;
    cin >> n;
    vector<int> v(n);
    //Enter sorted array - binary search always works on sorted array 
    cout<<"ENTER THE ARRAY/VECTOR:"<<endl;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout<<"ENTER THE ELEMENT TO BE SEARCHED IN THE ARRAY/VECTOR:"<<endl;
    int el;
    cin >> el;
    int ansIndex=returnIndex(v,el);
    if(ansIndex!=-1)
    {
        cout<<"THE INDEX OF THE ELEMENT "<<el<<" IS "<<ansIndex<<endl;
    }
    else
    {
        cout<<"ELEMENT "<<el<<" NOT FOUND"<<endl;
    }
    return 0;
}
