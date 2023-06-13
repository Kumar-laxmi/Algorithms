/* 
------------------------------------- Hierholzer’s Algorithm for finding an Eulerian Cycle -------------------------------------

An Eulerian Cycle is a path in a graph that visits every edge exactly once and returns to the starting vertex. 
To find an Eulerian Cycle using Hierholzer's Algorithm, we follow these steps:

1. Choose any starting vertex in the graph.
2. Follow a trail of edges from that vertex until returning to the starting vertex. Since the graph is directed, there will always be an unused edge leaving each visited vertex.
3. Repeat the process as long as there are vertices with unused edges connected to the current trail. Start a new trail from such vertices, following unused edges until returning to the starting vertex of the new trail.
4. If we get stuck (a vertex with no unused edges), backtrack to the nearest vertex in the current path that has unused edges.
5. Repeat steps 3 and 4 until all edges have been used.
6. Store the final path in a separate container.

For Example:
Consider a directed graph with the following edges:

0 -> 1 -> 2 -> 3 -> 0
1 -> 4 -> 1
2 -> 1
3 -> 2 -> 4 -> 0

To find the Eulerian Cycle using Hierholzer's Algorithm, we start from vertex 0 and traverse the graph by following unused edges until we return to vertex 0. 
Then, we identify the remaining unused edges and start new trails from vertices 1, 2, and 3, respectively. Finally, we merge all the paths to obtain the Eulerian Cycle: 

0 -> 1 -> 2 -> 3 -> 2 -> 1 -> 4 -> 1 -> 0.
*/

// This code is for that graph which is already an Eulerian graph.
#include <bits/stdc++.h>
using namespace std;

void dfs(int curr_v, vector< vector<int> >& adj, vector<int>& circuit, unordered_map<int,int>& edge_count, stack<int>& curr_path)
{
    while (edge_count[curr_v])
    {
        curr_path.push(curr_v);
        int next_v = adj[curr_v].back();
        edge_count[curr_v]--;
        adj[curr_v].pop_back();
        curr_v = next_v;
    }
    circuit.push_back(curr_v);
}

void printCycle(vector< vector<int> >& adj)
{
    unordered_map<int,int> edge_count;
    for (int i = 0; i < adj.size(); i++)
        edge_count[i] = adj[i].size();

    if (!adj.size())
        return;

    stack<int> curr_path;
    vector<int> circuit;

    curr_path.push(0);
    int curr_v = 0;

    while (!curr_path.empty())
    {
        if (edge_count[curr_v])
        {
            dfs(curr_v, adj, circuit, edge_count, curr_path);
            curr_v = curr_path.top();
            curr_path.pop();
        }
        else
        {
            circuit.push_back(curr_v);
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }

    for (int i = circuit.size() - 1; i >= 0; i--)
    {
        cout << circuit[i];
        if (i)
            cout << " -> ";
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    vector<vector<int>> adj(vertices);

    cout << "Enter the edges in the format 'source -> destination':" << endl;
    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        cout << "Source-" << i+1 << " : ";
        cin >> source;
        cout << "Destination-" << i+1 << " : ";
        cin >> destination;
        adj[source].push_back(destination);
    }

    cout << "\nEulerian Cycle: ";
    printCycle(adj);
    cout << endl;

    return 0;
}
