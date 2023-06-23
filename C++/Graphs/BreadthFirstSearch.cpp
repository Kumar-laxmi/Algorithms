#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // No. of vertices
    vector<vector<int>> adj; // Adjacency Lists

public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // BFS traversal from a given source node 's'
    void BFS(int s) {
		// Create a queue for BFS traversal
        queue<int> q;
        vector<bool> visited(V, false);

        // Mark the current node as visited and add into queue
        visited[s] = true;
        q.push(s);

        // Remove a vertex from queue and print it
        cout << "BFS traversal starting from vertex " << s << ": ";

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";


			// Get all adjacent vertices of the dequeued vertex s.
			// If an adjacent has not been visited, then mark it visited and enqueue it
            for (int nbr : adj[curr]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main() {
    int N, M;
    cout << "Enter the number of vertices and edges: ";
    cin >> N >> M;

    Graph g(N);

    for (int i = 1; i <= M; i++) {
        int u, v;
        cout << "Enter edge No. " << i << ": ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    g.BFS(s);

    return 0;
}
