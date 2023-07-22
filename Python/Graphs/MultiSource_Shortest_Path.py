from collections import deque

print("Enter the number of vertices, edges, and sources")
n, m, s = map(int, input().split())
adj = [[] for _ in range(n+1)]
sources = input("Enter the sources ").split()

print("Enter the edges:")

while m > 0:
    u, v = map(int, input().split())
    
    adj[u].append(v)
    adj[v].append(u)
    
    m -= 1

dist = [1e9] * (n + 1)
vis = [0] * (n + 1)
q = deque()

for it in sources:
    it = int(it)
    vis[it] = 1
    q.append(it)

lvl = 0

while q:
    sz = len(q)
    while sz > 0:
        node = q.popleft()
        
        dist[node] = lvl
        
        for it in adj[node]:
            if vis[it]:
                continue
            
            vis[it] = 1
            q.append(it)
        
        sz -= 1
    
    lvl += 1

for i in range(1, n+1):
    print(i, ":", dist[i])