QUESTION:- Given string str of the lowercase alphabet and an integer K.
The task is to count all substrings of length K which have exactly K distinct characters.

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        int i=0,j=0,cnt=0;
        map<char,int>mp;
        
        while(j<S.size()){
            mp[S[j]]++;
            if(j-i+1<K) {
                j++;
            }
            
            else if(j-i+1==K){
                
                if(mp.size()==K-1) cnt++;
                
                mp[S[i]]--;
                if(mp[S[i]]==0) mp.erase(S[i]);
                i++;
                j++;
            }
        }
        return cnt;
    }
};
