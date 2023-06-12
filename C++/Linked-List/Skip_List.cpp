#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int MAX_LEVEL = 16;  // Maximum level of the skip list

// Node structure for the skip list
struct SkipListNode {
    int value;
    SkipListNode** forward;

    SkipListNode(int level, int value) {
        this->value = value;
        forward = new SkipListNode*[level + 1];
        memset(forward, 0, sizeof(SkipListNode*) * (level + 1));
    }

    ~SkipListNode() {
        delete[] forward;
    }
};

// Skip List class
class SkipList {
private:
    int level;
    SkipListNode* header;

public:
    SkipList() {
        level = 0;
        header = new SkipListNode(MAX_LEVEL, 0);
        std::srand(std::time(0));  // Initialize random seed
    }

    ~SkipList() {
        delete header;
    }

    // Generate a random level for a new node
    int randomLevel() {
        int level = 0;
        while (std::rand() < RAND_MAX / 2 && level < MAX_LEVEL)
            level++;
        return level;
    }

    // Insert a value into the skip list
    void insert(int value) {
        SkipListNode* update[MAX_LEVEL + 1];
        memset(update, 0, sizeof(SkipListNode*) * (MAX_LEVEL + 1));
        SkipListNode* current = header;

        // Find the appropriate position to insert the new node
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        // If the value already exists, update the node's value
        if (current != nullptr && current->value == value) {
            cout << "Value already exists: " << value << endl;
            return;
        }

        // Generate a random level for the new node
        int newNodeLevel = randomLevel();

        // If the new node's level is greater than the current level, update the update array
        if (newNodeLevel > level) {
            for (int i = level + 1; i <= newNodeLevel; i++)
                update[i] = header;
            level = newNodeLevel;
        }

        // Create the new node
        SkipListNode* newNode = new SkipListNode(newNodeLevel, value);

        // Insert the new node into the skip list
        for (int i = 0; i <= newNodeLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        std::cout << "Inserted value: " << value << endl;
    }

    // Search for a value in the skip list
    bool search(int value) {
        SkipListNode* current = header;

        // Traverse the skip list
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
        }

        current = current->forward[0];

        // Check if the value is found
        if (current != nullptr && current->value == value) {
            cout << "Value found: " << value << endl;
            return true;
        }

        cout << "Value not found: " << value << endl;
        return false;
    }
};

int main() {
    SkipList skipList;

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(2);
    skipList.insert(9);

    skipList.search(6);
    skipList.search(5);

    return 0;
}
