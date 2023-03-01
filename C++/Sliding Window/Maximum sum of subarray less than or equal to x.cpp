Question:- Given an array arr[] of length N and an integer K, the task is the find the maximum sum subarray with a sum less than K.
Note: If K is less than the minimum element, then return INT_MIN.

class Solution{
public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int i=0,j=0,max_sum=0,msum=INT_MIN;
	    
	     while(j<n){
	     max_sum+=arr[j];
	     
	    while(max_sum > sum){
	        //remove cal for i
	        max_sum-=arr[i];
	        i++;
	    }
	         msum=max(max_sum,msum);
	         j++;
	     }
	 return msum;
}
};
