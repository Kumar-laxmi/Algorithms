#include <stdio.h>
#include <conio.h>
#define INFINITY 8888
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main()
{
    int G[MAX][MAX], i, j, n, u;
    printf("ENTER THE NUMBER OF VERTICES:");
    scanf("%d", &n);
    printf("\nENTER THE ADJACENCY MATRIX:\n");  
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("\nENTER THE STARTING NODE:"); 
    scanf("%d", &u);
    dijkstra(G, n, u);
    return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode)
{

    int cost[MAX][MAX], dist[MAX], pred[MAX];
    int visited[MAX], count, mindist, nextnode, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    // initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    dist[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindist = INFINITY;
        // nextnode gives the node at minimum distance
        for (i = 0; i < n; i++)
            if (dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                nextnode = i;
            }
        // check if a better path exists through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindist + cost[nextnode][i] < dist[i])
                {
                    dist[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // print the path and distance of each node 
    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            printf("\nDISTANCE OF NODE%d=%d", i, dist[i]);
            printf("\nPATH=%d", i);
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != startnode);
        }
}