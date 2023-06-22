 /* M-Coloring Algorithm

This algorithm is used to determine if the undirected graph can be colored with at most m colors 
such that no two adjacent vertices of the graph are colored with the same color.

Approach: Generate all possible configurations of colors,since each node can be colored using any of m available colors
the total number of color configurations possible is m^V. After generating a configuration of color, 
check if the adjacent vertices have the same colour,if not then print the solution of color assigned


Time Complexity: O(m^V)  where V is number of vertices, m= at most m colors required to color the graph
Auxiliary Space: O(V)

*/
#include<bits/stdc++.h>
using namespace std;
#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++){
        if (graph[v][i] && c == color[i]){
            //if adjacent vertices has same color return false
            return false;
        }
    }
 
    return true;
}

bool giveColor(bool graph[V][V], int m, int color[],int v)
{
    if (v == V)          // for all vertices color is assigned
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
        cout << "Solution does not exist";
        return false;
    }
 

    printSolution(color);
    return true;
}
void printSolution(int color[])
{
    cout << "Solution Exists:"<< " The colors assigned to the vertices are :" << endl;
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";
 
    cout <<endl;
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