#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function to find the minimum cut using Stoer-Wagner algorithm
int stoerWagner(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int minCut = INT_MAX;  // Initialize the minimum cut with maximum value
    bool inSet[MAX_VERTICES];  // Keep track of vertices included in the set
    int partition[MAX_VERTICES];  // Keep track of partition of vertices

    for (int i = 0; i < n; i++) {
        partition[i] = i;  // Initialize each vertex in its own partition
    }

    for (int phase = 0; phase < n - 1; phase++) {
        bool inTree[MAX_VERTICES] = {false};  // Mark all vertices as not yet included in the tree
        int weight[MAX_VERTICES] = {0};  // Initialize the weight array

        int prev = -1;  // Variable to store the previous vertex
        for (int i = 0; i < n - phase; i++) {
            int maxWeight = -1;
            int current = -1;
            for (int j = 0; j < n; j++) {
                if (!inTree[j] && !inSet[j] && weight[j] > maxWeight) {
                    maxWeight = weight[j];  // Update the maximum weight
                    current = j;  // Store the current vertex
                }
            }

            if (i == n - phase - 1) {
                if (maxWeight < minCut) {
                    minCut = maxWeight;  // Update the minimum cut value
                }
                inSet[current] = true;  // Include the current vertex in the set
                for (int j = 0; j < n; j++) {
                    if (!inTree[j]) {
                        graph[prev][j] += graph[current][j];  // Update the graph weights
                        graph[j][prev] += graph[current][j];
                    }
                }
            } else {
                inTree[current] = true;  // Include the current vertex in the tree
                for (int j = 0; j < n; j++) {
                    if (!inTree[j]) {
                        weight[j] += graph[current][j];  // Update the weight array
                    }
                }
                prev = current;  // Store the previous vertex
            }
        }
    }

    return minCut;  // Return the minimum cut value
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];  // Graph represented as an adjacency matrix
    int n, m;  // Number of vertices and edges

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;  // Set the weight of edge (u, v)
        graph[v][u] = weight;  // Set the weight of edge (v, u)
    }

    int minCut = stoerWagner(graph, n);  // Find the minimum cut using Stoer-Wagner algorithm

    printf("Minimum cut value: %d\n", minCut);

    return 0;
}
