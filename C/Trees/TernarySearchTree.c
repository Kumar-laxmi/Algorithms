// Ternary Search Tree (TST) implementation in C

#include <stdio.h>
#include <stdlib.h>

// The algorithm of the Ternary Search Tree (TST) 
//1.) Create a TST node class with character data, left, middle, and right pointers, and an end-of-word flag.
//2.) Implement an insert() function that recursively inserts characters into the TST based on comparisons.
//3.) Implement a search() function that recursively searches for a string in the TST by comparing characters.
//4.) Initialize an empty TST and use the insert() function to add strings to the TST.
//5.) Use the search() function to check if a string exists in the TST.


// Node struct represents a node in the TST
typedef struct Node {
    char data;          // The character stored in the node
    int isEndOfWord;    // Flag to indicate if the node represents the end of a word
    struct Node* left, * middle, * right; // Pointers to the left, middle, and right child nodes
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->isEndOfWord = 0;
    newNode->left = newNode->middle = newNode->right = NULL;
    return newNode;
}

// Function to insert a string into the TST
void insert(Node** node, const char* word) {
    // If the current node is null, create a new node
    if (*node == NULL) {
        *node = createNode(*word);
    }

    // Compare the current character with the character in the node
    if (*word < (*node)->data) {
        insert(&((*node)->left), word);
    }
    else if (*word > (*node)->data) {
        insert(&((*node)->right), word);
    }
    else {
        // If the characters match, move to the next character
        if (*(word + 1)) {
            insert(&((*node)->middle), word + 1);
        }
        else {
            // Mark the node as the end of a word
            (*node)->isEndOfWord = 1;
        }
    }
}

// Function to search for a string in the TST
int search(Node* node, const char* word) {
    // If the current node is null, the word does not exist in the TST
    if (node == NULL) {
        return 0;
    }

    // Compare the current character with the character in the node
    if (*word < node->data) {
        return search(node->left, word);
    }
    else if (*word > node->data) {
        return search(node->right, word);
    }
    else {
        // If the characters match, move to the next character
        if (*(word + 1) == '\0') {
            // Check if the node represents the end of a word
            return node->isEndOfWord;
        }
        else {
            return search(node->middle, word + 1);
        }
    }
}

// Main function to test the TernarySearchTree implementation
int main() {
    Node* root = NULL;

    // Insert some words into the TST
    insert(&root, "apple");
    insert(&root, "banana");
    insert(&root, "carrot");

    // Search for words in the TST
    printf("Enter String \n");
    char s[20];
    scanf("%[^\n]%*c", s);
    if(search(root, "apple") == 1){
        printf("%s is present ", s); // Output: 1 (exists)
    }else{
         printf("%s is not present", s); // Output: 0 (does not exist)
    }

    return 0;
}