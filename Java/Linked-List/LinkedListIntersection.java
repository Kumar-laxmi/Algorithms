/*
-----------------------------Problem Statement-----------------------------
There are two singly linked lists and the end of one linked list
is connected to the second list.Find the point of intersection of
these two linked lists.

Example: List1: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
         List2: 8 -> 9 -> 5 -> 6 -> 7
Output: Intersection point is 5
*/
import java.util.HashSet;
import java.util.Scanner;

class LinkedListIntersection {
    static class Node {
        int val;
        Node next;

        Node(int data) {
            val = data;
            next = null;
        }
    }

    static Node insertAtTail(Node head, int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return head;
        }
        Node tail = head;
        while (tail.next != null) {
            tail = tail.next;
        }
        tail.next = newNode;
        return head;
    }

    static void display(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
        System.out.println();
    }

    static Node intersectionNode(Node headA, Node headB) {
        Node ptr1 = headA;
        Node ptr2 = headB;

        while (ptr1 != ptr2) {
            ptr1 = (ptr1 == null) ? headB : ptr1.next;
            ptr2 = (ptr2 == null) ? headA : ptr2.next;
        }

        return ptr1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Node head1 = null;
        Node head2 = null;

        System.out.print("Enter the number of nodes in linked list 1: ");
        int n1 = scanner.nextInt();
        System.out.println("Enter the nodes of linked list 1: ");
        for (int i = 0; i < n1; i++) {
            int data = scanner.nextInt();
            head1 = insertAtTail(head1, data);
        }

        System.out.print("Enter the number of nodes in linked list 2: ");
        int n2 = scanner.nextInt();
        System.out.println("Enter the nodes of linked list 2: ");
        for (int i = 0; i < n2; i++) {
            int data = scanner.nextInt();
            head2 = insertAtTail(head2, data);
        }

        int pos = (int) (Math.random() * n1) + 1;
        Node temp = head1;
        for (int i = 1; i < pos; i++) {
            temp = temp.next;
        }
        Node tail2 = head2;
        while (tail2.next != null) {
            tail2 = tail2.next;
        }
        tail2.next = temp;

        System.out.print("Linked list 1: ");
        display(head1);
        System.out.print("Linked list 2: ");
        display(head2);

        Node intersection = intersectionNode(head1, head2);
        if (intersection != null) {
            System.out.println("Intersection point is: " + intersection.val);
            System.out.println("Linked list after intersection: ");
            display(intersection);
        } else {
            System.out.println("No intersection point");
        }

        scanner.close();
    }
}
