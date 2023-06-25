import java.util.*;

class DisjointSetUnion {
    static int[] parent = new int[1000000];

    // Find the root/representative of a vertex
    static int root(int a) {
        if (a == parent[a]) {
            return a;
        }
        // Path compression - Set the parent of 'a' to its root
        return parent[a] = root(parent[a]);
    }

    // Connect two components by setting their parent
    static void connect(int a, int b) {
        a = root(a);
        b = root(b);

        if (a != b) {
            // Union by setting the parent of 'b' to 'a'
            parent[b] = a;
        }
    }

    // Count the number of connected components
    static void connectedComponents(int n) {
        HashSet<Integer> s = new HashSet<Integer>();

        for (int i = 0; i < n; i++) {
            // Add the root of each vertex to the set
            s.add(root(parent[i]));
        }
        System.out.println("Number of connected components: " + s.size());
    }

    static void printAnswer(int N, int[][] edges) {
        // Initialize each vertex as its own parent
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }
        // Connect the edges
        for (int i = 0; i < edges.length; i++) {
            connect(edges[i][0], edges[i][1]);
        }
        // Print the number of connected components
        connectedComponents(N);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int N = scanner.nextInt();

        System.out.print("Enter the number of edges: ");
        int m = scanner.nextInt();

        int[][] edges = new int[m][2];

        System.out.println("Enter the edges:");
        for (int i = 0; i < m; i++) {
            edges[i][0] = scanner.nextInt();
            edges[i][1] = scanner.nextInt();
        }

        System.out.println("\nInput:");
        System.out.println("Number of vertices: " + N);
        System.out.println("Edges:");
        for (int i = 0; i < m; i++) {
            System.out.println(edges[i][0] + " " + edges[i][1]);
        }

        System.out.println("\nOutput:");
        printAnswer(N, edges);

        scanner.close();
    }
}
