
// hamiltonian_cycle Using Backtracking


#include <iostream>
#include <vector>
using namespace std;

const int N = 100; //max number of vertices in the graph

vector<int> g[N]; //adjacency list representation of the graph
bool visited[N]; //keep track of visited vertices
vector<int> path; //keep track of the current path

bool hamiltonian_cycle(int u) {
    if (path.size() == N) {
        if (path[0] == u) {
            return true;
        }
        else
        return false;
    }

    for (int v : g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);

            if (hamiltonian_cycle(v)) {
                return true;
            }

            visited[v] = false;
            path.pop_back();
        }
    }

    return false;
}



int main() {
    //initialize the graph with a Hamiltonian cycle
    g[0].push_back(1);
    g[1].push_back(2);
    g[2].push_back(3);
    g[3].push_back(0);
    g[3].push_back(4);
    g[4].push_back(5);
    g[5].push_back(3);

    path.push_back(0); //start with vertex 0
    visited[0] = true;

    if (hamiltonian_cycle(0)) {
        //if a Hamiltonian cycle is found, print the path
        for (int v : path) {
            cout << v << " ";
        }
    } else {
        cout << "No Hamiltonian cycle found.";
    }

    return 0;
}
