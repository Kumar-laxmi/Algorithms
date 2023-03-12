/*DFS (Depth-First Search) is a graph traversal algorithm that is used to explore a graph or a tree data structure.
The algorithm starts at a source node and visits all the nodes connected to it before backtracking to visit other nodes. 
It works by recursively traversing the depth of a graph or a tree, backtracking only when it has reached a dead end.
It uses stack data structure . 

BFS (Breadth-First Search) is a graph traversal algorithm that is used to explore a graph or a tree data structure. 
It starts at a source node and visits all the nodes connected to it at the current level before moving on to the next level.
It explores the graph level by level, visiting all the nodes at a given level before moving on to the next level.
It uses queue data structure . 
*/
#include <stdio.h>
#include <stdbool.h>

// MAX_SIZE specifies maximum size of the graph
#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];  // 'visited' is used to keep track of which nodes have been visited during traversal.
int queue[MAX_SIZE];
int front = -1, rear = -1;

//This function adds node to queue
void enqueue(int node) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = node;
}

//Used to remove node from the queue
int dequeue() {
    int node = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    return node;
}


/*This function performs a recursive depth-first search starting from the specified node. 
It marks the node as visited, prints it, and then recursively visits all of its neighbors that haven't been visited yet.
*/
void dfs(int node, int n) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

/*This function performs a breadth-first search starting from the specified start_node. It marks the node as visited, 
adds it to the queue, and then visits all of its neighbors before moving on to the next node in the queue.
*/
void bfs(int start_node, int n) {
    visited[start_node] = true;
    enqueue(start_node);

    while (front != -1) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int start_node;
    printf("Enter the starting node: ");
    scanf("%d", &start_node);

    printf("DFS traversal: ");
    dfs(start_node, n);

    // reset visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    printf("\nBFS traversal: ");
    bfs(start_node, n);

    return 0;
}

