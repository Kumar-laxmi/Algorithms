import java.util.*;
import java.io.*;

public class BreadthFirstSearch {
	
	class Graph {
	
		private int v; // No. of vertices
		private LinkedList<Integer> adj[]; 	// Adjacency Lists
	
		Graph(int v) {
			this.v = v;
			adj = new LinkedList[v];
			for (int i = 0; i < v; ++i)
				adj[i] = new LinkedList<Integer>();
		}
	
		void addEdge(int v, int w) { 
			adj[v].add(w);
			adj[w].add(v);
		}
	
		// BFS traversal from a given source node 's'
		void BFS(int s) {
	
			boolean visited[] = new boolean[v];
	
			// Create a queue for BFS traversal
			LinkedList<Integer> queue = new LinkedList<Integer>();
	
			// Mark the current node as visited and add into queue
			queue.add(s);
			visited[s] = true;
	
			while (!queue.isEmpty()) {
	
				// Remove a vertex from queue and print it
				int curr = queue.poll();
				System.out.print(curr+ " ");
			
				// Get all adjacent vertices of the dequeued vertex s.
				// If an adjacent has not been visited, then mark it visited and enqueue it
				for (int nbr : adj[curr]) {
					if (!visited[nbr]) {
						queue.add(nbr);
						visited[nbr] = true;
					}
				}
			}
		}	
	}

	public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the no. of vertices and edges:");
        String[] inp = br.readLine().split(" ");
        int N = Integer.parseInt(inp[0]);
		int M = Integer.parseInt(inp[1]);
		BreadthFirstSearch obj = new BreadthFirstSearch();
        Graph g = obj.new Graph(N);
        for (int i = 1; i <= M; i++) {
            System.out.println("Enter edge No. " + i + ":");
            inp = br.readLine().split(" ");
            int u = Integer.parseInt(inp[0]);
            int v = Integer.parseInt(inp[1]);
            g.addEdge(u, v);
        }

        System.out.println("Enter source vertex: ");
        int s = Integer.parseInt(br.readLine());

		g.BFS(s);
	}
}

