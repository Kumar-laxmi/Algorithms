#'I will use Tarjan's Algorithm to find the bridges
 #  So, what is a bridge -> A bridge of a connected graph is a graph edge whose removal disconnects the graph
#   So if we remove the bridge then the graph will be converted into multiple components.

   #e.g. 1 ←-----→ 3 ←----→ 4
    #    ↑       ↗          ↑
   #     |     ↗            |
   #     |   ↗              |
  #      ↓ ↙                ↓
 #       2                  5

  # In the above bidirectional graph, if we remove edge 3-4 then the graph will be broken into two different components so, we can say 3-4 is a bridge.
# T.c.=> O(V+E)
# Auxiliary Space: O(V)



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

    
    #     0 <--> 1 <---> 2
     #            |       |
     #            ↑       ↑
     #            |       |
     #            ↓       ↓
     #            3       4
     #
     #    In this graph there are 4 bridges [1,0] , [2,1] , [4,2] , [3,1]
     #
     #    Assuming that the graph is bi-directional and connected.
     #
     #


    bridges = graph.findBridges()

    print(f"{len(bridges)} bridges found!")

    for bridge in bridges:
        print(f"{bridge[0]} --> {bridge[1]}")
