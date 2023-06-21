// Algorithm:
// 1. Start with an empty Treap.
// 2. For each element to be inserted:
//    a. Create a new node with the element and a random priority.
//    b. Split the Treap at the position where the new node should be inserted.
//    c. Merge the left split, new node, and right split to form the updated Treap.
// 3. To delete an element, find the node with the target element and remove it.
// 4. To search for an element, traverse the Treap and return the corresponding node if found.
// 5. Perform any other required operations like rotating, merging, or splitting as needed.

#include <iostream>
#include <cstdlib>

// Structure for a node in the Treap
struct Node {
    int key;           // Value of the node
    int priority;      // Priority of the node
    Node* left;        // Pointer to the left child
    Node* right;       // Pointer to the right child

    Node(int k) {
        key = k;
        priority = rand();  // Assign a random priority
        left = nullptr;
        right = nullptr;
    }
};

// Split the Treap based on the key. Left Treap will have nodes <= key and right Treap will have nodes > key.
void split(Node* root, int key, Node*& left, Node*& right) {
    if (root == nullptr) {
        left = nullptr;
        right = nullptr;
    } else if (root->key <= key) {
        split(root->right, key, root->right, right);
        left = root;
    } else {
        split(root->left, key, left, root->left);
        right = root;
    }
}

// Merge two Treaps into a single Treap.
Node* merge(Node* left, Node* right) {
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(left, right->left);
        return right;
    }
}

// Insert a new node with a key into the Treap.
Node* insert(Node* root, int key) {
    Node* newNode = new Node(key);
    Node* left;
    Node* right;
    split(root, key, left, right);
    return merge(merge(left, newNode), right);
}

// Search for a key in the Treap.
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

// Delete a node with a key from the Treap.
Node* erase(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (root->key == key) {
        Node* temp = merge(root->left, root->right);
        delete root;
        return temp;
    }

    if (key < root->key)
        root->left = erase(root->left, key);
    else
        root->right = erase(root->right, key);

    return root;
}

// Inorder traversal of the Treap (for demonstration purposes)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    std::cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // User input to demonstrate Treap operations
    int choice;
    do {
        std::cout << "\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int key;
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                root = insert(root, key);
                std::cout << "Key " << key << " inserted.\n";
                break;
            }
            case 2: {
                int key;
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                root = erase(root, key);
                std::cout << "Key " << key << " deleted.\n";
                break;
            }
            case 3: {
                int key;
                std::cout << "Enter key to search: ";
                std::cin >> key;
                Node* result = search(root, key);
                if (result != nullptr)
                    std::cout << "Key " << key << " found.\n";
                else
                    std::cout << "Key " << key << " not found.\n";
                break;
            }
            case 4: {
                std::cout << "Inorder Traversal: ";
                inorder(root);
                std::cout << std::endl;
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    // Deallocate memory
    // ...
    
    return 0;
}
