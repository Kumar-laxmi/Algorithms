import java.io.*;
 
class GFG {
 
  /* A binary tree node has data, pointer to left child
        and a pointer to right child */
  static class node {
    int data;
    node left, right;
  }
 
  /* Helper function that allocates a new node with the
        given data and NULL left and right pointers. */
  static node newNode(int data)
  {
    node Node = new node();
    Node.data = data;
    Node.left = Node.right = null;
 
    return Node;
  }
 
  static int maxValue(node Node)
  {
    if (Node == null) {
      return Integer.MIN_VALUE;
    }
    int value = Node.data;
    int leftMax = maxValue(Node.left);
    int rightMax = maxValue(Node.right);
 
    return Math.max(value, Math.max(leftMax, rightMax));
  }
 
  static int minValue(node Node)
  {
    if (Node == null) {
      return Integer.MAX_VALUE;
    }
    int value = Node.data;
    int leftMax = minValue(Node.left);
    int rightMax = minValue(Node.right);
 
    return Math.min(value, Math.min(leftMax, rightMax));
  }
 
  /* Returns true if a binary tree is a binary search tree
     */
  static int isBST(node Node)
  {
    if (Node == null) {
      return 1;
    }
     
    /* false if the max of the left is > than us */
    if (Node.left != null
        && maxValue(Node.left) > Node.data) {
      return 0;
    }
     
    /* false if the min of the right is <= than us */
    if (Node.right != null
        && minValue(Node.right) < Node.data) {
      return 0;
    }
     
    /* false if, recursively, the left or right is not a
         * BST*/
    if (isBST(Node.left) != 1
        || isBST(Node.right) != 1) {
      return 0;
    }
     
    /* passing all that, it's a BST */
    return 1;
  }
 
  public static void main(String[] args)
  {
    node root = newNode(4);
    root.left = newNode(2);
    root.right = newNode(5);
     
    // root->right->left = newNode(7);
    root.left.left = newNode(1);
    root.left.right = newNode(3);
 
    // Function call
    if (isBST(root) == 1) {
      System.out.print("Is BST");
    }
    else {
      System.out.print("Not a BST");
    }
  }
}
