#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find the parent of a node in a subset
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the number of connected components
int countComponents(struct Graph* graph) {
    int V = graph->V;
    struct Edge* edges = graph->edges;

    // Create V subsets with single elements
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Iterate through all edges of the graph, perform union-find
    for (int e = 0; e < graph->E; e++) {
        int x = find(subsets, edges[e].src);
        int y = find(subsets, edges[e].dest);
        if (x != y) {
            unionSets(subsets, x, y);
        }
    }

    // Count the number of unique parents in subsets
    int count = 0;
    for (int v = 0; v < V; v++) {
        if (subsets[v].parent == v) {
            count++;
        }
    }

    free(subsets);
    return count;
}

int main() {
    // Example graph
    int V = 6;  // Number of vertices
    int E = 4;  // Number of edges

    struct Graph* graph = createGraph(V, E);

    // Add edges to the graph
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;

    graph->edges[1].src = 2;
    graph->edges[1].dest = 3;

    graph->edges[2].src = 4;
    graph->edges[2].dest = 5;

    graph->edges[3].src = 3;
    graph->edges[3].dest = 4;

    int components = countComponents(graph);
    printf("Number of connected components: %d\n", components);

    free(graph->edges);
    free(graph);

    return 0;
}
