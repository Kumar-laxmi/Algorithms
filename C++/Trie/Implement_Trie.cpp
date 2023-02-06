// C++ implementation of search and insert operations on Trie

#include <bits/stdc++.h>
using namespace std;
 
// TrieNode Class
class TrieNode
{
    public:
    TrieNode *children[26];
 
    // isEndOfWord is true if the node represents end of a word
    bool isEndOfWord;

    // Construtor
    TrieNode() {
        // Initializing the children array with NULL
        for(int i = 0 ; i < 26; i++) {
            children[i] = NULL;
        }

        // Initializing isEndOfWord with false
        isEndOfWord = false;
    }
};
 
// Trie class
class Trie
{
    private:
    TrieNode *root;

    public:
    // Constructor
    Trie() {
        // Creeating a new TrieNode
        root = new TrieNode();
    }

    // If not present, inserts key into trie
    // If the key is prefix of trie node, just marks leaf node
    void insert(string word)
    {
        TrieNode *curr = root;
    
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!curr -> children[index]) {
                curr -> children[index] = new TrieNode();
            }

            curr = curr -> children[index];
        }
    
        // mark last node as leaf
        curr -> isEndOfWord = true;
    }

    // Returns true if key presents in trie, else false
    bool search(string key)
    {
        TrieNode *curr = root;
    
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!curr -> children[index]) {
                return false;
            }
    
            curr = curr -> children[index];
        }
    
        return curr -> isEndOfWord;
    }
};

int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    Trie *t = new Trie();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        t -> insert(keys[i]);
 
    // Output based on the result
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    // Search for different keys
    cout<<"the"<<" -> "<<output[t -> search("the")]<<endl;
    cout<<"these"<<" -> "<<output[t -> search("these")]<<endl;
    cout<<"their"<<" -> "<<output[t -> search("their")]<<endl;
    cout<<"thaw"<<" -> "<<output[t -> search("thaw")]<<endl;

    return 0;
}