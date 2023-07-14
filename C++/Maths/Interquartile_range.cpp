//Problem statement :- Calculate Interquartile range from given number series 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;

    int arr[n];

    cout<<"Enter the array element"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);   // Here we sort our array

    int start = 0  , last = n-1;  // we assign 0 and n-1 as the index value for start and last index

    int Quartile1 , Quartile2 , Quartile3;

     int mid = (last - start)/2;   // Here we calculate median of our series

    cout<<"Median of series as Quartile2 : "<< arr[mid]<<endl;

    Quartile1 =arr[(mid-0)/2];  //Here we calculate first half Quartile

    cout<<"The Median of first half as Quartile1 : " <<Quartile1<<endl;

    Quartile3 = arr[mid+1+(last-mid)/2];   //Here we calculate second half Quartile

    cout<<"The Median of Second half as Quartile3 : "<<Quartile3<<endl;
   
    cout<<"The IQR value is "<<Quartile3 - Quartile1;
}

// Case 1: INPUt :- 1  3  5  2  4  6

//        OUTPUT:- Median of series as Quartile2 : 3
//                 The Median of first half as Quartile1 : 2
//                 The Median of second half as Quartile2 : 5
//                 The IQR value is : 3
