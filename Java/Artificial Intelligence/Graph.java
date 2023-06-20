// Java program to search if a target node is reachable from
// a source with given max depth.
import java.util.*;

// Graph class represents a directed graph using adjacency
// list representation.
class Graph {
int V; // No. of vertices

// Pointer to an array containing
// adjacency lists
LinkedList<Integer> adj[];

// A function used by IDDFS
boolean DLS(int v, int target, int limit)
{
	if (v == target)
	return true;

	// If reached the maximum depth, stop recursing.
	if (limit <= 0)
	return false;

	// Recur for all the vertices adjacent to source
	// vertex
	for (int i : adj[v])
	if (DLS(i, target, limit - 1))
		return true;

	return false;
}

public Graph(int v)
{
	V = v;
	adj = new LinkedList[v];
	for (int i = 0; i < v; ++i)
	adj[i] = new LinkedList();
}

void addEdge(int v, int w)
{
	adj[v].add(w); // Add w to v's list.
}

// IDDFS to search if target is reachable from v.
// It uses recursive DFSUtil().
boolean IDDFS(int src, int target, int max_depth)
{
	// Repeatedly depth-limit search till the
	// maximum depth.
	for (int i = 0; i <= max_depth; i++)
	if (DLS(src, target, i))
		return true;

	return false;
}
}

// Driver code
class IDS {
public static void main(String[] args)
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
	System.out.println(
	"Target 6 is reachable from source 0 "
	+ "within max depth 3 in java");
	else
	System.out.println(
	"Target is NOT reachable from source "
	+ "within max depth");
}
}
