#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if(!node) return node;
    Node* nHead = new Node(node->val);

    queue<pair<Node*,Node*>> q;
    map<Node*,Node*> mp;
    mp[node] = nHead;
    q.push({node,nHead});

    while(q.size()) {
        Node* old = q.front().first;
        Node* newNode = q.front().second;
        q.pop();

        for(auto it: old->neighbors) {  
            if(!mp.count(it)) {
                Node* newChild = new Node(it->val);
                newNode->neighbors.push_back(newChild);
                mp[it] = newChild;
                q.push({it,newChild});
            } else {
                Node* newNeighbor = mp[it];
                newNode->neighbors.push_back(newNeighbor);
            }  
        }
    }

    return nHead;
}

bool compareMemAddresses(Node* one,Node* two) {
    cout << "Values for node in graph 1 & graph 2 are: " << endl;
    cout << one->val << " " << two->val << endl;

    if(one == two) {
        return 1;
    } else {
        return 0;
    }
}

map<int,Node*> mp1;
map<int,Node*> mp2;

void bfs(Node* node,bool compare = 0) {
    unordered_set<Node*> vis;
    vis.insert(node);
    queue<Node*> q;
    q.push(node);

    while (q.size())
    {
        Node* fr = q.front();
        q.pop();
        int nval = fr->val;

        if(compare) {
            if(compareMemAddresses(mp1[nval],fr)) cout << "The pointers are pointing to the same location in memory" << endl; 
            cout << "The pointers are not pointing to the same location in memory" << endl; 
            cout << endl;
        } 

        for(auto it: fr->neighbors) {
            if(vis.count(it)) {
                continue;
            }

            vis.insert(it);
            q.push(it);
        }
    }
}


int main() {
    cout << "Enter the num of nodes & edges " << endl;

    int n,m;
    cin >> n >> m;

    cout << "Enter the edges " << endl;

    while (m--)
    {
        int u,v;
        cin >> u >> v;
        if(!mp1.count(u)) {
            Node* node = new Node(u);
            mp1[u] = node;
        }
        if(!mp1.count(v)) {
            Node* node = new Node(v);
            mp1[v] = node;
        }

        mp1[u]->neighbors.push_back(mp1[v]);
        mp1[v]->neighbors.push_back(mp1[u]);
    }
    
    cout << "Enter the root node" << endl;

    int rt;
    cin >> rt;

    Node* root = mp1[rt];
    Node* cpyNode = cloneGraph(root);
    bfs(root);
    bfs(cpyNode,1);
    
    return 0;
}