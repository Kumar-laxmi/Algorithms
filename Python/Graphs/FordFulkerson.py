from collections import deque

# Function to find the minimum of two numbers
def min(a, b):
    return a if a < b else b

# Function to find if there is a path from source to sink in the residual graph
def bfs(residualGraph, source, sink, parent):
    visited = [False] * len(residualGraph)  # Create a visited array to keep track of visited vertices
    queue = deque()  # Create a queue for BFS
    queue.append(source)  # Enqueue the source vertex
    visited[source] = True
    parent[source] = -1  # Set the parent of the source as -1

    # Standard BFS loop
    while queue:
        u = queue.popleft()
        for v in range(len(residualGraph)):
            if not visited[v] and residualGraph[u][v] > 0:
                queue.append(v)
                visited[v] = True
                parent[v] = u

    # If we reached the sink in BFS, then there is a path from source to sink
    return visited[sink]

# Function to implement the Ford-Fulkerson algorithm
def fordFulkerson(graph, source, sink):
    # Create a residual graph and initialize it with the original capacities
    residualGraph = [graph[i][:] for i in range(len(graph))]

    parent = [-1] * len(graph)  # This list is filled by BFS and stores the path
    maxFlow = 0  # Initialize the maximum flow

    # Augment the flow while there is a path from source to sink in the residual graph
    while bfs(residualGraph, source, sink, parent):
        # Find the maximum possible flow through the path found in BFS
        pathFlow = float('inf')
        v = sink
        while v != source:
            u = parent[v]
            pathFlow = min(pathFlow, residualGraph[u][v])
            v = parent[v]

        # Update the residual capacities of the edges and reverse edges along the path
        v = sink
        while v != source:
            u = parent[v]
            residualGraph[u][v] -= pathFlow
            residualGraph[v][u] += pathFlow
            v = parent[v]

        # Add the path flow to the overall maximum flow
        maxFlow += pathFlow

    # Return the overall maximum flow
    return maxFlow

# Get the number of vertices and edges from the user
V = int(input("Enter the number of vertices in the graph: "))
graph = [[0] * V for _ in range(V)]

# Get the edge details from the user and update the graph
numEdges = int(input("Enter the number of edges in the graph: "))
for _ in range(numEdges):
    u, v, capacity = map(int, input("Enter the start vertex, end vertex, and capacity of the edge (space-separated): ").split())
    graph[u][v] = capacity

source = int(input("Enter the source vertex: "))
sink = int(input("Enter the sink vertex: "))

# Call the Ford-Fulkerson algorithm to find the maximum flow
maxFlow = fordFulkerson(graph, source, sink)
print("The maximum flow in the graph is:", maxFlow)
