#include<bits/stdc++.h>
using namespace std;

// class for avl tree
class Node {
public:
    int data, height;
    Node *left, *right;
};

// height of tree
int height(Node *n) { return !n ? 0 : n->height; }

// node creation method
Node *newNode(int ele) {
    Node *newNode = new Node();
    newNode->data = ele;
    newNode->left, newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *rightRotate(Node *n) {
    Node *p = n->left, *p2 = p->right;

    // rotation
    p->right = n;
    n->left = p2;

    // height updation
    n->height = max(height(n->left), height(n->right)) + 1;
    p->height = max(height(p->left), height(p->right)) + 1;
    return p;
}

Node *leftRotate(Node *n) {
    Node *p = n->right, *p2 = p->left;
    
    // rotation
    p->left = n;
    n->right = p2;

    // height updation
    n->height = max(height(n->left), height(n->right)) + 1;
    p->height = max(height(p->left), height(p->right)) + 1;
    return p;
}

int balFact(Node *n) { return !n ? 0 : height(n->left) - height(n->right); }

// insertion method
Node *insert(Node *n, int ele) {
    if(!n) return newNode(ele);
    if(ele < n->data) n->left = insert(n->left, ele);
    else if(ele > n->data) n->right = insert(n->right, ele);
    else return n;

    // height updation
    n->height = max(height(n->left), height(n->right)) + 1;
    int balance = balFact(n);
    
    // ll rotation
    if(balance > 1 and ele < n->left->data) return rightRotate(n);
    // rr rotation
    if(balance < -1 and ele > n->right->data) return leftRotate(n);
    // lr rotation
    if(balance > 1 and ele > n->left->data) {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    // rl rotation
    if(balance < -1 and ele < n->right->data) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}

Node *minValueNode(Node *n) {
    Node *p = n;
    while(p->left) p = p->left;
    return p;
}

// deletion method
Node *deleteNode(Node *n, int ele) {
    if(!n) return n;
    // ele in left subtree
    if(ele < n->data) n->left = deleteNode(n->left, ele);
    // ele in right subtree
    else if(ele > n->data) n->right = deleteNode(n->right, ele);
    // ele = root node
    else {
        // node with no children or 1 child
        if(!n->left or !n->right) {
            Node *p = n->left ? n->left : n->right;
            if(!p) { p = n; n = NULL; } // no child case
            else *n = *p;
            delete p;
        }
        // 2 children case
        else {
            Node *p = minValueNode(n->right);
            n->data = p->data;
            n->right = deleteNode(n->right, p->data);
        }
    }
    // only 1 node case
    if(!n) return n;

    n->height = max(height(n->left), height(n->right)) + 1;
    int balance = balFact(n);

    // ll rotation
    if (balance > 1 and balFact(n->left) >= 0) return rightRotate(n);
 
    // lr rotation
    if (balance > 1 and balFact(n->left) < 0) {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
 
    // rr rotation
    if (balance < -1 and balFact(n->right) <= 0) return leftRotate(n);
 
    // rl rotation
    if (balance < -1 and balFact(n->right) > 0) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
 
    return n;
}

// traversal method
void preOrderTraversal(Node *n) {
    if(n) {
        cout << n->data << " ";
        preOrderTraversal(n->left);
        preOrderTraversal(n->right);
    }
}

int main() {
    Node *root = NULL;
    int ch, ele;
    while(1) {
        cout << "\nChoose an operation :\n1. INSERTION\n2. DELETETION\n3. PREORDER TRAVERSAL\n4. Exit Program";
        cout << "\nMAKE YOUR CHOICE : ";
        cin >> ch;
        switch (ch) {
        case 1:
            // insertion
            cout << "\nEnter the element for insertion : ";
            cin >> ele;
            root = insert(root, ele);
            break;
        
        case 2:
            // deletion
            cout << "\nEnter element for deletion : ";
            cin >> ele;
            root = deleteNode(root, ele);
            break;
        
        case 3:
            // preorder traversal
            cout << "\nPREORDER TRAVERSAL : ";
            preOrderTraversal(root);
            break;
        
        case 4:
            exit(1);
        
        default:
            break;
        }
    }
    return 0;
}