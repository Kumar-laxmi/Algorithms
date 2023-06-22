from typing import List, Tuple
INF = 0x3f3f3f3f
class Graph:
	def __init__(self, V: int):
		self.V = V
		self.adj = [[] for _ in range(V)]
	def addEdge(self, u: int, v: int, w: int):
		self.adj[u].append((v, w))
		self.adj[v].append((u, w))
	def shortestPath(self, src: int, W: int):
		dist = [[INF, None] for _ in range(self.V)]
		dist[src][0] = 0
		B = [[] for _ in range(W * self.V + 1)]
		B[0].append(src)
		idx = 0
		while True:
			while len(B[idx]) == 0 and idx < W * self.V:
				idx += 1
			if idx == W * self.V:
				break
			u = B[idx][0]
			B[idx].pop(0)
			for v, weight in self.adj[u]:
				du = dist[u][0]
				dv = dist[v][0]
				if dv > du + weight:
					if dv != INF:
						B[dv].remove(v)
					dist[v][0] = du + weight
					dv = dist[v][0]
					B[dv].append(v)
					dist[v][1] = len(B[dv]) - 1
		print("Distance from Source")
		for i in range(self.V):
			print(f"{i}	 {dist[i][0]}")
def main():
	V = 9
	W = 14
	g = Graph(V)
	g.addEdge(0, 1, 4)
	g.addEdge(0, 7, 8)
	g.addEdge(1, 2, 8)
	g.addEdge(1, 7, 11)
	g.addEdge(2, 3, 7)
	g.addEdge(2, 8, 2)
	g.addEdge(2, 5, 4)
	g.addEdge(3, 4, 9)
	g.addEdge(3, 5, 14)
	g.addEdge(4, 5, 10)
	g.addEdge(5, 6, 2)
	g.addEdge(6, 7, 1)
	g.addEdge(6, 8, 6)
	g.addEdge(7, 8, 7)
	g.shortestPath(0, W)
if __name__ == "__main__":
	main()
