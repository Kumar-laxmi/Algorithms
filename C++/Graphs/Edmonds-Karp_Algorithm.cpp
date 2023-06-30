// Path: C++\Graphs\Edmonds-Karp_Algorithm.cpp
// Edmonds-Karp Algorithm    
    //Time-Complexity: O(VE^2)    
    //Space-Complexity: O(V^2)  where V is the number of vertices and E is the number of edges in the graph.

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define V 6  // Number of vertices in the graph

// Function to perform Breadth-First Search (BFS)
bool bfs(vector<vector<int>>& residualGraph, vector<int>& parent, int source, int sink) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];  // Return true if there is a path from source to sink
}

// Function to find the maximum flow using Edmonds-Karp algorithm
int edmondsKarp(vector<vector<int>>& graph, int source, int sink) {
    vector<vector<int>> residualGraph(V, vector<int>(V, 0));  // Residual graph
    vector<int> parent(V, -1);  // Parent array to store the augmenting path

    for (int u = 0; u < V; ++u)
        for (int v = 0; v < V; ++v)
            residualGraph[u][v] = graph[u][v];

    int maxFlow = 0;  // Initialize the maximum flow

    // Augment the flow while there is a path from source to sink
    while (bfs(residualGraph, parent, source, sink)) {
        int pathFlow = INT_MAX;

        // Find the minimum residual capacity along the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
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
    vector<vector<int>> graph = {
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

    cout << "Maximum flow: " << maxFlow << endl;

    return 0;
}



/* 
Psudocode for Edmonds-Karp Algorithm:

function bfs(residualGraph, parent, source, sink):
    create a visited array with size V and initialize all elements as false
    create a queue data structure

    mark the source vertex as visited and enqueue it
    set the parent of the source vertex as -1

    while the queue is not empty:
        dequeue a vertex from the front of the queue

        for each adjacent vertex v of the dequeued vertex:
            if v is not visited and there is residual capacity from the dequeued vertex to v:
                mark v as visited
                set the parent of v as the dequeued vertex
                enqueue v

    return true if there is a path from the source to the sink, false otherwise

function edmondsKarp(graph, source, sink):
    create a residual graph with size V and initialize all elements as 0
    create a parent array with size V and initialize all elements as -1

    copy the capacity values from the given graph to the residual graph

    initialize the maximum flow as 0

    while there is a path from the source to the sink using bfs(residualGraph, parent, source, sink):
        set the pathFlow as infinity

        traverse the augmenting path from the sink to the source using the parent array:
            find the minimum residual capacity along the path and update pathFlow

        update the residual capacities and reverse edges along the path:
            for each vertex v in the path:
                find the parent vertex u
                reduce the residual capacity of the edge (u, v) by pathFlow
                increase the residual capacity of the edge (v, u) by pathFlow

        add the pathFlow to the maximum flow

    return the maximum flow

// Example usage:
create a graph with V vertices and initialize the capacity values

set the source vertex
set the sink vertex

find the maximum flow using edmondsKarp(graph, source, sink)
*/

/*
Note: This pseudocode outlines the main steps of the Edmonds-Karp algorithm, including the breadth-first search (BFS) to find augmenting paths and the updates to the residual graph based on the found paths. You can convert this pseudocode into a working implementation in the programming language of your choice.
*/
