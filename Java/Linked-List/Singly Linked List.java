/* Name : Abhinav kumar
Github username : Abhinavcode13
Repository name : Algorithms
Problem : Singly Linked List
Issue Number : #7
Problem Description :

A singly linked list is a linear data structure in which each element in the list is called a "node".
Each node contains two fields: a data field that stores the element, and a next field that contains the memory address of the next node in the list

Node 1      Node 2      Node 3     Node 4
+------+   +------+    +------+    +------+
|  10  |   |  25  |    |  32  |    |  17  |
+------+   +------+    +------+    +------+
| Next |-->| Next |--> | Next |--> | NULL |
+------+   +------+    +------+    +------+

In this example, the list has four nodes, each containing an integer value. The Next field of each node contains the memory address of the next node in the list.
The last node has a NULL value in its Next field, indicating the end of the list.

Traversing a Singly linked list:
To traverse a singly linked list, you start at the head node (the first node in the list) and follow the Next pointers until you reach the end of the list.
This allows you to access each element in the list in order.
*/

-------------------------------------------------------------------------//Java code begins here---------------------------------------------------------------------------------

//INSERTION IN SINGLY LINKED LIST USING JAVA  
  
import java.util.Scanner;

//Creating a node class that represents the node in the linked list
class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

//LinkedList class that represents the linked list
class LinkedList {
    Node head;

    public LinkedList() {
        this.head = null;
    }

 //To insert a node at the beginning of the list
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
//To insert a node at a specific position in the list
    public void insertAtPosition(int data, int position) {
        Node newNode = new Node(data);
        if (position == 1) {
            newNode.next = head;
            head = newNode;
            return;
        }
        Node current = head;
        for (int i = 1; i < position-1; i++) {
            current = current.next;
        }
        newNode.next = current.next;
        current.next = newNode;
    }
//To insert a node at the end of the list
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

//Traversing the data of linked list to print the all data.
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int choice, data, position;

        do {
            System.out.println("Choose an operation:");
            System.out.println("1. Insert at beginning");
            System.out.println("2. Insert at position");
            System.out.println("3. Insert at end");
            System.out.println("4. Print list");
            System.out.println("5. Exit");
            choice = sc.nextInt();

            switch(choice) {
                case 1:
                    System.out.println("Enter data:");
                    data = sc.nextInt();
                    list.insertAtBeginning(data);
                    break;

                case 2:
                    System.out.println("Enter data:");
                    data = sc.nextInt();
                    System.out.println("Enter position:");
                    position = sc.nextInt();
                    list.insertAtPosition(data, position);
                    break;

                case 3:
                    System.out.println("Enter data:");
                    data = sc.nextInt();
                    list.insertAtEnd(data);
                    break;

                case 4:
                    System.out.println("List:");
                    list.printList();
                    break;

                case 5:
                    System.out.println("Exiting...");
                    break;
                

                default:
                    System.out.println("Invalid choice!");
            }
        } while(choice != 5);
    }
}


//DELETION IN SINGLY LINKED LIST USING JAVA  


import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public LinkedList() {
        this.head = null;
    }
//To delete a node at the begin of the list  
   public void deleteAtBeginning() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        head = head.next;
    }
//To delete a node at the specified position of the list
    public void deleteAtPosition(int position) {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        if (position == 1) {
            head = head.next;
            return;
        }
        Node current = head;
        Node prev = null;
        for (int i = 1; i < position; i++) {
            prev = current;
            current = current.next;
            if (current == null) {
                System.out.println("Invalid position.");
                return;
            }
        }
        prev.next = current.next;
    }
//To delete a node at the end of the list
    public void deleteAtEnd() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        if (head.next == null) {
            head = null;
            return;
        }
        Node current = head;
        Node prev = null;
        while (current.next != null) {
            prev = current;
            current = current.next;
        }
        prev.next = null;
    }
