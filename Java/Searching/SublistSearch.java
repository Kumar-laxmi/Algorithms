// Path: C\Searching\sublist_search.c
// C program to check whether the first list is present in 2nd list or not, when two linked lists are given.
// Time-Complexity: O(M*N), where M is the number of nodes in the second list and N in the first.
// Auxiliary-Space: O(1).  

import java.util.Scanner;

// Class representing a node in the linked list
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

// Class representing the linked list
class LinkedList {
    Node head;

    // Function to insert a node at the end of the linked list
    void insertAtEnd(int data) {
        Node newNode = new Node(data);

        // If the list is empty, make the new node the head
        if (head == null) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        // Insert the new node at the end
        temp.next = newNode;
    }

    // Function to display the linked list
    void displayList() {
        Node temp = head;
        if (temp == null)
            System.out.print("NULL");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // Returns true if first list is present in second list else false
    boolean isSublist(LinkedList list1, LinkedList list2) {
        // If both linked lists are empty, return true
        if (list1.head == null && list2.head == null)
            return true;

        // Else, if one is empty and the other is not, return false
        if (list1.head == null || (list1.head != null && list2.head == null))
            return false;

        // current1 is to traverse in list1 and current2 in list2
        Node current1 = list1.head;
        Node current2 = list2.head;

        // Traverse the second list by picking nodes one by one
        while (list2.head != null) {
            // Initialize current2 pointer with the current node of the second list
            current2 = list2.head;

            // Start matching the first list with the second list
            while (current1 != null) {
                // If the second list becomes empty and the first list does not, return false
                if (current2 == null)
                    return false;

                // If the data part is the same, go to the next nodes of both lists
                else if (current1.data == current2.data) {
                    current1 = current1.next;
                    current2 = current2.next;
                }

                // If they are not equal, break the loop
                else
                    break;
            }

            // Return true if the first list gets traversed completely, indicating it is
            // matched
            if (current1 == null)
                return true;

            // Initialize current1 pointer with first again
            current1 = list1.head;

            // Move to the next node of the second list
            list2.head = list2.head.next;
        }

        return false;
    }
}

// Main class
public class SublistSearch {
    public static void main(String[] args) {
        // Create the first linked list
        LinkedList list1 = new LinkedList();

        // Size of list1
        Scanner scanner = new Scanner(System.in);
        System.out.print("No of Nodes in the first list: ");
        int N = scanner.nextInt();

        for (int i = 0; i < N; i++) {
            System.out.print("data " + (i + 1) + ": ");
            int data = scanner.nextInt();

            list1.insertAtEnd(data);
        }
        System.out.println();

        // Create the second linked list
        LinkedList list2 = new LinkedList();

        // Size of list2
        System.out.print("No of Nodes in the second list: ");
        int M = scanner.nextInt();

        for (int i = 0; i < M; i++) {
            System.out.print("data " + (i + 1) + ": ");
            int data = scanner.nextInt();

            list2.insertAtEnd(data);
        }
        System.out.println();

        // Display the first linked list
        System.out.print("List 1: ");
        list1.displayList();

        // Display the second linked list
        System.out.print("List 2: ");
        list2.displayList();
        System.out.println();

        // Check if the first list is a sublist of the second list
        boolean result = list1.isSublist(list1, list2);
        System.out.print("Is the first list a sublist of the second list? ");

        if (result) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }

        scanner.close();
    }
}
