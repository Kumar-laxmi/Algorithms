"""
Let's say this edge has negative weight, i.e. -2. Go from 1 to 2, cost = -2,
go from 2 to 1 again, cost = -4, go from 1 to 2 again, cost = -6
You can see the cost is getting reduced, so Dijkstra's algorithm can never find the minimum cost to reach 2
and ends up in an infinite loop.

Bellman-Ford algorithm works for:
    1. Directed graph (DG), if there is no negative cycle, and it will also tell if any negative cycle exists.
        Example: 1 -> 2 -> 3 ->...1; Weights: 1 -> 2: 6, 2 -> 3: -12, 3 -> 1: -7
        - Go from 1 to 2, cost = 6
        - Go from 2 to 3, cost 6 - 12 = -6
        - Go from 3 to 1, cost = -6 - 7 = -13
        - Go from 1 to 2, cost = -13 + 6 = -7 => less than 6
        So, there is a negative cycle.
    2. Undirected graph (UG)
        Example: 1 --- 2
        Weight(1---2) = x => convert it to DG as 1 <---> 2 with weight x for both sides

    The algorithm works for both types of graphs and if there is a negative cycle, it detects it instead of ending up in an infinite loop.

    Algorithm:
        1. Relax all edges N - 1 times
           if (dist[u] + wt < dist[v]) dist[v] = dist[u] + wt
           After N - 1 relaxations, the distance array will contain the shortest path to every node.
           Do one more relaxation after that. If the cost reduces in this relaxation, it means
           a negative cycle exists in the graph.
"""

v = int(input("Enter the number of vertices: "))

adj = [[] for _ in range(v)]

for i in range(v):
    ad = int(input("Enter the number of adjacencies of vertex {}: ".format(i)))

    print("Now enter the nodes in the adjacency of {} and the weight separated by space:".format(i))
    for _ in range(ad):
        x, y = map(int, input().split())
        adj[i].append((x, y))

dist = [float('inf')] * v
dist[0] = 0

for _ in range(v - 1):
    for u in range(v):
        for it in adj[u]:
            if dist[u] + it[1] < dist[it[0]]:
                dist[it[0]] = dist[u] + it[1]

flag = 0
for u in range(v):
    for it in adj[u]:
        if dist[u] + it[1] < dist[it[0]]:
            print("Negative cycle")
            flag = 1
            break

# Taking source at vertex 0
if not flag:
    for i in range(v):
        print(dist[i], end=" ")
    print()
