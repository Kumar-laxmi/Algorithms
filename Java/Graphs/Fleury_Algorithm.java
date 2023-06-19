/* 
------------------------------------- Fleury’s Algorithm -------------------------------------

Approach:-
1. Start with any vertex in the graph.

2. While there are unused edges in the graph, do the following steps:
    a. Choose any unused edge connected to the current vertex. It doesn't matter which one you choose.
    b. If removing the chosen edge doesn't disconnect the graph, go to the vertex at the other end of the chosen edge.
    c. If removing the chosen edge disconnects the graph, backtrack to the previous vertex that still has unused edges and choose a different edge.
    d. Repeat steps (a) to (c) until you can no longer choose any unused edges from the current vertex.

3. The algorithm terminates when you have traversed all the edges of the graph.

4. If all the vertices in the graph have even degrees, you will end up with an Eulerian circuit, which is a closed path that visits each edge exactly once.

5. If exactly two vertices in the graph have odd degrees, you will end up with an Eulerian path, which is a path that starts and ends at different vertices and visits each edge exactly once.
*/

// Program Starts
import java.util.ArrayList;
import java.util.Scanner;

// An Undirected graph using adjacency list representation
public class Fleury_Algorithm {

	private int vertices; // No. of vertices
	private ArrayList<Integer>[] adj; // adjacency list

	// Constructor
	Fleury_Algorithm(int numOfVertices) {
		// initialise vertex count
		this.vertices = numOfVertices;

		// initialise adjacency list
		initGraph();
	}

	// utility method to initialise adjacency list
	@SuppressWarnings("unchecked") private void initGraph() {
		adj = new ArrayList[vertices];
		for (int i = 0; i < vertices; i++) {
			adj[i] = new ArrayList<>();
		}
	}

	// add edge source-destination
	private void addEdge(Integer source, Integer destination) {
		adj[source].add(destination);
		adj[destination].add(source);
	}

	// This function removes edge source-destination from graph.
	private void removeEdge(Integer source, Integer destination) {
		adj[source].remove(destination);
		adj[destination].remove(source);
	}

	/* The main function that print Eulerian Trail. It first finds an odd degree vertex (if there
	is any) and then calls printEulerUtil() to print the path */
	private void printEulerTour() {
		// Find a vertex with odd degree
		Integer source = 0;
		for (int i = 0; i < vertices; i++) {
			if (adj[i].size() % 2 == 1) {
				source = i;
				break;
			}
		}

		// Print tour starting from oddv
		printEulerUtil(source);
		System.out.println();
	}

	// Print Euler tour starting from vertex source
	private void printEulerUtil(Integer source) {
		// Recur for all the vertices adjacent to this vertex
		for (int i = 0; i < adj[source].size(); i++) {
			Integer destination = adj[source].get(i);
			// If edge source-destination is a valid next edge
			if (isValidNextEdge(source, destination)) {
				System.out.print(source + "-" + destination + " ");

				// This edge is used so remove it now
				removeEdge(source, destination);
				printEulerUtil(destination);
			}
		}
	}

	// The function to check if edge source-destination can be considered as next edge in Euler Trail
	private boolean isValidNextEdge(Integer source, Integer destination) {
		// The edge source-destination is valid in one of the following two cases:

		// 1) If destination is the only adjacent vertex of source ie size of adjacent vertex list is 1
		if (adj[source].size() == 1) {
			return true;
		}

		// 2) If there are multiple adjacents, then source-destination is not a bridge Do following steps to check if source-destination is a bridge
		// 2.a) count of vertices reachable from source
		boolean[] isVisited = new boolean[this.vertices];
		int count1 = dfsCount(source, isVisited);

		// 2.b) Remove edge (source, destination) and after removing the edge, count vertices reachable from source
		removeEdge(source, destination);
		isVisited = new boolean[this.vertices];
		int count2 = dfsCount(source, isVisited);

		// 2.c) Add the edge back to the graph
		addEdge(source, destination);
		return (count1 > count2) ? false : true;
	}

	// A DFS based function to count reachable vertices from destination
	private int dfsCount(Integer destination, boolean[] isVisited) {
		// Mark the current node as visited
		isVisited[destination] = true;
		int count = 1;
		// Recur for all vertices adjacent to this vertex
		for (int adj : adj[destination]) {
			if (!isVisited[adj]) {
				count = count + dfsCount(adj, isVisited);
			}
		}
		return count;
	}

	// Driver program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices in the graph: ");
        int V = scanner.nextInt();

        Fleury_Algorithm g = new Fleury_Algorithm(V);

        System.out.print("Enter the number of edges in the graph: ");
        int E = scanner.nextInt();

        // Taking input from the user
        System.out.println("Enter the edges in the format (source destination)");
        for (int i = 0; i < E; i++) {
            int source, destination;
            System.out.print("Source " + (i + 1) + " : ");
            source = scanner.nextInt();
            System.out.print("Destination " + (i + 1) + " : ");
            destination = scanner.nextInt();
            g.addEdge(source, destination);
        }

        scanner.close();

        // Printing the final result after analyzing
        System.out.print("\nResult of Fleury Algorithm : ");
        g.printEulerTour();
        System.out.println();
    }
}
