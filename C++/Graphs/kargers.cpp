// # Karger's Algorithm (Min Cut)

// Karger's algorithm is a randomized algorithm used to find the minimum cut in a graph. The minimum cut of a graph is defined as the smallest number of edges that, if removed, would divide the graph into two disconnected components. Karger's algorithm is based on the concept of contraction, where two randomly chosen vertices are merged into a single vertex, reducing the size of the graph. The algorithm repeats this contraction step until only two vertices (representing the two sides of the cut) remain.

// ### Here is a high-level overview of Karger's algorithm:

// 1. Start with an undirected graph.
// 2. Repeat steps 3-4 until there are only two vertices left.
// 3. Randomly select an edge from the graph.
// 4. Merge the two vertices connected by the selected edge into a single vertex, combining their edges.
// 5. Return the cut represented by the remaining two vertices.

// The algorithm's main advantage is its simplicity and efficiency. It has a high probability of finding the correct minimum cut, but it may occasionally give incorrect results due to its randomized nature. To improve the accuracy, the algorithm is usually run multiple times to increase the chances of finding the correct minimum cut.

// Karger's algorithm has a time complexity of approximately O(n^2), where n is the number of vertices in the graph. Although it has a relatively high time complexity, it is efficient in practice for graphs with a large number of vertices.

// Note: Karger's algorithm is often used as a subroutine in other algorithms and has applications in network reliability, image segmentation, and clustering problems.












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
