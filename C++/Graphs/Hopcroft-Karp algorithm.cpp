/*
The Hopcroft-Karp algorithm is a graph algorithm used for finding the maximum cardinality matching in a bipartite graph. It falls under the category of graph algorithms, specifically matching algorithms.

Matching algorithms are used to find pairs of elements from different sets that satisfy certain criteria or constraints. In the case of bipartite graphs, a matching refers to a set of edges that do not share any common vertices, and the maximum cardinality matching is the largest possible matching in terms of the number of edges.

The Hopcroft-Karp algorithm efficiently computes the maximum cardinality matching in a bipartite graph with a time complexity of O(sqrt(V) * E), where V is the number of vertices and E is the number of edges in the graph.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class HopcroftKarp {
    int n, m;
    vector<vector<int>> graph;
    vector<int> match;
    vector<int> dist;

public:
    HopcroftKarp(int n, int m) : n(n), m(m), graph(n), match(m), dist(n) {}

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 0; u < n; ++u) {
            if (match[u] == -1) {
                dist[u] = 0;
                q.push(u);
            }
            else {
                dist[u] = INF;
            }
        }

        dist[-1] = INF;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[-1]) {
                for (int v : graph[u]) {
                    if (dist[match[v]] == INF) {
                        dist[match[v]] = dist[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
        }

        return dist[-1] != INF;
    }

    bool dfs(int u) {
        if (u == -1)
            return true;

        for (int v : graph[u]) {
            if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }

        dist[u] = INF;
        return false;
    }

    int maxMatching() {
        int matching = 0;

        while (bfs()) {
            for (int u = 0; u < n; ++u) {
                if (match[u] == -1 && dfs(u)) {
                    matching++;
                }
            }
        }

        return matching;
    }
};

int main() {
    int n, m, e;
    cin >> n >> m >> e;

    HopcroftKarp hk(n, m);

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        hk.addEdge(u, v);
    }

    int maxMatching = hk.maxMatching();
    cout << "Maximum Matching: " << maxMatching << endl;

    return 0;
}
