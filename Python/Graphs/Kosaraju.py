
class Vertex:
    def __init__(self, value):
        self.value = value
        self.d = None
        self.f = None


class DirectionalGraph:

    def __init__(self):
        self.adjacent = {}

    def has_vertex(self, v):
        try:
            self.adjacent[v]
            return True
        except KeyError:
            return False

    def add_vertex(self, v):
        if self.has_vertex(v):
            return False
        self.adjacent[v] = {}
        return True

    def add_vertices(self, arr):
        for v0 in arr:
            self.add_vertex(v0)
        return True


    def add_edge(self, start, end):
        if self.has_vertex(start) and self.has_vertex(end):
            self.adjacent[start][end] = True
            return True
        return False


time = 0


def dfs_ret(G, s, parent, stack):
    global time
    time += 1
    s.d = time

    for v in G.adjacent[s]:
        if v not in parent:
            parent[v] = s
            dfs_ret(G, v, parent, stack)

    time += 1
    s.f = time
    stack.append(s)


def dfs(G, stack):
    parent = {}
    stack = []

    for vertex in list(G.adjacent.keys()):
        if vertex not in parent:
            parent[vertex] = None
            dfs_ret(G, vertex, parent, stack)

    return stack

def dfs_single_visit(adj_list, v, visited, stack):
    for u in adj_list[v]:
        if u not in visited:
            visited[u] = v
            dfs_single_visit(adj_list, u, visited, stack)
    stack.append(v)






def Kosaraju(G):
    stack = dfs(G, [])

    rev_adj = {vertex: {} for vertex in G.adjacent.keys()}

    for vertex in G.adjacent.keys():
        for u in G.adjacent[vertex]:
            rev_adj[u][vertex] = True
    visited = {}
    components = []
    i = 0

    while stack:
        v = stack.pop()
        if v in visited:
            continue
        components.append([])
        visited[v] = True
        dfs_single_visit(rev_adj, v, visited, components[i])

        components.append([])
        i += 1

    return components

G = DirectionalGraph()

a = Vertex('a')
b = Vertex('b')
c = Vertex('c')
d = Vertex('d')
e = Vertex('e')
f = Vertex('f')
g = Vertex('g')
h = Vertex('h')
i = Vertex('i')
j = Vertex('j')
k = Vertex('k')

G.add_vertices([a, b, c, d, e, f, g, h, i, j, k])

G.add_edge(a, b)
G.add_edge(b, c)
G.add_edge(c, a)
G.add_edge(b, d)
G.add_edge(d, e)
G.add_edge(e, f)
G.add_edge(f, d)
G.add_edge(g, f)
G.add_edge(g, h)
G.add_edge(h, i)
G.add_edge(i, j)
G.add_edge(j, g)
G.add_edge(j, k)

y = Kosaraju(G)

for j in range(len(y)):
    if y[j]:
        print("Strongly connected Component:", j + 1, "=> ", end=" ")
        for v in y[j]:
            print(v.value, end=" ")
        print()
