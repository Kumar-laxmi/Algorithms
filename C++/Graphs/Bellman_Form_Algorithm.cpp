/** 1 ---- 2
 * Let's say this edge has negative weight, i.e. -2. Go from 1 to 2, cost = -2,
   go from 2 to 1 again, cost = -4, go from 1 to 2 again, cost = -6
 * You can see the cost is getting reduced, so the Dijkstra's algo can never find minimum cost to reach 2
   and end up in an infinte loop.
   
   Bellman's ford algo works for:
        1. DG, if there is no negative cycle, and it will also tell if there is any -ve cycle exists
            Ex: 1 -> 2 -> 3 ->...1; Weights: 1 -> 2: 6, 2 -> 3: -12, 3 -> 1: -7
            You go from 1 to 2, cost = 6
            go from 2 to 3, cost 6 - 12 = -6
            go from 3 to 1, cost = -6 - 7 = -13,
            go from 1 to 2, cost = -13 + 6 = -7 => less than 6
            ...so there is a negative cycle
        2. UG, Ex: 1 --- 2
            Weight(1---2) = x => convert it to DG as 1 <---> 2 with weight x for both sides

        The algo works for both graph and if there is a -ve cycle it detects it, instead of ending up in an inf loop.

        Algorithm:
            1. Relax all edges N - 1 times
               if (dist[u] + wt < dist[v]) dist[v] = dist[u] + wt
            After N - 1 relaxation the distance array will contain the shortest path to every nodes.
            Do one more relaxation after that, if the cost reduces in this relaxation, this means
            a -ve cycle exists in the graph.
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // number of vertices
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    // vector<pair<int, int>> adj[v + 1] = {
    //     {{1, 5}},
    //     {{2, -2}, {5, -3}},
    //     {{4, 3}},
    //     {{2, 6}, {4, -2}},
    //     {},
    //     {{3, 1}}
    // };

    vector<pair<int, int>> adj[v];

    for (int i = 0; i < v; i++) {
        int ad;
        cout << "Enter number of adcancies of vertex " << i << ": ";
        cin >> ad;

        cout << "Now enter the nodes in the adjacency of " << i << " and the weight separated by space:\n";
        for (int j = 0; j < ad; j++) {
            int x, y;
            cin >> x >> y;
            adj[i].push_back({x, y});
        }
    }

    vector<int> dist(v, 1000000000);
    dist[0] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (int u = 0; u < v; u++) {
            for (auto it : adj[u]) {
                if (dist[u] + it.second < dist[it.first]) dist[it.first] = dist[u] + it.second;
            }
        }
    }

    int flag = 0;
    for (int u = 0; u < v; u++) {
        for (auto it : adj[u]) {
            if (dist[u] + it.second < dist[it.first]) {
                cout << "Negative cycle\n";
                flag = 1;
                break;
            }
        }
    }
    
    // Taking source at vertex 0
    if (!flag) {
        for (int i = 0; i < v; i++) cout << dist[i] << " ";
        cout << endl;
    }
}