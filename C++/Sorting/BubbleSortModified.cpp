#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
        
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }

    }
    cout<<"Sorted Array using Bubble Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}