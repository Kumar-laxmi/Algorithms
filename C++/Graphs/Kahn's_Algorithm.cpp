
// Algorithm Working  :

// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited
// nodes as 0.

// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

// Step-3: Remove a vertex from the queue (Dequeue operation) and then.
// Increment the count of visited nodes by 1.
// Decrease in-degree by 1 for all its neighbouring nodes.
// If the in-degree of neighbouring nodes is reduced to zero, then add it to the queue.

// Step 4: Repeat Step 3 until the queue is empty.

// Step 5: If the count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

// Time Complexity :  O(V+E), where V = no. of nodes and E = no. of edges.
// Space Complexity : O(2N)

#include <bits/stdc++.h>
using namespace std;

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        // node is in your topo sort
        // so please remove it from the indegree

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}

int main()
{

    // Here we are taking an example of 6 vertices..
    // You can modify it as you wish
    // V = 6;
    // We are using an adjacency list for storing the edges
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    vector<int> ans = topoSort(V, adj);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}