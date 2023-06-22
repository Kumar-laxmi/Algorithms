/* 
------------------------------------- Hierholzer’s Algorithm for finding an Eulerian Cycle -------------------------------------

An Eulerian Cycle is a path in a graph that visits every edge exactly once and returns to the starting vertex. 
To find an Eulerian Cycle using Hierholzer's Algorithm, we follow these steps:

1. Choose any starting vertex in the graph.
2. Follow a trail of edges from that vertex until returning to the starting vertex. Since the graph is directed, there will always be an unused edge leaving each visited vertex.
3. Repeat the process as long as there are vertices with unused edges connected to the current trail. Start a new trail from such vertices, following unused edges until returning to the starting vertex of the new trail.
4. If we get stuck (a vertex with no unused edges), backtrack to the nearest vertex in the current path that has unused edges.
5. Repeat steps 3 and 4 until all edges have been used.
6. Store the final path in a separate container.

For Example:
Consider a directed graph with the following edges:

0 -> 1 -> 2 -> 3 -> 0
1 -> 4 -> 1
2 -> 1
3 -> 2 -> 4 -> 0

To find the Eulerian Cycle using Hierholzer's Algorithm, we start from vertex 0 and traverse the graph by following unused edges until we return to vertex 0. 
Then, we identify the remaining unused edges and start new trails from vertices 1, 2, and 3, respectively. Finally, we merge all the paths to obtain the Eulerian Cycle: 

0 -> 1 -> 2 -> 3 -> 2 -> 1 -> 4 -> 1 -> 0.
*/

// This code is for that graph which is already an Eulerian graph.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    struct Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void addEdge(LinkedList* adj[], int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = adj[src]->head;
    adj[src]->head = newNode;
}

void dfs(int curr_v, LinkedList* adj[], int* edge_count, int* circuit, int* curr_path_top)
{
    while (edge_count[curr_v])
    {
        circuit[(*curr_path_top)++] = curr_v;
        int next_v = adj[curr_v]->head->data;
        edge_count[curr_v]--;
        adj[curr_v]->head = adj[curr_v]->head->next;
        curr_v = next_v;
    }
    circuit[(*curr_path_top)++] = curr_v;
}

void printCycle(LinkedList* adj[], int num_vertices)
{
    int* edge_count = (int*)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        struct Node* current = adj[i]->head;
        edge_count[i] = 0;
        while (current != NULL) {
            edge_count[i]++;
            current = current->next;
        }
    }

    if (num_vertices == 0) {
        return;
    }

    int* circuit = (int*)malloc((num_vertices + 1) * sizeof(int));
    int curr_path_top = 0;
    int curr_v = 0;

    int* curr_path = (int*)malloc(num_vertices * sizeof(int));

    curr_path[curr_path_top++] = curr_v;

    while (curr_path_top > 0)
    {
        if (edge_count[curr_v])
        {
            dfs(curr_v, adj, edge_count, circuit, &curr_path_top);
            curr_v = curr_path[curr_path_top - 1];
            curr_path_top--;
        }
        else
        {
            circuit[curr_path_top++] = curr_v;
            curr_v = curr_path[curr_path_top - 1];
            curr_path_top--;
        }
    }

    for (int i = num_vertices; i >= 0; i--)
    {
        printf("%d", circuit[i]);
        if (i)
            printf(" -> ");
    }

    free(edge_count);
    free(circuit);
    free(curr_path);
}

int main()
{
    int num_vertices, num_edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    LinkedList* adj[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        adj[i] = createLinkedList();
    }

    printf("Enter the edges in the format 'source destination':\n");
    for (int i = 0; i < num_edges; i++)
    {
        int source, destination;
        printf("Source-%d : ", i + 1);
        scanf("%d", &source);
        printf("Destination-%d : ", i + 1);
        scanf("%d", &destination);
        addEdge(adj, source, destination);
    }

    printf("\nEulerian Cycle: ");
    printCycle(adj, num_vertices);
    printf("\n");

    for (int i = 0; i < num_vertices; i++) {
        struct Node* current = adj[i]->head;
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
        free(adj[i]);
    }

    return 0;
}
