#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s,e;
    vector<pair<int,int>>activity;//Pair of end time,start time is inserted into vector
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;//Input start time and end time
        activity.push_back(make_pair(e,s));
    }
    //sort the activities according to their finishing time so that we always consider the next activity as the minimum finishing time activity
    sort(activity.begin(),activity.end());//Sorting the activity according to end time (Finishing time)
    int current_end=-1;
    int count=0;
    for(int i=0;i<n;i++)
    {
        //If the start time of this activity is greater than or equal to the finish time of the previously selected activity then increment the count of number of processes that will execute
        if(activity[i].second>current_end)
        {
            count++;
            current_end=activity[i].first;
        }
    }
    cout<<count;//maximum number of processes executed
    return 0;
}