class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(2*n,0);
        for(int i=0;i<n;i++){
            a[i]+=nums[i];
            a[i+n]+=nums[i];
        }
        return a;
    }
};
