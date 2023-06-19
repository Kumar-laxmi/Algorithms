class Graph:

    def __init__(self, vertices):

        self.V = vertices  # number of vertices in the graph
        self.graph = []  # Array of edges

    # function for adding edges

    def add_edge(self, u, v, wt):
        # An edge from u--> with edge weight wt

        self.graph.append([u, v, wt])

    # Function for the implementation of BellmanFord Algorithm

    def bellman_ford(self, src):

        # A distance array to store shortest path from the source vertex
        # Initializing the distance from the source vertex to any other vertex as Infinity
        # and distance from source vertex to source vertex as 0

        dist = [float("Inf")] * self.V
        dist[src] = 0

        # Relaxing all the edges |number of vertices-1| times
        for _ in range(self.V - 1):

            for u, v, wt in self.graph:
                # if we get a shorter path, we update the distance array

                if dist[u] != float("Inf") and dist[u] + wt < dist[v]:
                    dist[v] = dist[u] + wt

        # To check if the graph contains negative edge cycle, we do relaxation
        # of AdjacencyList one more time
        # If distance array gets updated, then we say that there is a negative
        # weight cycle in this graph

        for u, v, wt in self.graph:

            if dist[u] != float("Inf") and  dist[u] + wt < dist[v]:
                print("Graph contains negative weight cycle")

                return

        # If the graph doesn't have negative weight cycle, we print the distance array
        
        print("Vertex  Distance from Source")

        for j in range(self.V):
            print("{0}\t\t{1}".format(j, dist[j]))


g = Graph(6)

g.add_edge(0, 1, 5)

g.add_edge(1, 2, -2)

g.add_edge(1, 5, -3)

g.add_edge(2, 4, 3)

g.add_edge(3, 2, 6)

g.add_edge(3, 4, -2)

g.add_edge(5, 3, 1)

g.bellman_ford(0)
