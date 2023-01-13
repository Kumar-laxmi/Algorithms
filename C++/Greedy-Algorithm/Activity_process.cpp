#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s,e;
    vector<pair<int,int>>activity;//end time,start time
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        activity.push_back(make_pair(e,s));
    }
    sort(activity.begin(),activity.end());
    int current_end=-1;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(activity[i].second>current_end)
        {
            count++;
            current_end=activity[i].first;
        }
    }
    cout<<count;//maximum number of processes
    return 0;
}