import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Multisource_Shortest_Path {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n,m,s;
        System.out.println("Enter number of vertices, edges and sources");

        n = sc.nextInt();
        m = sc.nextInt();
        s = sc.nextInt();

        ArrayList<Integer>[] adj = new ArrayList[n+1];
        int[] sources = new int[n+1];

        System.out.println("Enter sources");

        for (int i = 0;i<s;i++) {
            int src;
            src = sc.nextInt();

            sources[i] = src;
        }

        System.out.println("Enter the edges");

        for(int i = 1;i<=n;i++) {
            adj[i] = new ArrayList<Integer>();
        }

        for (int i = 0;i<m;i++) {
            int u,v;

            u = sc.nextInt();
            v = sc.nextInt();

            adj[u].add(v);
            adj[v].add(u);
        }

        int dist[] = new int[n+1];
        int vis[] = new int[n+1];

        for (int i = 0;i<=n;i++) {
            dist[i] = 1000000000;
        }

        Queue<Integer> q = new LinkedList<Integer>();

        for(int i = 0;i<s;i++) {
            q.add(sources[i]);
            vis[sources[i]] = 1;
        }

        int lvl = 0;

        while (q.size() > 0) {

            int sz = q.size();

            for(int i = 0;i<sz;i++) {
                int node = q.remove();
                dist[node] = lvl;

                for(int it: adj[node]) {
                    if(vis[it] == 1) {
                        continue;
                    }

                    vis[it] = 1;
                    q.add(it);
                }
            }

            lvl++;
        }

        for (int i = 1;i<=n;i++) {
            System.out.println(i + ": " + dist[i]);
        }

    }
}
