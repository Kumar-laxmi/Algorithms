#include <bits/stdc++.h>
#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Partition(int arr[],int p,int r){
	int x=arr[r]; //pivot element
	int i=p-1;
	int j;
	for(int j=p;j<=r-1;j++){
    	if(arr[j]<=x){
        	i++;
     	swap(arr[i],arr[j]);
  	   }
	}
  	swap(arr[i+1],arr[r]);
 
  	return i+1;
}
int Randomized_partition(int arr[],int p,int r){
	//rand()%(r-p+1) generate random number in range 0 to r-p
	// we want in range (p,r) so add p
	int i=p+rand_r(&seed)%(r-p+1);
	swap(arr[i],arr[r]);
    
	return(Partition(arr,p,r));
}
void Randomized_quicksort(int arr[],int p,int r){
	if(p<r){
    	int q=Randomized_partition(arr,p,r); //generate random index of pivot
    	Randomized_quicksort(arr,p,q-1);
    	Randomized_quicksort(arr,q+1,r);
	}
}
int main() {   
   int arr[]={78,9,10,-1,2,-45,91};
   int n = sizeof(arr)/sizeof(arr[0]);
    srand(time(0));  //generate random seed 
   Randomized_quicksort(arr,0,n-1) ; // arr,p,r;
   cout<<"Sorted array using Randomized quicksort is :"<<endl;
    for(int i=0;i<n;i++){
   	cout<<arr[i]<<" ";
   }
   cout<<endl;
}
