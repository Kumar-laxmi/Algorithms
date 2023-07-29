#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given key
// and a randomly generated priority value
struct Node* createNode(int key,int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->priority = priority;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to perform a right rotation on the given root node
struct Node* rightRotate(struct Node* root) {
    struct Node* newRoot = root->left;
    struct Node* temp = newRoot->right;
    newRoot->right = root;
    root->left = temp;
    return newRoot;
}
// Function to perform a left rotation on the given root node
struct Node* leftRotate(struct Node* root) {
    struct Node* newRoot = root->right;
    struct Node* temp = newRoot->left;
    newRoot->left = root;
    root->right = temp;
    return newRoot;
}
// Function to insert a new node with the given key into the tree
struct Node* insert(struct Node* root, int key,int priority) {
    if (root == NULL)
        return createNode(key,priority);

    if (key < root->key) {
        root->left = insert(root->left, key,priority);
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    } else {
        root->right = insert(root->right, key,priority);
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}
// Function to delete the node with the given key from the tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            root = temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            root = temp;
        } else {
            if (root->left->priority > root->right->priority) {
                root = rightRotate(root);
                root->right = deleteNode(root->right, key);
            } else {
                root = leftRotate(root);
                root->left = deleteNode(root->left, key);
            }
        }
    }
    return root;
}
// Function to perform an inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Key: %d Priority: %d\n", root->key, root->priority);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key,priority;

    srand(time(NULL));

    // Main loop to interact with the user and perform operations
    while (1) {
        printf("1. Insert  2. Delete  3. Print Inorder  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                root = insert(root, key,priority);
                break;

            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 3:
                printf("Inorder Traversal:\n");
                inorderTraversal(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
