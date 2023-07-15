/*Kruskals Algorithm
    Author: Phalesh Kolpe
    Kruskals algorithm is used to Find the MST(Minimum Spaning Tree) of a graph it considers the edges and weight of the edge
    Step 1: Sort all edges in increasing order of their edge weights.
    Step 2: Pick the smallest edge.
    Step 3: Check if the new edge creates a cycle or loop in a spanning tree.
    Step 4: If it doesn’t form the cycle, then include that edge in MST. Otherwise, discard it.
    Step 5: Repeat from step 2 until it includes |V| - 1 edges in MST.
    Expected Output Of the code:-
    Enter the number of vertices: 
    Enter the number of edges:
    Enter the details of each edge (source, destination, weight): 
    Give input for the above line in the following manner
    0 1 7
    where 0 is the soucre of edge 1 is the destination and 7 is the weight of the edge*/
import java.util.*;

// Structure to represent an edge
class Edge {
    int src, dest, weight;
    Edge(int src, int dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}

// Structure to represent a graph
class Graph {
    int V, E;
    ArrayList<Edge> edges;

    Graph(int V, int E) {
        this.V = V;
        this.E = E;
        this.edges = new ArrayList<>();
    }
}

// Main class
class Kruskals{
    // Function to find the parent of a node
    static int findParent(int[] parent, int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    // Function to perform union of two sets
    static void unionSets(int[] parent, int x, int y) {
        parent[x] = y;
    }

    // Function to compare two edges based on their weights
    static class EdgeComparator implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            return a.weight - b.weight;
        }
    }

    // Function to apply Kruskal's algorithm and find the minimum spanning tree
    static void kruskalMST(Graph graph) {
        int V = graph.V;
        ArrayList<Edge> result = new ArrayList<>();
        int e = 0;
        int i = 0;

        // Sort the edges in ascending order of their weights
        Collections.sort(graph.edges, new EdgeComparator());

        // Allocate memory for parent array
        int[] parent = new int[V];
        Arrays.fill(parent, -1);

        // Process each edge and add it to the MST if it does not form a cycle
        while (e < V - 1 && i < graph.E) {
            Edge nextEdge = graph.edges.get(i++);

            int x = findParent(parent, nextEdge.src);
            int y = findParent(parent, nextEdge.dest);

            if (x != y) {
                result.add(nextEdge);
                unionSets(parent, x, y);
                e++;
            }
        }

        // Print the edges of the MST
        System.out.println("Edges in the constructed MST:");
        for (Edge edge : result) {
            System.out.println(edge.src + " -- " + edge.dest + "  =>  " + edge.weight);
        }
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();

        Graph graph = new Graph(V, E);

        System.out.println("Enter the details of each edge (source, destination, weight):");
        for (int i = 0; i < E; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.edges.add(new Edge(src, dest, weight));
        }

        kruskalMST(graph);

        scanner.close();
    }
}
