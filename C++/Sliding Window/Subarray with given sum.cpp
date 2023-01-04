QUESTION:- Given an array arr[] of non-negative integers and an integer sum, find a subarray that adds to a given sum.
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
    //variable sliding window
    int i=0,j=0;
    int curr_sum=0;
    vector<int>ans;
 if(s==0) return {-1} ; 
 
    while(j<n){
        curr_sum+=arr[j] ; 
        
        if(curr_sum < s) j++;
        
        else if(curr_sum==s){
           return{i+1,j+1};
        }
        
        else if(curr_sum > s){
            //remove calculation for i
            while(curr_sum>s){
                curr_sum-=arr[i];
                i++;
            }
          
           if(curr_sum==s){
           return{i+1,j+1};
        }
        
            j++;
        }
    }
    return {-1} ; 
    
    }
};
