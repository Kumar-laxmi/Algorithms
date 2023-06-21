#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class HopcroftKarp {
private:
    int n, m;
    vector<vector<int>> graph;
    vector<int> match;
    vector<int> dist;

public:
    HopcroftKarp(int n, int m) : n(n), m(m), graph(n + 1), match(n + m + 1), dist(n + m + 1) {}

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; ++u) {
            if (match[u] == -1) {
                dist[u] = 0;
                q.push(u);
            }
            else {
                dist[u] = numeric_limits<int>::max();
            }
        }
        dist[0] = numeric_limits<int>::max();

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] < dist[0]) {
                for (int v : graph[u]) {
                    if (dist[match[v]] == numeric_limits<int>::max()) {
                        dist[match[v]] = dist[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
        }

        return dist[0] != numeric_limits<int>::max();
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : graph[u]) {
                if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
            dist[u] = numeric_limits<int>::max();
            return false;
        }
        return true;
    }

    int maxMatching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 1; u <= n; ++u) {
                if (match[u] == -1 && dfs(u)) {
                    ++matching;
                }
            }
        }
        return matching;
    }
};

int main() {
    int n, m, edges;
    cout << "Enter the number of vertices on the left side of the bipartite graph: ";
    cin >> n;
    cout << "Enter the number of vertices on the right side of the bipartite graph: ";
    cin >> m;
    cout << "Enter the number of edges: ";
    cin >> edges;

    HopcroftKarp hk(n, m);

    cout << "Enter the edges in the format (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        hk.addEdge(u, v);
    }

    int maxMatching = hk.maxMatching();

    cout << "Maximum Cardinality Matching: " << maxMatching << endl;

    return 0;
}

