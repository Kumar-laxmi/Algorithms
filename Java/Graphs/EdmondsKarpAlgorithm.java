// Path: Java\Graphs\EdmondsKarpAlgorithm.java
// Time Complexity: O(V * E^2)
// Space Complexity: O(V^2)

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class EdmondsKarpAlgorithm {

    static final int V = 6; // Number of vertices in the graph

    // Function to perform Breadth-First Search (BFS)
    static boolean bfs(int[][] residualGraph, int[] parent, int source, int sink) {
        boolean[] visited = new boolean[V];
        Queue<Integer> queue = new LinkedList<>();

        queue.add(source);
        visited[source] = true; 
        parent[source] = -1; 

        while (!queue.isEmpty()) {
            int u = queue.poll();

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && residualGraph[u][v] > 0) {
                    queue.add(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }

        return visited[sink]; // Return true if there is a path from source to sink
    }

    // Function to find the maximum flow using Edmonds-Karp algorithm
    static int edmondsKarp(int[][] graph, int source, int sink) {
        int[][] residualGraph = new int[V][V]; // Residual graph
        int[] parent = new int[V]; // Parent array to store the augmenting path

        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                residualGraph[u][v] = graph[u][v];
            }
        }

        int maxFlow = 0; // Initialize the maximum flow

        // Augment the flow while there is a path from source to sink
        while (bfs(residualGraph, parent, source, sink)) {
            int pathFlow = Integer.MAX_VALUE;

            // Find the minimum residual capacity along the augmenting path
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = Math.min(pathFlow, residualGraph[u][v]);
            }

            // Update the residual capacities and reverse edges along the path
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }

            maxFlow += pathFlow; // Add the path flow to the maximum flow
        }

        return maxFlow;
    }

    public static void main(String[] args) {
        int[][] graph = {
                {0, 16, 13, 0, 0, 0},
                {0, 0, 10, 12, 0, 0},
                {0, 4, 0, 0, 14, 0},
                {0, 0, 9, 0, 0, 20},
                {0, 0, 0, 7, 0, 4},
                {0, 0, 0, 0, 0, 0}
        };

        int source = 0; // Source vertex
        int sink = 5; // Sink vertex

        int maxFlow = edmondsKarp(graph, source, sink);

        System.out.println("Maximum flow: " + maxFlow);
    }
}


// Output>>  Maximum flow: 23 


