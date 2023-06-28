import java.util.Scanner;

/*
#Addition of two Numbers Linked-List Java #1317

  The code includes the necessary imports and defines a class named Main.
Within the Main class, a Scanner object is declared to take input from the user.
The class also defines a nested static class named ListNode, representing a node of the linked list. Each node has an integer value (val) and a reference to the next node (next).
The addTwoNumbers method is responsible for adding two numbers represented as linked lists. However, the logic for addition is not implemented and needs to be completed based on the requirements.
The printList method is used to print the values of the nodes in a linked list.
The makeList method is used to create a linked list with a given number of nodes. It takes input from the user and constructs the linked list accordingly.
In the main method, the user is prompted to enter the number of digits in the first and second linked lists. The makeList method is then called to create the respective linked lists based on the user input.
The addTwoNumbers method is called with the two linked lists as parameters to perform the addition.
Finally, the result is printed using the printList method.
Sample Input:
5
1 0 3 2 5
3
1 2 4
Sample Output:
1 0 3 5 8
 */
public class AdditionOfTwoNumbersinLL {
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int carry = 0;

        while (l1 != null || l2 != null) {
            int sum = carry;

            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }

            int digit = sum % 10;
            carry = sum / 10;

            current.next = new ListNode(digit);
            current = current.next;
        }

        if (carry > 0) {
            current.next = new ListNode(carry);
        }

        return reverseList(dummy.next);
    }

    public static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    public static ListNode makeList(int n) {
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the values of the nodes (separated by spaces): ");
        String[] input = scanner.nextLine().trim().split(" ");
        for (int i = 0; i < n; i++) {
            int val = Integer.parseInt(input[i]);
            prev.next = new ListNode(val);
            prev = prev.next;
        }

        return dummy.next;
    }

    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("Menu:");
            System.out.println("1. Add two numbers represented as linked lists");
            System.out.println("2. Exit");
            System.out.println("Enter your choice:");

            int choice = scanner.nextInt();
            System.out.println();

            switch (choice) {
                case 1:
                    System.out.print("Enter the number of digits in the first linked list: ");
                    int n1 = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character

                    ListNode head1 = makeList(n1);

                    System.out.print("Enter the number of digits in the second linked list: ");
                    int n2 = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character

                    ListNode head2 = makeList(n2);

                    ListNode result = addTwoNumbers(head1, head2);

                    System.out.print("Result: ");
                    printList(result);
                    System.out.println();
                    break;

                case 2:
                    exit = true;
                    break;

                default:
                    System.out.println("Invalid choice! Please try again.\n");
                    break;
            }
        }

        scanner.close();
    }
}
