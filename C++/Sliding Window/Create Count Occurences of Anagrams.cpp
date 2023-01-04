Question:- Given a word and a text, return the count of the occurrences of anagrams of the word in the text (For eg: anagrams of word for are for, ofr, rof etc.)
class Solution{
private:
    bool check(unordered_map<char,int> &mtar,unordered_map<char,int> &m){
        for(auto p : mtar){
            char tarch=p.first;
            int tarfreq=p.second;
            if(m[tarch]!=tarfreq)
            return false;
        }
        return true;
    }
public:
	int search(string pat, string txt) {
	    // code here
	    int k=pat.size();
	    int n=txt.length();
	    int start=0,end;
	    int ans=0;
	    
	    unordered_map<char,int> mtar;
	    for(int i=0;i<k;i++){
	        mtar[pat[i]]++;
	    }
	    unordered_map<char,int> m;
	    for(int i=0;i<k;i++){
	        end=i;
	        m[txt[i]]++;
	    }
	    if(check(mtar,m))
	    ans++;
	
	    
	        for(int i=end+1;i<n;i++){
	        end=i;
	        char newch=txt[i];
	        m[newch]++;
	        char oldch=txt[start++];
	        m[oldch]--;
	        if(check(mtar,m))
	        ans++;
	        
	    }
	    
	    
	    return ans;
	    
	}

};
