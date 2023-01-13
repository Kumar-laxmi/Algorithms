#include<iostream>
using namespace std;

void quickSort(int arr[],int lb,int ub)
{
    if(lb>=ub)
    {
        return ;
    }
    
    int i=lb,j=ub;
    int x=rand()%(ub-lb+1)+lb;
    swap(arr[x],arr[lb]);
    
    int pivot=arr[lb];
    
    while(i<j)
    {
        while( i<j && arr[i]<=pivot)
        i++;
        
        while(arr[j]>pivot)
        j--;
        
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    arr[lb]=arr[j];
    arr[j]=pivot;
    
    quickSort(arr,lb,j-1);
    quickSort(arr,j+1,ub);
}
int main()
{
    int n;
    cout<<"enter the size of array \n";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Sorted Array is as follows \n";
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}