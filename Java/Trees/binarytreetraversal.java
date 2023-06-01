//Modified by : Anubha Sharma
//Github Username: AnubhaSharma2709

//The program is to implement Binary Tree Traversal

//The Approach that I followed is:

//1. The user can dynamically input the binary tree and perform the Traversal

//2. I have used node class for implemetation of the program

//3. I have used recursion in the program to perfom Traversal

//Code Implemetation
import java.util.Scanner;

// Node class for creating binary tree nodes
class Node {
    int data;
    Node left;
    Node right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
public class binarytreetraversal {
    // Function to build a binary tree from user input
    public static Node buildTree() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the data (-1 to exit): ");
        int data = scanner.nextInt();

        if (data == -1) {
            return null;
        }

        Node root = new Node(data);

        System.out.println("Enter the left subtree of " + data + ":");
        root.left = buildTree();

        System.out.println("Enter the right subtree of " + data + ":");
        root.right = buildTree();

        return root;
    }

    // 1. Inorder Traversal: Left Data Right
    public static void inorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    // 2. Preorder Traversal: Data Left Right
    public static void preorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.data + " ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }

    // 3. Postorder Traversal: left Right Data
    public static void postorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data + " ");
    }
    
    // main function
    public static void main(String[] args) {
        Node root = buildTree();

        System.out.println("Binary Tree Traversals:");

        System.out.print("Inorder Traversal: ");
        inorderTraversal(root);
        System.out.println();

        System.out.print("Preorder Traversal: ");
        preorderTraversal(root);
        System.out.println();

        System.out.print("Postorder Traversal: ");
        postorderTraversal(root);
        System.out.println();
    }
}
