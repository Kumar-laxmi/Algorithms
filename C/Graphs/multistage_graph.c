// Path: C\Graphs\multistage_graph.py
// C program to find shortest distance in a multistage graph.
// Time-Complexity: O(N^2), where N is the number of nodes in the graph.
// Space-Complexity: O(N), where N is the number of nodes in the graph.

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Returns shortest cost
// from 0 to N-1.
int shortestPath(int N, int graph[N][N])
{

    // cost[i] is going to store shortest
    // distance from node i to node N-1.
    int cost[N];
    cost[N - 1] = 0;

    // Calculating shortest distance for
    // rest of the nodes
    for (int i = N - 2; i >= 0; i--)
    {

        // Initialize distance from
        // i to destination (N-1)
        cost[i] = INF;

        // Check all nodes of next stages
        // to find shortest distance from
        // i to N-1.
        for (int j = 0; j < N; j++)
        {

            // If edge exists
            if (graph[i][j] != INF)
            {

                // Apply recursive equation to cost to target through j.
                // Compare with the minimum cost so far.
                if (graph[i][j] + cost[j] < cost[i])
                {
                    cost[i] = graph[i][j] + cost[j];
                }
            }
        }
    }

    return cost[0];
}

// Main method
int main()
{
    // No of nodes
    int N = 12;

    // Graph stored in the form of an adjacency Matrix for multistage graph
    // 1 is the source 12 is the sink
    int graph[12][12] = {{INF, 9, 7, 3, 2, INF, INF, INF, INF, INF, INF, INF},
                         {INF, INF, INF, INF, INF, 4, 2, 1, INF, INF, INF, INF},
                         {INF, INF, INF, INF, INF, 2, 7, INF, INF, INF, INF, INF},
                         {INF, INF, INF, INF, INF, INF, INF, 11, INF, INF, INF, INF},
                         {INF, INF, INF, INF, INF, INF, 11, 8, INF, INF, INF, INF},
                         {INF, INF, INF, INF, INF, INF, INF, INF, 6, 5, INF, INF},
                         {INF, INF, INF, INF, INF, INF, INF, INF, 4, 3, INF, INF},
                         {INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, 6, INF},
                         {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4},
                         {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2},
                         {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5}};

    int minCost = shortestPath(N, graph);
    printf("%d\n", minCost);

    return 0;
}

/**

                           4                6
                 (2)--------------(6)---------------(9)
                /    \ \          |   \          /      \
               /      \  \       |2    \       / 4       \ 
              /    (3)~\---\-------     \ 5  /            \ 4
            9/    /   \ \    \ 2         \ /               \
            /   7/       \ 7\    \         /\               \
           /    /         \  \    \     /    \               \  
        (1)---<           1\-------(7)------~~-----(10)------(12)
           \    \           \  /          3/             2   /
            \    \ 3         \ /         /                  /
            2\    \      11 / \         /                  /
              \    (4)   /     \       /5                 /5
               \      \ /  11   \     /                  /
                \    /  \------\ \   /                  /
                 (5)--------------(8)---------------(11)
                          8                  6   

        |         |                |                  |         |
        |         |                |                  |         |
    stage-1   stage-2          stage-3            stage-4    stage-5
    {1}      {2,3,4,5}         {6,7,8}           {9,10,11}     {12}   ---------->  Nodes in ith stage

**/