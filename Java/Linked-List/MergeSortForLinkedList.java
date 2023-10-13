import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class MergeSortForLinkedList {
    static Node mergeSortedLists(Node list1, Node list2) {
        Node ptr1 = list1;
        Node ptr2 = list2;
        Node dummyNode = new Node(-1);
        Node ptr3 = dummyNode;

        while (ptr1 != null && ptr2 != null) {
            if (ptr1.data > ptr2.data) {
                ptr3.next = ptr2;
                ptr2 = ptr2.next;
            } else {
                ptr3.next = ptr1;
                ptr1 = ptr1.next;
            }
            ptr3 = ptr3.next;
        }

        while (ptr1 != null) {
            ptr3.next = ptr1;
            ptr1 = ptr1.next;
            ptr3 = ptr3.next;
        }

        while (ptr2 != null) {
            ptr3.next = ptr2;
            ptr2 = ptr2.next;
            ptr3 = ptr3.next;
        }
        return dummyNode.next;
    }

    static void displayList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lenA, lenB;

        System.out.println("Enter the length of first linked list: ");
        lenA = sc.nextInt();

        System.out.println("Enter the length of second linked list: ");
        lenB = sc.nextInt();

        // First Linked List
        int data;
        System.out.println("Enter the data for head node of the first list: ");
        data = sc.nextInt();
        Node headA = new Node(data);
        Node tailA = headA;
        System.out.println("Enter data for the other nodes of the first list: ");
        for (int i = 1; i < lenA; i++) {
            data = sc.nextInt();
            tailA.next = new Node(data);
            tailA = tailA.next;
        }

        System.out.println("Enter the data for head node of the second list: ");
        data = sc.nextInt();
        Node headB = new Node(data);
        Node tailB = headB;
        System.out.println("Enter data for the other nodes of the second list: ");
        for (int i = 1; i < lenB; i++) {
            data = sc.nextInt();
            tailB.next = new Node(data);
            tailB = tailB.next;
        }
        Node head = mergeSortedLists(headA, headB);
        displayList(head);
    }
}