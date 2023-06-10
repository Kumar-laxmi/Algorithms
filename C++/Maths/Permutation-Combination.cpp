#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int fact(int n){
    if(n<=1)
    return 1;
    else
    return n*fact(n-1);
}

int main()
{
int n,r;
cout<<"Enter n and r"<<endl;
cin>>n>>r;
int nr=n-r;
if(n>=r){
double Per=fact(n)/fact(nr);
double Com=Per/fact(r);
cout<<"Permutation of nPr is "<<Per<<endl;
cout<<"Combination of nCr is "<<Com<<endl;
}
else
cout<<"Invalid Input";
return 0;
}