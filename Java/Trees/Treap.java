import java.util.Random;
import java.util.Scanner;

// Algorithm:
// 1. Start with an empty Treap.
// 2. For each element to be inserted:
//    a. Create a new node with the element and a random priority.
//    b. Split the Treap at the position where the new node should be inserted.
//    c. Merge the left split, new node, and right split to form the updated Treap.
// 3. To delete an element, find the node with the target element and remove it.
// 4. To search for an element, traverse the Treap and return the corresponding node if found.
// 5. Perform any other required operations like rotating, merging, or splitting as needed.

// Class for a node in the Treap
class Node {
    int key;           // Value of the node
    int priority;      // Priority of the node
    Node left;         // Reference to the left child
    Node right;        // Reference to the right child

    public Node(int key) {
        this.key = key;
        this.priority = new Random().nextInt();  // Assign a random priority
        this.left = null;
        this.right = null;
    }
}

// Java implementation of Treap data structure
public class Treap {
    private Node root;  // Root node of the Treap

    // Split the Treap based on the key. Left Treap will have nodes <= key and right Treap will have nodes > key.
    private void split(Node root, int key, Node[] left, Node[] right) {
        if (root == null) {
            left[0] = null;
            right[0] = null;
        } else if (root.key <= key) {
            split(root.right, key, left, right);
            root.right = left[0];
            left[0] = root;
        } else {
            split(root.left, key, left, right);
            root.left = right[0];
            right[0] = root;
        }
    }

    // Merge two Treaps into a single Treap.
    private Node merge(Node left, Node right) {
        if (left == null)
            return right;
        if (right == null)
            return left;

        if (left.priority > right.priority) {
            left.right = merge(left.right, right);
            return left;
        } else {
            right.left = merge(left, right.left);
            return right;
        }
    }

    // Insert a new node with a key into the Treap.
    private void insert(int key) {
        Node newNode = new Node(key);
        Node[] left = new Node[1];
        Node[] right = new Node[1];
        split(root, key, left, right);
        root = merge(merge(left[0], newNode), right[0]);
    }

    // Search for a key in the Treap.
    private Node search(Node root, int key) {
        if (root == null || root.key == key)
            return root;
        if (root.key < key)
            return search(root.right, key);
        return search(root.left, key);
    }

    // Delete a node with a key from the Treap.
    private Node erase(Node root, int key) {
        if (root == null)
            return root;

        if (root.key == key) {
            return merge(root.left, root.right);
        }

        if (key < root.key)
            root.left = erase(root.left, key);
        else
            root.right = erase(root.right, key);

        return root;
    }

    // Inorder traversal of the Treap
    private void inorder(Node root) {
        if (root == null)
            return;
        inorder(root.left);
        System.out.print(root.key + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Treap treap = new Treap();
        Scanner scanner = new Scanner(System.in);

        // User input to demonstrate Treap operations
        int choice;
        do {
            System.out.println("\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter key to insert: ");
                    int key = scanner.nextInt();
                    treap.insert(key);
                    System.out.println("Key " + key + " inserted.");
                    break;
                case 2:
                    System.out.print("Enter key to delete: ");
                    key = scanner.nextInt();
                    treap.root = treap.erase(treap.root, key);
                    System.out.println("Key " + key + " deleted.");
                    break;
                case 3:
                    System.out.print("Enter key to search: ");
                    key = scanner.nextInt();
                    Node result = treap.search(treap.root, key);
                    if (result != null)
                        System.out.println("Key " + key + " found.");
                    else
                        System.out.println("Key " + key + " not found.");
                    break;
                case 4:
                    System.out.print("Inorder Traversal: ");
                    treap.inorder(treap.root);
                    System.out.println();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        } while (choice != 5);

        // Deallocate memory
        // ...
    }
}
