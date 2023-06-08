#include <bits/stdc++.h>
using namespace std;
 
// Stores the parent of each vertex
int parent[1000000];
// Function to find the topmost
// parent of vertex a
int root(int a)
{
    // If current vertex is
    // the topmost vertex
    if (a == parent[a]) {
        return a;
    }
 
    // Otherwise, set topmost vertex of
    // its parent as its topmost vertex
    return parent[a] = root(parent[a]);
}
// Function to connect the component
// having vertex a with the component
// having vertex b
void connect(int a, int b)
{
    // Connect edges
    a = root(a);
    b = root(b);
 
    if (a != b) {
        parent[b] = a;
    }
}
// Function to find unique top most parents
void connectedComponents(int n)
{
    set<int> s;
 
    // Traverse all vertices
    for (int i = 0; i < n; i++) {
 
        // Insert all topmost
        // vertices obtained
        s.insert(root(parent[i]));}
    // Print count of connected components
    cout << s.size() << '\n';
}
// Function to print answer
void printAnswer(int N,vector<vector<int> > edges)
{
    // Setting parent to itself
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
     // Traverse all edges
    for (int i = 0; i < edges.size(); i++) {
        connect(edges[i][0], edges[i][1]);
    } 
    // Print answer
    connectedComponents(N);
}
 // Driver Code
int main()
{
    // Given N
    int N = 8;
     // Given edges
    vector<vector<int> > edges = {{ 1, 0 }, { 0, 2 }, { 5, 3 }, { 3, 4 }, { 6, 7 }    };
     // Function call
    printAnswer(N, edges);
     return 0;
}