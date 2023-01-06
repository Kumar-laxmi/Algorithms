#include<bits/stdc++.h>
using namespace std ;
long long int mod = 1e18+7;
//Large Exponentiation 
//a^b --> a,b,mod < 10^18 
//T.C ->O(log^2(N)) --> O(log(N)*log(N))

int binExp(int a , int b){
    int ans=1;
  while(b>0){
    //see if set-bit 
    if(b&1){
        ans=binMultiply(ans,a) ;
    }
    a = binMultiply(a,a); 
    b>>=1 ; //right-shift the bit
  }
  return ans;
}
 
// add krte jayenge a ko and mod lete jayenge step by step -> O(n) but for O(logn) use binary technique -> 
// a+a+a+a+..... b times
int binMultiply(long long int a , long long int b){
      int ans=0; // as ans get added 
  while(b>0){
    //see if set-bit than  add in ans
    if(b&1){
        ans=(ans+a)%mod;
    }
    a = (a+a)%mod;  //go to next power
    b>>=1 ; //right-shift the bit
  }
  return ans;
}


int main(){
int a = 2 , b=13 ; 
cout<<binExp(a,b)<<"\n"; //2^13
cout<<binMultiply(a,b)<<"\n"; //2*(13) = 26 

    return 0;
}
