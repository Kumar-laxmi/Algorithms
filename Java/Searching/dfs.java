import java.util.Scanner;
import java.util.Stack;
import java.util.LinkedList;

class dfs {
    static int V;     //Number of vertices 
    static boolean[] visited;
    static LinkedList<Integer>[] adj; // Intialization of Linked List

    static void DFS_iterative(int v) {
        Stack<Integer> stack = new Stack<>();
        stack.push(v);
        while (!stack.isEmpty()) {
            v = stack.pop();
            if (!visited[v]) {
                System.out.print(v + " ");
                visited[v] = true;
            }
            for (Integer i : adj[v]) 
            {
                if (!visited[i]) {
                    stack.push(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        int E,count = 1, to = 0, from = 0;
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

        DFS_iterative(start);
    }
}
