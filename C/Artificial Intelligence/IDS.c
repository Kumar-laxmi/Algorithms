using System;
using System.Collections.Generic;

// Graph class represents a directed graph using adjacency
// list representation.
class Graph {
private int V; // No. of vertices

// Pointer to an array containing adjacency lists
private List<int>[] adj;

// Constructor
public Graph(int V)
{
	this.V = V;
	adj = new List<int>[ V ];
	for (int i = 0; i < V; ++i)
	adj[i] = new List<int>();
}

// Add w to v's list
public void addEdge(int v, int w) { adj[v].Add(w); }

// A function used by IDDFS
private bool DLS(int v, int target, int limit)
{
	if (v == target)
	return true;

	// If reached the maximum depth, stop recursing.
	if (limit <= 0)
	return false;

	// Recur for all the vertices adjacent to source
	// vertex
	foreach(
	int i in adj[v]) if (DLS(i, target,
							limit
							- 1)) return true;

	return false;
}

// IDDFS to search if target is reachable from v.
// It uses recursive DLS().
public bool IDDFS(int src, int target, int max_depth)
{
	// Repeatedly depth-limit search till the maximum
	// depth.
	for (int i = 0; i <= max_depth; i++)
	if (DLS(src, target, i))
		return true;

	return false;
}
}

// Driver code
class IDS {
static void Main(string[] args)
{
	// Let us create a Directed graph with 7 nodes
	Graph g = new Graph(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 6);

	int target = 6, maxDepth = 3, src = 0;
	if (g.IDDFS(src, target, maxDepth))
	Console.WriteLine(
	"Target is reachable from source within max depth in c");
	else
	Console.WriteLine(
	"Target is NOT reachable from source within max depth");
}
}

