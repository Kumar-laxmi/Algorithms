import collections
class graph:
   def __init__(self,graphDict=None):
      if graphDict is None:
         graphDict = {}
      self.graphDict = graphDict
def bfs(graph, startnode):
   visited, queue = set([startnode]), collections.deque([startnode])
   while queue:
      vertex = queue.popleft()
      marked(vertex)
      for node in graph[vertex]:
         if node not in visited:
            visited.add(node)
            queue.append(node)

def marked(n):
   print(n)


graphDict = { 
   "a" : set(["b","c"]),
   "b" : set(["a", "d"]),
   "c" : set(["a", "d"]),
   "d" : set(["e"]),
   "e" : set(["a"])
}
bfs(graphDict, "a")