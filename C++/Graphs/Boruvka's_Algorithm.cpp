/*
Boruvka's Algorithm is mainly used to find or derive a Minimum Spanning Tree of an edge-weighted undirected graph.

It is a greedy algorithm, first given in 1926 by Otakar Boruvka, a Czech mathematician as a method of constructing an efficient electricity network.

Boruvka's Algorithm works for a linked network with distinct edge weights, implying a unique MST. The cheapest edge from one node to another in the graph is determined first, without consideration for previously inserted edges. The process of merging these grouping continues until MST is completed. A disjoint-set data structure is used to track MST components.

It is also applicable to unconnected graphs where a forest of trees with shortest possible spread is formed. Because our edge comparison uses nodes when weights are identical, repeated edge weights are permitted.



BORUVKA'S ALGORITHM

1. The idea is to separate all nodes at first, then process each node one by one by connecting nodes together from different components.

2. For each node, we find edge with least weight and connect them to form a component. Then we move to the next vertex.

3. After this, for each component, we choose the smallest or cheapest edge so that we get disconnected components of graphs. Then we combine the graph using the above process. If any loop or cycle found, we ignore those edges.

4. After getting all the disconnected componenets, we try connecting them following the above steps. Each repetition of this process reduces the number of nodes. Within each connected components of the graph, to atmost half of this former value, so after logarithmically many repetitions, the process finishes.

5. At the end, the weight of edges we add from the Minimum Spanning Tree.




TIME COMPLEXITY: O(E * log(N))  E = Number of Edges   N = Number of Nodes

SPACE COMPLEXITY: O(N)


            SAMPLE INPUT:

                   { 0 - 1 } - 6
                   { 0 - 6 } - 7
                   { 1 - 2 } - 11
                   { 1 - 6 } - 15
                   { 1 - 7 } - 27
                   { 2 - 4 } - 4
                   { 2 - 3 } - 12
                   { 3 - 4 } - 18
                   { 3 - 5 } - 7
                   { 4 - 5 } - 25
                   { 4 - 7 } - 3
                   { 4 - 8 } - 10
                   { 5 - 8 } - 16
                   { 6 - 7 } - 3
                   { 7 - 8 } - 6

            

            SAMPLE OUTPUT:

                    Edge 0-1 with weight 6 included in Minimum Spanning Tree
                    Edge 2-4 with weight 4 included in Minimum Spanning Tree
                    Edge 3-5 with weight 10 included in Minimum Spanning Tree
                    Edge 4-7 with weight 3 included in Minimum Spanning Tree
                    Edge 6-7 with weight 3 included in Minimum Spanning Tree
                    Edge 7-8 with weight 6 included in Minimum Spanning Tree
                    Edge 0-6 with weight 7 included in Minimum Spanning Tree
                    Edge 2-3 with weight 12 included in Minimum Spanning Tree

                    Weight of Minimum Spanning Tree is 51



*/



// C++ IMPLEMENTATION

// Boruvka's algorithm to find Minimum Spanning Tree of a given connected, undirected and weighted graph
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph {
	int V; // No. of vertices
	vector<vector<int> >graph; // Default dictionary to store graph

	// A utility function to find set of an element i (uses path compression technique)
	int find(vector<int>& parent, int i){
		if (parent[i] == i) {
			return i;
		}
		return find(parent, parent[i]);
	}

	// A function that does union of two sets of x and y (uses union by rank)
	void unionSet(vector<int>& parent, vector<int>& rank,
				int x, int y){
		int rootX = find(parent, x);
		int rootY = find(parent, y);

		// Attach smaller rank tree under root of high rank tree (Union by Rank)
		if (rank[rootX] < rank[rootY]) {
			parent[rootX] = rootY;
		}
		else if (rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		// If ranks are same, then make one as root and increment its rank by one
		else {
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}

public:
	Graph(int vertices)	{
		V = vertices;
		graph = vector<vector<int> >();
	}

	// Function to add an edge to graph
	void addEdge(int u, int v, int w){
		graph.push_back({ u, v, w });
	}

	// The main function to construct MST using Boruvka's algorithm
	void boruvkaMST(){
		vector<int> parent(V);

		// An array to store index of the cheapest edge of subset. It store [u,v,w] for each component
		vector<int> rank(V);
		vector<vector<int> > minimum(V, vector<int>(3, -1));

		// Initially there are V different trees. Finally there will be one tree that will be MST
		int numberOfTrees = V;
		int MSTWeight = 0;

		// Create V subsets with single elements
		for (int node = 0; node < V; node++) {
			parent[node] = node;
			rank[node] = 0;
		}

		// Keep combining components (or sets) until all components are not combined into single MST
		while (numberOfTrees > 1) {
			// Traverse through all edges and update cheapest of every component
			for (int i = 0; i < graph.size(); i++) {
				// Find components (or sets) of two corners of current edge
				int u = graph[i][0], v = graph[i][1],
					w = graph[i][2];
				int setA = find(parent, u),
					setB = find(parent, v);

				// If two corners of current edge belong to same set, ignore current edge. Else check if current edge is closer to previous cheapest edges of set1 and set2
				if (setA != setB) {
					if (minimum[setA][2] == -1
						|| minimum[setA][2] > w) {
						minimum[setA] = { u, v, w };
					}
					if (minimum[setB][2] == -1
						|| minimum[setB][2] > w) {
						minimum[setB] = { u, v, w };
					}
				}
			}

			// Consider the above picked cheapest edges and add them to MST
			for (int node = 0; node < V; node++) {
				// Check if cheapest for current set exists
				if (minimum[node][2] != -1) {
					int u = minimum[node][0],
						v = minimum[node][1],
						w = minimum[node][2];
					int setA = find(parent, u),
						setB = find(parent, v);
					if (setA != setB) {
						MSTWeight += w;
						unionSet(parent, rank, setA, setB);
						printf("Edge %d-%d with weight %d included in Minimum Spanning Tree (MST)\n", u, v, w);
						numberOfTrees--;
					}
				}
			}
			for (int node = 0; node < V; node++) {
				// Reset cheapest array
				minimum[node][2] = -1;
			}
		}
		printf("\nWeight of Minimum Spanning Tree (MST) is %d\n", MSTWeight);
	}
};

int main(){
	Graph g(9);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 6, 7);
    g.addEdge(1, 6, 15);
    g.addEdge(1, 7, 27);
    g.addEdge(1, 2, 11);
    g.addEdge(2, 3, 12);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 18);
    g.addEdge(3, 5, 10);
    g.addEdge(4, 5, 25);
    g.addEdge(4, 7, 3);
    g.addEdge(4, 8, 10);
    g.addEdge(5, 8, 16);
    g.addEdge(6, 7, 3);
    g.addEdge(7, 8, 6);

	g.boruvkaMST();
}