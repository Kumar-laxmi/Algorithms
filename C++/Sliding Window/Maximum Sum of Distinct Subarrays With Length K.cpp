Question:- Given an array arr[] consisting of N integers and an integer K.
The task is to find a subarray of size K with maximum sum and count of distinct elements same as that of the original array.

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //fixed sized sliding window
        int i=0,j=0;
        int n = nums.size();
       long long int max_sum=0;
       long long int sum=0;
        map<int,int>freq;
        
        while(j<n){
            
            //reaching window size 
            sum+=nums[j]; freq[nums[j]]++;
            if(j-i+1<k){   
                j++;
            }
            
            
            //window size reach , find max_sum if freq size is equal to k 
          else  if(j-i+1 == k){
                //see max_sum only if all distinct element in window
                if(freq.size()==k){
                max_sum=max(max_sum,sum);
                  
                }
                
                //now, move to next window by removing the calculation for i
                freq[nums[i]]--; 
                sum-=nums[i]; //remove calculation of i from sum as well
                if(freq[nums[i]]==0){
                     //erase it from freq
                    freq.erase(nums[i]);
                }
                //going to next window
                i++;
                j++;
            }
            
            
        }
        
        return max_sum;
    }
};
