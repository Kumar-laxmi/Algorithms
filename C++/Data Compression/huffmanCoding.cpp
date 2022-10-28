#include<bits/stdc++.h>
using namespace std;
#define maxTreeHeight 100
// huffman tree node
struct huffmanNode {
    char data; // input char
    long long freq; // char frequency
    huffmanNode *left, *right; // node childs
    huffmanNode(char data, long long freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// compare 2 heap nodes
struct compareNode {
    bool operator()(huffmanNode *l, huffmanNode *r) { 
        return l->freq < r->freq;
    }
};

// build & traverse huffman tree
void huffmanTree(vector<char> data, vector<int> freq, int size) {
    struct huffmanNode *left, *right, *top;
    // insert all data array characters
    priority_queue<huffmanNode *, vector<huffmanNode *>, compareNode> minHeap;
    for(int i = 0; i < size; i++)
        minHeap.push(new huffmanNode(data[i], freq[i])); 
    while(minHeap.size() != 1) {
        // extract 2 minimum freq. items
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        // new node contruction from sum of left & right node freq.
        top = new huffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

void printCodes(huffmanNode *root, string s) {
    if(!root) return;
    if(root->data != '$')
        cout << root->data << " : " << s << endl;
    printCodes(root->left, s + '0');
    printCodes(root->right, s + '1');
}

string revomeDuplicates(string s) {
    int n = s.length(), idx = 0;
    unordered_map<char, int> m;
    for(int i = 0; i < n; i++) {
        if(!m[s[i]]) {
            s[idx++] = s[i];
            m[s[i]]++;
        }
    }
    return s;
}

int main() {
    string s; // store input string
    vector<char> ar; // store each character
    vector<int> freq; // store character frequency
    map<char, int> m; // count freqency of each character
    
    // input code
    cout << "Enter String : ";
    cin >> s;

    for(int i  = 0; i < s.size(); i++) m[s[i]]++;
    s = revomeDuplicates(s);
    // store characters and freqency
    for(char c : s) ar.push_back(c);
    for(auto i : m) freq.push_back(i.second);
    
    // function call
    huffmanTree(ar, freq, ar.size());
    return 0;
}