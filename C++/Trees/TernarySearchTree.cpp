// Ternary Search Tree (TST) implementation in C++

#include <iostream>
using namespace std;

// The algorithm of the Ternary Search Tree (TST) 
//1.) Create a TST node class with character data, left, middle, and right pointers, and an end-of-word flag.
//2.) Implement an insert() function that recursively inserts characters into the TST based on comparisons.
//3.) Implement a search() function that recursively searches for a string in the TST by comparing characters.
//4.) Initialize an empty TST and use the insert() function to add strings to the TST.
//5.) Use the search() function to check if a string exists in the TST.

// Node class represents a node in the TST
class Node {
public:
    char data;          // The character stored in the node
    bool isEndOfWord;   // Flag to indicate if the node represents the end of a word
    Node* left, * middle, * right; // Pointers to the left, middle, and right child nodes

    // Constructor to initialize the node
    Node(char data) {
        this->data = data;
        this->isEndOfWord = false;
        this->left = this->middle = this->right = nullptr;
    }
};

// Ternary Search Tree class
class TernarySearchTree {
private:
    Node* root; // Root node of the TST

public:
    // Constructor to initialize the TST
    TernarySearchTree() {
        this->root = nullptr;
    }

    // Method to insert a string into the TST
    void insert(string word) {
        root = insert(root, word, 0);
    }

    // Recursive method to insert a character into the TST
    Node* insert(Node* node, const string& word, int index) {
        // If the current node is null, create a new node
        if (node == nullptr) {
            node = new Node(word[index]);
        }

        // Compare the current character with the character in the node
        if (word[index] < node->data) {
            node->left = insert(node->left, word, index);
        }
        else if (word[index] > node->data) {
            node->right = insert(node->right, word, index);
        }
        else {
            // If the characters match, move to the next character
            if (index + 1 < word.length()) {
                node->middle = insert(node->middle, word, index + 1);
            }
            else {
                // Mark the node as the end of a word
                node->isEndOfWord = true;
            }
        }
        return node;
    }

    // Method to search for a string in the TST
    bool search(string word) {
        return search(root, word, 0);
    }

    // Recursive method to search for a character in the TST
    bool search(Node* node, const string& word, int index) {
        // If the current node is null, the word does not exist in the TST
        if (node == nullptr) {
            return false;
        }

        // Compare the current character with the character in the node
        if (word[index] < node->data) {
            return search(node->left, word, index);
        }
        else if (word[index] > node->data) {
            return search(node->right, word, index);
        }
        else {
            // If the characters match, move to the next character
            if (index + 1 == word.length()) {
                // Check if the node represents the end of a word
                return node->isEndOfWord;
            }
            else {
                return search(node->middle, word, index + 1);
            }
        }
    }
};

// Main function to test the TernarySearchTree implementation
int main() {
    TernarySearchTree tst;

    // Insert some words into the TST
    tst.insert("apple");
    tst.insert("banana");
    tst.insert("carrot");
    cout<<"Enter String "<<endl;
    string s;
    cin>>s;
    if(tst.search(s) == 1) cout<<s<<" is Present "<< endl;// Output: 1 (exists)
    else cout<<s<<" is not Present "<< endl;  // Output: 0 (does not exist)
    return 0;
}