from collections import deque

class HopcroftKarp:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.graph = [[] for _ in range(n + 1)]
        self.match = [-1] * (n + m + 1)
        self.dist = [0] * (n + m + 1)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def bfs(self):
        queue = deque()
        for u in range(1, self.n + 1):
            if self.match[u] == -1:
                self.dist[u] = 0
                queue.append(u)
            else:
                self.dist[u] = float('inf')

        self.dist[0] = float('inf')

        while queue:
            u = queue.popleft()
            if self.dist[u] < self.dist[0]:
                for v in self.graph[u]:
                    if self.dist[self.match[v]] == float('inf'):
                        self.dist[self.match[v]] = self.dist[u] + 1
                        queue.append(self.match[v])

        return self.dist[0] != float('inf')

    def dfs(self, u):
        if u != 0:
            for v in self.graph[u]:
                if self.dist[self.match[v]] == self.dist[u] + 1 and self.dfs(self.match[v]):
                    self.match[u] = v
                    self.match[v] = u
                    return True

            self.dist[u] = float('inf')
            return False

        return True

    def max_matching(self):
        matching = 0

        while self.bfs():
            for u in range(1, self.n + 1):
                if self.match[u] == -1 and self.dfs(u):
                    matching += 1

        return matching

if __name__ == '__main__':
    n = int(input("Enter the number of vertices in the left set: "))
    m = int(input("Enter the number of vertices in the right set: "))
    e = int(input("Enter the number of edges: "))

    hk = HopcroftKarp(n, m)

    print("Enter the edges:")
    for _ in range(e):
        u, v = map(int, input().split())
        hk.add_edge(u, v)

    max_matching = hk.max_matching()
    print("Maximum Matching:", max_matching)
