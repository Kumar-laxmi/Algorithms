//C++ code to search for an element in a 2d matrix using binary search

#include <bits/stdc++.h>
using namespace std;

bool bSearch(vector<vector<int>> arr,int target){
    int r=arr.size();
    int c=arr[0].size();
    //Initializing start and end index variables
    int s=0;
    int e=r*c -1;
    //Preventing integer overflow
    int mid=s+(e-s)/2;
    //Loop for binary search
    while(s<=e){
        int element= arr[mid/c][mid%c];

        if(target==element) return true;

        else if(target > element) s=mid+1;

        else e=mid-1;

        mid=s+(e-s)/2;
    }
    return false;
}

int main(){
    vector<vector<int>> arr;
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

    if(bSearch(arr,target)) cout<<"Element found !!"<<endl;
    else cout<<"Element not found !!"<<endl;
}