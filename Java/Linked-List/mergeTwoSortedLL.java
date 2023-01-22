<<<<<<< HEAD
import java.util.Scanner;

class MergeTwoSortedLL {
=======
class mergeTwoSortedLL {
>>>>>>> 323a1508ef9188dd9f95f5af77ba2c7dd708ae37
    // Link list node
    static class Node {
        int data;
        Node next;
    };

    // Function to create a new node
    static Node newNode(int key) {
        Node temp = new Node();
        temp.data = key;
        temp.next = null;
        return temp;
    }

    // Function to print the linked list
    static void printList(Node node) {
        while (node != null) {
            System.out.printf("%d ", node.data);
            node = node.next;
        }
    }

    // Function to merge two sorted linked lists
    static Node merge(Node h1, Node h2) {
        // Initialize dummy node
        Node dummy = newNode(0);
        Node current = dummy;

        // Iterate through both linked lists and add the
        // smaller value to the current node
        while (h1 != null && h2 != null) {
            if (h1.data < h2.data) {
                current.next = h1;
                h1 = h1.next;
            } else {
                current.next = h2;
                h2 = h2.next;
            }
            current = current.next;
        }

        // Add remaining elements from h1
        if (h1 != null) {
            current.next = h1;
        }

        // Add remaining elements from h2
        if (h2 != null) {
            current.next = h2;
        }

        return dummy.next;
    }

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);
        Node head1 = null;
        Node head2 = null;
        Node current = null;

        System.out.println("Enter values for first linked list (press -1 to stop):");
        while (true) {
            int input = scanner.nextInt();
            if (input == -1) {
                break;
            }
            Node newNode = newNode(input);
            if (head1 == null) {
                head1 = newNode;
                current = head1;
            } else {
                current.next = newNode;
                current = newNode;
            }
        }
        System.out.println("Enter values for first linked list (press -1 to stop):");
        while (true) {
            int input = scanner.nextInt();
            if (input == -1) {
                break;
            }
            Node newNode = newNode(input);
            if (head2 == null) {
                head2 = newNode;
                current = head2;
            } else {
                current.next = newNode;
                current = newNode;
            }
        }

        Node mergedhead = merge(head1, head2);

        printList(mergedhead);
    }
}
