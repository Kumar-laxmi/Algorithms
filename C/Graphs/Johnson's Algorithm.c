#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    int distance[MAX_VERTICES];
    int predecessor[MAX_VERTICES];
} BellmanFordResult;

typedef struct {
    int distance[MAX_VERTICES];
} DijkstraResult;

// Function to initialize the graph
void initializeGraph(int graph[][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(int graph[][MAX_VERTICES], int source, int destination, int weight) {
    graph[source][destination] = weight;
}

// Function to perform the Bellman-Ford algorithm
BellmanFordResult bellmanFord(int graph[][MAX_VERTICES], int numVertices, int source) {
    BellmanFordResult result;
    
    // Initialize distance and predecessor arrays
    for (int i = 0; i < numVertices; i++) {
        result.distance[i] = INF;
        result.predecessor[i] = -1;
    }
    result.distance[source] = 0;
    
    // Relax all edges (numVertices - 1) times
    for (int i = 1; i <= numVertices - 1; i++) {
        for (int u = 0; u < numVertices; u++) {
            for (int v = 0; v < numVertices; v++) {
                if (graph[u][v] != INF && result.distance[u] != INF && result.distance[u] + graph[u][v] < result.distance[v]) {
                    result.distance[v] = result.distance[u] + graph[u][v];
                    result.predecessor[v] = u;
                }
            }
        }
    }
    
    // Check for negative weight cycles
    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] != INF && result.distance[u] != INF && result.distance[u] + graph[u][v] < result.distance[v]) {
                result.distance[v] = -INF;
                result.predecessor[v] = -1;
            }
        }
    }
    
    return result;
}

// Function to perform Dijkstra's algorithm
DijkstraResult dijkstra(int graph[][MAX_VERTICES], int numVertices, int source) {
    DijkstraResult result;
    bool visited[MAX_VERTICES];
    
    // Initialize distance and visited arrays
    for (int i = 0; i < numVertices; i++) {
        result.distance[i] = INF;
        visited[i] = false;
    }
    result.distance[source] = 0;
    
    // Find the shortest path for all vertices
    for (int i = 0; i < numVertices - 1; i++) {
        int minDistance = INF;
        int minIndex = -1;
        
        // Find the vertex with minimum distance
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && result.distance[j] <= minDistance) {
                minDistance = result.distance[j];
                minIndex = j;
            }
        }
        
        // Mark the vertex as visited
        visited[minIndex] = true;
        
        // Update the distance of adjacent vertices
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[minIndex][v] != INF && result.distance[minIndex] != INF && result.distance[minIndex] + graph[minIndex][v] < result.distance[v]) {
                result.distance[v] = result.distance[minIndex] + graph[minIndex][v];
            }
        }
    }
    
    return result;
}

// Function to perform Johnson's algorithm
void johnsonsAlgorithm(int graph[][MAX_VERTICES], int numVertices) {
    // Add a new vertex and edges with weight 0 to all other vertices
    int augmentedGraph[MAX_VERTICES + 1][MAX_VERTICES + 1];
    initializeGraph(augmentedGraph, numVertices + 1);
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            augmentedGraph[i][j] = graph[i][j];
        }
    }
    
    for (int i = 0; i < numVertices; i++) {
        augmentedGraph[numVertices][i] = 0;
    }
    
    // Run Bellman-Ford algorithm to get the shortest paths from the new vertex to all other vertices
    BellmanFordResult bellmanFordResult = bellmanFord(augmentedGraph, numVertices + 1, numVertices);
    
    // Check for negative weight cycles
    if (bellmanFordResult.distance[numVertices] == -INF) {
        printf("Graph contains negative weight cycle. Johnson's algorithm cannot be applied.\n");
        return;
    }
    
    // Remove the added vertex and edges from the augmented graph
    int newGraph[MAX_VERTICES][MAX_VERTICES];
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            newGraph[i][j] = augmentedGraph[i][j];
        }
    }
    
    // Recalculate the edge weights using the distance values from Bellman-Ford algorithm
    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            if (newGraph[u][v] != INF) {
                newGraph[u][v] = newGraph[u][v] + bellmanFordResult.distance[u] - bellmanFordResult.distance[v];
            }
        }
    }
    
    // Run Dijkstra's algorithm for each vertex to get the shortest paths
    for (int u = 0; u < numVertices; u++) {
        DijkstraResult dijkstraResult = dijkstra(newGraph, numVertices, u);
        
        // Print the shortest paths from vertex u
        printf("Shortest paths from vertex %d:\n", u);
        for (int v = 0; v < numVertices; v++) {
            if (dijkstraResult.distance[v] == INF) {
                printf("Vertex %d is unreachable\n", v);
            } else {
                printf("Vertex %d: Distance = %d, Predecessor = %d\n", v, dijkstraResult.distance[v], u);
            }
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    int graph[MAX_VERTICES][MAX_VERTICES];
    initializeGraph(graph, numVertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &source, &destination, &weight);
        addEdge(graph, source, destination, weight);
    }
    
    johnsonsAlgorithm(graph, numVertices);
    
    return 0;
}
