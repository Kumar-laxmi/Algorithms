#include <bits/stdc++.h>
using namespace std;

// topological sort means linear ordering of values such that if there is an edge u -> v,
// u appears before v in that ordering.

/**
 *  5 -> 0 <- 4
 *  => 5 4 0
 *  5 -> 0 edge in graph and in array 5 appears before 0,
 *  same for 4 -> 0 edge.
 *  It is applicable only for DAG, Directed Acyclic Graph.
 *  Directed because it tells about the ordering
 *  If cyclic graph, like 2 -> 3 -> 4 ->...2
 *  Array: [2, 3, 4] for edge 4 -> 2, 4 can never appear before 2,
 *  So only applicable for acyclic graph
**/

void topoDFS(int node, stack<int> &topo, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) topoDFS(i, topo, vis, adj);
    }

    topo.push(node);
}

void topoSortDFS(int v, vector<int> adj[]) {
    stack<int> topo;
    vector<int> vis(v + 1, 0);

    for (int i = 0; i <= v; i++) {
        if (!vis[i]) topoDFS(i, topo, vis, adj);
    }

    while (!topo.empty()) {
        cout << topo.top() << " ";
        topo.pop();
    }
    cout << endl;
}

// Kahn's Algorithm
void topoSortBFS(int v, vector<int> adj[]) {
    queue<int> nodes;
    vector<int> inDeg(v + 1, 0);
    vector<int> ans;

    for (int i = 0; i <= v; i++) {
        for (int j : adj[i]) inDeg[j]++;
    }

    for (int i = 0; i <= v; i++) if (inDeg[i] == 0) nodes.push(i);

    while (!nodes.empty()) {
        int n = nodes.front();
        ans.push_back(n);
        nodes.pop();

        for (int i : adj[n]) {
            inDeg[i]--;
            if (inDeg[i] == 0) nodes.push(i);
        }
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    // if vertex are numbered from 1 to v
    int v;
    cout << "Enter v: ";
    cin >> v;

    vector<int> adj[v + 1];
    for (int i = 0; i <= v; i++) {
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
    
    cout << "Topological Sort using DFS: ";
    topoSortDFS(v, adj);
    cout << endl;

    cout << "Topological Sort using BFS: ";
    topoSortBFS(v, adj);
    cout << endl;
}