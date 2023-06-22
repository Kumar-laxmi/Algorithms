 // M-Coloring Algorithm in C 
#include <stdbool.h>
#include <stdio.h>
#define V 4
 
void printSolution(int color[]);
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++){
        if (graph[v][i] && c == color[i]){
            return false;
        }
    }
    return true;
}

bool giveColor(bool graph[V][V], int m, int color[],int v)
{
    if (v == V)          // for all vertices, color is assigned return true
        return true;

    for (int c = 1; c <= m; c++) {

        if (isSafe(v, graph, color, c)) {
            color[v] = c;              
 
            if (giveColor(graph, m, color, v + 1)
                == true)
                return true;

            /* If assigning color c doesn't
               lead to a solution then remove it */
            color[v] = 0;
        }
    }
 
//if no color can be assigned return false
    return false;
}
bool MColoring(bool graph[V][V], int m)
{
 
    int color[V];
    for (int i = 0; i < V; i++){
        color[i] = 0;  //initializing color array with zero
    }
 
    // Start with vertex 0 and give color
    if (giveColor(graph, m, color, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
 

    printSolution(color);
    return true;
}
void printSolution(int color[])
{
    printf("Solution Exists:"
           " The colors assigned to the vertices are : \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);

    printf("\n");
}
int main()
{
 
    /* Given Graph  and  m = 3
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
  
    int m = 3;
    MColoring(graph, m);
    return 0;
}