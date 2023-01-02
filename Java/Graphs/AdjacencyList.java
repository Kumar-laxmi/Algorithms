import java.util.ArrayList;

public class AdjacencyList {
    // Method to add an undirected edge between nodes u and v to the graph
    static void addEdge(ArrayList<ArrayList<Integer>> graph, int u, int v) {
        // Add v to the list of u
        graph.get(u).add(v);
        // Add u to the list of v
        graph.get(v).add(u);
    }

    // Method to print the graph
    static void printGraph(ArrayList<ArrayList<Integer>> graph) {
        // Iterate through each node in the graph
        for (int i = 0; i < graph.size(); i++) {
            // Get the list of edges for the current node
            for (int v : graph.get(i)) {
                // Print the edge
                System.out.println("Node " + i + "--->" + v);
            }
        }
    }

    public static void main(String[] args) {
        // Number of nodes in the graph
        int V = 5;
        // Initialize the graph as a list of lists
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(V);
        // Initialize the lists for each node
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<Integer>());
        }
        addEdge(adj, 0, 1);
        addEdge(adj, 1, 2);
        addEdge(adj, 0, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 2, 4);
        addEdge(adj, 2, 4);
        addEdge(adj, 1, 2);

        // Print the graph
        printGraph(adj);
    }
}
