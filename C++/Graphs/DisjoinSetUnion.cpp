#include <bits/stdc++.h>
using namespace std;

int parent[1000000];

// Find the topmost parent of a vertex
int root(int a)
{
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = root(parent[a]);
}

// Connect two components by updating their parent
void connect(int a, int b)
{
    a = root(a);
    b = root(b);

    if (a != b) {
        parent[b] = a;
    }
}

// Count the number of connected components
void connectedComponents(int n)
{
    set<int> s;

    for (int i = 0; i < n; i++) {
        s.insert(root(parent[i]));
    }
    cout << "Number of connected components: " << s.size() << '\n';
}

// Print the input and call the functions
void printAnswer(int N, vector<vector<int>> edges)
{
    // Initialize each vertex as its own parent
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    // Connect the edges
    for (int i = 0; i < edges.size(); i++) {
        connect(edges[i][0], edges[i][1]);
    }

    // Print the number of connected components
    connectedComponents(N);
}

int main()
{
    int N;
    cout << "Enter the number of vertices: ";
    cin >> N;

    vector<vector<int>> edges;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    cout << "\nInput:\n";
    cout << "Number of vertices: " << N << '\n';
    cout << "Edges:\n";
    for (int i = 0; i < m; i++) {
        cout << edges[i][0] << " " << edges[i][1] << '\n';
    }

    cout << "\nOutput:\n";
    printAnswer(N, edges);

    return 0;
}
