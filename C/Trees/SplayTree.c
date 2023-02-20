#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int key) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *rightRotate(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node *splay(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (root->key > key) {
        if (root->left == NULL) {
            return root;
        }

        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL) {
                root->left = leftRotate(root->left);
            }
        }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if (root->right == NULL) {
            return root;
        }

        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL) {
                root->right = rightRotate(root->right);
            }
        } else if (root->right->key < key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

Node *search(Node *root, int key) {
    return splay(root, key);
}

Node *insert(Node *root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    root = splay(root, key);

    if (root->key == key) {
        return root;
    }

    Node *node = newNode(key);

    if (root->key > key) {
        node->right = root;
        node->left = root->left;
        root->left = NULL;
    } else {
        node->left = root;
        node->right = root->right;
        root->right = NULL;
    }

    return node;
}




Node *deleteNode(Node *root, int key) {
    if (root == NULL) {
        return root;
    }

    root = splay(root, key);

    if (root->key != key) {
        return root;
    }

    if (root->left == NULL) {
        Node *rightChild = root->right;
        free(root);
        return rightChild;
    } else {
        Node *leftChild = splay(root->left, key);
        leftChild->right = root->right;
        free(root);
        return leftChild;
    }
}

int main(void) {
    Node *root = NULL;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 150);
    root = insert(root, 250);
    root = deleteNode(root, 200);
    root = deleteNode(root, 50);

    return 0;
}
