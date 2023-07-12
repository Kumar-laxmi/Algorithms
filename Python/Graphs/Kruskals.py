"""Kruskals Algorithm
    Author: Phalesh Kolpe
    Kruskals algorithm is used to Find the MST(Minimum Spaning Tree) of a graph it considers the edges and weight of the edge
    Step 1: Sort all edges in increasing order of their edge weights.
    Step 2: Pick the smallest edge.
    Step 3: Check if the new edge creates a cycle or loop in a spanning tree.
    Step 4: If it doesn't form the cycle, then include that edge in MST. Otherwise, discard it.
    Step 5: Repeat from step 2 until it includes |V| - 1 edges in MST.
    Expected Output Of the code:-
    Enter the number of edges: 
    Enter the source vertex of the edge: 
    Enter the destination vertex of the edge: 
    Enter the weight of the edge: 
    """

class Graph:
    def __init__(self):
        self.vertices = {}  # Map vertices to integer indices
        self.edges = []     # Graph edges

    # Add a vertex to the graph
    def add_vertex(self, vertex):
        if vertex not in self.vertices:
            index = len(self.vertices)
            self.vertices[vertex] = index

    # Add an edge to the graph
    def add_edge(self, src, dest, weight):
        self.edges.append((src, dest, weight))

    # Find set of an element i
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    # Union of two sets
    def union(self, parent, rank, x, y):
        x_root = self.find(parent, x)
        y_root = self.find(parent, y)

        if rank[x_root] < rank[y_root]:
            parent[x_root] = y_root
        elif rank[x_root] > rank[y_root]:
            parent[y_root] = x_root
        else:
            parent[y_root] = x_root
            rank[x_root] += 1

    # Kruskal's algorithm
    def kruskal(self):
        result = []          # MST result
        i = 0                # Index variable for sorted edges
        e = 0                # Index variable for result[]

        # Sort all the edges in non-decreasing order of their weight
        self.edges = sorted(self.edges, key=lambda item: item[2])

        parent = {}
        rank = {}

        # Create subsets with single elements
        for vertex in self.vertices:
            parent[vertex] = vertex
            rank[vertex] = 0

        while e < len(self.vertices) - 1:
            src, dest, weight = self.edges[i]
            i += 1
            x = self.find(parent, src)
            y = self.find(parent, dest)

            if x != y:
                e += 1
                result.append((src, dest, weight))
                self.union(parent, rank, x, y)

        # Print the constructed MST
        print("Edges in the constructed MST:")
        for src, dest, weight in result:
            print(f"{src} -- {dest}  =>  {weight}")


# Example usage
g = Graph()

num_edges = int(input("Enter the number of edges: "))
for _ in range(num_edges):
    src = input("Enter the source vertex of the edge: ")
    dest = input("Enter the destination vertex of the edge: ")
    weight = int(input("Enter the weight of the edge: "))

    g.add_vertex(src)
    g.add_vertex(dest)
    g.add_edge(src, dest, weight)

g.kruskal()
