/*
Prim's algorithm is a greedy algorithm that finds the minimum spanning tree of a weighted undirected graph. 
It starts with an arbitrary vertex and adds the minimum weight edge to the current tree until all vertices are included. 
The algorithm maintains sets of included and not-yet-included vertices, updating key values of adjacent vertices.
This process continues until all vertices are included, ensuring the minimum weight tree.
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//Setting the maximum vertices to 100, which can be changed as per requirement
#define MAX_VERTICES 100

// Function to find the vertex with the minimum key value
int findMinKeyVertex(int key[], bool mstSet[], int V) {
    int minKey = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the minimum spanning tree
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Minimum Spanning Tree:\n");
    for (int v = 1; v < V; v++) {
        printf("%d -- %d : %d\n", parent[v], v, graph[v][parent[v]]);
    }
}

// Function to implement Prim's algorithm to find the minimum spanning tree
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[V];  // Array to store the constructed minimum spanning tree
    int key[V];     // Key values used to pick the minimum weight edge
    bool mstSet[V]; // Set to keep track of vertices included in the minimum spanning tree

    // Initialize all keys as infinite and mstSet as false
    for (int v = 0; v < V; v++) {
        key[v] = INT_MAX;
        mstSet[v] = false;
    }

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1; // First vertex is always the root of the minimum spanning tree

    // Construct the minimum spanning tree with V-1 vertices
    for (int count = 0; count < V - 1; count++) {
        int u = findMinKeyVertex(key, mstSet, V);
        mstSet[u] = true;

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Print the minimum spanning tree
    printMST(parent, graph, V);
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0; // Initialize all edges as 0 (no connection)
        }
    }

    printf("Enter edges and their weights (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        int source, destination, weight;
        scanf("%d %d %d", &source, &destination, &weight);
        graph[source][destination] = weight;
        graph[destination][source] = weight; // Graph is undirected, so set both directions
    }

    primMST(graph, V);

    return 0;
}
