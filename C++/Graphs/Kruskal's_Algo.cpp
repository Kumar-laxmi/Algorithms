// this algorith uses DSU to make MST
// step 1: sort all edges according to their weights
// step 2: iterate over all edges and check if u and v don't belong to the same component, join them

#include <bits/stdc++.h>
using namespace std;

struct node {
    int u, v, wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt;
}

int findPar(int node, vector<int> &parent) {
    if (node == parent[node]) return node;
    return parent[node] = findPar(parent[node], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &Rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);

    if (Rank[u] < Rank[v]) {
        parent[u] = v;
    }
    else if (Rank[u] > Rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        Rank[u]++;
    }
}

int main() {
    int n = 7;
    vector<node> nodes;
    nodes.push_back(node(1, 2, 2));
    nodes.push_back(node(1, 4, 1));
    nodes.push_back(node(1, 5, 4));
    nodes.push_back(node(2, 3, 3));
    nodes.push_back(node(2, 4, 3));
    nodes.push_back(node(2, 6, 7));
    nodes.push_back(node(3, 4, 5));
    nodes.push_back(node(3, 6, 8));
    nodes.push_back(node(4, 5, 9));

    sort(nodes.begin(), nodes.end(), comp);
    vector<int> parent(n + 1), Rank(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto i : nodes) {
        if (findPar(i.u, parent) != findPar(i.v, parent)) {
            cost += i.wt;
            mst.push_back({i.u, i.v});
            unionn(i.u, i.v, parent, Rank);
        }
    }

    for (auto i : mst) cout << i.first << " " << i.second << endl;
    cout << cost << endl;
}