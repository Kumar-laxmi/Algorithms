// Path: C\Graphs\Edmonds-Karp_Algorithm.c
// Time Complexity: O(V * E^2)
// Space Complexity: O(V^2)

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6  // Number of vertices in the graph

// Function to perform Breadth-First Search (BFS)
bool bfs(int residualGraph[V][V], int parent[V], int source, int sink) {
    bool visited[V] = {false};
    int queue[V];
    int front = -1;
    int rear = -1;

    queue[++rear] = source;
    visited[source] = true;
    parent[source] = -1;

    while (front != rear) {
        int u = queue[++front];

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                queue[++rear] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];  // Return true if there is a path from source to sink
}

// Function to find the maximum flow using Edmonds-Karp algorithm
int edmondsKarp(int graph[V][V], int source, int sink) {
    int residualGraph[V][V] = {0};  // Residual graph
    int parent[V] = {-1};  // Parent array to store the augmenting path

    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int maxFlow = 0;  // Initialize the maximum flow

    // Augment the flow while there is a path from source to sink
    while (bfs(residualGraph, parent, source, sink)) {
        int pathFlow = INT_MAX;

        // Find the minimum residual capacity along the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < residualGraph[u][v]) ? pathFlow : residualGraph[u][v];
        }

        // Update the residual capacities and reverse edges along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;  // Add the path flow to the maximum flow
    }

    return maxFlow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;  // Source vertex
    int sink = 5;    // Sink vertex

    int maxFlow = edmondsKarp(graph, source, sink);

    printf("Maximum flow: %d\n", maxFlow);

    return 0;
}



// Output>>  Maximum flow: 23