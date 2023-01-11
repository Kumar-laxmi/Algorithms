import java.util.*;

/* Approach:
Using TreeSet in java to sort and store values of given Binary Tree and then iterating through that set to get the BST.
All traversal in the following code has been done inorder.
*/

class BinaryTreeToBST {
  // Class for defining structure of Nodes of Tree
  public class Node {
    int data;
    Node left, right;

    Node(int data) {
      this.data = data; // Initializing the current node data
      this.left = null; // Making left child null
      this.right = null; // Making right child null
    }
  }
  // Function to perform traversal of Tree (Inorder)
  public static void traverse(Node root) {
    if (root == null) {
      return;
    }

    traverse(root.left);
    System.out.print(root.data + " ");
    traverse(root.right);
  }

  // Function to traverse the binary tree and store its nodes' values in a set
  public static void nodeSet(Node root, Set < Integer > set) {
    // base case
    if (root == null) {
      return;
    }

    nodeSet(root.left, set);
    set.add(root.data);
    nodeSet(root.right, set);
  }

  // Function to put keys back into a set in their correct order in the BST
  public static void binaryToBST(Node root, Iterator < Integer > it) {
    if (root == null) {
      return;
    }

    binaryToBST(root.left, it);
    root.data = it.next();
    binaryToBST(root.right, it);
  }

  // Function to convert a binary tree to BST by maintaining its original structure

  public static void convertToBST(Node root) {
    // traverse the binary tree and store its nodes data in a set
    Set < Integer > set = new TreeSet < > ();
    nodeSet(root, set);

    // Iterating through the set using iterator and placing the nodes at their requires position in BST.
    Iterator < Integer > it = set.iterator();
    binaryToBST(root, it);
  }

  // Generate Tree
  public Node genTree() {
    Node root = new Node(9);
    root.left = new Node(4);
    root.right = new Node(5);
    root.left.left = new Node(15);
    root.left.right = new Node(1);
    root.right.left = new Node(3);
    root.right.right = new Node(7);

    return root;
  }

  public static void main(String[] args) {
    BinaryTreeToBST btobst = new BinaryTreeToBST();
    Node root = btobst.genTree();

    System.out.println("Given Binary Tree: ");
    traverse(root);
    System.out.print("\n\n");
    System.out.println("After converting to BST: ");
    convertToBST(root);
    traverse(root);
  }
}
