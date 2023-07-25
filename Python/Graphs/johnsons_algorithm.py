from heapq import heappop, heappush
from math import inf

class Edge:
    def __init__(self, source, destination, weight):
        self.source = source
        self.destination = destination
        self.weight = weight

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.edges = []

    def addEdge(self, source, destination, weight):
        self.edges.append(Edge(source, destination, weight))

    # Bellman-Ford algorithm to find the minimum distance from a single source to all vertices
    def bellmanFord(self, source):
        distances = [inf] * self.V
        distances[source] = 0

        for _ in range(self.V - 1):
            for edge in self.edges:
                u, v, w = edge.source, edge.destination, edge.weight
                if distances[u] != inf and distances[u] + w < distances[v]:
                    distances[v] = distances[u] + w

        # Check for negative cycles
        for edge in self.edges:
            u, v, w = edge.source, edge.destination, edge.weight
            if distances[u] != inf and distances[u] + w < distances[v]:
                return None

        return distances

    # Dijkstra's algorithm to find the shortest paths from a single source to all vertices
    def dijkstra(self, source):
        distances = [inf] * self.V
        distances[source] = 0

        pq = [(0, source)]

        while pq:
            dist_u, u = heappop(pq)

            for edge in self.edges:
                if edge.source == u:
                    v, w = edge.destination, edge.weight
                    if distances[u] != inf and distances[u] + w < distances[v]:
                        distances[v] = distances[u] + w
                        heappush(pq, (distances[v], v))

        return distances

    # Johnson's algorithm to find the shortest paths between all pairs of vertices
    def johnsonAlgorithm(self):
        # Add a new vertex with zero-weight edges to all other vertices
        new_vertex = self.V
        for i in range(self.V):
            self.addEdge(new_vertex, i, 0)

        # Run Bellman-Ford algorithm to get the shortest paths from the new vertex
        h = self.bellmanFord(new_vertex)
        if h is None:
            print("Graph contains a negative cycle. Johnson's algorithm cannot proceed.")
            return [[inf] * self.V for _ in range(self.V)]

        # Re-weight the edges
        for edge in self.edges:
            u, v, w = edge.source, edge.destination, edge.weight
            edge.weight = w + h[u] - h[v]

        all_pairs_distances = [[inf] * self.V for _ in range(self.V)]

        # Run Dijkstra's algorithm for each vertex to find the shortest paths
        for i in range(self.V):
            dijkstra_distances = self.dijkstra(i)

            for j in range(self.V):
                # Update the distance by reverting the re-weighting
                all_pairs_distances[i][j] = dijkstra_distances[j] + h[j] - h[i]

        return all_pairs_distances

def main():
    V = int(input("Enter the number of vertices: "))
    E = int(input("Enter the number of edges: "))

    graph = Graph(V)

    print("Enter edge information (source, destination, weight) for each edge:")
    for _ in range(E):
        source, destination, weight = map(int, input().split())
        graph.addEdge(source, destination, weight)

    all_pairs_distances = graph.johnsonAlgorithm()

    print("Shortest distances between all pairs of vertices:")
    for i in range(V):
        for j in range(V):
            if all_pairs_distances[i][j] == inf:
                print("INF", end=" ")
            else:
                print(all_pairs_distances[i][j], end=" ")
        print()

if __name__ == "__main__":
    main()
