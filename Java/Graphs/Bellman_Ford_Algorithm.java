import java.util.ArrayList;
import java.util.Arrays;

public class Main{
    private static void BellmanFord(int V, int E, int src, ArrayList<ArrayList<Integer>>AdjacencyList){
        
        // Creating a distance array of size V to store the shortest path from source vertex
        int [] dist = new int[V];

        // Filling distance from source vertex to other vertices as MAX_VALUE
        // and distance from source to source vertex as 0

        for(int i = 0; i < V; i++){
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;

        //Relaxing all the edges in the AdjacencyList |v|-1 times
        for(int i = 0; i < V; i++){
            for(int j = 0; j < E; j++){
                //for every edge from u-->v with weight wt
                int u = AdjacencyList.get(j).get(0);
                int v = AdjacencyList.get(j).get(1);
                int wt = AdjacencyList.get(j).get(2);

                // If we get a shorter path, we update the distance array
                if(dist[u] != Integer.MAX_VALUE && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // To check if the graph contains negative edge cycle, we do relaxation 
        // of AdjacencyList one more time
        // If distance array gets updated, then we say that there is a negative 
        // weight cycle in this graph
            for(int j = 0; j < E; j++){
                int u = AdjacencyList.get(j).get(0);
                int v = AdjacencyList.get(j).get(1);
                int wt = AdjacencyList.get(j).get(2);

                if(dist[u] != Integer.MAX_VALUE && dist[u] + wt < dist[v]){
                    System.out.println("The graph contains a negative weight cycle");
                    return ;
                }
            }

        // If the graph doesn't have negative weight cycle, we print the distance array
        System.out.println("Vertex  Distance from source vertex");
        for(int i = 0; i < V; i++){
            System.out.println(i + "\t\t" + dist[i]);
        }
         System.out.println("");
    }
    // driver code
    public static void main(String[] args) {

        // V-> number of vertices 
        // E-> number of AdjacencyList
        int V = 6;
        int E = 7;
        int Src = 0;
        ArrayList<ArrayList<Integer>> AdjacencyList = new ArrayList<ArrayList<Integer>>();

        ArrayList<Integer> edge1 = new ArrayList<Integer>();
        edge1.add(0);
        edge1.add(1);
        edge1.add(5);  // 0-->1  weight=5

        ArrayList<Integer> edge2 = new ArrayList<Integer>();
        edge2.add(1);
        edge2.add(2);
        edge2.add(-2); //1-->2  weight =-2

        ArrayList<Integer> edge3 = new ArrayList<Integer>();
        edge3.add(1);
        edge3.add(5);
        edge3.add(-3);  // 1-->5  weight=-3
        
        ArrayList<Integer> edge4 = new ArrayList<Integer>();
        edge4.add(2);
        edge4.add(4);
        edge4.add(3);  // 2-->4  weight=3
        
        ArrayList<Integer> edge5 = new ArrayList<Integer>();
        edge5.add(3);
        edge5.add(2);
        edge5.add(6);  // 3--> 2  weight=6

        ArrayList<Integer> edge6 = new ArrayList<Integer>();
        edge6.add(3);
        edge6.add(4);
        edge6.add(-2); // 3-->4  weight=-2

        ArrayList<Integer> edge7 = new ArrayList<Integer>();
        edge7.add(5);
        edge7.add(3);
        edge7.add(1); // 5-->3  weight= 1

        AdjacencyList.add(edge1);
        AdjacencyList.add(edge2);
        AdjacencyList.add(edge3);
        AdjacencyList.add(edge4);
        AdjacencyList.add(edge5);
        AdjacencyList.add(edge6);
        AdjacencyList.add(edge7);

        BellmanFord(V, E, Src, AdjacencyList);
    }
}


