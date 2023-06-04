/* I will use Tarjan's Algorithm to find the bridges
   So, what is a bridge -> A bridge of a connected graph is a graph edge whose removal disconnects the graph
   So if we remove the bridge then the graph will be converted into multiple components.

   e.g. 1 ←-----→ 3 ←----→ 4
        ↑       ↗          ↑
        |     ↗            |
        |   ↗              |
        ↓ ↙                ↓
        2                  5

   In the above bidirectional graph, if we remove edge 3-4 then the graph will be broken into two different components so, we can say 3-4 is a bridge.

   T.c.=> O(V+E)
   Auxiliary Space: O(V)

*/
import java.util.ArrayList;
import java.util.List;

class Edge {
    int u;
    int v;

    public Edge(int u, int v) {
        this.u = u;
        this.v = v;
    }
}

class DFSData {
    int node;
    int parent;

    public DFSData(int node, int parent) {
        this.node = node;
        this.parent = parent;
    }
}

class Graph {
    List<Edge> edges;
    int numEdges;
    List<Integer>[] adjList;
    int[] adjListSize;
    int[] tin;
    int[] low;
    int timer;
    boolean[] visited;

    public Graph(int numNodes) {
        edges = new ArrayList<>();
        numEdges = 0;
        adjList = new ArrayList[numNodes];
        adjListSize = new int[numNodes];
        tin = new int[numNodes];
        low = new int[numNodes];
        timer = 1;
        visited = new boolean[numNodes];

        for (int i = 0; i < numNodes; i++) {
            adjList[i] = new ArrayList<>();
            adjListSize[i] = 0;
            visited[i] = false;
        }
    }

    public void addEdge(int u, int v) {
        Edge edge = new Edge(u, v);
        edges.add(edge);
        numEdges++;
        adjList[u].add(v);
        adjList[v].add(u);
        adjListSize[u]++;
        adjListSize[v]++;
    }
    
    public void dfs(int node, int parent, DFSData[] dfsData, int[] numBridges, Edge[] bridges) {
        visited[node] = true;
        tin[node] = low[node] = timer++;

        // Traverse all adjacent nodes of the current node
        for (int i = 0; i < adjListSize[node]; i++) {
            int child = adjList[node].get(i);

            // Skip the parent node to avoid going back in the same path
            if (child == parent)
                continue;

            // If the child node is not visited, perform DFS on it
            if (!visited[child]) {
                // Store the DFS data of the child node
                dfsData[child] = new DFSData(child, node);

                dfs(child, node, dfsData, numBridges, bridges);

                // Update the low value of the current node based on the child's low value
                low[node] = Math.min(low[node], low[child]);

                // If the low value of the child is greater than the tin value of the current node,
                // it means the edge is a bridge
                if (low[child] > tin[node]) {
                    bridges[numBridges[0]] = new Edge(node, child);
                    numBridges[0]++;
                }
            } else {
                // If the child node is already visited, update the low value of the current node
                // based on the child's tin value
                low[node] = Math.min(low[node], tin[child]);
            }
        }
    }

    public Edge[] findBridges() {
        DFSData[] dfsData = new DFSData[adjList.length];
        int[] numBridges = {0};
        Edge[] bridges = new Edge[numEdges];

        // Perform DFS on the graph starting from node 0
        dfs(0, -1, dfsData, numBridges, bridges);

        return bridges;
    }
}

public class TarjanAlgorithm {
    public static void main(String[] args) {
        int numNodes = 5;
        Graph graph = new Graph(numNodes);

        graph.addEdge(0, 1);
        graph.addEdge(1, 3);
        graph.addEdge(1, 2);
        graph.addEdge(2, 4);

        Edge[] bridges = graph.findBridges();

        System.out.println(bridges.length + " bridges found!");

        for (Edge bridge : bridges) {
            System.out.println(bridge.u + " --> " + bridge.v);
        }
    }
}
