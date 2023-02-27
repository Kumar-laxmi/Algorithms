Question:- Given a string you need to print longest possible substring that has exactly M unique characters. 
If there is more than one substring of longest possible length, then print any one of them.

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    //variable sized sliding window
    int i=0,j=0,max_size=-1;
    unordered_map<char,int>mp;
    while(j<s.size()){
        //insert in map
        mp[s[j]]++;
        
        if(mp.size()<k) j++;
        
        else if(mp.size()==k){
            //see for max_size
            max_size =  max(max_size,j-i+1) ;
            j++;
        }
        else if(mp.size()>k){
            //remove calculation for i
            while(mp.size()>k){
                mp[s[i]]--;
                //if frequency is 0 --> erase it
                if(mp[s[i]]==0) mp.erase(s[i]);
                 i++;
            }
            j++;
        }
    }
    return max_size;
    }
};
