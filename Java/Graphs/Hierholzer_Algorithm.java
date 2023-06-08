/* 
------------------------------------- Hierholzer’s Algorithm for finding an Eulerian Cycle -------------------------------------

An Eulerian Cycle is a path in a graph that visits every edge exactly once and returns to the starting vertex. 
To find an Eulerian Cycle using Hierholzer's Algorithm, we follow these steps:

1. Choose any starting vertex in the graph.
2. Follow a trail of edges from that vertex until returning to the starting vertex. Since the graph is directed, there will always be an unused edge leaving each visited vertex.
3. Repeat the process as long as there are vertices with unused edges connected to the current trail. Start a new trail from such vertices, following unused edges until returning to the starting vertex of the new trail.
4. If we get stuck (a vertex with no unused edges), backtrack to the nearest vertex in the current path that has unused edges.
5. Repeat steps 3 and 4 until all edges have been used.
6. Store the final path in a separate container.

For Example:
Consider a directed graph with the following edges:

0 -> 1 -> 2 -> 3 -> 0
1 -> 4 -> 1
2 -> 1
3 -> 2 -> 4 -> 0

To find the Eulerian Cycle using Hierholzer's Algorithm, we start from vertex 0 and traverse the graph by following unused edges until we return to vertex 0. 
Then, we identify the remaining unused edges and start new trails from vertices 1, 2, and 3, respectively. Finally, we merge all the paths to obtain the Eulerian Cycle: 

0 -> 1 -> 2 -> 3 -> 2 -> 1 -> 4 -> 1 -> 0.
*/

// This code is for that graph which is already an Eulerian graph.
import java.util.*;

/**
 * Hierholzer_Algorithm
 */

public class Hierholzer_Algorithm {
    static void dfs(int curr_v, List<List<Integer>> adj, List<Integer> circuit, HashMap<Integer, Integer> edge_count, Stack<Integer> curr_path) {
        while (edge_count.get(curr_v) != 0) {
            curr_path.push(curr_v);
            int next_v = adj.get(curr_v).remove(adj.get(curr_v).size() - 1);
            edge_count.put(curr_v, edge_count.get(curr_v) - 1);
            curr_v = next_v;
        }
        circuit.add(curr_v);
    }
    
    static void printCycle(List<List<Integer>> adj) {
        HashMap<Integer, Integer> edge_count = new HashMap<>();
        for (int i = 0; i < adj.size(); i++) {
            edge_count.put(i, adj.get(i).size());
        }
    
        if (adj.isEmpty()) {
            return;
        }
    
        Stack<Integer> curr_path = new Stack<>();
        List<Integer> circuit = new ArrayList<>();
    
        curr_path.push(0);
        int curr_v = 0;
    
        while (!curr_path.empty()) {
            if (edge_count.get(curr_v) != 0) {
                dfs(curr_v, adj, circuit, edge_count, curr_path);
                curr_v = curr_path.peek();
                curr_path.pop();
            } else {
                circuit.add(curr_v);
                curr_v = curr_path.peek();
                curr_path.pop();
            }
        }
    
        for (int i = circuit.size() - 1; i >= 0; i--) {
            System.out.print(circuit.get(i));
            if (i > 0) {
                System.out.print(" -> ");
            }
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        List<List<Integer>> adj = new ArrayList<>();
    
        for (int i = 0; i < 5; i++) {
            adj.add(new ArrayList<>());
        }
        adj.get(0).add(1);
        adj.get(1).add(4);
        adj.get(4).add(1);
        adj.get(1).add(2);
        adj.get(2).add(3);
        adj.get(3).add(2);
        adj.get(2).add(1);
        adj.get(1).add(0);

        printCycle(adj);
    }
}
