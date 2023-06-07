#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    int size;
    vector<int> *adj;
    int *visit;
    graph(int n)
    {
        size = n;
        adj = new vector<int>[size];
        visit = new int[size];
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void bfs(int start)
    {
        queue<int> q;
        vector<int> visit(size, 0);
        q.push(start);
        visit[start] = 1;
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (int adjacent : adj[node])
            {
                if (visit[adjacent] == 0)
                {
                    visit[adjacent] = 1;
                    q.push(adjacent);
                }
            }
        }
    }

    void DFStrav(int u, vector<int> &visit)
    {
        visit[u] = 1;
        cout << u << " ";
        for (int adjacent : adj[u])
        {
            if (visit[adjacent] != 1)
                DFStrav(adjacent, visit);
        }
    }
    void dfs(int start)
    {
        vector<int> visit(size, 0);
        DFStrav(start, visit);
    }
};

int main()
{
    int n;
    cout << "enter the no. of nodes:" << endl;
    cin >> n;

    graph g(n); // now the constructor will make a adjacent list of size 5 (0-4).
    // now we will add the edges in adjacent list.

    int edges;
    cout << "enter the no. of edges you want to add in the graph." << endl;
    // the value of node should be between 0 to size-1.
    cin >> edges;
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g.add_edge(u, v);
    }
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);

    int start;
    cout << "enter the source node where you want to start the traversal:" << endl;
    cin >> start;
    cout << "The BFS traversal for above graph will be:" << endl;
    g.bfs(start);
    cout << endl;
    cout << "The DFS traversal for above graph will be:" << endl;
    g.dfs(start);

    return 0;
}