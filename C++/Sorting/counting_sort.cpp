#include<bits/stdc++.h>

using namespace std;
// complexity time - O(n+ k), space - O(n + k)
// used as subroutine in radix sort 
//Not a comparison based algorithm 
void countSort(int a[],int n,int k){
int count[k];
for(int i = 0;i <k;i++)
count[i]=0;
for(int i = 0;i<n;i++)
count[a[i]]++;


for(int i = 1;i  <k;i++)
count[i] =count[i-1]+count[i];
int output[n];
for(int i = n - 1;i>=0;i--){
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
}
for(int i = 0;i < n ;i++)
a[i] = output[i];
}




int main()
{
int a[]={50,10,20,80,5,22,22},k = INT_MIN;
for(int i : a)
k = max(k,i);
int n = sizeof(a)/sizeof(int);
countSort(a,n,k+1);
for(int e:a)
cout<<e<<" ";
return 0;
}