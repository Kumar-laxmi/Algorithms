def DFS(i):
    print(i, end=" ")
    visited[i] = 1
    for j in range(n):
        if visited[j] == 0 and G[i][j] == 1:
            DFS(j)

n = int(input("Enter number of nodes: "))

G = [[0] * n for _ in range(n)]
visited = [0] * n

print("Enter values of adjacency matrix of the graph:")
for i in range(n):
    row = list(map(int, input().split()))
    for j in range(n):
        G[i][j] = row[j]

for i in range(n):
    visited[i] = 0

s = int(input("Enter source node: "))

print("Depth First Traversal: ", end="")
DFS(s)