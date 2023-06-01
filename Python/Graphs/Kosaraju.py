
class Vertex:
    def __init__(self, value):
        self.value = value
        self.d = None
        self.f = None


class DirectionalGraph:

    def __init__(self):
        self.adj = {}

    def has_vertex(self, v):
        try:
            self.adj[v]
            return True
        except KeyError:
            return False

    def add_vertex(self, v):
        if self.has_vertex(v):
            return False
        self.adj[v] = {}
        return True

    def add_vertices(self, arr):
        for v in arr:
            self.add_vertex(v)
        return True

    def has_edge(self, start, end):
        if self.has_vertex(start) and self.has_vertex(end):
            try:
                return self.adj[start][end] is True
            except KeyError:
                return False
        return False

    def add_edge(self, start, end):
        if self.has_vertex(start) and self.has_vertex(end):
            self.adj[start][end] = True
            return True
        return False

    def remove_edge(self, start, end):
        if self.has_edge(start, end):
            del self.adj[start][end]
            return True
        return False

    def remove_vertex(self, v):
        if self.has_vertex(v):
            for vertex in self.adj.keys():
                self.remove_edge(vertex, v)
            del self.adj[v]
            return True
        return False

time = 0


def dfs_visit(G, s, parent, stack):
    global time
    time += 1
    s.d = time

    for v in G.adj[s]:
        if v not in parent:
            parent[v] = s
            dfs_visit(G, v, parent, stack)

    time += 1
    s.f = time
    stack.append(s)


def dfs(G, stack):
    parent = {}
    stack = []

    for vertex in list(G.adj.keys()):
        if vertex not in parent:
            parent[vertex] = None
            dfs_visit(G, vertex, parent, stack)

    return stack

def dfs_single_visit(adj_list, v, visited, stack):
    for u in adj_list[v]:
        if u not in visited:
            visited[u] = v
            dfs_single_visit(adj_list, u, visited, stack)
    stack.append(v)


def kosaraju(G):
    stack = dfs(G, [])

    rev_adj = {vertex: {} for vertex in G.adj.keys()}

    for vertex in G.adj.keys():
        for u in G.adj[vertex]:
            rev_adj[u][vertex] = True
    visited = {}
    components = []
    i = 0

    while stack != []:
        v = stack.pop()
        if v in visited:
            continue
        components.append([])
        visited[v] = True
        dfs_single_visit(rev_adj, v, visited, components[i])

        components.append([])
        i += 1

    return components
def print_stack(stk):
    for i in stk:
        print(i.value, i.f)


def print_adjacency_list(adj):
    for v in adj.keys():
        print(v.value, " -> ", end=" ")
        for u in adj[v]:
            print(u.value, end=" ")
        print()



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

y = kosaraju(G)

for j in range(len(y)):
    if y[j] != []:
        print("Strongly connected Component:", j + 1, " ", end=" ")
        for v in y[j]:
            print(v.value, end=" ")
        print()