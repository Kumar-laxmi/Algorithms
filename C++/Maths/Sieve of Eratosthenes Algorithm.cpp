/*
Time complexity of Sieve of Eratosthenes is n*log(log(n))
It is one of the most efficient ways to find all prime numbers.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

//declared globally
int N = 1e5; 
//sieve for prime numbers.
vector<int> sieve;
vector<bool>isprime(N,1);

void sieveOfEratosthenes() {
    for(int p=2; p*p<=N; p++){
         if(isprime[p]==1) {
             for(int i=p*p; i<=N; i+=p){
                 isprime[i]=0;
             } 
         }
    }
    for(int p=2; p<=N; p++) if(isprime[p]) {
        sieve.push_back(p);
    }
}
signed main(){
int n  ;
cin>>n;
cout<<"First "<<n<<" prime numbers are\n";
//print first n prime numbers
sieveOfEratosthenes(); // calling sieve to display prime numbers
for(int i=0;i<n;i++){
    cout<<sieve[i]<<" ";
}
return 0;}
