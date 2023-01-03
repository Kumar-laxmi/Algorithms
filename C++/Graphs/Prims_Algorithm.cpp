#include <bits/stdc++.h>
using namespace std;

void primsMST(int nodes, int starting_node, vector<pair<int, int>> adj[])
{
    // vis vector
    vector<vector<int>> is_contributing(nodes, vector<int>(nodes, 0));
    // set to store the nodes which are already taken
    set<int> st;
    st.insert(starting_node);

    // initial cost of the MST is set to be 0
    int cost_of_mst = 0;

    // answer vector is used to store the edges [staring node, ending node] along with their weights
    vector<pair<pair<int, int>, int>> ans;

    // as we know MST have [n] vertices and [n - 1], edges thus we are running the loop for n - 1 times to select n - 1 remaining nodes because starting_node is already there
    for (int count = 0; count < nodes - 1; ++count)
    {
        // In prims algorithm at every iteration we look the edge whose edge weight is minimum from every node included in the set
        int min_cost = INT_MAX;

        // at starting we don't know starting nodes and edge which will contribute thus we marked src = -1 and dest = -1 initially
        int src = -1;
        int dest = -1;

        // iterating over each node present in the set
        for (auto it = st.begin(); it != st.end(); ++it)
        {
            // taking the number of the node in the set, we are storing it's value in s.
            int s = *it;

            // iterating over the adjacency list of the node s
            for (auto vals : adj[s])
            {
                // checking if min_cost > vals.second and if the edge is not already included
                if (min_cost > vals.second and !is_contributing[s][vals.first])
                {
                    // after checking the above condition checking if the node is not already present in the set to avoid the cycle
                    if (st.find(vals.first) == st.end())
                    {
                        // if all the above conditons are true then updating the value of min_cost, src and dest
                        min_cost = vals.second;
                        src = s;
                        dest = vals.first;
                    }
                }
            }
        }

        // adding weight of the edge in the total cost of the MST
        cost_of_mst += min_cost;

        // inserting the node into the set
        st.insert(dest);

        // marking the edge, which signifies the edge is already taken to avoid the duplicate edges
        is_contributing[src][dest] = 1;

        // pushing the edge along with its weight in the ans vector
        ans.push_back({{src, dest}, min_cost});
    }

    // output section

    // printing all the edges along with their weight which are there in MST
    cout << "The edges in MST are as follows:-"
         << "\n";
    for (auto vals : ans)
    {
        cout << vals.first.first << "<->" << vals.first.second << ": " << vals.second << "\n";
    }

    // printing the cost of MST
    cout << "The Minimum cost of the spanning tree is"
         << "\n";
    cout << cost_of_mst << "\n";
}

int main()
{
    int nodes, edges, u, v, weight, starting_node;
    cout << "Enter the number of nodes and number of edges in the graph"
         << "\n";
    cin >> nodes >> edges; // taking input the number of nodes and edges

    // creating an adjacency list for nodes
    // we are using pair of vector because for every node we want to store its adjacent node along with the weight of the edge
    vector<pair<int, int>> adj[nodes];

    cout << "Enter the src, destination and weight of nodes"
         << "\n";

    // This while loop will run egdes number of times to take input for every edge
    while (edges--)
    {
        // we are taking input [src_node, dest_node, weight] for every edge
        cin >> u >> v >> weight;

        // as the graph is undirected if there is edge between a -> b then there is also an edge between b -> a
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // taking input for the starting node from which user wants to start calculations by the way for every node the output will be same
    cout << "Enter the node number from which you want to start"
         << "\n";
    cin >> starting_node;

    // calling function mst_cost to find out the cost of the mst and sending number of nodes along with adjacency list as an argument
    primsMST(nodes, starting_node, adj);
    return 0;
}
