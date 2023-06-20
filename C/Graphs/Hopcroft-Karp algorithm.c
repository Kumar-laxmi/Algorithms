#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define NIL 0
#define INF INT_MAX

// Maximum number of vertices
#define MAX 1000

int n, m;                   // Number of vertices in the left and right sets
int graph[MAX][MAX];        // Bipartite graph representation
int match[MAX];             // Stores the matching pair
int dist[MAX];              // Distance array for BFS

bool bfs()
{
    int queue[MAX];
    int front = 0, rear = 0;

    for (int u = 1; u <= n; u++) {
        if (match[u] == NIL) {
            dist[u] = 0;
            queue[rear++] = u;
        }
        else
            dist[u] = INF;
    }

    dist[NIL] = INF;

    while (front < rear) {
        int u = queue[front++];
        if (dist[u] < dist[NIL]) {
            for (int v = 1; v <= m; v++) {
                if (graph[u][v] && dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    queue[rear++] = match[v];
                }
            }
        }
    }

    return dist[NIL] != INF;
}

bool dfs(int u)
{
    if (u != NIL) {
        for (int v = 1; v <= m; v++) {
            if (graph[u][v] && dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }

    return true;
}

int hopcroftKarp()
{
    memset(match, NIL, sizeof(match));
    int matching = 0;

    while (bfs()) {
        for (int u = 1; u <= n; u++) {
            if (match[u] == NIL && dfs(u))
                matching++;
        }
    }

    return matching;
}

int main()
{
    int e;  // Number of edges

    printf("Enter the number of vertices in the left set: ");
    scanf("%d", &n);
    printf("Enter the number of vertices in the right set: ");
    scanf("%d", &m);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    memset(graph, 0, sizeof(graph));

    printf("Enter the edges:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    int maxMatching = hopcroftKarp();
    printf("Maximum Matching: %d\n", maxMatching);

    return 0;
}
