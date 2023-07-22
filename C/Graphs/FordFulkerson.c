 #include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6  // Number of vertices in the graph

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find if there is a path from source to sink in the residual graph
bool bfs(int residualGraph[V][V], int source, int sink, int parent[]) {
    // Create a visited array to keep track of visited vertices
    bool visited[V] = { false };

    // Create a queue for BFS and enqueue the source vertex
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = true;
    parent[source] = -1;

    // Standard BFS loop
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached the sink in BFS, then there is a path from source to sink
    return visited[sink];
}

// Function to implement the Ford-Fulkerson algorithm
int fordFulkerson(int graph[V][V], int source, int sink) {
    // Create a residual graph and initialize it with the original capacities
    int residualGraph[V][V];
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];  // This array is filled by BFS and stores the path

    int maxFlow = 0;  // Initialize the maximum flow

    // Augment the flow while there is a path from source to sink in the residual graph
    while (bfs(residualGraph, source, sink, parent)) {
        // Find the maximum possible flow through the path found in BFS
        int pathFlow = INT_MAX;
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
    int graph[V][V];  // Adjacency matrix representation of the graph

    // Get the number of vertices and edges from the user
    int numEdges;
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    // Initialize the graph with zero capacity initially
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // Get the edge details from the user and update the graph
    for (int i = 0; i < numEdges; i++) {
        int u, v, capacity;
        printf("Enter the start vertex, end vertex, and capacity of edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &capacity);
        graph[u][v] = capacity;
    }

    int source, sink;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the sink vertex: ");
    scanf("%d", &sink);

    // Call the Ford-Fulkerson algorithm to find the maximum flow
    int maxFlow = fordFulkerson(graph, source, sink);
    printf("The maximum flow in the graph is: %d\n", maxFlow);

    return 0;
}
