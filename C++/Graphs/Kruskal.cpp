#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the node structure for the graph
struct Edge {
    int src, dest, weight;
};

// Compare function for sorting edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent of a node in a disjoint set
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    return findParent(parent[node], parent);
}

// Function to perform union of two disjoint sets
void unionNodes(int node1, int node2, vector<int>& parent, vector<int>& rank) {
    int parent1 = findParent(node1, parent);
    int parent2 = findParent(node2, parent);

    if (rank[parent1] < rank[parent2]) {
        parent[parent1] = parent2;
    }
    else if (rank[parent1] > rank[parent2]) {
        parent[parent2] = parent1;
    }
    else {
        parent[parent1] = parent2;
        rank[parent2]++;
    }
}

// Function to perform Kruskal's algorithm
vector<Edge> kruskalAlgorithm(vector<Edge>& edges, int n) {
    vector<Edge> mst;
    vector<int> parent(n);
    vector<int> rank(n);

    // Initialize the parent array and rank array for each node in the graph
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort the edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Iterate through the edges in sorted order
    for (auto edge : edges) {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;

        // Check if adding the edge would create a cycle in the graph
        if (findParent(src, parent) != findParent(dest, parent)) {
            mst.push_back(edge);
            unionNodes(src, dest, parent, rank);
        }
    }

    return mst;
}

// Main function to test the Kruskal's algorithm implementation
int main() {
    // Define the edges of the graph
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    // Perform Kruskal's algorithm to find the minimum spanning tree of the graph
    vector<Edge> mst = kruskalAlgorithm(edges, 4);

    // Print the edges of the minimum spanning tree
    cout << "Edges of the minimum spanning tree:" << endl;
    for (auto edge : mst) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
