#include <bits/stdc++.h>
using namespace std;
void bubble(vector<int> &arr, int length)
{
    if(length == 1) return ;
    int didswap = 0; 
    for(int i = 0 ; i < length-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i],arr[i+1]);
            didswap = 1;
        }
    }
    if(didswap == 0) return;

    bubble(arr,--length);
}

int main()
{
    vector<int> arr = {100, 23, 47, 99, 9, 25};
    bubble(arr,arr.size());

    
    for (auto it : arr)
    {
        cout << it << endl;
    }
    return 0;
}