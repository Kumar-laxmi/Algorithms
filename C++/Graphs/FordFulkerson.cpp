 #include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find if there is a path from source to sink in the residual graph
bool bfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    int V = residualGraph.size();

    vector<bool> visited(V, false); // Create a visited array to keep track of visited vertices
    queue<int> q; // Create a queue for BFS
    q.push(source); // Enqueue the source vertex
    visited[source] = true;
    parent[source] = -1; // Set the parent of the source as -1

    // Standard BFS loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }

    // If we reached the sink in BFS, then there is a path from source to sink
    return visited[sink];
}

// Function to implement the Ford-Fulkerson algorithm
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int V = graph.size();

    // Create a residual graph and initialize it with the original capacities
    vector<vector<int>> residualGraph(V, vector<int>(V));
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    vector<int> parent(V); // This array is filled by BFS and stores the path
    int maxFlow = 0; // Initialize the maximum flow

    // Augment the flow while there is a path from source to sink in the residual graph
    while (bfs(residualGraph, source, sink, parent)) {
        // Find the maximum possible flow through the path found in BFS
        int pathFlow = numeric_limits<int>::max();
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Update the residual capacities of the edges and reverse edges along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        // Add the path flow to the overall maximum flow
        maxFlow += pathFlow;
    }

    // Return the overall maximum flow
    return maxFlow;
}

int main() {
    int V; // Number of vertices in the graph
    int source, sink; // Source and sink vertices

    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0)); // Adjacency matrix representation of the graph

    int numEdges;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    // Get the edge details from the user and update the graph
    for (int i = 0; i < numEdges; i++) {
        int u, v, capacity;
        cout << "Enter the start vertex, end vertex, and capacity of edge " << i + 1 << ": ";
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    cout << "Enter the sink vertex: ";
    cin >> sink;

    // Call the Ford-Fulkerson algorithm to find the maximum flow
    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "The maximum flow in the graph is: " << maxFlow << endl;

    return 0;
}
