// Cpp-program to implement famous Kruskal's Algorithm
// Kruskal's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph.

// The idea is to sort all edges of given graph in increasing order, and then keep on adding new edges and nodes in the spanning tree if the added edge does not form a cycle.


/* A minimum spanning tree is constructed from a weighted & undirected graph, so it:
-> Connects all nodes / vertices
-> Has no cycles
-> Has smallest possible sum of edge weights.*/

#include <algorithm>
#include <iostream>
using namespace std;

const int maximum = 100000;
int no[maximum], nodes, edges;
pair <long long, pair<int, int>> k[maximum];

int base(int a) // Find the base/parent of the given node
{
    while (no[a] != a)
    {
        no[a] = no[no[a]];  // Path compression optimization
        a = no[a];
    }
    return a;
}

// Merge the sets containing nodes a and b
void temp(int a, int b)
{
    int k = base(a);
    int l = base(b);
    no[k] = no[l];
}

// Kruskal's algorithm to find the minimum spanning tree
long long krus(pair<long long, pair<int, int>> k[])
{
    int a, b;
    long long cost, minCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        a = k[i].second.first;
        b = k[i].second.second;
        cost = k[i].first;
        if (base(a) != base(b))   // Check if adding the edge forms a cycle
        {
            minCost += cost;
            temp(a, b); // Merge the sets
        }
    }
    return minCost;
}

int main()
{
    int a, b;
    long long w, cost, minCost;

    for (int i = 0; i < maximum; ++i)
    {
        no[i] = i;  // Initialize each node as a separate set
    }

    cout << "Enter Nodes and edges";
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cout << "Enter the value of a, b and edges ";
        cin >> a >> b >> w;
        k[i] = make_pair(w, make_pair(a, b));
    }
    sort(k, k + edges);
    
    minCost = krus(k);   // Find the minimum spanning tree cost
    cout << "Minimum cost is " << minCost << endl;
    return 0;
}

// Time Complexity: O(E log N)