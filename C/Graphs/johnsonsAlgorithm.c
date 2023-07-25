#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

struct Edge
{
    int source;
    int destination;
    int weight;
};

struct Graph
{
    int V;
    int E;
    struct Edge *edges;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

void addEdge(struct Graph *graph, int source, int destination, int weight)
{
    graph->edges[graph->E].source = source;
    graph->edges[graph->E].destination = destination;
    graph->edges[graph->E].weight = weight;
    graph->E++;
}

bool bellmanFord(struct Graph *graph, int source, int *distances)
{
    int V = graph->V;
    int E = graph->E;

    for (int i = 0; i < V; ++i)
        distances[i] = INF;
    distances[source] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            int u = graph->edges[j].source;
            int v = graph->edges[j].destination;
            int w = graph->edges[j].weight;

            if (distances[u] != INF && distances[u] + w < distances[v])
                distances[v] = distances[u] + w;
        }
    }

    // Check for negative cycles
    for (int j = 0; j < E; ++j)
    {
        int u = graph->edges[j].source;
        int v = graph->edges[j].destination;
        int w = graph->edges[j].weight;

        if (distances[u] != INF && distances[u] + w < distances[v])
            return false;
    }

    return true;
}

void dijkstra(struct Graph *graph, int source, int *distances)
{
    int V = graph->V;
    int E = graph->E;

    for (int i = 0; i < V; ++i)
        distances[i] = INF;
    distances[source] = 0;

    struct MinHeapNode
    {
        int v;
        int dist;
    };

    struct MinHeap
    {
        int size;
        int capacity;
        struct MinHeapNode *array;
    };

    struct MinHeap *createMinHeap(int capacity)
    {
        struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
        minHeap->size = 0;
        minHeap->capacity = capacity;
        minHeap->array = (struct MinHeapNode *)malloc(capacity * sizeof(struct MinHeapNode));
        return minHeap;
    }

    void swapMinHeapNodes(struct MinHeapNode * a, struct MinHeapNode * b)
    {
        struct MinHeapNode temp = *a;
        *a = *b;
        *b = temp;
    }

    void minHeapify(struct MinHeap * minHeap, int idx)
    {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < minHeap->size && minHeap->array[left].dist < minHeap->array[smallest].dist)
            smallest = left;

        if (right < minHeap->size && minHeap->array[right].dist < minHeap->array[smallest].dist)
            smallest = right;

        if (smallest != idx)
        {
            swapMinHeapNodes(&minHeap->array[idx], &minHeap->array[smallest]);
            minHeapify(minHeap, smallest);
        }
    }

    struct MinHeapNode extractMin(struct MinHeap * minHeap)
    {
        if (minHeap->size == 0)
        {
            struct MinHeapNode empty = {-1, -1};
            return empty;
        }

        struct MinHeapNode root = minHeap->array[0];
        struct MinHeapNode lastNode = minHeap->array[minHeap->size - 1];
        minHeap->array[0] = lastNode;

        --minHeap->size;
        minHeapify(minHeap, 0);

        return root;
    }

    void decreaseKey(struct MinHeap * minHeap, int v, int dist)
    {
        int i;
        for (i = 0; i < minHeap->size; ++i)
        {
            if (minHeap->array[i].v == v)
                break;
        }

        minHeap->array[i].dist = dist;

        while (i != 0 && minHeap->array[i].dist < minHeap->array[(i - 1) / 2].dist)
        {
            swapMinHeapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    bool isInMinHeap(struct MinHeap * minHeap, int v)
    {
        for (int i = 0; i < minHeap->size; ++i)
        {
            if (minHeap->array[i].v == v)
                return true;
        }
        return false;
    }

    void dijkstraAlgo(struct Graph * graph, int src, int *dist)
    {
        int V = graph->V;
        int V_heap = graph->V + 1; // Adding a dummy vertex to avoid index confusion

        struct MinHeap *minHeap = createMinHeap(V_heap);

        for (int v = 0; v < V_heap; ++v)
        {
            dist[v] = INF;
            minHeap->array[v].v = v;
            minHeap->array[v].dist = INF;
            minHeap->size++;
        }

        dist[src] = 0;
        decreaseKey(minHeap, src, 0);

        while (minHeap->size != 0)
        {
            struct MinHeapNode minHeapNode = extractMin(minHeap);
            int u = minHeapNode.v;

            struct Edge *edges = graph->edges;
            for (int i = 0; i < graph->E; ++i)
            {
                int v = edges[i].destination;
                int weight = edges[i].weight;

                if (dist[u] != INF && isInMinHeap(minHeap, v) && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    decreaseKey(minHeap, v, dist[v]);
                }
            }
        }
    }

    dijkstraAlgo(graph, source, distances);
}

void johnsonAlgorithm(struct Graph *graph)
{
    int V = graph->V;
    int E = graph->E;

    // Add a new vertex with zero-weight edges to all other vertices
    int newVertex = V;
    for (int i = 0; i < V; ++i)
        addEdge(graph, newVertex, i, 0);

    // Run Bellman-Ford algorithm to get the shortest paths from the new vertex
    int *h = (int *)malloc((V + 1) * sizeof(int));
    if (!bellmanFord(graph, newVertex, h))
    {
        printf("Graph contains a negative cycle. Johnson's algorithm cannot proceed.\n");
        return;
    }

    // Re-weight the edges
    for (int i = 0; i < E; ++i)
    {
        int u = graph->edges[i].source;
        int v = graph->edges[i].destination;
        int w = graph->edges[i].weight;

        graph->edges[i].weight = w + h[u] - h[v];
    }

    printf("Shortest distances between all pairs of vertices:\n");

    // Run Dijkstra's algorithm for each vertex to find the shortest paths
    for (int i = 0; i < V; ++i)
    {
        int *distances = (int *)malloc(V * sizeof(int));
        dijkstra(graph, i, distances);

        for (int j = 0; j < V; ++j)
        {
            // Update the distance by reverting the re-weighting
            distances[j] = distances[j] - h[i] + h[j];

            if (distances[j] == INF)
                printf("INF ");
            else
                printf("%d ", distances[j]);
        }

        printf("\n");
        free(distances);
    }

    free(h);
}

void freeGraph(struct Graph *graph)
{
    free(graph->edges);
    free(graph);
}

int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph *graph = createGraph(V, E);

    printf("Enter edge information (source, destination, weight) for each edge:\n");
    for (int i = 0; i < E; ++i)
    {
        int source, destination, weight;
        scanf("%d%d%d", &source, &destination, &weight);
        addEdge(graph, source, destination, weight);
    }

    johnsonAlgorithm(graph);

    freeGraph(graph);

    return 0;
}
