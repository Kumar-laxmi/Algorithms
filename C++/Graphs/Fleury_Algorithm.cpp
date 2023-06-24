/*
------------------------------------- Fleury’s Algorithm -------------------------------------

Approach:-
1. Start with any vertex in the graph.

2. While there are unused edges in the graph, do the following steps:
    a. Choose any unused edge connected to the current vertex. It doesn't matter which one you choose.
    b. If removing the chosen edge doesn't disconnect the graph, go to the vertex at the other end of the chosen edge.
    c. If removing the chosen edge disconnects the graph, backtrack to the previous vertex that still has unused edges and choose a different edge.
    d. Repeat steps (a) to (c) until you can no longer choose any unused edges from the current vertex.

3. The algorithm terminates when you have traversed all the edges of the graph.

4. If all the vertices in the graph have even degrees, you will end up with an Eulerian circuit, which is a closed path that visits each edge exactly once.

5. If exactly two vertices in the graph have odd degrees, you will end up with an Eulerian path, which is a path that starts and ends at different vertices and visits each edge exactly once.
*/

// Program starts
#include <bits/stdc++.h>

using namespace std;

// A class that represents an undirected graph
class Graph {
	int V; // No. of vertices
	list<int>* adj;

public:
	// Constructor
	Graph(int V) {
		this->V = V;
		adj = new list<int>[V];
	}

    // Destructor
	~Graph() {
        delete[] adj;
    }

	// functions to add edges
	void addEdge(int source, int destination) {
		adj[source].push_back(destination);
		adj[destination].push_back(source);
	}

    // This function removes edge source-destination from graph. It removes the edge by replacing adjacent vertex value with -1.
	void removeEdge(int source, int destination) {
        // Find destination in adjacency list of source and replace it with -1
        list<int>::iterator idestination = find(adj[source].begin(), adj[source].end(), destination);
        *idestination = -1;

        // Find source in adjacency list of destination and replace it with -1
        list<int>::iterator isource = find(adj[destination].begin(), adj[destination].end(), source);
        *isource = -1;
    }

    // The main function that print Eulerian Trail. It first finds an odd degree vertex (if there is any) and then calls printEulerUtil() to print the path
	void printEulerTrail() {
        // Find a vertex with odd degree
        int source = 0;
        for (int i = 0; i < V; i++) {
            // Condition to check the odd degree
            if (adj[i].size() & 1) {
                source = i;
                break;
            }
        }

        // Print trail starting from odd vertices
        printEulerUtil(source);
        cout << endl;
    }

    // Print Euler trail starting from vertex source
	void printEulerUtil(int source) {
        // Recursion for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[source].begin(); i != adj[source].end(); ++i) {
            int destination = *i;

            // If edge source-destination is not removed and it's a valid next edge
            if (destination != -1 && isValidNextEdge(source, destination)) {
                cout << source << "-" << destination << " ";
                removeEdge(source, destination);
                printEulerUtil(destination);
            }
        }
    }

    // A DFS based function to count reachable vertices from destination
	int DFSCount(int destination, bool visited[]) {
        // Mark the current node as visited
        visited[destination] = true;
        int count = 1;

        // Recursion for all vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[destination].begin(); i != adj[destination].end(); ++i) {
            if (*i != -1 && !visited[*i]) {
                count += DFSCount(*i, visited);
            }
        }

        return count;
    }

    // The function to check if edge source-destination can be considered as next edge in Euler Trail
	bool isValidNextEdge(int source, int destination) {
        // The edge source-destination is valid in one of the following two

        // cases:
        // 1) If destination is the only adjacent vertex of source
        int count = 0; // To store count of adjacent vertices
        list<int>::iterator i;
        for (i = adj[source].begin(); i != adj[source].end(); ++i) {
            if (*i != -1) {
                count++;
            }
        }
        if (count == 1) {
            return true;
        }

        // 2) If there are multiple adjacents, then source-destination is not a bridge Do following steps to check if source-destination is a bridge
        // 2.a) count of vertices reachable from source
        bool visited[V];
        memset(visited, false, V);
        int count1 = DFSCount(source, visited);

        // 2.b) Remove edge (source, destination) and after removing the edge, count vertices reachable from source
        removeEdge(source, destination);
        memset(visited, false, V);
        int count2 = DFSCount(source, visited);

        // 2.c) Add the edge back to the graph
        addEdge(source, destination);

        // 2.d) If count1 is greater, then edge (source, destination) is a bridge
        return (count1 > count2) ? false : true;
    }
};

// Driver program
int main() {
    int V; // No. of vertices
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    Graph g(V);

    int E; // No. of edges
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    // Taking input from the user
    cout << "Enter the edges in the format (source destination)" << endl;
    for (int i = 0; i < E; i++) {
        int source, destination;
        cout << "Source " << i+1 << " : ";
        cin >> source;
        cout << "Destination " << i+1 << " : ";
        cin >> destination;
        g.addEdge(source, destination);
    }

    // Printing the final result after analysing
    cout << "\nResult of Fleury Algorithm : ";
    g.printEulerTrail();
    cout << endl;

	return 0;
}
