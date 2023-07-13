#   The Bron-Kerbosch is a algorithm to find all maximal cliques (complete subgraphs) in an undirected graph.
#   Clique: Set of vertices such that every pair of vertices is connected by an edge.
#   Maximal Clique: A clique is maximal if it cannot be extended by adding another vertex in the graph.

def bron_kerbosch(clique, potential, excluded, graph):
    if not potential and not excluded:
        print("Maximal Clique:", end=" ")
        print(*clique)
        return

    potential_copy = potential.copy()
    for vertex in potential_copy:
        new_clique = clique.copy()
        new_clique.add(vertex)
        new_potential = set()
        new_excluded = set()

        for neighbor in potential:
            if graph[vertex][neighbor] == 1:
                new_potential.add(neighbor)
        for neighbor in excluded:
            if graph[vertex][neighbor] == 1:
                new_excluded.add(neighbor)

        bron_kerbosch(new_clique, new_potential, new_excluded, graph)

        potential.remove(vertex)
        excluded.add(vertex)


if __name__ == "__main__":
    N = int(input("Enter the number of vertices: "))

    graph = [[0] * N for _ in range(N)]
    print("Enter the adjacency matrix:")
    for i in range(N):
        graph[i] = list(map(int, input().split()))

    clique = set()
    potential = set(range(N))
    excluded = set()

    bron_kerbosch(clique, potential, excluded, graph)
