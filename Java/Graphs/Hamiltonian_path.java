import java.util.Scanner;
import java.util.Arrays;
 

public class Hamiltonian_path
{
    private int V, count;
    private int[] path;     
    private int[][] graph;
 
    /** Function to find cycle **/
    public void findHamiltonianCycle(int[][] g)
    {
        V = g.length;
        path = new int[V]; //Path array is declared
         
        Arrays.fill(path, -1); //Used to fill the path array
        graph = g;        
        try
        {            
            path[0] = 0;
            count = 1;            
            solve(0);
            System.out.println("No solution");
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
            display();
        }
    }
   
    public void solve(int vertex) throws Exception
    {
      
        if (graph[vertex][0] == 1 && pathCount == V)
            throw new Exception("Solution found");
        
        if (count == V)
            return;
 
        for (int v = 0; v < V; v++)
        {
            if (graph[vertex][v] == 1 )
            {
                /** add to path **/            
                path[count++] = v;    
                /** remove connection **/            
                graph[vertex][v] = 0;
                graph[v][vertex] = 0;
 
                /** if vertex not already selected  solve recursively **/
                if (!isPresent(v))
                    solve(v);
 
                /** restore connection **/
                graph[vertex][v] = 1;
                graph[v][vertex] = 1;
                /** remove path **/
                path[--count] = -1;                    
            }
        }
    }    
    /** function to check if path is already selected **/
    public boolean isPresent(int v)
    {
        for (int i = 0; i < count - 1; i++)
            if (path[i] == v)
                return true;
        return false;                
    }
    /** display solution **/
    public void display()
    {
        System.out.print("\nPath : ");
        for (int i = 0; i <= V; i++)
            System.out.print(path[i % V] +" ");
        System.out.println();
    }    
  
    public static void main (String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("HamiltonianCycle Algorithm Test\n");
   
        HamiltonianCycle hc = new HamiltonianCycle();
 
        /** Accept number of vertices **/
        System.out.println("Enter number of vertices\n");
        int V = scan.nextInt();
 
        /** get graph **/
        System.out.println("\nEnter matrix\n");
        int[][] graph = new int[V][V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = scan.nextInt();
 
        hc.findHamiltonianCycle(graph);        
    }    
}
