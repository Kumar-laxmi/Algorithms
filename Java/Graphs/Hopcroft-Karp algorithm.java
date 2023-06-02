import java.util.*;

class HopcroftKarp {
    private static final int NIL = 0;
    private static final int INF = Integer.MAX_VALUE;

    private int n, m;
    private List<List<Integer>> graph;
    private int[] match;
    private int[] dist;

    public HopcroftKarp(int n, int m) {
        this.n = n;
        this.m = m;
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        match = new int[n + m + 1];
        dist = new int[n + m + 1];
        Arrays.fill(dist, INF);
    }

    public void addEdge(int u, int v) {
        graph.get(u).add(v);
    }

    private boolean bfs() {
        Queue<Integer> queue = new LinkedList<>();
        for (int u = 1; u <= n; u++) {
            if (match[u] == NIL) {
                dist[u] = 0;
                queue.add(u);
            } else {
                dist[u] = INF;
            }
        }

        dist[NIL] = INF;

        while (!queue.isEmpty()) {
            int u = queue.poll();
            if (dist[u] < dist[NIL]) {
                for (int v : graph.get(u)) {
                    if (dist[match[v]] == INF) {
                        dist[match[v]] = dist[u] + 1;
                        queue.add(match[v]);
                    }
                }
            }
        }

        return dist[NIL] != INF;
    }

    private boolean dfs(int u) {
        if (u != NIL) {
            for (int v : graph.get(u)) {
                if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }

            dist[u] = INF;
            return false;
        }

        return true;
    }

    public int maxMatching() {
        int matching = 0;

        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (match[u] == NIL && dfs(u)) {
                    matching++;
                }
            }
        }

        return matching;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices in the left set: ");
        int n = scanner.nextInt();
        System.out.print("Enter the number of vertices in the right set: ");
        int m = scanner.nextInt();
        System.out.print("Enter the number of edges: ");
        int e = scanner.nextInt();

        HopcroftKarp hk = new HopcroftKarp(n, m);

        System.out.println("Enter the edges:");
        for (int i = 0; i < e; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            hk.addEdge(u, v);
        }

        int maxMatching = hk.maxMatching();
        System.out.println("Maximum Matching: " + maxMatching);
    }
}
