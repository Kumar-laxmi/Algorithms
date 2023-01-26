
// Algorithm Working  :

// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited
// nodes as 0.

// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

// Step-3: Remove a vertex from the queue (Dequeue operation) and then.
// Increment the count of visited nodes by 1.
// Decrease in-degree by 1 for all its neighbouring nodes.
// If the in-degree of neighbouring nodes is reduced to zero, then add it to the queue.

// Step 4: Repeat Step 3 until the queue is empty.

// Step 5: If the count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

// Time Complexity :  O(V+E), where V = no. of nodes and E = no. of edges.
// Space Complexity : O(2N)

import java.util.*;

class Solution{

    // Function to return list containing vertices in Topological order.
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) {
        int indegree[] = new int[V];
        for (int i = 0; i < V; i++) {
            for (int it : adj.get(i)) {
                indegree[it]++;
            }
        }
        Queue<Integer> q = new LinkedList<Integer>();
        ;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        int topo[] = new int[V];
        int i = 0;
        while (!q.isEmpty()) {
            int node = q.peek();
            q.remove();
            topo[i++] = node;
            // node is in your topo sort
            // so please remove it from the indegree

            for (int it : adj.get(node)) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.add(it);
                }
            }
        }
        return topo;
    }
}


public class kahn_algorithm {
    public static void main(String[] args) {
        int V = 6;

        // We are using  2-d arraylist to store the connections
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        adj.get(2).add(3);
        adj.get(3).add(1);
        adj.get(4).add(0);
        adj.get(4).add(1);
        adj.get(5).add(0);
        adj.get(5).add(2);

        int[] ans = Solution.topoSort(V, adj);
        for (int node : ans) {
            System.out.print(node + " ");
        }
        System.out.println("");
    }
}