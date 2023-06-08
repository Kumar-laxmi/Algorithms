/* I will use Tarjan's Algorithm to find the bridges
   So, what is a bridge -> A bridge of a connected graph is a graph edge whose removal disconnects the graph
   So if we remove the bridge then the graph will be converted into multiple components.

   e.g. 1 ←-----→ 3 ←----→ 4
        ↑       ↗          ↑
        |     ↗            |
        |   ↗              |
        ↓ ↙                ↓
        2                  5

   In the above bidirectional graph, if we remove edge 3-4 then the graph will be broken into two different components so, we can say 3-4 is a bridge.

   T.c.=> O(V+E)
   Auxiliary Space: O(V)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct
{
    int u;
    int v;
} Edge;

typedef struct
{
    int node;
    int parent;
} DFSData;

typedef struct
{
    Edge edges[MAX_NODES];
    int numEdges;
    int adjList[MAX_NODES][MAX_NODES];
    int adjListSize[MAX_NODES];
    int tin[MAX_NODES];
    int low[MAX_NODES];
    int timer;
    bool visited[MAX_NODES];
} Graph;

// Initialize the graph
void initGraph(Graph *graph)
{
    graph->numEdges = 0;
    for (int i = 0; i < MAX_NODES; i++)
    {
        graph->adjListSize[i] = 0;
        graph->visited[i] = false;
    }
}

// Add an edge to the graph
void addEdge(Graph *graph, int u, int v)
{
    Edge edge = {u, v};
    graph->edges[graph->numEdges++] = edge;
    graph->adjList[u][graph->adjListSize[u]++] = v;
    graph->adjList[v][graph->adjListSize[v]++] = u;
}

// Depth-first search (DFS) function
void dfs(Graph *graph, int node, int parent, DFSData *dfsData, int *numBridges, Edge *bridges)
{
    graph->visited[node] = true;
    graph->tin[node] = graph->low[node] = graph->timer++;

    for (int i = 0; i < graph->adjListSize[node]; i++)
    {
        int child = graph->adjList[node][i];

        if (child == parent)
            continue;

        if (!graph->visited[child])
        {
            dfsData[child].node = child;
            dfsData[child].parent = node;

            dfs(graph, child, node, dfsData, numBridges, bridges);

            // Update the low-link value of the current node
            graph->low[node] = (graph->low[node] < graph->low[child]) ? graph->low[node] : graph->low[child];

            // If the low-link value of the child is greater than the tin value of the node,
            // it is a bridge, so store it
            if (graph->low[child] > graph->tin[node])
            {
                bridges[*numBridges].u = node;
                bridges[*numBridges].v = child;
                (*numBridges)++;
            }
        }
        else
        {
            // Update the low-link value of the current node
            graph->low[node] = (graph->low[node] < graph->tin[child]) ? graph->low[node] : graph->tin[child];
        }
    }
}

// Function to find bridges using Tarjan's algorithm
void findBridges(Graph *graph, Edge *bridges, int *numBridges)
{
    DFSData dfsData[MAX_NODES];
    *numBridges = 0;

    dfs(graph, 0, -1, dfsData, numBridges, bridges);
}

int main()
{
    Graph graph;
    initGraph(&graph);

    int numNodes = 5;

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 4);
    /*
     *     0 <--> 1 <---> 2
     *            ↑       ↑
     *            |       |
     *            |       |
     *            ↓       ↓
     *            3       4
     *
     *    In this graph there are 4 bridges [1,0] , [2,1] , [4,2] , [3,1]
     *
     *    Assuming that the graph is bi-directional and connected.
     *
     */

    Edge bridges[MAX_NODES];
    int numBridges;

    // Find bridges in the graph
    findBridges(&graph, bridges, &numBridges);

    printf("%d bridges found!\n", numBridges);

    // Print the bridges
    for (int i = 0; i < numBridges; i++)
    {
        printf("%d --> %d\n", bridges[i].u, bridges[i].v);
    }

    return 0;
}
