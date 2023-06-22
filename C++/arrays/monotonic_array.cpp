#include<iostream>
#include<vector>
using namespace std;

    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<e){
            if(nums[s]<=nums[s+1]&&nums[s]<=nums[e]&&e==n-1){
                s++;
            }
            else if(nums[e]<=nums[e-1]&&nums[e]<=nums[s]&&s==0){
                e--;
            }
            else{
                break;
            }        
        }
        if(s==n-1||e==0){
            return true;
        }
        return false;
    }

int main(){
    int n;
    cout<<"enter no of elements in array";
    cin>>n;
    cout<<"enter the elements of array";
    vector<int> nums;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
    cout<<endl;

    if(isMonotonic(nums)){
        cout<<"the array is monotonic";
    }
    else{
        cout<<"the array is not monotonic";
    }
}
// MONOTONIC ARRAY IN C++
// This Program Tells if an array is monotonic or not
