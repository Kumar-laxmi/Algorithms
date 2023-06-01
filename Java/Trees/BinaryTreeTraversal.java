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
public class BinaryTreeTraversal {
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

    // Inorder traversal
    public static void inorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    // Preorder traversal
    public static void preorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.data + " ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }

    // Postorder traversal
    public static void postorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data + " ");
    }

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
