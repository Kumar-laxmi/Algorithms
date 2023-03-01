#include<bits/stdc++.h>

using namespace std;
int hPartition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
       
        if (i >= j)
            return j;
            
             swap(a[i], a[j]);
    }
}

void quickSort(int a[],int l,int h){
    if(l<h){
        int p = hPartition(a,l,h);
        quickSort(a,l,p);
        quickSort(a,p+1,h);
    }
}

int main()
{
int a[] = {5,2,1,100,22,33,-1};
int n = sizeof(a)/sizeof(int);
quickSort(a,0,n-1);
for(auto i : a)
cout<<i<<" ";
return 0;
}