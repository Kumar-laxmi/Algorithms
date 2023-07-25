#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

struct Edge
{
    int source;
    int destination;
    int weight;
};

class Graph
{
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int source, int destination, int weight)
    {
        edges.push_back({source, destination, weight});
    }

    // Bellman-Ford algorithm to find the minimum distance from a single source to all vertices
    bool bellmanFord(int source, vector<int> &distances)
    {
        distances.assign(V, INF);
        distances[source] = 0;

        for (int i = 0; i < V - 1; ++i)
        {
            for (const Edge &edge : edges)
            {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;

                if (distances[u] != INF && distances[u] + w < distances[v])
                    distances[v] = distances[u] + w;
            }
        }

        // Check for negative cycles
        for (const Edge &edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distances[u] != INF && distances[u] + w < distances[v])
                return false;
        }

        return true;
    }

    // Dijkstra's algorithm to find the shortest paths from a single source to all vertices
    vector<int> dijkstra(int source)
    {
        vector<int> distances(V, INF);
        distances[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (const Edge &edge : edges)
            {
                if (edge.source == u)
                {
                    int v = edge.destination;
                    int w = edge.weight;

                    if (distances[u] != INF && distances[u] + w < distances[v])
                    {
                        distances[v] = distances[u] + w;
                        pq.push({distances[v], v});
                    }
                }
            }
        }

        return distances;
    }

    // Johnson's algorithm to find the shortest paths between all pairs of vertices
    vector<vector<int>> johnsonAlgorithm()
    {
        // Add a new vertex with zero-weight edges to all other vertices
        int newVertex = V;
        for (int i = 0; i < V; ++i)
            addEdge(newVertex, i, 0);

        // Run Bellman-Ford algorithm to get the shortest paths from the new vertex
        vector<int> h;
        if (!bellmanFord(newVertex, h))
        {
            cout << "Graph contains a negative cycle. Johnson's algorithm cannot proceed." << endl;
            return vector<vector<int>>(V, vector<int>(V, INF));
        }

        // Re-weight the edges
        for (Edge &edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            edge.weight = w + h[u] - h[v];
        }

        vector<vector<int>> allPairsDistances(V, vector<int>(V, INF));

        // Run Dijkstra's algorithm for each vertex to find the shortest paths
        for (int i = 0; i < V; ++i)
        {
            vector<int> dijkstraDistances = dijkstra(i);

            for (int j = 0; j < V; ++j)
            {
                // Update the distance by reverting the re-weighting
                allPairsDistances[i][j] = dijkstraDistances[j] + h[j] - h[i];
            }
        }

        return allPairsDistances;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter edge information (source, destination, weight) for each edge:" << endl;
    for (int i = 0; i < E; ++i)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    vector<vector<int>> allPairsDistances = graph.johnsonAlgorithm();

    cout << "Shortest distances between all pairs of vertices:" << endl;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (allPairsDistances[i][j] == INF)
                cout << "INF ";
            else
                cout << allPairsDistances[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
