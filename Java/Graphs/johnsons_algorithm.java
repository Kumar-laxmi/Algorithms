import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Edge {
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight) {
        this.source = source;
        this.destination = destination;
        this.weight = weight;
    }
}

class Graph {
    private int V;
    private List<Edge> edges;

    Graph(int vertices) {
        V = vertices;
        edges = new ArrayList<>();
    }

    void addEdge(int source, int destination, int weight) {
        edges.add(new Edge(source, destination, weight));
    }

    // Bellman-Ford algorithm to find the minimum distance from a single source to all vertices
    private int[] bellmanFord(int source) {
        int[] distances = new int[V];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (Edge edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;

                if (distances[u] != Integer.MAX_VALUE && distances[u] + w < distances[v])
                    distances[v] = distances[u] + w;
            }
        }

        // Check for negative cycles
        for (Edge edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distances[u] != Integer.MAX_VALUE && distances[u] + w < distances[v]) {
                System.out.println("Graph contains a negative cycle. Johnson's algorithm cannot proceed.");
                return null;
            }
        }

        return distances;
    }

    // Dijkstra's algorithm to find the shortest paths from a single source to all vertices
    private int[] dijkstra(int source) {
        int[] distances = new int[V];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;

        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.weight - b.weight);
        pq.offer(new Edge(source, source, 0));

        while (!pq.isEmpty()) {
            Edge current = pq.poll();

            if (current.weight > distances[current.destination])
                continue;

            for (Edge edge : edges) {
                if (edge.source == current.destination) {
                    int v = edge.destination;
                    int w = edge.weight;

                    if (distances[current.destination] != Integer.MAX_VALUE && distances[current.destination] + w < distances[v]) {
                        distances[v] = distances[current.destination] + w;
                        pq.offer(new Edge(current.destination, v, distances[v]));
                    }
                }
            }
        }

        return distances;
    }

    // Johnson's algorithm to find the shortest paths between all pairs of vertices
    int[][] johnsonAlgorithm() {
        // Add a new vertex with zero-weight edges to all other vertices
        int newVertex = V;
        for (int i = 0; i < V; ++i)
            addEdge(newVertex, i, 0);

        // Run Bellman-Ford algorithm to get the shortest paths from the new vertex
        int[] h = bellmanFord(newVertex);
        if (h == null)
            return new int[V][V];

        // Re-weight the edges
        for (Edge edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            edge.weight = w + h[u] - h[v];
        }

        int[][] allPairsDistances = new int[V][V];

        // Run Dijkstra's algorithm for each vertex to find the shortest paths
        for (int i = 0; i < V; ++i) {
            int[] dijkstraDistances = dijkstra(i);

            for (int j = 0; j < V; ++j) {
                // Update the distance by reverting the re-weighting
                allPairsDistances[i][j] = dijkstraDistances[j] + h[j] - h[i];
            }
        }

        return allPairsDistances;
    }
}

public class Main {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int V = input.nextInt();
        System.out.print("Enter the number of edges: ");
        int E = input.nextInt();

        Graph graph = new Graph(V);

        System.out.println("Enter edge information (source, destination, weight) for each edge:");
        for (int i = 0; i < E; ++i) {
            int source = input.nextInt();
            int destination = input.nextInt();
            int weight = input.nextInt();
            graph.addEdge(source, destination, weight);
        }

        int[][] allPairsDistances = graph.johnsonAlgorithm();

        System.out.println("Shortest distances between all pairs of vertices:");
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (allPairsDistances[i][j] == Integer.MAX_VALUE)
                    System.out.print("INF ");
                else
                    System.out.print(allPairsDistances[i][j] + " ");
            }
            System.out.println();
        }
    }
}
