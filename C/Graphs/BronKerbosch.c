/*
 *   The Bron-Kerbosch is a algorithm to find all maximal cliques (complete subgraphs) in an undirected graph.
 *   Clique: Set of vertices such that every pair of vertices is connected by an edge.
 *   Maximal Clique: A clique is maximal if it cannot be extended by adding another vertex in the graph.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int count;
} Set;

void initializeSet(Set* set) {
    set->count = 0;
}

void addToSet(Set* set, int vertex) {
    set->vertices[set->count++] = vertex;
}

int isVertexInSet(Set* set, int vertex) {
    int i;
    for (i = 0; i < set->count; ++i) {
        if (set->vertices[i] == vertex) {
            return 1;
        }
    }
    return 0;
}

void bronKerbosch(Set* clique, Set* potential, Set* excluded, int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    if (potential->count == 0 && excluded->count == 0) {
        printf("Maximal Clique: ");
        for (int i = 0; i < clique->count; ++i) {
            printf("%d ", clique->vertices[i]);
        }
        printf("\n");
        return;
    }

    Set potentialCopy = *potential;
    int i;
    for (i = 0; i < potentialCopy.count; ++i) {
        int vertex = potentialCopy.vertices[i];
        Set newClique = *clique;
        addToSet(&newClique, vertex);
        Set newPotential, newExcluded;
        initializeSet(&newPotential);
        initializeSet(&newExcluded);

        int j;
        for (j = 0; j < potential->count; ++j) {
            int neighbor = potential->vertices[j];
            if (graph[vertex][neighbor] == 1) {
                addToSet(&newPotential, neighbor);
            }
        }
        for (j = 0; j < excluded->count; ++j) {
            int neighbor = excluded->vertices[j];
            if (graph[vertex][neighbor] == 1) {
                addToSet(&newExcluded, neighbor);
            }
        }

        bronKerbosch(&newClique, &newPotential, &newExcluded, graph, numVertices);

        int k;
        for (k = 0; k < potential->count; ++k) {
            if (potential->vertices[k] == vertex) {
                int l;
                for (l = k; l < potential->count - 1; ++l) {
                    potential->vertices[l] = potential->vertices[l + 1];
                }
                potential->count--;
                break;
            }
        }
        addToSet(excluded, vertex);
    }
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    int i, j;
    for (i = 0; i < numVertices; ++i) {
        for (j = 0; j < numVertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    Set clique, potential, excluded;
    initializeSet(&clique);
    initializeSet(&potential);
    initializeSet(&excluded);

    for (i = 0; i < numVertices; ++i) {
        addToSet(&potential, i);
    }

    bronKerbosch(&clique, &potential, &excluded, graph, numVertices);

    return 0;
}
