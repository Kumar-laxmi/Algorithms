from collections import defaultdict
# Given N
N = 8
 
# Given edges
edges = [[1, 0 ], [ 0, 2 ], [ 5, 3 ], [ 3, 4 ], [ 6, 7 ]]
 
# Stores the parent of each vertex
parent = list(range(N))
  
# Function to find the topmost
# parent of vertex x
def find(x):
  if x != parent[x]:
    parent[x] = find(parent[x])
  return parent[x]
 
def union(x,y):
  parent_x = find(x)
  parent_y = find(y)
  if parent_x != parent_y:
    parent[parent_y] = parent_x
     
for x,y in edges:
  union(x,y)
 
dict_pair = defaultdict(list)
 
for idx, val in enumerate(parent):
  dict_pair[find(val)].append(idx)
 
print(len(dict_pair.keys()))
     
 