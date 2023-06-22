MAX_VERTICES = 100

# Function to find the minimum cut using Stoer-Wagner algorithm
def stoerWagner(graph, n):
    minCut = float('inf')  # Initialize the minimum cut with infinity
    inSet = [False] * MAX_VERTICES  # Keep track of vertices included in the set
    partition = list(range(MAX_VERTICES))  # Keep track of partition of vertices

    for i in range(n):
        partition[i] = i  # Initialize each vertex in its own partition

    for phase in range(n - 1):
        inTree = [False] * MAX_VERTICES  # Mark all vertices as not yet included in the tree
        weight = [0] * MAX_VERTICES  # Initialize the weight array

        prev = -1  # Variable to store the previous vertex
        for i in range(n - phase):
            maxWeight = -1
            current = -1
            for j in range(n):
                if not inTree[j] and not inSet[j] and weight[j] > maxWeight:
                    maxWeight = weight[j]  # Update the maximum weight
                    current = j  # Store the current vertex

            if i == n - phase - 1:
                if maxWeight < minCut:
                    minCut = maxWeight  # Update the minimum cut value
                inSet[current] = True  # Include the current vertex in the set
                for j in range(n):
                    if not inTree[j]:
                        graph[prev][j] += graph[current][j]  # Update the graph weights
                        graph[j][prev] += graph[current][j]
            else:
                inTree[current] = True  # Include the current vertex in the tree
                for j in range(n):
                    if not inTree[j]:
                        weight[j] += graph[current][j]  # Update the weight array
                prev = current  # Store the previous vertex

    return minCut  # Return the minimum cut value


graph = [[0] * MAX_VERTICES for _ in range(MAX_VERTICES)]  # Graph represented as an adjacency matrix
n = int(input("Enter the number of vertices: "))
m = int(input("Enter the number of edges: "))

print("Enter the edges and their weights:")
for _ in range(m):
    u, v, weight = map(int, input().split())
    graph[u][v] = weight  # Set the weight of edge (u, v)
    graph[v][u] = weight  # Set the weight of edge (v, u)

minCut = stoerWagner(graph, n)  # Find the minimum cut using Stoer-Wagner algorithm

print("Minimum cut value:", minCut)
