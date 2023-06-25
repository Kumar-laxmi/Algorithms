import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class BipartiteGraph {
    private List<Integer>[] adj;
    private int[] pairU;
    private int[] pairV;
    private int[] dist;

    public BipartiteGraph(int uVertices, int vVertices) {
        adj = new List[uVertices + 1];
        for (int i = 1; i <= uVertices; i++) {
            adj[i] = new ArrayList<>();
        }
        pairU = new int[uVertices + 1];
        pairV = new int[vVertices + 1];
        dist = new int[uVertices + 1];
    }

    public void addEdge(int u, int v) {
        adj[u].add(v);
    }

    public int maxMatching() {
        int n = pairU.length - 1;
        int m = pairV.length - 1;

        int matching = 0;
        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (pairU[u] == 0 && dfs(u)) {
                    matching++;
                }
            }
        }

        return matching;
    }

    private boolean bfs() {
        int n = pairU.length - 1;
        int m = pairV.length - 1;

        for (int u = 1; u <= n; u++) {
            if (pairU[u] == 0) {
                dist[u] = 0;
            } else {
                dist[u] = Integer.MAX_VALUE;
            }
        }
        dist[0] = Integer.MAX_VALUE;

        boolean foundAugmentingPath = true;
        while (foundAugmentingPath) {
            foundAugmentingPath = false;

            for (int u = 1; u <= n; u++) {
                if (pairU[u] == 0) {
                    if (bfsVisit(u)) {
                        foundAugmentingPath = true;
                    }
                }
            }
        }

        return pairU[0] != 0;
    }

    private boolean bfsVisit(int u) {
        if (u == 0) {
            return true;
        }

        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1) {
                if (bfsVisit(pairV[v])) {
                    pairU[u] = v;
                    pairV[v] = u;
                    return true;
                }
            }
        }

        dist[u] = Integer.MAX_VALUE;
        return false;
    }

    private boolean dfs(int u) {
        if (u == 0) {
            return true;
        }

        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v])) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }

        dist[u] = Integer.MAX_VALUE;
        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        int uVertices = 4;
        int vVertices = 3;

        BipartiteGraph graph = new BipartiteGraph(uVertices, vVertices);

        // Adding edges to the graph
        graph.addEdge(1, 1);
        graph.addEdge(1, 2);
        graph.addEdge(2, 2);
        graph.addEdge(2, 3);
        graph.addEdge(3, 2);
        graph.addEdge(4, 3);

       
