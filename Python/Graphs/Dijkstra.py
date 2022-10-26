class Graph:
    #Initializing Graph
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.dist = {}
    
    def addNode(self,value):
        self.nodes.add(value)
    
    def addEdge(self, fromNode, toNode, distance):
        self.edges[fromNode].append(toNode)
        self.dist[(fromNode, toNode)] = distance

    #Dijkstra algorithm
    def dijkstra(graph, initial):
        visited = {initial : 0}
        path = defaultdict(list)

        nodes = set(graph.nodes)

        while nodes:
            minNode = None
            for node in nodes:
                if node in visited:
                    if minNode is None:
                        minNode = node
                    elif visited[node] < visited[minNode]:
                        minNode = node
            if minNode is None:
                break

            nodes.remove(minNode)
            c_weight = visited[minNode]

            for edge in graph.edges[minNode]:
                weight = c_weight + graph.dist[(minNode, edge)]
                if edge not in visited or weight < visited[edge]:
                    visited[edge] = weight
                    path[edge].append(minNode)
        
        return visited, path

graph1 = Graph()
graph1.addNode("A")
graph1.addNode("B")
graph1.addNode("C")
graph1.addNode("D")
graph1.addNode("E")
graph1.addNode("F")
graph1.addNode("G")
graph1.addEdge("A", "B", 5)
graph1.addEdge("A", "C", 7)
graph1.addEdge("B", "C", 3)
graph1.addEdge("B", "D", 9)
graph1.addEdge("B", "E", 12)
graph1.addEdge("C", "F", 4)
graph1.addEdge("D", "E", 12)
graph1.addEdge("E", "G", 7)
graph1.addEdge("F", "G", 9)

print(dijkstra(graph1, "B"))