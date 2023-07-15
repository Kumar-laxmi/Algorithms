/*
 *   Prim's Algorithm
 *   Author: Brandon Szeto
 *   Prim's algorithm is used to find the MST (Minimum Spaning Tree) of a
 *   weighted, undirected graph.
 *
 *   Expected Output Of the code:
 *   Enter the number of vertices:
 *   (e.g)   - 3
 *   Enter the adjacency matrix (connected and symmetric):
 *   (e.g)   - Ordered like:
 *              {0, 1, 2},
 *              {1, 0, 3},
 *              {2, 3, 0}
 *   Edge     Weight
 *   0 <-> 1    1
 *   1 <-> 2    2
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int minimum_key(int k[], bool mst[], int n) {
  int minimum = INF, min = -1, i;

  /*iterate over all vertices to find the vertex with minimum key-value*/
  for (i = 0; i < n; i++)
    if (!mst[i] && k[i] < minimum) {
      minimum = k[i];
      min = i;
    }
  return min;
}

void prims(int G[MAX_VERTICES][MAX_VERTICES], int n) {
  int parent[n], k[n], i, count, edge, v;
  bool mst[n];

  // Initialize all keys = INF and all mst = 0
  for (i = 0; i < n; i++) {
    k[i] = INF;
    mst[i] = false;
  }

  // Choosing an arbitrary element (the first)
  k[0] = 0;
  parent[0] = -1;

  for (count = 0; count < n - 1; count++) {
    // Pop from priority queue
    edge = minimum_key(k, mst, n);
    mst[edge] = true;
    for (v = 0; v < n; v++) {
      if (G[edge][v] && mst[v] == 0 && G[edge][v] < k[v]) {
        parent[v] = edge, k[v] = G[edge][v];
      }
    }
  }

  /*Print the constructed Minimum spanning tree*/
  printf("\n Edge \t  Weight\n");
  for (i = 1; i < n; i++) {
    printf(" %d <-> %d    %d \n", parent[i], i, G[i][parent[i]]);
  }
}

int main() {
  // Manual input
  int G[MAX_VERTICES][MAX_VERTICES], i, j, n;
  printf("Enter the number of vertices:");
  scanf("%d", &n);
  printf("\nEnter the adjacency matrix (GRAPH SHOULD BE CONNECTED):\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &G[i][j]);
  prims(G, n);

  // Uncomment below and comment above to input readable adjacency matrix
  /* int G[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 2}, {1, 0, 1}, {2, 1, 0}}; */
  /* prims(G, 3); */

  return 0;
}
