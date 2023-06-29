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

                    Edge 0-6 with weight 7 included in Minimum Spanning Tree (MST)
                    Edge 1-2 with weight 11 included in Minimum Spanning Tree (MST)
                    Edge 2-4 with weight 4 included in Minimum Spanning Tree (MST)
                    Edge 3-5 with weight 10 included in Minimum Spanning Tree (MST)
                    Edge 6-7 with weight 3 included in Minimum Spanning Tree (MST)
                    Edge 7-8 with weight 6 included in Minimum Spanning Tree (MST)
                    Edge 4-8 with weight 10 included in Minimum Spanning Tree (MST)
                    Edge 5-8 with weight 16 included in Minimum Spanning Tree (MST)

                    Weight of Minimum Spanning Tree (MST) is 67





*/



// C+ IMPLEMENTATION


// Boruvka's algorithm to find Minimum Spanning Tree of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int u, v, w;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v, int w) {
    graph->edge[u].u = u;
    graph->edge[u].v =v;
    graph->edge[u].w = w;
}

// A utility function to find the set of an element i (uses path compression technique)
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// A function that does union of two sets of x and y (uses union by rank)
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// The main function to construct MST using Boruvka's algorithm
void boruvkaMST(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    struct Edge* edge = graph->edge;

    int* parent = (int*)malloc(V * sizeof(int));
    int* rank = (int*)malloc(V * sizeof(int));
    struct Edge* minimum = (struct Edge*)malloc(V * sizeof(struct Edge));

    int numberOfTrees = V;
    int MSTWeight = 0;

    // Create V subsets with single elements
    for (int node = 0; node < V; node++) {
        parent[node] = node;
        rank[node] = 0;
        minimum[node].w = -1;
    }

    // Keep combining components (or sets) until all components are not combined into a single MST
    while (numberOfTrees > 1) {
        // Traverse through all edges and update cheapest of every component
        for (int i = 0; i < E; i++) {
            int setA = find(parent, edge[i].u);
            int setB = find(parent, edge[i].v);

            if (setA != setB) {
                if (minimum[setA].w == -1 || edge[i].w < minimum[setA].w)
                    minimum[setA] = edge[i];

                if (minimum[setB].w == -1 || edge[i].w < minimum[setB].w)
                    minimum[setB] = edge[i];
            }
        }

        // Consider the above-picked cheapest edges and add them to MST
        for (int node = 0; node < V; node++) {

            if (minimum[node].w != -1) {
                int setA = find(parent, minimum[node].u);
                int setB = find(parent, minimum[node].v);

                if (setA != setB) {
                    MSTWeight += minimum[node].w;
                    unionSets(parent, rank, setA, setB);
                    printf("Edge %d-%d with weight %d included in Minimum Spanning Tree (MST)\n", minimum[node].u, minimum[node].v, minimum[node].w);
                    numberOfTrees--;
                }
            }
        }

        // Reset cheapest array
        for (int node = 0; node < V; node++) {
            minimum[node].w = -1;
        }
    }

    printf("\nWeight of Minimum Spanning Tree (MST) is %d\n", MSTWeight);
}

int main() {
    int V = 9; // Number of vertices
    int E = 15; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges to the graph    
    addEdge(graph,0, 1, 6);
    addEdge(graph,0, 6, 7);
    addEdge(graph,1, 6, 15);
    addEdge(graph,1, 7, 27);
    addEdge(graph,1, 2, 11);
    addEdge(graph,2, 3, 12);
    addEdge(graph,2, 4, 4);
    addEdge(graph,3, 4, 18);
    addEdge(graph,3, 5, 10);
    addEdge(graph,4, 5, 25);
    addEdge(graph,4, 7, 3);
    addEdge(graph,4, 8, 10);
    addEdge(graph,5, 8, 16);
    addEdge(graph,6, 7, 3);
    addEdge(graph,7, 8, 6);

    // Find and print the Minimum Spanning Tree
    boruvkaMST(graph);

    return 0;
}