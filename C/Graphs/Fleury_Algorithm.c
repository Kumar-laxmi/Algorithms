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
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Graph {
    int V; // No. of vertices
    int* adj;
};

// Constructor
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int*)malloc(V * V * sizeof(int));
    return graph;
}

// Destructor
void destroyGraph(struct Graph* graph) {
    free(graph->adj);
    free(graph);
}

// Function to add edges
void addEdge(struct Graph* graph, int source, int destination) {
    graph->adj[source * graph->V + destination] = 1;
    graph->adj[destination * graph->V + source] = 1;
}

// Function to remove edge (source, destination) from the graph
void removeEdge(struct Graph* graph, int source, int destination) {
    graph->adj[source * graph->V + destination] = 0;
    graph->adj[destination * graph->V + source] = 0;
}

// A DFS based function to count reachable vertices from destination
int DFSCount(struct Graph* graph, int destination, bool* visited) {
    // Mark the current node as visited
    visited[destination] = true;
    int count = 1;

    // Recursion for all vertices adjacent to this vertex
    for (int i = 0; i < graph->V; ++i) {
        if (graph->adj[destination * graph->V + i] && !visited[i]) {
            count += DFSCount(graph, i, visited);
        }
    }

    return count;
}

// The function to check if edge (source, destination) can be considered as next edge in Euler Trail
bool isValidNextEdge(struct Graph* graph, int source, int destination) {
    // The edge (source, destination) is valid in one of the following two cases:

    // 1) If destination is the only adjacent vertex of source
    int count = 0; // To store count of adjacent vertices
    for (int i = 0; i < graph->V; ++i) {
        if (graph->adj[source * graph->V + i]) {
            count++;
        }
    }
    if (count == 1) {
        return true;
    }

    // 2) If there are multiple adjacents, then source-destination is not a bridge.
    // Do the following steps to check if (source, destination) is a bridge:

    // 2.a) Count of vertices reachable from source
    bool visited[graph->V];
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = false;
    }
    int count1 = DFSCount(graph, source, visited);

    // 2.b) Remove edge (source, destination) and after removing the edge, count vertices reachable from source
    removeEdge(graph, source, destination);
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = false;
    }
    int count2 = DFSCount(graph, source, visited);

    // 2.c) Add the edge back to the graph
    addEdge(graph, source, destination);

    // 2.d) If count1 is greater, then the edge (source, destination) is a bridge
    return (count1 > count2) ? false : true;
}

// The main function that prints the Eulerian Trail.
// It first finds an odd degree vertex (if there is any) and then calls printEulerUtil() to print the path.
void printEulerTrail(struct Graph* graph) {
    // Find a vertex with an odd degree
    int source = 0;
    for (int i = 0; i < graph->V; ++i) {
        // Condition to check the odd degree
        int count = 0;
        for (int j = 0; j < graph->V; ++j) {
            if (graph->adj[i * graph->V + j]) {
                count++;
            }
        }
        if (count & 1) {
            source = i;
            break;
        }
    }

    // Print trail starting from the odd vertex
    printf("%d ", source);
    while (true) {
        int destination = -1;
        for (int i = 0; i < graph->V; ++i) {
            if (graph->adj[source * graph->V + i] && isValidNextEdge(graph, source, i)) {
                destination = i;
                break;
            }
        }
        if (destination == -1) {
            break;
        }
        printf("%d ", destination);
        removeEdge(graph, source, destination);
        source = destination;
    }
    printf("\n");
}

// Driver program
int main() {
    int V; // No. of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    struct Graph* g = createGraph(V);

    int E; // No. of edges
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    // Taking input from the user
    printf("Enter the edges in the format (source destination)\n");
    for (int i = 0; i < E; ++i) {
        int source, destination;
        printf("Source %d: ", i + 1);
        scanf("%d", &source);
        printf("Destination %d: ", i + 1);
        scanf("%d", &destination);
        addEdge(g, source, destination);
    }

    // Printing the final result after analyzing
    printf("\nResult of Fleury Algorithm: ");
    printEulerTrail(g);
    printf("\n");

    destroyGraph(g);

    return 0;
}
