import java.util.*;

class Graph {
    private int V;
    private int E;
    private Edge[] edges;

    public Graph(int V, int E) {
        this.V = V;
        this.E = E;
        edges = new Edge[E];
    }

    private static class Edge {
        int source;
        int destination;
        int weight;

        public Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }

    public void addEdge(int source, int destination, int weight) {
        edges[E++] = new Edge(source, destination, weight);
    }

    private boolean bellmanFord(int source, int[] distances) {
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

        for (Edge edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distances[u] != Integer.MAX_VALUE && distances[u] + w < distances[v])
                return false;
        }

        return true;
    }

    public void dijkstra(int source, int[] distances) {
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;

        PriorityQueue<Node> minHeap = new PriorityQueue<>((a, b) -> a.dist - b.dist);
        for (int i = 0; i < V; ++i)
            minHeap.offer(new Node(i, distances[i]));

        while (!minHeap.isEmpty()) {
            Node minNode = minHeap.poll();
            int u = minNode.v;

            for (Edge edge : edges) {
                if (edge.source == u) {
                    int v = edge.destination;
                    int weight = edge.weight;

                    if (distances[u] != Integer.MAX_VALUE && distances[u] + weight < distances[v]) {
                        distances[v] = distances[u] + weight;
                        // Update distance in the min heap
                        for (Node node : minHeap) {
                            if (node.v == v) {
                                node.dist = distances[v];
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    private static class Node {
        int v;
        int dist;

        public Node(int v, int dist) {
            this.v = v;
            this.dist = dist;
        }
    }

    public void johnsonAlgorithm() {
        int newVertex = V;

        for (int i = 0; i < V; ++i)
            addEdge(newVertex, i, 0);

        int[] h = new int[V + 1];
        if (!bellmanFord(newVertex, h)) {
            System.out.println("Graph contains a negative cycle. Johnson's algorithm cannot proceed.");
            return;
        }

        for (Edge edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            edge.weight = w + h[u] - h[v];
        }

        System.out.println("Shortest distances between all pairs of vertices:");
        for (int i = 0; i < V; ++i) {
            int[] distances = new int[V];
            dijkstra(i, distances);

            for (int j = 0; j < V; ++j) {
                distances[j] = distances[j] - h[i] + h[j];

                if (distances[j] == Integer.MAX_VALUE)
                    System.out.print("INF ");
                else
                    System.out.print(distances[j] + " ");
            }

            System.out.println();
        }
    }
}

public class JohnsonsAlgorithm {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();

        Graph graph = new Graph(V, E);

        System.out.println("Enter edge information (source, destination, weight) for each edge:");
        for (int i = 0; i < E; ++i) {
            int source = scanner.nextInt();
            int destination = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(source, destination, weight);
        }

        graph.johnsonAlgorithm();

        scanner.close();
    }
}
