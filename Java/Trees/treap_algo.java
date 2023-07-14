
import java.util.Scanner;

class Node {
    int key;
    int priority;
    Node left, right;

    // Function to create a new node with the given key
// and a randomly generated priority value
    public Node(int key, int priority) {
        this.key = key;
        this.priority = priority;
        this.left = this.right = null;
    }
}

class treap_algo {
    Node root;

    // Function to perform a right rotation on the given root node
    private Node rightRotate(Node root) {
        Node newRoot = root.left;
        Node temp = newRoot.right;
        newRoot.right = root;
        root.left = temp;
        return newRoot;
    }
    // Function to perform a left rotation on the given root node
    private Node leftRotate(Node root) {
        Node newRoot = root.right;
        Node temp = newRoot.left;
        newRoot.left = root;
        root.right = temp;
        return newRoot;
    }

    // Function to insert a new node with the given key into the tree
    private Node insert(Node root, int key, int priority) {
        if (root == null)
            return new Node(key, priority);

        if (key < root.key) {
            root.left = insert(root.left, key, priority);
            if (root.left.priority > root.priority)
                root = rightRotate(root);
        } else {
            root.right = insert(root.right, key, priority);
            if (root.right.priority > root.priority)
                root = leftRotate(root);
        }
        return root;
    }
    // Function to delete the node with the given key from the tree

    private Node deleteNode(Node root, int key) {
        if (root == null)
            return root;

        if (key < root.key)
            root.left = deleteNode(root.left, key);
        else if (key > root.key)
            root.right = deleteNode(root.right, key);
        else {
            if (root.left == null) {
                Node temp = root.right;
                root = null;
                return temp;
            } else if (root.right == null) {
                Node temp = root.left;
                root = null;
                return temp;
            }

            if (root.left.priority > root.right.priority) {
                root = rightRotate(root);
                root.right = deleteNode(root.right, key);
            } else {
                root = leftRotate(root);
                root.left = deleteNode(root.left, key);
            }
        }
        return root;
    }
// Function to perform an inorder traversal of the tree
    private void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.println("Key: " + root.key + " Priority: " + root.priority);
            inorderTraversal(root.right);
        }
    }

    public void insert(int key, int priority) {
        root = insert(root, key, priority);
    }

    public void delete(int key) {
        root = deleteNode(root, key);
    }

    public void printInorder() {
        System.out.println("Inorder Traversal:");
        inorderTraversal(root);
    }

    public static void main(String[] args) {
       treap_algo treap = new treap_algo();
        int choice, key, priority;
        Scanner scanner = new Scanner(System.in);
        //Main loop to interact with the user and perform operations
        while (true) {
            System.out.println("1. Insert  2. Delete  3. Print Inorder  4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the key to insert: ");
                    key = scanner.nextInt();
                    System.out.print("Enter the priority: ");
                    priority = scanner.nextInt();
                    treap.insert(key, priority);
                    break;

                case 2:
                    System.out.print("Enter the key to delete: ");
                    key = scanner.nextInt();
                    treap.delete(key);
                    break;

                case 3:
                    treap.printInorder();
                    break;

                case 4:
                    scanner.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
            System.out.println();
        }
    }
}
