from collections import deque
 
 
# A class to represent a graph object
class Graph:
    # Constructor
    def __init__(self, edges, n):
 
        # A list of lists to represent an adjacency list
        self.adjList = [[] for _ in range(n)]
 
        # add edges to the undirected graph
        for (src, dest) in edges:
            self.adjList[src].append(dest)
            self.adjList[dest].append(src)
 
 
# Perform BFS on the graph starting from vertex `v`
def BFS(graph, v, discovered):
 
    # create a queue for doing BFS
    q = deque()
 
    # mark the source vertex as discovered
    discovered[v] = True
 
    # enqueue source vertex
    q.append(v)
 
    # loop till queue is empty
    while q:
 
        # dequeue front node and print it
        v = q.popleft()
        print(v, end=' ')
 
        # do for every edge (v, u)
        for u in graph.adjList[v]:
            if not discovered[u]:
                # mark it as discovered and enqueue it
                discovered[u] = True
                q.append(u)
 
 
if __name__ == '__main__':
 
    # List of graph edges as per the above diagram
    edges = [
        (1, 2), (1, 3), (1, 4), (2, 5), (2, 6), (5, 9),
        (5, 10), (4, 7), (4, 8), (7, 11), (7, 12)
        # vertex 0, 13, and 14 are single nodes
    ]
 
    # total number of nodes in the graph (labelled from 0 to 14)
    n = 15
 
    # build a graph from the given edges
    graph = Graph(edges, n)
 
    # to keep track of whether a vertex is discovered or not
    discovered = [False] * n
 
    # Perform BFS traversal from all undiscovered nodes to
    # cover all connected components of a graph
    for i in range(n):
        if not discovered[i]:
            # start BFS traversal from vertex i
            BFS(graph, i, discovered)
 