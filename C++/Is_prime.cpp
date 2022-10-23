#include <bits/stdc++.h>
using namespace std;

int main(){
    int number;
    cin>>number;

    //CHECK PRIME

    // 1) O(N) complexity
    /*
    What we will do here is we will iterate from 2 till number -1
    and check if the number is divisible by any of this. If it is then it is not
    a prime number
    */

    for(int i=2;i<number;i++){
        if((number%i)==0){
            cout<<"number is not prime"<<"\n";
            return;
        }
    }

    //But this is a very slow approach

    // 2) O(sqrt(N)) complexity

    /*
    Here we will use the property that for every facto of a number 
    less than its square root we get a factor which is greater than its squareroot.
    So it is sufficient to check till its squareroot.
    */

    for(int i=2;i*i<=N;i++){
        if((number%i)==0){
            cout<<"number is not prime"<<"\n";
            return;
        }
    }
    //This is a good algorithm and you can check the number if it is prime or not below 1 sec.
}