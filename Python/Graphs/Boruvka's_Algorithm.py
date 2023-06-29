# Boruvka's algorithm to find Minimum Spanning Tree of a given connected, undirected and weighted graph

from collections import defaultdict

# Class to represent a graph
class Graph:

	def __init__(self,vertices):
		self.V= vertices # No. of vertices
		self.graph = [] # Default dictionary to store graph
		

	# Function to add an edge to graph
	def addEdge(self,u,v,w):
		self.graph.append([u,v,w])

	# A utility function to find set of an element i (uses path compression technique)
	def find(self, parent, i):
		if parent[i] == i:
			return i
		return self.find(parent, parent[i])

	# A function that does union of two sets of x and y (uses union by rank)
	def union(self, parent, rank, x, y):
		rootX = self.find(parent, x)
		rootY = self.find(parent, y)

		# Attach smaller rank tree under root of high rank tree (Union by Rank)
		if rank[rootX] < rank[rootY]:
			parent[rootX] = rootY
		elif rank[rootX] > rank[rootY]:
			parent[rootY] = rootX
		#If ranks are same, then make one as root and increment its rank by one
		else :
			parent[rootY] = rootX
			rank[rootX] += 1

	# The main function to construct MST using Boruvka's algorithm
	def boruvkaMST(self):
		parent = []
        rank = []

		# An array to store index of the cheapest edge of subset. It store [u,v,w] for each component
		minimum =[]

		# Initially there are V different trees. Finally there will be one tree that will be MST
		numberOfTrees = self.V
		MSTWeight = 0

		# Create V subsets with single elements
		for node in range(self.V):
			parent.append(node)
			rank.append(0)
			minimum =[-1] * self.V
	
		# Keep combining components (or sets) until all components are not combined into single MST

		while numberOfTrees > 1:

			# Traverse through all edges and update cheapest of every component
			for i in range(len(self.graph)):

				# Find components (or sets) of two corners of current edge
				u,v,w = self.graph[i]
				setA = self.find(parent, u)
				setB = self.find(parent ,v)

				# If two corners of current edge belong to same set, ignore current edge. Else check if current edge is closer to previous cheapest edges of set1 and set2
				if setA != setB:	
					
					if minimum[setA] == -1 or minimum[setA][2] > w :
						minimum[setA] = [u,v,w]

					if minimum[setB] == -1 or minimum[setB][2] > w :
						minimum[setB] = [u,v,w]

			# Consider the above picked cheapest edges and add them to MST
			for node in range(self.V):

				# Check if cheapest for current set exists
				if minimum[node] != -1:
					u,v,w = minimum[node]
					setA = self.find(parent, u)
					setB = self.find(parent ,v)

					if setA != setB :
						MSTWeight += w
						self.union(parent, rank, setA, setB)
						print ("Edge %d-%d with weight %d included in Minimum Spanning Tree (MST)" % (u,v,w))
						numberOfTrees = numberOfTrees - 1
			
			#reset cheapest array
			minimum =[-1] * self.V

			
		print ("\nWeight of Minimum Spanning Tree (MST) is %d" % MSTWeight)
						

	
g = Graph(9)
g.addEdge(0, 1, 6)
g.addEdge(0, 6, 7)
g.addEdge(1, 6, 15)
g.addEdge(1, 7, 27)
g.addEdge(1, 2, 11)
g.addEdge(2, 3, 12)
g.addEdge(2, 4, 4)
g.addEdge(3, 4, 18)
g.addEdge(3, 5, 10)
g.addEdge(4, 5, 25)
g.addEdge(4, 7, 3)
g.addEdge(4, 8, 10)
g.addEdge(5, 8, 16)
g.addEdge(6, 7, 3)
g.addEdge(7, 8, 6)

g.boruvkaMST()