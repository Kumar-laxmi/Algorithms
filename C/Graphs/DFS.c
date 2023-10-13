#include <stdio.h>
#include <stdlib.h>

void DFS(int);
int G[100][100], visited[100], n, s;

void DFS(int i) {
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for (j = 1; j <= n; j++) {
        if (visited[j] == 0 && G[i][j] == 1)
            DFS(j);
    }
}

int main() {
    int i, j;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter values of adjacency matrix of the graph:\n");
    // 1-indexed graph
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    printf("Enter source node: ");
    scanf("%d", &s);

    printf("Depth First Traversal: ");
    DFS(s);

    return 0;
}

