import java.util.*;
class DisjoinSetUnion{
 
// Stores the parent of each vertex
static int []parent = new int[1000000];
 
// Function to find the topmost
// parent of vertex a
static int root(int a)
{
   
    // If current vertex is
    // the topmost vertex
    if (a == parent[a])
    {
        return a;
    }
 
    // Otherwise, set topmost vertex of
    // its parent as its topmost vertex
    return parent[a] = root(parent[a]);
}
 
// Function to connect the component
// having vertex a with the component
// having vertex b
static void connect(int a, int b)
{
   
    // Connect edges
    a = root(a);
    b = root(b);
 
    if (a != b) {
        parent[b] = a;
    }
}
 
// Function to find unique top most parents
static void connectedComponents(int n)
{
    HashSet<Integer> s = new HashSet<Integer>();
 
    // Traverse all vertices
    for (int i = 0; i < n; i++)
    {
 
        // Insert all topmost
        // vertices obtained
        s.add(parent[i]);
    }
 
    // Print count of connected components
    System.out.println(s.size());
}
 
// Function to print answer
static void printAnswer(int N,int [][] edges)
{
 
    // Setting parent to itself
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
 
    // Traverse all edges
    for (int i = 0; i < edges.length; i++)
    {
        connect(edges[i][0], edges[i][1]);
    }
 
    // Print answer
    connectedComponents(N);
}
 
// Driver Code
public static void main(String[] args)
{
   
    // Given N
    int N = 8;
 
    // Given edges
   int [][]edges = {{ 1, 0 }, { 0, 2 },
                    { 5, 3 }, { 3, 4 },
                    { 6, 7 }};
 
    // Function call
    printAnswer(N, edges);
}
}