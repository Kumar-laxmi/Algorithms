#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

void solver() {
    cout << "Enter the number of vertices,edges and sources" << endl;
    
    int n,m,s;
    cin >> n >> m >> s;
  
    vector<int> adj[n+1];
    vector<int> sources;
    
    cout << "Enter the sources: ";
    
    for(int i = 0;i<s;i++) {
        int src;
        cin >> src;
        
        sources.push_back(src);
    }
    
    cout << "Enter the edges" << endl;
    
    while(m--) {
        int u,v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(n+1,1e9);
    vector<int> vis(n+1,0);
    queue<int> q;
    
    for(auto it: sources) {
        vis[it] = 1;
        q.push(it);
    }
    
    int lvl = 0;
    
    while(q.size()) {
        int sz = q.size();
        while(sz--) {
            int node = q.front();
            q.pop();
            
            dist[node] = lvl;
            
            for(auto it: adj[node]) {
                if(vis[it]) {
                    continue;
                }
                
                vis[it] = 1;
                q.push(it);
            }
        }
        lvl++;
        
    }
    
    for(int i = 1;i<=n;i++) {
        cout << i << ": " << dist[i] << endl;
    }
}

int main() {
    fast_io;
    int t = 1;
    
    while(t--) {
       solver();
    }
    
    return 0;
}
