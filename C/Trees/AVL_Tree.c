#include<stdio.h>

#include<stdlib.h>

// structure  avl tree Node
struct Node {
  int data, height;
  struct Node * left, * right;
};
// function to get maximum of two integers
int max(int num1, int num2) {
  return (num1 > num2) ? num1 : num2;
}
// height of tree
int height(struct Node * n) {
  return !n ? 0 : n -> height;
}

// Node creation method
struct Node * newNode(int ele) {
  struct Node * new = (struct Node * ) malloc(sizeof(struct Node));
  new -> data = ele;
  new -> left = new -> right = NULL;
  new -> height = 1;
  return (new);
}

struct Node * rightRotate(struct Node * n) {
  struct Node * p = n -> left, * p2 = p -> right;
  // rotation
  p -> right = n;
  n -> left = p2;

  // height updation
  n -> height = height(n -> left) > height(n -> right) ? height(n -> left) + 1 : height(n -> right) + 1;
  p -> height = height(p -> left) > height(p -> right) ? height(p -> left) + 1 : height(p -> right) + 1;
  return p;
}

struct Node * leftRotate(struct Node * n) {
  struct Node * p = n -> right, * p2 = p -> left;
  // rotation
  p -> left = n;
  n -> right = p2;

  // height updation
  n -> height = height(n -> left) > height(n -> right) ? height(n -> left) + 1 : height(n -> right) + 1;
  p -> height = height(p -> left) > height(p -> right) ? height(p -> left) + 1 : height(p -> right) + 1;
  return p;
}

int balFact(struct Node * n) {
  if(n==NULL){
    return 0;
  }
  return height(n -> left) - height(n -> right);
}

// insertion method
struct Node * insert(struct Node * n, int ele) {
  if (!n) return newNode(ele);
  if (ele < n -> data) n -> left = insert(n -> left, ele);
  else if (ele > n -> data) n -> right = insert(n -> right, ele);
  else return n;
  // height updation
  n -> height = height(n -> left) > height(n -> right) ? height(n -> left) + 1 : height(n -> right) + 1;
  int balance = balFact(n);

  // ll rotation
  if (balance > 1 && ele < n -> left -> data) return rightRotate(n);
  // rr rotation
  if (balance < -1 && ele > n -> right -> data) return leftRotate(n);
  // lr rotation
  if (balance > 1 && ele > n -> left -> data) {
    n -> left = leftRotate(n -> left);
    return rightRotate(n);
  }
  // rl rotation
  if (balance < -1 && ele < n -> right -> data) {
    n -> right = rightRotate(n -> right);
    return leftRotate(n);
  }

  return n;
}

struct Node * minValueNode(struct Node * n) {
  struct Node * p = n;
  while (p -> left) p = p -> left;
  return p;
}

// deletion method
struct Node * deleteNode(struct Node * n, int element) {
  if (!n)
  {return n;}
  // element in left subtree
  if (element < n -> data) {
    n->left = deleteNode(n -> left, element);
  }
  // element in right subtree
  else if (element > n -> data) {n -> right = deleteNode(n -> right, element);}
  // element = root Node
  else {
    // Node with no children || 1 child
    if (!n -> left || !n -> right) {
      struct Node * p = n -> left ? n -> left : n -> right;
      if (!p) {
        p = n;
        n = NULL;
      } // no child case
      else * n = * p;
      free(p);
    }
    // 2 children case
    else {
      struct Node * p = minValueNode(n -> right);
      n -> data = p -> data;
      n -> right = deleteNode(n -> right, p -> data);
    }
  }
  // only 1 Node case
  if (!n) return n;

  n -> height = max(height(n -> left), height(n -> right)) + 1;
  int balance = balFact(n);

  // ll rotation
  if (balance > 1 && balFact(n -> left) >= 0) return rightRotate(n);

  // lr rotation
  if (balance > 1 && balFact(n -> left) < 0) {
    n -> left = leftRotate(n -> left);
    return rightRotate(n);
  }

  // rr rotation
  if (balance < -1 && balFact(n -> right) <= 0) return leftRotate(n);

  // rl rotation
  if (balance < -1 && balFact(n -> right) > 0) {
    n -> right = rightRotate(n -> right);
    return leftRotate(n);
  }

  return n;
}

// traversal method
void preorderTraversal(struct Node * n) {
  if (n) {
    printf("%d ", n -> data);
    preorderTraversal(n -> left);
    preorderTraversal(n -> right);
  }
}

int main() {
  struct Node * root = NULL;
  int ch, element;
  while (1) {
    printf("\nChoose an operation :\n1. INSERTION\n2. DELETETION\n3. PREORDER TRAVERSAL\n4. Exit Program");
    printf("\nMAKE YOUR CHOICE : ");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      // insertion
      printf("\nEnter the element for insertion : ");
      scanf("%d", & element);
      root = insert(root, element);
      break;
    case 2:
      // deletion
      printf("\nEnter element for deletion : ");
      scanf("%d", & element);
      root = deleteNode(root, element);
      break;

    case 3:
      // preorder traversal
      printf("\nPREORDER TRAVERSAL : ");
      preorderTraversal(root);
      break;

    case 4:
      exit(1);

    default:
      break;
    }

  }
  return 0;
}
