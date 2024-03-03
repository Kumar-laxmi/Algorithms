 import java.util.Scanner;


public class FlattenLinkedList {
// Node Class
static class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
// Printing Linked List
    static void printLinkedList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.bottom;
        }
    }

    static Node flattenLinkedList(Node root) {
            // Initialize the head pointers
        Node head1 = root;
        Node head2 = root.next;
        root = root.next;

        while (root != null) {
                    // Initialize head and tail for the new flattened list
            Node head = null;
            Node tail = null;

            // Merge the two sorted linked lists
            while (head1 != null && head2 != null) {
                if (head1.data < head2.data) {
                    Node newNode = new Node(head1.data);
                    if (head == null && tail == null) {
                        head = newNode;
                        tail = newNode;
                    } else {
                        tail.bottom = newNode;
                        tail = tail.bottom;
                    }
                    head1 = head1.bottom;
                } else {
                    Node newNode = new Node(head2.data);
                    if (head == null && tail == null) {
                        head = newNode;
                        tail = newNode;
                    } else {
                        tail.bottom = newNode;
                        tail = tail.bottom;
                    }
                    head2 = head2.bottom;
                }
            }

            // Append the remaining nodes of the linked lists
            while (head1 != null) {
                Node newNode = new Node(head1.data);
                if (head == null && tail == null) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail.bottom = newNode;
                    tail = tail.bottom;
                }
                head1 = head1.bottom;
            }

            while (head2 != null) {
                Node newNode = new Node(head2.data);
                if (head == null && tail == null) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail.bottom = newNode;
                    tail = tail.bottom;
                }
                head2 = head2.bottom;
            }

            // Move to the next level
            root = root.next;
            head1 = head;
            head2 = root;
        }

        return head1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter No of attempts: ");
        int t = sc.nextInt();

        while (t-- > 0) {
            int n, m, flag = 1, flag1 = 1;
            Node temp = null;
            Node head = null;
            Node pre = null;
            Node tempB = null;
            Node preB = null;

            System.out.print("Enter size of horizontal Linkedlist: ");
            n = sc.nextInt();
            int[] work = new int[n];
            System.out.println("Elements in Horizontal Linkedlist: ");
            for (int i = 0; i < n; i++) {
                work[i] = sc.nextInt();
            }

            // Create the horizontal linked list with bottom linked lists
            for (int i = 0; i < n; i++) {
                m = work[i];
                --m;
                int data;
                System.out.print("Enter Head For Bottom LinkedList: ");
                data = sc.nextInt();
                temp = new Node(data);
                temp.next = null;
                temp.bottom = null;

                if (flag == 1) {
                    head = temp;
                    pre = temp;
                    flag = 0;
                    flag1 = 1;
                } else {
                    pre.next = temp;
                    pre = temp;
                    flag1 = 1;
                }

                System.out.println("Enter Bottom Linkedlist Elements: ");
                for (int j = 0; j < m; j++) {
                    int temp_data;
                    temp_data = sc.nextInt();
                    tempB = new Node(temp_data);

                    if (flag1 == 1) {
                        temp.bottom = tempB;
                        preB = tempB;
                        flag1 = 0;
                    } else {
                        preB.bottom = tempB;
                        preB = tempB;
                    }
                }
            }

            Node root = flattenLinkedList(head);
            printLinkedList(root);
            System.out.println();
        }
    }
}
