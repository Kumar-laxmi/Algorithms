/*Kruskals Algorithm
    Author: Phalesh Kolpe
    Kruskals algorithm is used to Find the MST(Minimum Spaning Tree) of a graph it considers the edges and weight of the edge
    Step 1: Sort all edges in increasing order of their edge weights.
    Step 2: Pick the smallest edge.
    Step 3: Check if the new edge creates a cycle or loop in a spanning tree.
    Step 4: If it doesn’t form the cycle, then include that edge in MST. Otherwise, discard it.
    Step 5: Repeat from step 2 until it includes |V| - 1 edges in MST.
    Expected Output Of the code:
    Enter the number of vertices: 
    Enter the number of edges:
    Enter the details of each edge (source, destination, weight): 
    Give input for the above line in the following manner
    0 1 7
    where 0 is the soucre of edge 1 is the destination and 7 is the weight of the edge*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int v, e;
    struct edge* edge;
};

// Function to create a graph
struct Graph* createGraph(int v, int e) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->e = e;
    graph->edge = (struct edge*)malloc(e * sizeof(struct edge));
    return graph;
}

// Function to find the parent of a node
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two sets
void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}

// Function to compare two edges based on their weights
int compareedges(const void* a, const void* b) {
    struct edge* edge1 = (struct edge*)a;
    struct edge* edge2 = (struct edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to apply Kruskal's algorithm and find the minimum spanning tree
void kruskalMST(struct Graph* graph) {
    int v = graph->v;
    struct edge result[v];
    int e = 0;
    int i = 0;

    // Sort the edges in ascending order of their weights
    qsort(graph->edge, graph->e, sizeof(graph->edge[0]), compareedges);

    // Allocate memory for parent array
    int* parent = (int*)malloc(v * sizeof(int));

    // Initialize parent array with -1
    for (int v = 0; v < v; v++)
        parent[v] = -1;

    // Process each edge and add it to the MST if it does not form a cycle
    while (e < v - 1 && i < graph->e) {
        struct edge nextedge = graph->edge[i++];

        int x = findParent(parent, nextedge.src);
        int y = findParent(parent, nextedge.dest);

        if (x != y) {
            result[e++] = nextedge;
            unionSets(parent, x, y);
        }
    }

    // Print the edges of the MST
    printf("Edges in the constructed MST:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d  =>  %d\n", result[i].src, result[i].dest, result[i].weight);

    free(parent);
}

int main() {
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    struct Graph* graph = createGraph(v, e);

    printf("Enter the details of each edge (source, destination, weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    kruskalMST(graph);

    return 0;
}
