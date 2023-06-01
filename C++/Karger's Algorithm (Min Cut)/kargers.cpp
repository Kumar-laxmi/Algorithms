#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest;
};

// Function to find the root of a vertex
int findRoot(vector<int>& parent, int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return findRoot(parent, parent[vertex]);
}

// Function to perform union of two subsets
void unionSets(vector<int>& parent, int x, int y) {
    int rootX = findRoot(parent, x);
    int rootY = findRoot(parent, y);
    parent[rootX] = rootY;
}

// Function to find the minimum cut using Karger's algorithm
int findMinCut(vector<Edge>& edges, int vertices) {
    vector<int> parent(vertices);
    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    int remainingVertices = vertices;

    // Create a random number generator
    random_device rd;
    mt19937 rng(rd());

    // Keep contracting vertices until only 2 vertices are left
    while (remainingVertices > 2) {
        uniform_int_distribution<int> dist(0, edges.size() - 1);
        int randomEdge = dist(rng);

        int rootSrc = findRoot(parent, edges[randomEdge].src);
        int rootDest = findRoot(parent, edges[randomEdge].dest);

        if (rootSrc == rootDest)
            continue;

        unionSets(parent, rootSrc, rootDest);
        remainingVertices--;
    }

    // Count the edges crossing the cut
    int cutEdges = 0;
    for (const auto& edge : edges) {
        int rootSrc = findRoot(parent, edge.src);
        int rootDest = findRoot(parent, edge.dest);
        if (rootSrc != rootDest)
            cutEdges++;
    }

    return cutEdges;
}

int main() {
    int vertices = 4;
    int edgesCount = 5;

    vector<Edge> edges = { {0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3} };

    int minCut = findMinCut(edges, vertices);

    cout << "Minimum cut found: " << minCut << endl;

    return 0;
}
