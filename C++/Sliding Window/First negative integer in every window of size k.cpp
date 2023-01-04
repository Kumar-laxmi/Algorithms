Question:- Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k.
 If a window does not contain a negative integer, then print 0 for that window.
  
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
            
            vector<long long int>ans,res;
            int i=0,j=0;
            while(j<N){
                 if(A[j]<0) ans.push_back(A[j]) ;
                 
                 if(j-i+1 < k) {j++;}
                 else if(j-i+1==k){
                     if(ans.size()==0) res.push_back(0);
                     else {res.push_back(ans[0]);
                 if(A[i]==ans[0]){
                     ans.erase(ans.begin());
                 }}
                i++; j++;}
            }
            return res;
 }
