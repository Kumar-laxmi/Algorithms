/* I will use Tarjan's Algorithm to find the bridges
   So, what is a bridge -> A bridge of a connected graph is a graph edge whose removal disconnects the graph
   So if we remove the bridge then the graph will be converted into multiple components.
  
   e.g. 1 ←-----→ 3 ←----→ 4
        ↑       ↗          ↑
        |     ↗            |
        |   ↗              |
        ↓ ↙                ↓
        2                  5
      
   In the above bidirectional graph, if we remove edge 3-4 then the graph will be broken into two different components so, we can say 3-4 is a bridge.
  
   T.c.=> O(V+E)
   Auxiliary Space: O(V)

*/


#include<bits/stdc++.h> // includes all header files including algorithms for min, max & standard template library for using vector
using namespace std;

class Solution {
private:
    int timer=1;
    void dfs(int node, int parent, vector<int>& vis, int tin[], int low[], 
            vector<int> adj[], vector<vector<int>>& ans){
        vis[node] = 1;                      // mark node as visited
        tin[node] = low[node] = timer;      // put the time of insertion
        timer++;                            // increase timer value for next insertion elements
        for(auto it: adj[node]){
            if(it == parent)    continue;   // we don't want to go back through the same path (we don't need to call DFS)
            if(!vis[it]){                   // if it has not been discovered before or previously visited
                dfs(it, node, vis, tin, low, adj, ans);
                low[node]= min(low[node], low[it]);     // storing least value, low[it] might be an ancestor of node
                if(low[it] > tin[node]){                // if the lowest time of insertion is greater than tin val i.e. we cannot reach the current node thus it is a bridge
                    ans.push_back({it, node});          // store the edge in ans (2d vector)
                }
            } else {                                    // if it was already discovered then we found an ancestor
                low[node]= min(low[node], tin[it]);     // finds the ancestor with the least tin value i.e. dfs time insertion
            }
        }
    }
   
   public:
    vector<vector<int>> findBridges(int n, vector<vector<int>>& connections){
        // making adjacency list
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);    // using these two statements
            adj[it[1]].push_back(it[0]);    // we are making the graph bidirectional
        }
        
        vector<int> vis(n, 0); // to check whether nodes are visited before
        int tin[n];            // will store DFS time insertion value using timer variable in Solution
        int low[n];            // minimum lowest time insertion of all adjacent nodes apart from parent
        vector<vector<int>> ans;  // we will store the ans here
        
        dfs(0, -1, vis, tin, low, adj, ans);    // initital node: 0, initital parent: -1
        return ans;
    }
};

// Main Function --> Driver code

int main() 
{
    Solution s1;    // creating obj of class Solution

    int noOfNodes = 5;
    vector<vector<int>> node;     //    2d Vector,  without (using namespace std) -> we have to write: std::vector<std::vector<int>>
    node.push_back({0, 1});       //    this inserts the element in the 2d vector
    node.push_back({1, 3});
    node.push_back({1, 2});
    node.push_back({2, 4});
    /*
     *     0 <--> 1 <---> 2
     *            ↑       ↑
     *            |       |
     *            |       |
     *            ↓       ↓
     *            3       4
     *
     *    In this graph there are 4 bridges [1,0] , [2,1] , [4,2] , [3,1]
     *
     *    Assuming that the graph is bi-directional and connected.
     *
     */
    vector<vector<int>> bridges= s1.findBridges(noOfNodes, node);
    
    cout<<"\n"<<bridges.size()<<" bridges found!!\n";

    for (auto &it: bridges) {
        cout <<it[0]<<" --> "<<it[1]<<"\n";
    }
    
    return 0;
}
