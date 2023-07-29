 import java.util.Arrays;
import java.util.Scanner;

public class FordFulkerson {

    // Function to find the minimum of two numbers
    private static int min(int a, int b) {
        return (a < b) ? a : b;
    }

    // Function to find if there is a path from source to sink in the residual graph
    private static boolean bfs(int[][] residualGraph, int source, int sink, int[] parent) {
        int V = residualGraph.length;

        boolean[] visited = new boolean[V]; // Create a visited array to keep track of visited vertices
        Arrays.fill(visited, false);

        // Create a queue for BFS
        int[] queue = new int[V];
        int front = 0, rear = 0;
        queue[rear++] = source;
        visited[source] = true;
        parent[source] = -1; // Set the parent of the source as -1

        // Standard BFS loop
        while (front < rear) {
            int u = queue[front++];
            for (int v = 0; v < V; v++) {
                if (!visited[v] && residualGraph[u][v] > 0) {
                    queue[rear++] = v;
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }

        // If we reached the sink in BFS, then there is a path from source to sink
        return visited[sink];
    }

    // Function to implement the Ford-Fulkerson algorithm
    private static int fordFulkerson(int[][] graph, int source, int sink) {
        int V = graph.length;

        // Create a residual graph and initialize it with the original capacities
        int[][] residualGraph = new int[V][V];
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                residualGraph[u][v] = graph[u][v];
            }
        }

        int[] parent = new int[V]; // This array is filled by BFS and stores the path
        int maxFlow = 0; // Initialize the maximum flow

        // Augment the flow while there is a path from source to sink in the residual graph
        while (bfs(residualGraph, source, sink, parent)) {
            // Find the maximum possible flow through the path found in BFS
            int pathFlow = Integer.MAX_VALUE;
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, residualGraph[u][v]);
            }

            // Update the residual capacities of the edges and reverse edges along the path
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }

            // Add the path flow to the overall maximum flow
            maxFlow += pathFlow;
        }

        // Return the overall maximum flow
        return maxFlow;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int V; // Number of vertices in the graph
        int source, sink; // Source and sink vertices

        System.out.print("Enter the number of vertices in the graph: ");
        V = scanner.nextInt();

        int[][] graph = new int[V][V]; // Adjacency matrix representation of the graph

        System.out.print("Enter the number of edges in the graph: ");
        int numEdges = scanner.nextInt();

        // Initialize the graph with zero capacity initially
        for (int i = 0; i < V; i++) {
            Arrays.fill(graph[i], 0);
        }

        // Get the edge details from the user and update the graph
        for (int i = 0; i < numEdges; i++) {
            int u, v, capacity;
            System.out.print("Enter the start vertex, end vertex, and capacity of edge " + (i + 1) + ": ");
            u = scanner.nextInt();
            v = scanner.nextInt();
            capacity = scanner.nextInt();
            graph[u][v] = capacity;
        }

        System.out.print("Enter the source vertex: ");
        source = scanner.nextInt();

        System.out.print("Enter the sink vertex: ");
        sink = scanner.nextInt();

        // Call the Ford-Fulkerson algorithm to find the maximum flow
        int maxFlow = fordFulkerson(graph, source, sink);
        System.out.println("The maximum flow in the graph is: " + maxFlow);
    }
}
