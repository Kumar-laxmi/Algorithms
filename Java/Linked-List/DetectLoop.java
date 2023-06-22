/*
Given a linked list, check if the linked list has loop(cycle) or not.

Example: Head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3
Output: True

Solution:
1. Traverse the list one by one and keep putting the node addresses in a Hash Table.
2. At any point, if NULL is reached then return false.
3. If next of current node points to any of the previously stored nodes in Hash then return true.
*/
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    //Linked List Node
    static class Node {
    int val;
    Node next;

    //constructor
    Node(int data) {
        val = data;
        next = null;
     }
    }
    //Display linked list
    static void display(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
        System.out.println();
    }

    //Function to detect loop in a linked list
    static boolean detectLoop(Node head) {
        Set<Node> hash = new HashSet<>();
        Node temp = head;
        while (temp != null) {
            //if node is already present in hash set
            if (hash.contains(temp)) {
                return true;
            }
            //insert node into hash set
            hash.add(temp);
            temp = temp.next;
        }
        return false;
    }

    public static void main(String[] args) {
        //Create an empty linked list
        Node head = null;
        Node tail = null;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();

        //Insert nodes in linked list
        System.out.print("Enter the nodes: ");
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        //Create a loop in linked list
        tail.next = head.next.next;

        if (detectLoop(head))
            System.out.println("Loop detected");
        else
            System.out.println("No loop detected");
    }
}
