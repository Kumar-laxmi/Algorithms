import java.util.*;

//We keep track of the head node in circular singly linked list  

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;                       //Assigns data to data variable of the node
        this.next = null;                       //Makes the next pointer of that node as NULL
    }
}

public class CircularSinglyLinkedList {
    Node head;

    public CircularSinglyLinkedList() {
        head = null;                            //To initialize the linked list head node
    }

    // Insert at the front of the list
    public void insertFront(int data) {
        Node newNode = new Node(data);
        if (head == null) {                     //if list is empty, insert as first node(as for only one node, first and last node are the same)
            head = newNode;
            head.next = head;                   //connecting the next pointer of the node to itself as it is a circular linked list
        } else {
            newNode.next = head;
            Node current = head;
            while (current.next != head) {
                current = current.next;
            }
            current.next = newNode;               //making the node as first node
            head = newNode;                        //pointing the head node to the new node
        }
    }

    // Insert at the end of the list
    public void insertRear(int data) {
        Node newNode = new Node(data);
        if (head == null) {                         //if list is empty, insert as first node(as for only one node, first and last node are the same)
            head = newNode;
            head.next = head;                       //connecting the next pointer of the node to itself as it is a circular linked list
        } else {
            Node current = head;
            while (current.next != head) {          //traversing till the last node
                current = current.next;
            }
            current.next = newNode;                 //to make it as the last node, storing the address of the first node in the next address
            newNode.next = head;                    //pointing the head node to the next of new node
        }
    }

    // Insert at a given position in the list
    public void insertAtPos(int data, int position) {
        Node newNode = new Node(data);
        if (head == null) {                         //if list is empty, insert as first node(as for only one node, first and last node are the same)
            head = newNode;
            head.next = head;                       //connecting the next pointer of the node to itself as it is a circular linked list
        } else if (position == 1) {                 //if position is 1 then insert as first node
            newNode.next = head;
            Node current = head;
            while (current.next != head) {
                current = current.next;
            }
            current.next = newNode;
            head = newNode;
        } else {
            Node current = head;
            int i = 1;
            while (i < position - 1 && current.next != head) {  //finding the node address where newnode is going to be added
                current = current.next;
                i++;
            }
            newNode.next = current.next;                        //inserting the newnode after prev pointer
            current.next = newNode;
        }
    }

    // Delete at the front of the list
    public void deleteFront() {
        if (head == null) {                                                 //List empty condition
            return;
        } else if (head.next == head) {                              //If there is only one node, then the next pointer of the node will point to itself
            head = null;
        } else {
            Node current = head;
            while (current.next != head) {
                current = current.next;
            }
            current.next = head.next;
            head = head.next;
        }
    }

    // Delete at the end of the list
    public void deleteRear() {
        if (head == null) {                                         //List empty condition
            return;
        } else if (head.next == head) {                              //If there is only one node, then the next pointer of the node will point to itself
            head = null;
        } else {
            Node current = head;
            while (current.next.next != head) {
                current = current.next;
            }
            current.next = head;
        }
    }

    // Method to display the contents of the list
    public void display() {
        if (head == null) {                                                         //List empty condition
            System.out.println("List is empty!");
            return;
        }
        Node current = head;
        do {                                                                            //traverses all the nodes of the linked list.
            System.out.print(current.data + " ");                                       //prints the data of the nodes
            current = current.next;
        } while (current != head);
        System.out.println();
    }

 //Menu based operation
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        CircularSinglyLinkedList sll = new CircularSinglyLinkedList();
        int c=1;
		while(c!=0)
		{
		System.out.println("Enter your choice:");
		System.out.println("1: insert at rear");
		System.out.println("2: insert at front");
		System.out.println("3: insert at position");
		System.out.println("4: delete from first");
		System.out.println("5: delete from rear");
		System.out.println("7: Display");
		System.out.println("8: Exit");
		int ch=sc.nextInt();
		switch(ch)
		{
			case 1:
			{
				System.out.println("Enter the data to be entered");
				int a=sc.nextInt();
				sll.insertRear(a);
				break;
			}

			case 2:
			{
				System.out.println("Enter the data to be entered");
				int a=sc.nextInt();
				sll.insertFront(a);
				break;
			}

			case 3:
			{
				System.out.println("Enter the data to be entered");
				int a=sc.nextInt();
				System.out.println("Enter the position");
				int pos=sc.nextInt();
				sll.insertAtPos(a,pos);
				break;
			}

			case 4:
			{
				sll.deleteFront();
				break;
			}

			case 5:
			{
				sll.deleteRear();
				break;
			}
			case 7:
			{
				sll.display();
				break;
			}
			case 8:
			{
				c=0;
				break;
			}
		}
	}
        sc.close();
    }
}
