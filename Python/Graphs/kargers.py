import random

# A class to represent a subset for the Union-Find algorithm
class Subset:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

# A class to represent an unweighted edge in the graph
class Edge:
    def __init__(self, src, dest):
        self.src = src
        self.dest = dest

# A class to represent a connected, undirected, and unweighted graph
class Graph:
    def __init__(self, vertices, edges):
        self.vertices = vertices
        self.edges = edges

# A utility function to find the subset to which a particular vertex belongs (uses path compression technique)
def find(subsets, i):
    if subsets[i].parent != i:
        subsets[i].parent = find(subsets, subsets[i].parent)
    return subsets[i].parent

# A function that performs union of two subsets (uses union by rank)
def union(subsets, x, y):
    x_root = find(subsets, x)
    y_root = find(subsets, y)

    if subsets[x_root].rank < subsets[y_root].rank:
        subsets[x_root].parent = y_root
    elif subsets[x_root].rank > subsets[y_root].rank:
        subsets[y_root].parent = x_root
    else:
        subsets[y_root].parent = x_root
        subsets[x_root].rank += 1

# Karger's algorithm to find the minimum cut in a graph
def karger_min_cut(graph):
    vertices = graph.vertices
    edges = graph.edges

    # Create subsets for each vertex
    subsets = []
    for v in range(vertices):
        subsets.append(Subset(v, 0))

    # Initially, there are 'vertices' in the contracted graph
    num_vertices = vertices

    # Keep contracting vertices until there are only 2 vertices left
    while num_vertices > 2:
        # Pick a random edge
        random_edge = random.choice(edges)

        # Find the subsets of the source and destination vertices of the edge
        subset_src = find(subsets, random_edge.src)
        subset_dest = find(subsets, random_edge.dest)

        # If the source and destination vertices belong to the same subset, skip this edge
        if subset_src == subset_dest:
            continue

        # Contract the edge (merge the subsets of the source and destination vertices)
        union(subsets, subset_src, subset_dest)
        num_vertices -= 1

    # Count the number of remaining edges between the two final subsets
    min_cut = 0
    for edge in edges:
        subset_src = find(subsets, edge.src)
        subset_dest = find(subsets, edge.dest)
        if subset_src != subset_dest:
            min_cut += 1

    return min_cut

# Driver program to test the algorithm
def main():
    # Create a graph with 4 vertices and 5 edges
    V = 4
    E = 5
    graph = Graph(V, [Edge(0, 1), Edge(0, 2), Edge(0, 3), Edge(1, 2), Edge(2, 3)])

    # Run Karger's algorithm to find the minimum cut
    min_cut = karger_min_cut(graph)
    print("Minimum cut found by Karger's algorithm:", min_cut)

if __name__ == '__main__':
    main()
