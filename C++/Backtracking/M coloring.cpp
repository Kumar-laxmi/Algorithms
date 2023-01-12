// ================== Problem Statement =============

/*
the m-coloring problem, which is a generalization of the classic graph 
coloring problem. In the m-coloring problem, we are given an undirected 
graph and a positive integer m, and we are asked to find a valid coloring 
of the graph such that no two adjacent vertices share the same color and 
no more than m colors are used in total.
*/

#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int num_vertices) {
        adj_list.resize(num_vertices);
    }

    void addEdge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    const vector<int>& getAdjList(int vertex) const {
        return adj_list[vertex];
    }

    int getNumVertices() const {
        return adj_list.size();
    }

private:
    vector<vector<int>> adj_list;
};

bool isSafe(const Graph& g, vector<int>& colors, int vertex, int color) {
    for (int adj_vertex : g.getAdjList(vertex)) {
        if (colors[adj_vertex] == color) {
            return false;
        }
    }
    return true;
}

bool mColoringUtil(const Graph& g, vector<int>& colors, int m, int vertex) {
    if (vertex == g.getNumVertices()) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(g, colors, vertex, c)) {
            colors[vertex] = c;

            if (mColoringUtil(g, colors, m, vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

bool mColoring(const Graph& g, int m) {
    vector<int> colors(g.getNumVertices(), 0);

    if (mColoringUtil(g, colors, m, 0) == false) {
        cout << "No solution exists." << endl;
        return false;
    }
    for (int i = 0; i < g.getNumVertices(); i++) {
        cout << "Vertex " << i << " has color " << colors[i] << endl;
    }
    return true;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    int m = 3;
    mColoring(g, m);
    return 0;
}
