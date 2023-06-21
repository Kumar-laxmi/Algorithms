// C-program to implement famous Kruskal's Algorithm
// Kruskal's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph.

// The idea is to sort all edges of given graph in increasing order, and then keep on adding new edges and nodes in the spanning tree if the added edge does not form a cycle.


/* A minimum spanning tree is constructed from a weighted & undirected graph, so it:
-> Connects all nodes / vertices
-> Has no cycles
-> Has smallest possible sum of edge weights.*/

#include <stdio.h>
#include <stdlib.h>

#define maximum 100000

int no[maximum], nodes, edges;

struct Edge 
{
    long long weight;
    int u, v;
};

struct Edge k[maximum];

// Find the base/parent of the given node
int base(int a) 
{
    while (no[a] != a) 
    {
        no[a] = no[no[a]];  // Path compression optimization
        a = no[a];
    }
    return a;
}

// Merge the sets containing nodes a and b
void temp(int a, int b) 
{
    int k = base(a);
    int l = base(b);
    no[k] = no[l];
}

// Kruskal's algorithm to find the minimum spanning tree
long long krus(struct Edge k[]) 
{
    int a, b;
    long long cost, minCost = 0;
    for (int i = 0; i < edges; ++i) 
    {
        a = k[i].u;
        b = k[i].v;
        cost = k[i].weight;
        if (base(a) != base(b))  // Check if adding the edge forms a cycle
        {
            minCost += cost;
            temp(a, b);  // Merge the sets
        }
    }
    return minCost;
}

int main() 
{
    int a, b;
    long long w, cost, minCost;

    for (int i = 0; i < maximum; ++i) 
    {
        no[i] = i;  // Initialize each node as a separate set
    }

    printf("Enter Nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    for (int i = 0; i < edges; ++i) 
    {
        printf("Enter the value of a, b, and weight: ");
        scanf("%d %d %lld", &a, &b, &w);
        k[i].weight = w;
        k[i].u = a;
        k[i].v = b;
    }

    // Sort the edges based on weight using bubble sort
    for (int i = 0; i < edges - 1; ++i) 
    {
        for (int j = 0; j < edges - i - 1; ++j) 
        {
            if (k[j].weight > k[j + 1].weight) 
            {
                struct Edge temp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = temp;
            }
        }
    }

    minCost = krus(k);  // Find the minimum spanning tree cost
    printf("Minimum cost is %lld\n", minCost);

    return 0;
}

// Time Complexity: O(E log N)