#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// BFS traversal from a given source node 's'
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};

    // Create a queue for BFS traversal
    struct Node* queue = createNode(startVertex);

    // Mark the current node as visited and add into queue
    visited[startVertex] = 1;

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (queue != NULL) {
        int currentVertex = queue->data;

        // Remove a vertex from queue and print it
        printf("%d ", currentVertex);
        struct Node* temp = queue;
        queue = queue->next;
        free(temp);


        // Get all adjacent vertices of the dequeued vertex s.
        // If an adjacent has not been visited, then mark it visited and enqueue it
        struct Node* adj = graph->adjList[currentVertex];
        while (adj != NULL) {
            int adjVertex = adj->data;
            if (visited[adjVertex] == 0) {
                struct Node* newNode = createNode(adjVertex);
                newNode->next = queue;
                queue = newNode;
                visited[adjVertex] = 1;
            }
            adj = adj->next;
        }
    }
}

int main() {
    int N, M, i;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &N, &M);

    struct Graph* graph = createGraph(N);

    for (i = 1; i <= M; i++) {
        int u, v;
        printf("Enter edge No. %d: ", i);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    BFS(graph, s);

    return 0;
}
