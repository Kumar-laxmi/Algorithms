/**
It tells about one component under which, all those nodes are present such that using that node one can visit
all other nodes of that component.
Such component is also called as Strongly Connected Component(SCC)

Algorithm:
    1. Sort all the nodes according to their finishing time => Topological sort
    2. Transpose the graph => Reverse the direction of all edges
    3. Do the DFS according to the finish time
**/
#include <bits/stdc++.h>
using namespace std;

void topoDFS(int node, stack<int> &topo, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) topoDFS(i, topo, vis, adj);
    }
    topo.push(node);
}

void topoSortDFS(int v, vector<int> adj[], stack<int> &topo) {
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) topoDFS(i, topo, vis, adj);
    }
}

void kosaraju(int node, vector<int> &vis, vector<int> adj[]) {
    cout << node << " ";
    vis[node] = 1;
    for (auto i : adj[node]) {
        if (!vis[i]) kosaraju(i, vis, adj);
    }
}

int main() {
    // if vertex are numbered from 1 to v

    int v;
    cout << "Enter v: ";
    cin >> v;

    vector<int> adj[v + 1];
    for (int i = 1; i <= v; i++) {
        cout << "Enter number of adjacencies of vertex " << i << ": ";
        int ad;
        cin >> ad;
        cout << "Now enter the vertices that are adjacent to vertex " << i << ":\n";
        for (int j = 0; j < ad; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    stack<int> topo;
    topoSortDFS(v, adj, topo);

    vector<int> transpose[v + 1];
    for (int i = 1; i <= v; i++) {
        for (auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }
    
    cout << "All SCC: \n";
    vector<int> vis(v + 1, 0);

    while (!topo.empty()) {
        int node = topo.top();
        topo.pop();
        if (!vis[node]) {
            kosaraju(node, vis, transpose);
            cout << endl;
        }
    }
}