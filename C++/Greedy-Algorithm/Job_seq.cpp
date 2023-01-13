#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;

}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>job;
    int profit,deadl;
    for(int i=0;i<n;i++)
    {
        cin>>profit>>deadl;
        job.push_back(make_pair(profit,deadl));
    }
    sort(job.begin(),job.end(),compare);
    int max_end=0;
    for(int i=0;i<n;i++)
    {
        if(max_end<job[i].second)
        {
            max_end=job[i].second;
        }
    }
    int fill[max_end];
    for(int i=0;i<max_end;i++)
    {
        fill[i]=-1;
    }
    int profittt;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int j=job[i].second-1;
        while(j>=0 &&fill[j]!=-1)
        {
            j--;
        }
        if(j>=0 && fill[j]==-1)
        {
            fill[j]=i;
            profittt+=job[i].first;
            cnt++;
        }
    }
    cout<<"maximum profit:"<<profittt;
    return 0;
}