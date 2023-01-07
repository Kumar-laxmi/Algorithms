#include <iostream>
#include <vector>
#include <utility>
#include <cfloat>
#include <cmath>
#include <algorithm>

using namespace std;

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest;
    double weight;
};

// a structure to represent a connected, directed and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges
    vector<Edge> edges;

    // Constructor
    Graph(int V, int E) : V(V), E(E) {}

    // Utility function to add an edge
    void add_edge(int src, int dest, double weight)
    {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }
};

// The main function that calulates the shortest distance between every pair of vertices
double TSP(Graph& graph, vector<int>& path)
{
    int V = graph.V;
    vector<int> vertex_set;
    for (int i = 0; i < V; i++)
        vertex_set.push_back(i);

    // store minimum weight Hamiltonian Cycle
    double min_path_weight = DBL_MAX;

    do {
        // store current Path weight(cost)
        double current_path_weight = 0;

        // compute current path weight
        int k = vertex_set[0];
        for (int i = 0; i < V - 1; i++) {
            int j = vertex_set[i + 1];
            current_path_weight += graph.edges[k * V + j].weight;
            k = j;
        }
        current_path_weight += graph.edges[k * V + vertex_set[0]].weight;

        // update minimum
        min_path_weight = min(min_path_weight, current_path_weight);
    } while (next_permutation(vertex_set.begin(), vertex_set.end()));

    return min_path_weight;
}

// Driver program to test above functions
int main()
{
    // create a graph
    int V = 4;
    Graph graph(V, V * (V - 1));

    // Example graph
    // (0)--10--(1)--15--(2)--20--(3)--12--(0)
    graph.add_edge(0, 1, 10);
    graph.add_edge(0, 3, 12);
    graph.add_edge(1, 2, 15);
    graph.add_edge(2, 3, 20);

    vector<int> path;
    double min_path_weight = TSP(graph, path);

    cout << "Minimum path weight: " << min_path_weight << endl;

    return 0;
}
