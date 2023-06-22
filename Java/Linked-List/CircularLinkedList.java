import java.util.Scanner;

// Node class represents a node in the circular linked list
class Node {
    int data;       // Data value of the node
    Node next;      // Reference to the next node

    // Constructor to initialize the node
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

// Circular Linked List class
public class CircularLinkedList {
    Node head;      // Head node of the circular linked list

    // Method to insert a node at the end of the circular linked list

    // Insert nodes into the list:
    // a. Create a new node with the given data.
    // b. If the head is null, make the new node the head and set its next pointer to itself, forming a circular reference.
    // c. If the head is not null, traverse the list until the last node is reached (i.e., the node whose next pointer points to the head).
    // d. Set the next pointer of the last node to the new node.
    // e. Set the next pointer of the new node to the head, completing the circular reference.



    void insert(int data) {
        Node newNode = new Node(data);   // Create a new node

        // If the list is empty, set the head to the new node and make it point to itself
        if (head == null) {
            head = newNode;
            newNode.next = head;
        } else {
            Node currentNode = head;

            // Traverse to the last node
            while (currentNode.next != head) {
                currentNode = currentNode.next;
            }

            currentNode.next = newNode;   // Make the last node point to the new node
            newNode.next = head;          // Make the new node point to the head
        }
    }
    
    // Function to update the value of a node in the circular linked list
    void updateNode(int oldValue, int newValue) {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        
        Node curr = head.next;
        
        do {
            if (curr.data == oldValue) {
                curr.data = newValue;
                return;
            }
            curr = curr.next;
        } while (curr != head.next);
        
        System.out.println("Value not found in the list.");
    }
    

    // Method to delete a node from the circular linked list
    void delete(int data) {
        // If the list is empty, return
        if (head == null) {
            return;
        }

        // If the head node is to be deleted
        if (head.data == data) {
            // If the list has only one node
            if (head.next == head) {
                head = null;
            } else {
                Node lastNode = head;

                // Traverse to the last node
                while (lastNode.next != head) {
                    lastNode = lastNode.next;
                }

                head = head.next;           // Move the head to the next node
                lastNode.next = head;       // Make the last node point to the new head
            }
        } else {
            Node prevNode = null;
            Node currentNode = head;

            // Traverse to find the node to be deleted
            while (currentNode.next != head) {
                prevNode = currentNode;
                currentNode = currentNode.next;

                // If the node is found
                if (currentNode.data == data) {
                    prevNode.next = currentNode.next;   // Update the reference to bypass the node
                    break;
                }
            }
        }
    }

    // Method to print the circular linked list
    // Traverse the circular linked list:
    // a. Set a temporary node variable to the head.
    // b. Start a loop that continues until the temporary node variable becomes equal to the head again (indicating completion of a full traversal).
    // c. Within the loop, process the data of the current node.
    // d. Update the temporary node variable to its next pointer for the next iteration.
    void display() {
        // If the list is empty, return
        if (head == null) {
            return;
        }

        Node currentNode = head;

        // Traverse and print the data at each node
        do {
            System.out.print(currentNode.data + " ");
            currentNode = currentNode.next;
        } while (currentNode != head);
    }

    // Main method
    public static void main(String[] args) {
        CircularLinkedList circularList = new CircularLinkedList();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            circularList.insert(data);
        }

        // Print the circular linked list
        System.out.print("Circular Linked List: ");
        circularList.display();
        System.out.println();

        System.out.print("Enter the element to delete: ");
        int deleteData = scanner.nextInt();
        circularList.delete(deleteData);

        // Print the updated circular linked list
        System.out.print("Updated Circular Linked List: ");
        circularList.display();
        System.out.println();

        // Update circular linked list
        System.out.print("Enter the element to update: ");
        int oldValue = scanner.nextInt();
        System.out.print("Enter the new value: ");
        int newValue = scanner.nextInt();
        circularList.updateNode(oldValue , newValue);
        circularList.display();
    }
}