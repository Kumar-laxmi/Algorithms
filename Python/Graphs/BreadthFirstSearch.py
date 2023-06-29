from collections import deque

class Graph:
    def __init__(self, v):
        self.v = v
        self.adj = [[] for _ in range(v)]

    def addEdge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)

	# BFS traversal from a given source node 's'
    def BFS(self, s):
        		
        #Create a queue for BFS traversal
        queue = deque()
        visited = [False] * self.v

		# Mark the current node as visited and add into queue
        visited[s] = True
        queue.append(s)

        while queue:
            curr = queue.popleft()
            
            # Remove a vertex from queue and print it
            print(curr, end=" ")
            
			# Get all adjacent vertices of the dequeued vertex s.
			# If an adjacent has not been visited, then mark it visited and enqueue it
            for nbr in self.adj[curr]:
                if not visited[nbr]:
                    queue.append(nbr)
                    visited[nbr] = True


if __name__ == "__main__":
    N, M = map(int, input("Enter the no. of vertices and edges: ").split())
    g = Graph(N)

    for i in range(M):
        u, v = map(int, input(f"Enter edge No. {i+1}: ").split())
        g.addEdge(u, v)

    s = int(input("Enter source vertex: "))
    g.BFS(s)
