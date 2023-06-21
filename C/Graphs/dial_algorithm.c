#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->weight = weight;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void shortestPath(struct Graph* graph, int src, int W) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int));
    bool* inQueue = (bool*)malloc(V * sizeof(bool));
    int* bucket = (int*)malloc((W * V + 1) * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        inQueue[i] = false;
    }

    dist[src] = 0;
    bucket[rear++] = src;
    inQueue[src] = true;

    while (front != rear) {
        int u = bucket[front++];
        inQueue[u] = false;

        struct Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;

                if (!inQueue[v]) {
                    bucket[rear++] = v;
                    inQueue[v] = true;
                }
            }

            temp = temp->next;
        }
    }

    printf("Distance from source:\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    free(dist);
    free(inQueue);
    free(bucket);
}

int main() {
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    shortestPath(graph, 0, 14);

    return 0;
}
