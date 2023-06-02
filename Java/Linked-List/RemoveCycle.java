import java.util.Scanner;

class RemoveCycle{
    static Node head;
 
    static class Node {
 
        int data;
        Node next;
 
        Node(int d)
        {
            data = d;
            next = null;
        }
    }
 
    // Function that detects loop in the list
    int detectAndRemoveCycle(Node node)
    {
        Node slow = node, fast = node;
        while (slow != null && fast != null
               && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
 
            // If slow and fast meet at same point then loop
            // is present
            if (slow == fast) {
                removeCycle(slow, node);
                return 1;
            }
        }
        return 0;
    }
 
    // Function to remove loop
    void removeCycle(Node loop, Node head)
    {
        Node ptr1 = loop;
        Node ptr2 = loop;
 
        // Count the number of nodes in loop
        int k = 1, i;
        Node prevNode = ptr1;
        while (ptr1.next != ptr2) {
            // keeping track beforeing moving next
            prevNode = ptr1;
            ptr1 = ptr1.next;
            k++;
        }
        prevNode.next = null;
    }
 
    // Function to print the linked list
    void printList(Node node)
    {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }
 
    // Driver program to test above functions
    public static void main(String[] args)
    {
        RemoveCycle list = new RemoveCycle();
        list.head = new Node(50);
        list.head.next = new Node(20);
        list.head.next.next = new Node(15);
        list.head.next.next.next = new Node(4);
        list.head.next.next.next.next = new Node(10);
 
        // Creating a loop for testing
        head.next.next.next.next.next = head.next.next;
        list.detectAndRemoveCycle(head);
        System.out.println(
            "Linked List after removing loop : ");
        list.printList(head);
    }
}
