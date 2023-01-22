import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class bfs {
    static int V;  // Number of vertices 
    static int E;  // Number of edges 
    static boolean[] visited;
    static LinkedList<Integer>[] adj;   // Intialization of Linked List

    static void BFS_iterative(int v) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(v);
        visited[v] = true;
        while (!queue.isEmpty()) {
            v = queue.poll();
            System.out.print(v + " ");
            for (Integer i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        int count = 1, to = 0, from = 0;
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        V = sc.nextInt();
        
        visited = new boolean[V];
        adj = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();
        }

        
        System.out.print("Enter the number of edges: ");
        E = sc.nextInt();
        System.out.println("Enter the edges in the format <to> <from> : ");
         while (count <= E) 
            {
                to = sc.nextInt();
                from = sc.nextInt();
 
                adj[to].add(from);
                count++;
            }

        System.out.print("Enter the starting vertex: ");
        int start = sc.nextInt();

        BFS_iterative(start);
    }
}