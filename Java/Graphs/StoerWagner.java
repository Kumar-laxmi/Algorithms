import java.util.Scanner;
public class StoerWagner {
    private static final int MAX_VERTICES = 100;

    // Function to find the minimum cut using Stoer-Wagner algorithm
    private static int StoerWagnerAlgorithm(int[][] graph, int n) {
        int minCut = Integer.MAX_VALUE; // Initialize the minimum cut with maximum value
        boolean[] inSet = new boolean[MAX_VERTICES]; // Keep track of vertices included in the set
        int[] partition = new int[MAX_VERTICES]; // Keep track of partition of vertices

        for (int i = 0; i < n; i++) {
            partition[i] = i; // Initialize each vertex in its own partition
        }

        for (int phase = 0; phase < n - 1; phase++) {
            boolean[] inTree = new boolean[MAX_VERTICES]; // Mark all vertices as not yet included in the tree
            int[] weight = new int[MAX_VERTICES]; // Initialize the weight array

            int prev = -1; // Variable to store the previous vertex
            for (int i = 0; i < n - phase; i++) {
                int maxWeight = -1;
                int current = -1;
                for (int j = 0; j < n; j++) {
                    if (!inTree[j] && !inSet[j] && weight[j] > maxWeight) {
                        maxWeight = weight[j]; // Update the maximum weight
                        current = j; // Store the current vertex
                    }
                }

                if (i == n - phase - 1) {
                    if (maxWeight < minCut) {
                        minCut = maxWeight; // Update the minimum cut value
                    }
                    inSet[current] = true; // Include the current vertex in the set
                    for (int j = 0; j < n; j++) {
                        if (!inTree[j]) {
                            graph[prev][j] += graph[current][j]; // Update the graph weights
                            graph[j][prev] += graph[current][j];
                        }
                    }
                } else {
                    inTree[current] = true; // Include the current vertex in the tree
                    for (int j = 0; j < n; j++) {
                        if (!inTree[j]) {
                            weight[j] += graph[current][j]; // Update the weight array
                        }
                    }
                    prev = current; // Store the previous vertex
                }
            }
        }

        return minCut; // Return the minimum cut value
    }

    public static void main(String[] args) {
        int[][] graph = new int[MAX_VERTICES][MAX_VERTICES]; // Graph represented as an adjacency matrix
        int n, m; // Number of vertices and edges

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        n = scanner.nextInt();

        System.out.print("Enter the number of edges: ");
        m = scanner.nextInt();

        System.out.println("Enter the edges and their weights:");
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int weight = scanner.nextInt();
            graph[u][v] = weight; // Set the weight of edge (u, v)
            graph[v][u] = weight; // Set the weight of edge (v, u)
        }

        int minCut = StoerWagnerAlgorithm(graph, n); // Find the minimum cut using Stoer-Wagner algorithm

        System.out.println("Minimum cut value: " + minCut);
    }
}
