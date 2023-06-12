#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_LEVEL 16

// Node structure for the skip list
typedef struct SkipListNode {
    int value;
    struct SkipListNode** forward;
} SkipListNode;

// Skip List structure
typedef struct SkipList {
    int level;
    SkipListNode* header;
} SkipList;

// Create a new SkipListNode
SkipListNode* createSkipListNode(int level, int value) {
    SkipListNode* node = (SkipListNode*)malloc(sizeof(SkipListNode));
    node->value = value;
    node->forward = (SkipListNode**)malloc(sizeof(SkipListNode*) * (level + 1));
    memset(node->forward, 0, sizeof(SkipListNode*) * (level + 1));
    return node;
}

// Create a new SkipList
SkipList* createSkipList() {
    SkipList* skipList = (SkipList*)malloc(sizeof(SkipList));
    skipList->level = 0;
    skipList->header = createSkipListNode(MAX_LEVEL, 0);
    srand(time(NULL)); // Initialize random seed
    return skipList;
}

// Generate a random level for a new node
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL)
        level++;
    return level;
}

// Insert a value into the skip list
void insert(SkipList* skipList, int value) {
    SkipListNode* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(SkipListNode*) * (MAX_LEVEL + 1));
    SkipListNode* current = skipList->header;

    // Find the appropriate position to insert the new node
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    // If the value already exists, update the node's value
    if (current != NULL && current->value == value) {
        printf("Value already exists: %d\n", value);
        return;
    }

    // Generate a random level for the new node
    int newNodeLevel = randomLevel();

    // If the new node's level is greater than the current level, update the update array
    if (newNodeLevel > skipList->level) {
        for (int i = skipList->level + 1; i <= newNodeLevel; i++)
            update[i] = skipList->header;
        skipList->level = newNodeLevel;
    }

    // Create the new node
    SkipListNode* newNode = createSkipListNode(newNodeLevel, value);

    // Insert the new node into the skip list
    for (int i = 0; i <= newNodeLevel; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }

    printf("Inserted value: %d\n", value);
}

// Search for a value in the skip list
bool search(SkipList* skipList, int value) {
    SkipListNode* current = skipList->header;

    // Traverse the skip list
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value)
            current = current->forward[i];
    }

    current = current->forward[0];

    // Check if the value is found
    if (current != NULL && current->value == value) {
        printf("Value found: %d\n", value);
        return true;
    }

    printf("Value not found: %d\n", value);
    return false;
}

// Free the memory allocated for the skip list
void freeSkipList(SkipList* skipList) {
    SkipListNode* current = skipList->header;
    while (current != NULL) {
        SkipListNode* temp = current->forward[0];
        free(current->forward);
        free(current);
        current = temp;
    }
    free(skipList);
}

int main() {
    SkipList* skipList = createSkipList();

    insert(skipList, 3);
    insert(skipList, 6);
    insert(skipList, 2);
    insert(skipList, 9);

    search(skipList, 6);
    search(skipList, 5);

    freeSkipList(skipList);

    return 0;
}
