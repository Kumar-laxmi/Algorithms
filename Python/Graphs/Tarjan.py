from collections import defaultdict

class Graph:
    def __init__(self, numNodes):
        self.edges = []
        self.numEdges = 0
        self.adjList = defaultdict(list)
        self.adjListSize = [0] * numNodes
        self.tin = [-1] * numNodes
        self.low = [-1] * numNodes
        self.timer = 1
        self.visited = [False] * numNodes

    def addEdge(self, u, v):
        self.edges.append((u, v))
        self.numEdges += 1
        self.adjList[u].append(v)
        self.adjList[v].append(u)
        self.adjListSize[u] += 1
        self.adjListSize[v] += 1

    def dfs(self, node, parent, dfsData, numBridges, bridges):
        self.visited[node] = True
        self.tin[node] = self.low[node] = self.timer
        self.timer += 1

        # Traverse all adjacent nodes of the current node
        for child in self.adjList[node]:
            # Skip the parent node to avoid going back in the same path
            if child == parent:
                continue

            # If the child node is not visited, perform DFS on it
            if not self.visited[child]:
                # Store the DFS data of the child node
                dfsData[child] = (child, node)

                self.dfs(child, node, dfsData, numBridges, bridges)

                # Update the low value of the current node based on the child's low value
                self.low[node] = min(self.low[node], self.low[child])

                # If the low value of the child is greater than the tin value of the current node,
                # it means the edge is a bridge
                if self.low[child] > self.tin[node]:
                    bridges[numBridges[0]] = (node, child)
                    numBridges[0] += 1
            else:
                # If the child node is already visited, update the low value of the current node
                # based on the child's tin value
                self.low[node] = min(self.low[node], self.tin[child])

    def findBridges(self):
        dfsData = {}
        numBridges = [0]
        bridges = [None] * self.numEdges

        # Perform DFS on the graph starting from node 0
        self.dfs(0, -1, dfsData, numBridges, bridges)

        return bridges

if __name__ == '__main__':
    numNodes = 5

    graph = Graph(numNodes)

    graph.addEdge(0, 1)
    graph.addEdge(1, 3)
    graph.addEdge(1, 2)
    graph.addEdge(2, 4)

    bridges = graph.findBridges()

    print(f"{len(bridges)} bridges found!")

    for bridge in bridges:
        print(f"{bridge[0]} --> {bridge[1]}")
