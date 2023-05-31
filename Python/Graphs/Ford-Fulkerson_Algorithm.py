# Path: Python\Graphs\Ford-Fulkerson_Algorithm.py
# Ford-Fulkerson algorithm in Python:
    #Time-Complexity: O(E * maxFlow) where E is the number of edges in the graph.
    #Space-Complexity: O(V^2)  where V is the number of vertices in the graph.

from collections import deque
from math import inf

class Edge:
    def __init__(self, u, v, capacity):
        self.u = u
        self.v = v
        self.capacity = capacity
        self.flow = 0

def addEdge(graph, u, v, capacity):
    edge1 = Edge(u, v, capacity)
    edge2 = Edge(v, u, 0)
    graph[u].append(edge1)
    graph[v].append(edge2)

def bfs(residualGraph, parent, source, sink):
    visited = [False] * len(residualGraph)
    queue = deque()

    queue.append(source)
    visited[source] = True
    parent[source] = None

    while queue:
        u = queue.popleft()

        for edge in residualGraph[u]:
            v = edge.v
            if not visited[v] and edge.capacity > edge.flow:
                queue.append(v)
                visited[v] = True
                parent[v] = u

    return visited[sink]

def fordFulkerson(graph, source, sink):
    maxFlow = 0
    n = len(graph)

    residualGraph = [[] for _ in range(n)]
    for u in range(n):
        for edge in graph[u]:
            v = edge.v
            capacity = edge.capacity - edge.flow
            addEdge(residualGraph, u, v, capacity)

    parent = [None] * n

    while bfs(residualGraph, parent, source, sink):
        pathFlow = inf

        v = sink
        while v != source:
            u = parent[v]
            for edge in residualGraph[u]:
                if edge.v == v:
                    pathFlow = min(pathFlow, edge.capacity)
                    break

            v = parent[v]

        v = sink
        while v != source:
            u = parent[v]
            for edge in residualGraph[u]:
                if edge.v == v:
                    edge.flow += pathFlow
                    for reverseEdge in residualGraph[v]:
                        if reverseEdge.v == u:
                            reverseEdge.flow -= pathFlow
                            break
                    break

            v = parent[v]

        maxFlow += pathFlow

    return maxFlow

if __name__ == "__main__":
    n = 6  # Number of vertices in the graph

    graph = [[] for _ in range(n)]  # Adjacency list to represent the graph

    # Adding edges to the graph
    addEdge(graph, 0, 1, 16)
    addEdge(graph, 0, 2, 13)
    addEdge(graph, 1, 2, 10)
    addEdge(graph, 1, 3, 12)
    addEdge(graph, 2, 1, 4)
    addEdge(graph, 2, 4, 14)
    addEdge(graph, 3, 2, 9)
    addEdge(graph, 3, 5, 20)
    addEdge(graph, 4, 3, 7)
    addEdge(graph, 4, 5, 4)

    source = 0  # Source vertex
    sink = 5  # Sink vertex

    maxFlow = fordFulkerson(graph, source, sink)
    print("Maximum Flow:", maxFlow)



'''
# Pseudocode for Ford-Fulkerson algorithm in Python:-->>

function addEdge(graph, u, v, capacity):
    create an edge e1 from u to v with capacity
    create an edge e2 from v to u with capacity 0
    add e1 to the adjacency list of u in graph
    add e2 to the adjacency list of v in graph

function bfs(residualGraph, parent, source, sink):
    create a visited array of size n and initialize all elements as false
    create an empty queue

    enqueue the source vertex into the queue
    mark the source vertex as visited
    set the parent of the source vertex as None

    while the queue is not empty:
        dequeue a vertex u from the queue

        for each edge in the residual graph[u]:
            if the edge capacity minus the edge flow is greater than 0 and the destination vertex v is not visited:
                enqueue v into the queue
                mark v as visited
                set the parent of v as u

    return true if there is a path from source to sink in the residual graph, else return false

function fordFulkerson(graph, source, sink):
    initialize maxFlow as 0
    create a residual graph with the same size as the original graph, initially with all capacities and flows set to 0

    for each edge (u, v) in the graph:
        add the edge (u, v, capacity) to the residual graph
        add the edge (v, u, 0) to the residual graph

    create a parent array of size n and initialize all elements as None

    while bfs(residualGraph, parent, source, sink) is true:
        set pathFlow as infinity

        set v as the sink vertex
        while v is not the source vertex:
            set u as the parent of v
            for each edge in the residual graph[u]:
                if the edge destination vertex is v:
                    set pathFlow as the minimum of pathFlow and the edge capacity minus the edge flow
                    break

            set v as the parent of v

        set v as the sink vertex
        while v is not the source vertex:
            set u as the parent of v
            for each edge in the residual graph[u]:
                if the edge destination vertex is v:
                    increase the edge flow by pathFlow
                    for each reverseEdge in the residual graph[v]:
                        if the reverseEdge destination vertex is u:
                            decrease the reverseEdge flow by pathFlow
                            break

                    break

            set v as the parent of v

        increase maxFlow by pathFlow

    return maxFlow

# Main program
initialize n as the number of vertices in the graph
initialize the graph as an empty adjacency list of size n

# Adding edges to the graph
addEdge(graph, 0, 1, 16)
addEdge(graph, 0, 2, 13)
addEdge(graph, 1, 2, 10)
addEdge(graph, 1, 3, 12)
addEdge(graph, 2, 1, 4)
addEdge(graph, 2, 4, 14)
addEdge(graph, 3, 2, 9)
addEdge(graph, 3, 5, 20)
addEdge(graph, 4, 3, 7)
addEdge(graph, 4, 5, 4)

initialize the source vertex
initialize the sink vertex

compute the maximum flow using the Ford-Fulkerson algorithm and store the result in maxFlow

print "Maximum Flow: " followed by maxFlow
'''

'''
Note: In the pseudocode, 'n' represents the number of vertices in the graph, 'graph' represents the adjacency list representation of the graph, 'residualGraph' represents the residual graph, and 'parent' is an array used to store the parent vertices in the BFS traversal. The 'addEdge' function is used to add edges to the graph and residual graph.
'''
