#include <stdio.h>
#include <stdlib.h>

#define INF 99999

//struct for the edges of the graph
struct Edge {
  // an edge from u to v with edge weight wt
  int u, v, wt;
};

//struct for a graph
struct Graph {
  int V;        // number of vertices in the graph
  int E;        //number of edges in the graph
  struct Edge *edge;  //array of edges
};

void bellman_ford(struct Graph *g, int src) {
  //variables
  int i, j, u, v, wt;
  int total_V = g->V;
  int total_E = g->E;

  //distance array of size |Ttotal_V| for storing shortest path from source vertex to other vertices
  int dist[total_V];
  
  // Filling distance from source vertex to other vertices as MAX_VALUE
  // and distance from source to source vertex as 0
  for (i = 0; i < total_V; i++) {
    dist[i] = INF;
  }
  dist[src] = 0;

  //Relaxing all the edges in the AdjacencyList |total_V|-1 times
  for (i = 1; i <= total_V - 1; i++) {
    for (j = 0; j < total_E; j++) {
        
      //for every edge from u-->v with weight wt
      u = g->edge[j].u;
      v = g->edge[j].v;
      wt = g->edge[j].wt;
      
      // If we get a shorter path, we update the distance array
      if (dist[u] != INF && dist[u] + wt < dist[v]) {
        dist[v] = dist[u] + wt;
      }
    }
  }

  // To check if the graph contains negative edge cycle, we do relaxation 
  // of edges one more time
  // If distance array gets updated, then we say that there is a negative 
  // weight cycle in this graph
  for (i = 0; i < total_E; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    wt = g->edge[i].wt;
    if (dist[u] != INF && dist[u] + wt < dist[v]) {
      printf("The graph contains a negative weight cycle\n");
      return;
    }
  }

  // If the graph doesn't have negative weight cycle, we print the distance array
  printf("Vertex  Distance from source vertex\n");
  for (i = 0; i < total_V; i++) {
    printf("%d        %d\n", i,dist[i]);
  }
  printf("\n");
}


int main(void) {
  //creating graph
  struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
  g->V = 6;  //total number of vertices
  g->E = 7;  //total number of edges

  //array of edges for graph
  g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));

  // 0 --> 1 weight=5
  g->edge[0].u = 0;
  g->edge[0].v = 1;
  g->edge[0].wt = 5;

  // 1 --> 2 weight=-2
  g->edge[1].u = 1;
  g->edge[1].v = 2;
  g->edge[1].wt = -2;

  // 1 --> 5 weight=-3
  g->edge[2].u = 1;
  g->edge[2].v = 5;
  g->edge[2].wt = -3;

  // 2 --> 4 weight=3
  g->edge[3].u = 2;
  g->edge[3].v = 4;
  g->edge[3].wt = 3;

  // 3 --> 2 weight=6
  g->edge[4].u = 3;
  g->edge[4].v = 2;
  g->edge[4].wt = 6;
  
  // 3 --> 4 weight=-2
  g->edge[5].u = 3;
  g->edge[5].v = 4;
  g->edge[5].wt = -2;
  
  // 5 --> 3 weight=1
  g->edge[6].u = 5;
  g->edge[6].v = 3;
  g->edge[6].wt = 1;

  bellman_ford(g, 0);  //0 is the source vertex

  return 0;
}

