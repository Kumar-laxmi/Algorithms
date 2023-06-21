# Python-program to implement famous Kruskal's Algorithm
# Kruskal's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph.

# The idea is to sort all edges of given graph in increasing order, and then keep on adding new edges and nodes in the spanning tree if the added edge does not form a cycle.


# A minimum spanning tree is constructed from a weighted & undirected graph, so it:
# -> Connects all nodes / vertices
# -> Has no cycles
# -> Has smallest possible sum of edge weights.

def base(a, no):    #base/parent of node
    while no[a] != a:
        no[a] = no[no[a]]
        a = no[a]
    return a

def temp(a, b, no):     # Merge sets containing nodes a and b
    k = base(a, no)
    l = base(b, no)
    no[k] = no[l]

def krus(k, edges, no):
    a, b = 0, 0
    cost = 0
    minCost = 0
    for i in range(edges):
        a = k[i][1][0]
        b = k[i][1][1]
        cost = k[i][0]
        if base(a, no) != base(b, no):
            minCost += cost
            temp(a, b, no)      # Merge sets
    return minCost

maximum = 100000
no = [i for i in range(maximum)]
nodes, edges = map(int, input("Enter Nodes and edges: ").split())
k = []

for i in range(edges):
    a, b, w = map(int, input("Enter the value of a, b, and weight: ").split())
    k.append((w, (a, b)))

k.sort()
minCost = krus(k, edges, no)
print("Minimum cost is", minCost)

# Time Complexity: O(E log N)