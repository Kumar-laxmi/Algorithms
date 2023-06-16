from collections import defaultdict

# Take input from the user
N = int(input("Enter the number of vertices: "))
edges = []
num_edges = int(input("Enter the number of edges: "))
print("Enter the edges in the format 'x y':")
for _ in range(num_edges):
    x, y = map(int, input().split())
    edges.append([x, y])

# Stores the parent of each vertex
parent = list(range(N))

# Function to find the topmost parent of vertex x
def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    parent_x = find(x)
    parent_y = find(y)
    if parent_x != parent_y:
        parent[parent_y] = parent_x

# Perform the union-find algorithm on the given edges
for x, y in edges:
    union(x, y)

# Create a dictionary to store the groups of vertices
dict_pair = defaultdict(list)

# Group vertices based on their parent
for idx, val in enumerate(parent):
    dict_pair[find(val)].append(idx)

# Print the input and output
print("\nInput:")
print("Number of vertices:", N)
print("Edges:", edges)

print("\nOutput:")
print("Number of disjoint groups:", len(dict_pair.keys()))
print("Groups of vertices:")
for group in dict_pair.values():
    print(group)
