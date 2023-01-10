Question:-Given an array and an integer K, find the maximum for each and every contiguous subarray of size K.

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        // your code here
        vector<int>ans;
        int i=0;
        int j=0;
        list<int> l;
        while(j<n)
        {
    while(l.size()>0 && l.back()<nums[j]){
         l.pop_back();
    }
         l.push_back(nums[j]);               
           

          if(j-i+1<k)    ++j;
        else if(j-i+1==k){
        ans.push_back(l.front());
                if(nums[i]==l.front()){
                    l.pop_front();
                }
                ++i;
                ++j;
            }
        }
        return ans;
    }
};
