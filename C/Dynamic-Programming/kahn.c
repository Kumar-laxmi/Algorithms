#include <stdio.h>
#include <stdlib.h>

// Struct to represent a graph
struct Graph {
    int V;
    int** adj;
};

// Function to create a new graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for adjacency matrix
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
}

// Function to perform topological sort
void topologicalSort(struct Graph* graph) {
    int V = graph->V;

    // Array to store the in-degree of vertices
    int in_degree[V];
    for (int i = 0; i < V; i++) {
        in_degree[i] = 0;
    }

    // Calculate the in-degree of each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph->adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    // Create a queue and enqueue all vertices with in-degree 0
    int queue[V];
    int front = 0;
    int rear = 0;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int cnt = 0;
    int topOrder[V];
    while (front != rear) {
        int u = queue[front++];
        topOrder[cnt++] = u;

        // Decrease in-degree of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph->adj[u][v] == 1) {
                if (--in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Check if there was a cycle
    if (cnt != V) {
        printf("Cycle is present in the graph\n");
        return;
    }

    // Print the topological order
    printf("Topological Sort: ");
    for (int i = 0; i < cnt; i++) {
        printf("%d ", topOrder[i]);
    }
}

int main() {
    int V = 6;
    struct Graph* mygraph = createGraph(V);

    addEdge(mygraph, 5, 2);
    addEdge(mygraph, 5, 0);
    addEdge(mygraph, 4, 0);
    addEdge(mygraph, 4, 1);
    addEdge(mygraph, 2, 3);
    addEdge(mygraph, 3, 1);

    printf("Topological Sort function will run now\n");
    topologicalSort(mygraph);

    return 0;
}
