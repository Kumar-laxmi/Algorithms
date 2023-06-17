#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int MAX_LEVEL = 6; // Maximum level for skip list

// Skip list node
struct SkipNode {
    int value;
    SkipNode** forward; // Array of pointers to forward nodes at each level
    SkipNode(int level, int value) {
        this->value = value;
        forward = new SkipNode*[level + 1]; // Allocate memory for the forward pointers
        std::fill_n(forward, level + 1, nullptr); // Initialize all pointers to nullptr
    }
    ~SkipNode() {
        delete[] forward; // Free the memory allocated for the forward pointers
    }
};

// Skip list
struct SkipList {
    SkipNode* header; // Pointer to the header node
    int level; // Current level of the skip list

    SkipList() {
        header = new SkipNode(MAX_LEVEL, 0); // Create the header node with maximum level
        level = 0; // Set the initial level to 0
    }

    ~SkipList() {
        delete header; // Free the memory allocated for the header node
    }

    // Generate random level for a node
    int randomLevel() {
        int level = 0;
        while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) // Randomly increase the level with a probability of 1/2
            level++;
        return level;
    }

    // Insert a value into the skip list
    void insert(int value) {
        SkipNode* update[MAX_LEVEL + 1]; // Array to store the update nodes at each level
        std::fill_n(update, MAX_LEVEL + 1, nullptr); // Initialize all update nodes to nullptr
        SkipNode* current = header; // Start from the header node

        // Find the appropriate position to insert the value
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current; // Store the update nodes
        }

        current = current->forward[0];

        // If the value is already present, return
        if (current == nullptr || current->value != value) {
            int newLevel = randomLevel(); // Generate a random level for the new node
            if (newLevel > level) {
                for (int i = level + 1; i <= newLevel; i++)
                    update[i] = header; // Update the pointers in the update array for the new level
                level = newLevel; // Update the current level
            }
            current = new SkipNode(newLevel, value); // Create a new node
            for (int i = 0; i <= newLevel; i++) {
                current->forward[i] = update[i]->forward[i]; // Update the forward pointers
                update[i]->forward[i] = current;
            }
            cout << "Inserted " << value << " into the skip list." << endl;
        }
    }

    // Search for a value in the skip list
    bool search(int value) {
        SkipNode* current = header; // Start from the header node
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i]; // Move forward at each level until the value is found or surpassed
        }
        current = current->forward[0]; // Move to the next node at the lowest level
        if (current != nullptr && current->value == value) {
            cout << value << " found in the skip list." << endl;
            return true;
        }
        cout << value << " not found in the skip list." << endl;
        return false;
    }

    // Display the skip list
    void display() {
        cout << "Skip List: " << endl;
        for (int i = 0; i <= level; i++) {
            SkipNode* node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << node->value << " ";
                node = node->forward[i];
            }
            cout << endl;
        }
    }
};

int main() {
    srand(time(nullptr)); // Initialize random seed

    SkipList skipList;

    skipList.insert(3);
    skipList.insert(7);
    skipList.insert(2);
    skipList.insert(9);

    skipList.display();

    skipList.search(2);
    skipList.search(5);

    return 0;
}
