# Path: Python\Graphs\Edmonds-Karp_Algorithm.py 
# Edmonds-Karp Algorithm    
    #Time-Complexity: O(VE^2)    
    #Space-Complexity: O(V^2)  where V is the number of vertices and E is the number of edges in the graph.

from collections import deque

def bfs(residualGraph, parent, source, sink):
    visited = [False] * len(residualGraph)
    queue = deque()

    queue.append(source)
    visited[source] = True
    parent[source] = -1

    while queue:
        u = queue.popleft()

        for v in range(len(residualGraph)):
            if not visited[v] and residualGraph[u][v] > 0:
                queue.append(v)
                parent[v] = u
                visited[v] = True

    return visited[sink]

def edmondsKarp(graph, source, sink):
    V = len(graph)
    residualGraph = [[0] * V for _ in range(V)]
    parent = [-1] * V

    for u in range(V):
        for v in range(V):
            residualGraph[u][v] = graph[u][v]

    maxFlow = 0

    while bfs(residualGraph, parent, source, sink):
        pathFlow = float('inf')

        v = sink
        while v != source:
            u = parent[v]
            pathFlow = min(pathFlow, residualGraph[u][v])
            v = parent[v]

        v = sink
        while v != source:
            u = parent[v]
            residualGraph[u][v] -= pathFlow
            residualGraph[v][u] += pathFlow
            v = parent[v]

        maxFlow += pathFlow

    return maxFlow

if __name__ == "__main__":
    graph = [
        [0, 16, 13, 0, 0, 0],
        [0, 0, 10, 12, 0, 0],
        [0, 4, 0, 0, 14, 0],
        [0, 0, 9, 0, 0, 20],
        [0, 0, 0, 7, 0, 4],
        [0, 0, 0, 0, 0, 0]
    ]

    source = 0
    sink = 5

    maxFlow = edmondsKarp(graph, source, sink)

    print("Maximum flow:", maxFlow)




'''
#Psudocode for Edmonds-Karp Algorithm:: Here's a pseudocode representation of the Edmonds-Karp algorithm for finding the maximum flow in a network:

function bfs(residualGraph, parent, source, sink):
    create a visited array of size V and initialize all elements as false
    create an empty queue

    enqueue the source vertex into the queue
    mark the source vertex as visited
    set the parent of the source vertex as -1

    while the queue is not empty:
        dequeue a vertex u from the queue

        for each vertex v in the range from 0 to V:
            if v is not visited and the residual capacity from u to v is greater than 0:
                enqueue v into the queue
                mark v as visited
                set the parent of v as u

    return true if there is a path from source to sink in the residual graph, else return false

function edmondsKarp(graph, source, sink):
    initialize a residual graph of size V with all capacities as 0
    initialize a parent array of size V with all elements as -1

    for each vertex u in the range from 0 to V:
        for each vertex v in the range from 0 to V:
            set the capacity of the edge from u to v in the residual graph as the capacity in the original graph

    set maxFlow as 0

    while bfs(residualGraph, parent, source, sink) is true:
        set pathFlow as infinity

        set v as the sink vertex
        while v is not the source vertex:
            set u as the parent of v
            update pathFlow as the minimum of pathFlow and the residual capacity from u to v
            set v as the parent of v

        set v as the sink vertex
        while v is not the source vertex:
            set u as the parent of v
            subtract pathFlow from the residual capacity from u to v in the residual graph
            add pathFlow to the residual capacity from v to u in the residual graph
            set v as the parent of v

        add pathFlow to maxFlow

    return maxFlow

    # Main program
    initialize the graph with the given capacities
    set the source vertex
    set the sink vertex

    compute the maximum flow using the Edmonds-Karp algorithm and store the result in maxFlow

    print "Maximum flow: " followed by maxFlow
'''

'''
Note: In the pseudocode, 'V' represents the number of vertices in the graph, 'residualGraph' refers to the residual capacities of the graph, and graph represents the original 'graph' with capacities.
'''