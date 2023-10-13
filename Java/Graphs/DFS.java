
import java.util.*;

 public class DFS {
    static int[][] G;
    static int[] visited;
    static int n;
    static int s;

    public static void DFS(int i) {
        System.out.print(i + " ");
        visited[i] = 1;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 0 && G[i][j] == 1) {
                DFS(j);
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of nodes in the graph : ");
        n = input.nextInt();

        G = new int[n + 1][n + 1];
        visited = new int[n + 1];
        //1-indexed graph
        System.out.println("Enter values of adjacency matrix of the graph:");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = input.nextInt();
            }
        }

        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
        }

        System.out.print("Enter source node: ");
        s = input.nextInt();

        System.out.print("Depth First Traversal: ");
        DFS(s);
    }
}