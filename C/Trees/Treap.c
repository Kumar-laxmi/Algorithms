// Algorithm:
// 1. Start with an empty Treap.
// 2. For each element to be inserted:
//    a. Create a new node with the element and a random priority.
//    b. Split the Treap at the position where the new node should be inserted.
//    c. Merge the left split, new node, and right split to form the updated Treap.
// 3. To delete an element, find the node with the target element and remove it.
// 4. To search for an element, traverse the Treap and return the corresponding node if found.
// 5. Perform any other required operations like rotating, merging, or splitting as needed.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a node in the Treap
struct Node {
    int key;           // Value of the node
    int priority;      // Priority of the node
    struct Node* left; // Pointer to the left child
    struct Node* right; // Pointer to the right child
};

// Create a new node with the given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->priority = rand(); // Assign a random priority
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Split the Treap based on the key. Left Treap will have nodes <= key and right Treap will have nodes > key.
void split(struct Node* root, int key, struct Node** left, struct Node** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
    } else if (root->key <= key) {
        split(root->right, key, &(root->right), right);
        *left = root;
    } else {
        split(root->left, key, left, &(root->left));
        *right = root;
    }
}

// Merge two Treaps into a single Treap.
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
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
struct Node* insert(struct Node* root, int key) {
    struct Node* newNode = createNode(key);
    struct Node* left;
    struct Node* right;
    split(root, key, &left, &right);
    return merge(merge(left, newNode), right);
}

// Search for a key in the Treap.
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

// Delete a node with a key from the Treap.
struct Node* erase(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (root->key == key) {
        struct Node* temp = merge(root->left, root->right);
        free(root);
        return temp;
    }

    if (key < root->key)
        root->left = erase(root->left, key);
    else
        root->right = erase(root->right, key);

    return root;
}

// Inorder traversal of the Treap
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    // Initialize random seed
    srand(time(NULL));

    // User input to demonstrate Treap operations
    int choice;
    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int key;
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d inserted.\n", key);
                break;
            }
            case 2: {
                int key;
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = erase(root, key);
                printf("Key %d deleted.\n", key);
                break;
            }
            case 3: {
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);
                struct Node* result = search(root, key);
                if (result != NULL)
                    printf("Key %d found.\n", key);
                else
                    printf("Key %d not found.\n", key);
                break;
            }
            case 4: {
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    // Deallocate memory
    // ...

    return 0;
}
