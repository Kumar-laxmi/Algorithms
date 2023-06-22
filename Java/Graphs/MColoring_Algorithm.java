 // M-Coloring Algorithm in java
package Java.Graphs;
// import java.util.*;

public class MColoring_Algorithm{
     final int V = 4;
     int color[];

      boolean isSafe(int v, int graph[][], int color[], int c)
    {
        for (int i = 0; i < V; i++){
            if (graph[v][i] == 1 && c == color[i]){
                //if adjacent vertices has same color return false
                return false;
            }
        }
        return true;
    }  

     boolean giveColor(int graph[][], int m,int color[], int v)
    {
        if (v == V){        
            // for all vertices, color is assigned return true       
            return true;
        }
 
        for (int c = 1; c <= m; c++) {
            if (isSafe(v, graph, color, c)) {
                color[v] = c;
 
                if (giveColor(graph, m, color,v + 1))
                    return true;
 
                color[v] = 0;
            }
        }
        return false;
    }

     boolean MColoring(int graph[][], int m)
    {
        color = new int[V];
        for (int i = 0; i < V; i++)
            color[i] = 0;
 
        // Start with vertex 0 and give color
        if (!giveColor(graph, m, color, 0)) {
            System.out.println("Solution does not exist");
            return false;
        }
 
        printSolution(color);
        return true;
    }
 

    void printSolution(int color[])
    {
        System.out.println("Solution Exists:" + " The colors assigned to vertices are: ");
        for (int i = 0; i < V; i++){
            System.out.print(" " + color[i] + " ");
        }
        System.out.println();
    }
   public static void main(String args[]) {
       MColoring_Algorithm color = new MColoring_Algorithm();
       /* Given Graph  and  m = 3
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
   
    int graph[][] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
  
    int m = 3;
    color.MColoring(graph,m);
   }
}