#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int key;
    int priority;
    Node* left;
    Node* right;
};
 // Function to create a new node with the given key
// and a randomly generated priority value
Node* createNode(int key, int priority) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->priority = priority;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to perform a right rotation on the given root node
Node* rightRotate(Node* root) {
    Node* newRoot = root->left;
    Node* temp = newRoot->right;
    newRoot->right = root;
    root->left = temp;
    return newRoot;
}
// Function to perform a left rotation on the given root node
Node* leftRotate(Node* root) {
    Node* newRoot = root->right;
    Node* temp = newRoot->left;
    newRoot->left = root;
    root->right = temp;
    return newRoot;
}
// Function to insert a new node with the given key into the tree
Node* insert(Node* root, int key, int priority) {
    if (root == NULL)
        return createNode(key, priority);

    if (key < root->key) {
        root->left = insert(root->left, key, priority);
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else {
        root->right = insert(root->right, key, priority);
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}
 // Function to delete the node with the given key from the tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        else {
            if (root->left->priority > root->right->priority) {
                root = rightRotate(root);
                root->right = deleteNode(root->right, key);
            }
            else {
                root = leftRotate(root);
                root->left = deleteNode(root->left, key);
            }
        }
    }
    return root;
}
// Function to perform an inorder traversal of the tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << "Key: " << root->key << " Priority: " << root->priority << endl;
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, key, priority;
//Main loop to interact with the user and perform operations
    while (true) {
        cout << "1. Insert  2. Delete  3. Print Inorder  4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                cout << "Enter the priority: ";
                cin >> priority;
                root = insert(root, key, priority);
                break;

            case 2:
                cout << "Enter the key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;

            case 3:
                cout << "Inorder Traversal:" << endl;
                inorderTraversal(root);
                break;

           case 4:
                exit(0);

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout << endl;
    }

    return 0;
}
