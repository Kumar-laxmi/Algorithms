'''
------------------------------------- Hierholzer’s Algorithm for finding an Eulerian Cycle -------------------------------------

An Eulerian Cycle is a path in a graph that visits every edge exactly once and returns to the starting vertex. 
To find an Eulerian Cycle using Hierholzer's Algorithm, we follow these steps:

1. Choose any starting vertex in the graph.
2. Follow a trail of edges from that vertex until returning to the starting vertex. Since the graph is directed, there will always be an unused edge leaving each visited vertex.
3. Repeat the process as long as there are vertices with unused edges connected to the current trail. Start a new trail from such vertices, following unused edges until returning to the starting vertex of the new trail.
4. If we get stuck (a vertex with no unused edges), backtrack to the nearest vertex in the current path that has unused edges.
5. Repeat steps 3 and 4 until all edges have been used.
6. Store the final path in a separate container.

For Example:
Consider a directed graph with the following edges:

0 -> 1 -> 2 -> 3 -> 0
1 -> 4 -> 1
2 -> 1
3 -> 2 -> 4 -> 0

To find the Eulerian Cycle using Hierholzer's Algorithm, we start from vertex 0 and traverse the graph by following unused edges until we return to vertex 0. 
Then, we identify the remaining unused edges and start new trails from vertices 1, 2, and 3, respectively. Finally, we merge all the paths to obtain the Eulerian Cycle: 

0 -> 1 -> 2 -> 3 -> 2 -> 1 -> 4 -> 1 -> 0.
'''

# This code is for that graph which is already an Eulerian graph.
def dfs(curr_v, adj, circuit, edge_count, curr_path):
    while edge_count[curr_v]:
        curr_path.append(curr_v)
        next_v = adj[curr_v].pop()
        edge_count[curr_v] -= 1
        curr_v = next_v
    circuit.append(curr_v)

def printCycle(adj):
    edge_count = {}
    for i in range(len(adj)):
        edge_count[i] = len(adj[i])

    if not adj:
        return
    
    curr_path = []
    circuit = []

    curr_path.append(0)
    curr_v = 0

    while curr_path:
        if edge_count[curr_v]:
            dfs(curr_v, adj, circuit, edge_count, curr_path)
            curr_v = curr_path[-1]
            curr_path.pop()
        else:
            circuit.append(curr_v)
            curr_v = curr_path[-1]
            curr_path.pop()

    for i in range(len(circuit) - 1, -1, -1):
        print(circuit[i], end='')
        if i > 0:
            print(' -> ', end='')
    print()

if __name__ == '__main__':
    adj = [[] for _ in range(5)]

    adj[0].append(1)
    adj[1].append(4)
    adj[4].append(1)
    adj[1].append(2)
    adj[2].append(3)
    adj[3].append(2)
    adj[2].append(1)
    adj[1].append(0)

    printCycle(adj)
