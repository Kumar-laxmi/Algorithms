#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int n=1e3+!0;
vector<int>adj[n];
vector<int>indegree(n,0);


vector<int> topological(int n)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        for(int child:adj[i])
        {
            indegree[child]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(int child:adj[node])
        {
            indegree[child]--;
            if(indegree[child]==0)
            {
                q.push(child);
            }
        }
    }
    return topo;
}



int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
    }

    vector<int>a;
    a=topological(n);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<"   ";
    }
    return 0;
}