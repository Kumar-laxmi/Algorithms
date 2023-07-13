/*
 *   The Bron-Kerbosch is a algorithm to find all maximal cliques (complete subgraphs) in an undirected graph.
 *   Clique: Set of vertices such that every pair of vertices is connected by an edge.
 *   Maximal Clique: A clique is maximal if it cannot be extended by adding another vertex in the graph.
 */
import java.util.*;

public class BronKerbosch {

    public static void bronKerbosch(Set<Integer> clique, Set<Integer> potential, Set<Integer> excluded, int[][] graph) {
        if (potential.isEmpty() && excluded.isEmpty()) {
            System.out.print("Maximal Clique: ");
            for (int vertex : clique) {
                System.out.print(vertex + " ");
            }
            System.out.println();
            return;
        }

        Set<Integer> potentialCopy = new HashSet<>(potential);
        for (int vertex : potentialCopy) {
            Set<Integer> newClique = new HashSet<>(clique);
            newClique.add(vertex);
            Set<Integer> newPotential = new HashSet<>();
            Set<Integer> newExcluded = new HashSet<>();

            for (int neighbor : potential) {
                if (graph[vertex][neighbor] == 1) {
                    newPotential.add(neighbor);
                }
            }
            for (int neighbor : excluded) {
                if (graph[vertex][neighbor] == 1) {
                    newExcluded.add(neighbor);
                }
            }

            bronKerbosch(newClique, newPotential, newExcluded, graph);

            potential.remove(vertex);
            excluded.add(vertex);
        }
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the number of vertices: ");
            int N = scanner.nextInt();

            int[][] graph = new int[N][N];
            System.out.println("Enter the adjacency matrix:");
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    graph[i][j] = scanner.nextInt();
                }
            }

            Set<Integer> clique = new HashSet<>();
            Set<Integer> potential = new HashSet<>();
            Set<Integer> excluded = new HashSet<>();
            for (int i = 0; i < N; ++i) {
                potential.add(i);
            }

            bronKerbosch(clique, potential, excluded, graph);
        }
    }
}