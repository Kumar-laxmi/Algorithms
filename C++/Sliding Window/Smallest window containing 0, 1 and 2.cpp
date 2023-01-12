Question:- Given a string S of size N consisting of the characters 0, 1 and 2.
The task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. 
If no such substring exists, then return -1.

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        //variable sized sliding window
        int i=0 , j=0 , ans=0;
        int min_size = INT_MAX;
        map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<3) j++;
        else if(mp.size()==3){   
             while(mp.size()==3){
                min_size=min(min_size,j-i+1);
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
             }
                j++;
            }
        }
        if(min_size==INT_MAX) return -1;
        else return min_size;
    }
};
