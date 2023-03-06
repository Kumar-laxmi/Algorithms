/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms*/
import java.util.Scanner;
// Node class
class Node 
{
    int data;
    Node next;
}
// Main class
public class linklist_length 
{
    // Function to find the length of a singly linked list
    public static int findLength(Node head) 
    {
        int count = 0;
        Node current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }
    public static void main(String[] args) 
    {
        // Creating an empty linked list
        Node head = null;
        // Reading input from the user to create the linked list
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of nodes in the linked list: ");
        int n = input.nextInt();
        if (n > 0) 
        {
            System.out.print("Enter the data for each node: ");
            Node prev = null;
            for (int i = 0; i < n; i++) {
                Node current = new Node();
                current.data = input.nextInt();
                current.next = null;
                if (prev == null) {
                    head = current;
                } else {
                    prev.next = current;
                }
                prev = current;
            }
        }
        // Finding the length of the linked list
        int length = findLength(head);
        // Printing the length of the linked list
        System.out.println("Length of the linked list is: " + length);
    }
}