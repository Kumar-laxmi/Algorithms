// Path: C/Trees/trie.c
// C program to implement trie.

// A prefix trie is an ordered tree data structure used in the representation of a set of strings over a finite alphabet set,
// which allows efficient storage of words with common prefixes.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Trie node
struct TrieNode
{
    // 26 lowercase alphabets
    struct TrieNode *children[26];
    bool isEndOfWord;
};

// Creates a new Trie node
struct TrieNode *createNode()
{
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    newNode->isEndOfWord = false;

    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Inserts a word into the Trie
void insert(struct TrieNode *root, const char *word)
{
    struct TrieNode *currentNode = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int ind = word[i] - 'a';

        if (currentNode->children[ind] == NULL)
        {
            currentNode->children[ind] = createNode();
        }

        currentNode = currentNode->children[ind];
    }

    currentNode->isEndOfWord = true;
}

// Searches for a word in the Trie
bool search(struct TrieNode *root, const char *word)
{
    struct TrieNode *currentNode = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int ind = word[i] - 'a';

        if (currentNode->children[ind] == NULL)
        {
            return false;
        }

        currentNode = currentNode->children[ind];
    }

    return (currentNode != NULL && currentNode->isEndOfWord);
}

// Checks if a Trie node has any children
bool hasChildren(struct TrieNode *node)
{
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i] != NULL)
        {
            return true;
        }
    }

    return false;
}

// Deletes a word from the Trie
bool deleteWord(struct TrieNode *root, const char *word, int level)
{
    if (root == NULL)
    {
        return false;
    }

    if (word[level] == '\0')
    {
        if (root->isEndOfWord)
        {
            root->isEndOfWord = false;

            if (!hasChildren(root))
            {
                free(root);
                root = NULL;
            }

            return true;
        }

        return false;
    }

    int ind = word[level] - 'a';
    bool deleted = deleteWord(root->children[ind], word, level + 1);

    if (deleted && !hasChildren(root->children[ind]))
    {
        free(root->children[ind]);
        root->children[ind] = NULL;
    }

    return deleted;
}

// Deletes the entire Trie
void deleteTrie(struct TrieNode *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            deleteTrie(root->children[i]);
        }
    }

    free(root);
}

// Program starts here
int main()
{
    struct TrieNode *root = createNode();

    // Inserting words into the Trie
    insert(root, "apple");
    insert(root, "banana");
    insert(root, "car");
    insert(root, "cat");
    insert(root, "cart");
    insert(root, "candid");
    printf("Words: apple, banana, car, cat, cart, candid are Inserted.\n\n");

    printf("Search results:\n");

    // Searching for words in the Trie
    printf("apple: %s\n", search(root, "apple") ? "Found" : "Not found");
    printf("banana: %s\n", search(root, "banana") ? "Found" : "Not found");
    printf("care: %s\n", search(root, "care") ? "Found" : "Not found");
    printf("cat: %s\n", search(root, "cat") ? "Found" : "Not found");
    printf("cart: %s\n", search(root, "cart") ? "Found" : "Not found");
    printf("dog: %s\n", search(root, "dog") ? "Found" : "Not found");

    // Deleting words from the Trie
    deleteWord(root, "banana", 0);

    printf("\nAfter deleting 'banana':\n");
    printf("banana: %s\n", search(root, "banana") ? "Found" : "Not found");

    deleteWord(root, "car", 0);

    printf("\nAfter deleting 'car':\n");
    printf("car: %s\n", search(root, "car") ? "Found" : "Not found");
    printf("cart: %s\n", search(root, "cart") ? "Found" : "Not found");

    // Deleting the entire Trie
    deleteTrie(root);

    return 0;
}
