//C++ code to search for an element in a 2d matrix using binary search

/*
    Binary Search is usally done on a 1D array but there can be multiple approaches to conduct a binary search in a 2D array. For eg,
    1. Convert the 2D array into a 1D array and conduct the search. 
        Time Complexity: O(Logm+Logn)
        Space Complexity: O(m+n)

    2. Another efficient approach is to virtualize the 2D array into a 1D array by using % and / operators to determine the indexes, and then 
        apply Binary Search in that virtual 1D array. 
        The following code follows this approach.
        Time Complexity: O(Logmn)
        Space Complexity : O(1).
*/
#include <bits/stdc++.h>
using namespace std;

bool bSearch(vector<vector<int>> arr,int target){
    int r=arr.size();
    int c=arr[0].size();
    //Initializing start and end index variables
    int s=0;//starting index
    int e=r*c -1;//Storing the last index of the virtual 1D array.
    //Preventing integer overflow
    int mid=s+(e-s)/2;
    //Loop for binary search
    while(s<=e){
        int element= arr[mid/c][mid%c];//[mid/c][mid%c] will give the middle index of the virtual 1D array 

        if(target==element) return true;//If found return true

        else if(target > element) s=mid+1;//Target is in the lower half of the matrix so starting index updates.

        else e=mid-1; // Target is in the upper half of the matrix so ending index updates.

        mid=s+(e-s)/2;// Updating the middle value to the updated starting and ending indexes.
    }
    return false;
}

int main(){
    vector<vector<int>> arr;//Initializing a 2D vector 
    int r,c;
    cout<<"Enter the dimensions of the array :"<<endl;
    cin>>r>>c;
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<r;i++){
        vector<int> rw;
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            rw.push_back(x);
        }
        arr.push_back(rw);
    }
    cout<<"Enter the element you want to search :"<<endl;
    int target ;
    cin>>target;

    if(bSearch(arr,target)) cout<<"Element found !!"<<endl;//If the function bSearch returns true then this executes.
    else cout<<"Element not found !!"<<endl;
}