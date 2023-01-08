#include<bits/stdc++.h>
using namespace std;
void sort012(vector<int> &nums, int n) 
{
    int l = 0, m = 0, h = n-1;
    while(m <= h)
    {
        if(nums[m] == 0)
        {
            swap(nums[l], nums[m]);
            l++;
            m++;
        }
        else if(nums[m] == 1)
        {
            m++;
        }
        else
        {
            swap(nums[h], nums[m]);
            h--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    sort012(nums, n);
    for(int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}