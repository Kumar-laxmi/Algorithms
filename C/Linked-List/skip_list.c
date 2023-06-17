#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_LEVEL 6 // Maximum level for skip list

// Skip list node
typedef struct SkipNode {
    int value;
    struct SkipNode** forward; // Array of pointers to forward nodes at each level
} SkipNode;

// Skip list
typedef struct SkipList {
    SkipNode* header; // Pointer to the header node
    int level; // Current level of the skip list
} SkipList;

// Create a new node
SkipNode* createNode(int level, int value) {
    SkipNode* newNode = (SkipNode*)malloc(sizeof(SkipNode));
    newNode->value = value;
    newNode->forward = (SkipNode**)malloc(sizeof(SkipNode*) * (level + 1)); // Allocate memory for the forward pointers
    memset(newNode->forward, 0, sizeof(SkipNode*) * (level + 1)); // Initialize all pointers to NULL
    return newNode;
}

// Create a new skip list
SkipList* createSkipList() {
    SkipList* skipList = (SkipList*)malloc(sizeof(SkipList));
    skipList->header = createNode(MAX_LEVEL, 0); // Create the header node with maximum level
    skipList->level = 0; // Set the initial level to 0
    return skipList;
}

// Generate random level for a node
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) // Randomly increase the level with a probability of 1/2
        level++;
    return level;
}

// Insert a value into the skip list
void insert(SkipList* skipList, int value) {
    SkipNode* update[MAX_LEVEL + 1]; // Array to store the update nodes at each level
    memset(update, 0, sizeof(SkipNode*) * (MAX_LEVEL + 1)); // Initialize all update nodes to NULL
    SkipNode* current = skipList->header; // Start from the header node

    // Find the appropriate position to insert the value
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value)
            current = current->forward[i];
        update[i] = current; // Store the update nodes
    }

    current = current->forward[0];

    // If the value is already present, return
    if (current == NULL || current->value != value) {
        int newLevel = randomLevel(); // Generate a random level for the new node
        if (newLevel > skipList->level) {
            for (int i = skipList->level + 1; i <= newLevel; i++)
                update[i] = skipList->header; // Update the pointers in the update array for the new level
            skipList->level = newLevel; // Update the current level
        }
        current = createNode(newLevel, value); // Create a new node
        for (int i = 0; i <= newLevel; i++) {
            current->forward[i] = update[i]->forward[i]; // Update the forward pointers
            update[i]->forward[i] = current;
        }
        printf("Inserted %d into the skip list.\n", value);
    }
}

// Search for a value in the skip list
bool search(SkipList* skipList, int value) {
    SkipNode* current = skipList->header; // Start from the header node
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value)
            current = current->forward[i]; // Move forward at each level until the value is found or surpassed
    }
    current = current->forward[0]; // Move to the next node at the lowest level
    if (current != NULL && current->value == value) {
        printf("%d found in the skip list.\n", value);
        return true;
    }
    printf("%d not found in the skip list.\n", value);
    return false;
}

// Display the skip list
void display(SkipList* skipList) {
    printf("Skip List:\n");
    for (int i = 0; i <= skipList->level; i++) {
        SkipNode* node = skipList->header->forward[i];
        printf("Level %d: ", i);
        while (node != NULL) {
            printf("%d ", node->value);
            node = node->forward[i];
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    SkipList* skipList = createSkipList();

    insert(skipList, 3);
    insert(skipList, 7);
    insert(skipList, 2);
    insert(skipList, 9);

    display(skipList);

    search(skipList, 2);
    search(skipList, 5);

    return 0;
}
