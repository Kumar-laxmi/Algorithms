// Path: C++\Graphs\Ford-Fulkerson_Algorithm.cpp
// Ford-Fulkerson algorithm in C++ programming:
    //Time-Complexity: O(E * maxFlow) where E is the number of edges in the graph.
    //Space-Complexity: O(V^2)  where V is the number of vertices in the graph.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Structure to represent an edge in the graph
struct Edge {
    int u, v;   // source and destination vertices
    int capacity; // capacity of the edge
    int flow;   // current flow through the edge

    Edge(int u, int v, int capacity) : u(u), v(v), capacity(capacity), flow(0) {}
};

// Function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int u, int v, int capacity) {
    Edge e1(u, v, capacity);
    Edge e2(v, u, 0); // reverse edge with 0 capacity for residual graph

    graph[u].push_back(e1);
    graph[v].push_back(e2);
}

// Helper function to check if there is an augmenting path
bool bfs(vector<vector<Edge>>& graph, vector<int>& parent, int source, int sink) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.v;
            if (!visited[v] && edge.capacity > edge.flow) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

// Ford-Fulkerson Algorithm
int fordFulkerson(vector<vector<Edge>>& graph, int source, int sink) {
    int maxFlow = 0;
    int n = graph.size();

    // Create a residual graph with capacities initially equal to original graph
    vector<vector<Edge>> residualGraph(n);
    for (int u = 0; u < n; ++u) {
        for (const auto& edge : graph[u]) {
            int v = edge.v;
            int capacity = edge.capacity - edge.flow;
            addEdge(residualGraph, u, v, capacity);
        }
    }

    vector<int> parent(n, -1);

    while (bfs(residualGraph, parent, source, sink)) {
        int pathFlow = INF;

        // Find the minimum residual capacity along the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            for (auto& edge : residualGraph[u]) {
                if (edge.v == v) {
                    pathFlow = min(pathFlow, edge.capacity);
                    break;
                }
            }
        }

        // Update the residual capacities and reverse edges
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            for (auto& edge : residualGraph[u]) {
                if (edge.v == v) {
                    edge.flow += pathFlow;
                    for (auto& reverseEdge : residualGraph[v]) {
                        if (reverseEdge.v == u) {
                            reverseEdge.flow -= pathFlow;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n = 6; // Number of vertices in the graph

    vector<vector<Edge>> graph(n); // Adjacency list to represent the graph

    // Adding edges to the graph
    addEdge(graph, 0, 1, 16);
    addEdge(graph, 0, 2, 13);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 1, 3, 12);
    addEdge(graph, 2, 1, 4);
    addEdge(graph, 2, 4, 14);
    addEdge(graph, 3, 2, 9);
    addEdge(graph, 3, 5, 20);
    addEdge(graph, 4, 3, 7);
    addEdge(graph, 4, 5, 4);

    int source = 0; // Source vertex
    int sink = 5;   // Sink vertex

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}



// Pseudocode for Ford-Fulkerson Algorithm: Here's a pseudocode representation of the Ford-Fulkerson algorithm

/*
function fordFulkerson(graph, source, sink):
    initialize residualGraph as a copy of graph
    maxFlow = 0

    while there is an augmenting path in residualGraph from source to sink:
        pathFlow = findMinimumCapacityAlongPath(residualGraph, source, sink)
        updateResidualCapacities(residualGraph, source, sink, pathFlow)
        maxFlow += pathFlow

    return maxFlow

function findMinimumCapacityAlongPath(residualGraph, source, sink):
    initialize parent array
    initialize a queue

    enqueue source into the queue
    mark source as visited in the parent array

    while queue is not empty:
        current = dequeue from the queue

        for each neighbor of current in residualGraph:
            if neighbor is not visited and capacity > flow:
                enqueue neighbor into the queue
                mark neighbor as visited in the parent array

    if sink is visited:
        return minimum capacity along the augmenting path
    else:
        return 0

function updateResidualCapacities(residualGraph, source, sink, pathFlow):
    for each edge in the augmenting path from sink to source:
        update capacity and flow for the forward edge
        update capacity and flow for the reverse edge

main:
    create an empty graph
    add edges to the graph
    specify source and sink vertices

    maxFlow = fordFulkerson(graph, source, sink)
    print maxFlow

*/

