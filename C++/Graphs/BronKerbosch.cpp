/*
 *   The Bron-Kerbosch is a algorithm to find all maximal cliques (complete subgraphs) in an undirected graph.
 *   Clique: Set of vertices such that every pair of vertices is connected by an edge.
 *   Maximal Clique: A clique is maximal if it cannot be extended by adding another vertex in the graph.
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void bronKerbosch(set<int>& clique, set<int>& potential, set<int>& excluded, const vector<vector<int>>& graph) {
    if (potential.empty() && excluded.empty()) {
        cout << "Maximal Clique: ";
        for (int vertex : clique) {
            cout << vertex << " ";
        }
        cout << endl;
        return;
    }

    set<int> potentialCopy = potential;
    for (int vertex : potentialCopy) {
        set<int> newClique = clique;
        newClique.insert(vertex);
        set<int> newPotential;
        set<int> newExcluded;

        for (int neighbor : potential) {
            if (graph[vertex][neighbor] == 1) {
                newPotential.insert(neighbor);
            }
        }
        for (int neighbor : excluded) {
            if (graph[vertex][neighbor] == 1) {
                newExcluded.insert(neighbor);
            }
        }

        bronKerbosch(newClique, newPotential, newExcluded, graph);

        potential.erase(vertex);
        excluded.insert(vertex);
    }
}

int main() {
    int N;
    cout << "Enter the number of vertices: ";
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    set<int> clique, potential, excluded;
    for (int i = 0; i < N; ++i) {
        potential.insert(i);
    }

    bronKerbosch(clique, potential, excluded, graph);

    return 0;
}
