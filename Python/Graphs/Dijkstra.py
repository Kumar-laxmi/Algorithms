#Initializing the Graph Class
from collections import defaultdict


class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.distances = {}
    
    def addNode(self,value):
        self.nodes.add(value)
    
    def addEdge(self, fromNode, toNode, distance):
        self.edges[fromNode].append(toNode)
        self.distances[(fromNode, toNode)] = distance
        
    #Implementing Dijkstra's Algorithm
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
        currentWeight = visited[minNode]

        for edge in graph.edges[minNode]:
            weight = currentWeight + graph.distances[(minNode, edge)]
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
graph1.addEdge("A", "B", 2)
graph1.addEdge("A", "C", 5)
graph1.addEdge("B", "C", 6)
graph1.addEdge("B", "D", 1)
graph1.addEdge("B", "E", 3)
graph1.addEdge("C", "F", 8)
graph1.addEdge("D", "E", 4)
graph1.addEdge("E", "G", 9)
graph1.addEdge("F", "G", 7)

print(dijkstra(graph1, "A"))
