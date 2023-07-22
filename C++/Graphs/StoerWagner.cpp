#include<bits/stdc++.h>

using namespace std;

// Function to find the minimum cut using the Stoer-Wagner algorithm
int stoerWagner(vector<vector<int>>& graph, int n) {
    // Initialize the minimum cut value
    int minCut = INT_MAX;

    // Create a vector to keep track of merged vertices
    vector<bool> merged(n, false);

    // Create a vector to store the contraction order of vertices
    vector<int> order(n);

    // Iterate over n-1 vertices
    for (int phase = 0; phase < n - 1; ++phase) {
        // Initialize the weight vector and the visited vector
        vector<int> weight(n, 0);
        vector<bool> visited(n, false);

        // Set the source vertex as the last merged vertex
        int src = order[phase - 1];

        // Perform n-1 contractions
        for (int i = 0; i < n - phase; ++i) {
            // Select the vertex with the maximum weight
            int maxWeight = -1, maxVertex;
            for (int v = 0; v < n; ++v) {
                if (!merged[v] && !visited[v] && weight[v] > maxWeight) {
                    maxWeight = weight[v];
                    maxVertex = v;
                }
            }

            // Mark the vertex as visited
            visited[maxVertex] = true;

            // If it's not the last contraction, update the weights
            if (i != n - phase - 1) {
                for (int v = 0; v < n; ++v) {
                    if (!merged[v] && !visited[v]) {
                        weight[v] += graph[maxVertex][v];
                    }
                }
            }

            // Update the source vertex for the next contraction
            src = maxVertex;
        }

        // Update the minimum cut value
        minCut = min(minCut, weight[src]);

        // Merge the source vertex into the previous vertex
        merged[src] = true;

        // Store the contraction order
        order[phase] = src;
    }

    return minCut;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    // Create an adjacency matrix to represent the graph
    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // Find the minimum cut using the Stoer-Wagner algorithm
    int minCut = stoerWagner(graph, n);

    cout << "The minimum cut value is: " << minCut << endl;

    return 0;
}
