Question:- Given an array of size N and an integer K, return the count of distinct numbers in all windows of size K.
  
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //fixed sliding window
        int i=0,j=0;
        vector<int>ans;
        unordered_map<int,int>mp;
        while(j<n){
            mp[A[j]]++;
            
            //reach window size
            if(j-i+1 <k) {j++;}
          
            else if(j-i+1 == k){
                ans.push_back(mp.size());
            //remove calculation for i
                mp[A[i]]--;
                if(mp[A[i]]==0) mp.erase(A[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
