/*Kruskals Algorithm
    Author: Phalesh Kolpe
    Kruskals algorithm is used to Find the MST(Minimum Spaning Tree) of a graph it considers the edges and weight of the edge
    Step 1: Sort all edges in increasing order of their edge weights.
    Step 2: Pick the smallest edge.
    Step 3: Check if the new edge creates a cycle or loop in a spanning tree.
    Step 4: If it doesn’t form the cycle, then include that edge in MST. Otherwise, discard it.
    Step 5: Repeat from step 2 until it includes |V| - 1 edges in MST.
    Expected Output Of the code:-
    Enter the number of vertices: 
    Enter the number of edges:
    Enter the details of each edge (source, destination, weight): 
    Give input for the above line in the following manner
    0 1 7
    where 0 is the soucre of edge 1 is the destination and 7 is the weight of the edge*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int v, e;
    vector<edge> edges;
};

int findParent(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two sets
void unionSets(vector<int>& parent, int x, int y) {
    parent[x] = y;
}

// Function to compare two edges based on their weights
bool compareedges(const edge& a, const edge& b) {
    return a.weight < b.weight;
}

// Function to apply Kruskal's algorithm and find the minimum spanning tree
void kruskalMST(Graph& graph) {
    int v = graph.v;
    vector<edge> result;
    int e = 0;
    int i = 0;

    // Sort the edges in ascending order of their weights
    sort(graph.edges.begin(), graph.edges.end(), compareedges);

    // Allocate memory for parent array
    vector<int> parent(v, -1);

    // Process each edge and add it to the MST if it does not form a cycle
    while (e < v - 1 && i < graph.e) {
        edge nextedge = graph.edges[i++];

        int x = findParent(parent, nextedge.src);
        int y = findParent(parent, nextedge.dest);

        if (x != y) {
            result.push_back(nextedge);
            unionSets(parent, x, y);
            e++;
        }
    }

    // Print the edges of the MST
    cout << "Edges in the constructed MST:" << endl;
    for (const edge& edge : result) {
        cout << edge.src << " -- " << edge.dest << "  =>  " << edge.weight << endl;
    }
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    Graph graph;
    graph.v = v;
    graph.e = e;

    cout << "Enter the details of each edge (source, destination, weight):" << endl;
    for (int i = 0; i < e; i++) {
        edge edge;
        cin >> edge.src >> edge.dest >> edge.weight;
        graph.edges.push_back(edge);
    }

    kruskalMST(graph);

    return 0;
}
