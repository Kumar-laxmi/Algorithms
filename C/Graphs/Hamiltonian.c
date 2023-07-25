#include<stdio.h>

#define V 5

void printSolution(int path[]);

int isSafe(int v, int graph[V][V], int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

int hamCycleUtil(int graph[V][V], int path[], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1) == 1)
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int hamCycle(int graph[V][V])
{
    int *path = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == 0)
    {
        printf("\nSolution does not exist");
        return 0;
    }

    printSolution(path);
    return 1;
}

void printSolution(int path[])
{
    printf("Solution Exists: Following is one Hamiltonian Cycle\n");
    for (int i = 0; i < V; i++)
        printf(" %d", path[i]);

    printf(" %d\n", path[0]);
}

int main()
{
    int graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0},
    };

    hamCycle(graph1);

    int graph2[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0},
    };

    hamCycle(graph2);

    return 0;
}
