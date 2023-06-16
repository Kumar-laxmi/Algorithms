import java.util.Scanner;

class Reverse_in_group_of_K {
    static class Node {
        int data;
        Node next;

        // Constructor to initialize value
        Node(int x) {
            data = x;
            next = null;
        }
    }
    static Node insert(Node head, int val) {
        Node temp = new Node(val);
        if (head == null) {
            temp.next = head;
            return temp;
        }

        Node curr = head;
        while (curr.next != null)
            curr = curr.next;

        curr.next = temp;
        temp.next = null;
        return head;
    }

    static Node reverse(Node head, int k) {
        Node curr = head;
        Node prevFirst = null;
        boolean isFirstPass = true;

        while (curr != null) {
            Node first = curr;
            Node prev = null;
            int count = 0;

            while (curr != null && count < k) {
                Node next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if (isFirstPass) {
                head = prev;
                isFirstPass = false;
            }
            else
                prevFirst.next = prev;
            prevFirst = first;
        }
        return head;
    }

    static void print(Node head) {
        Node curr = head;
        System.out.println("\n\n");
        while (curr != null) {
            System.out.print(curr.data + "->");
            curr = curr.next;
        }
        System.out.println("NULL\n\n");
    }

    public static void main(String[] args) {
        Node head = null;
        int n, val, k;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter n, k: ");
        n = scanner.nextInt();
        k = scanner.nextInt();
        System.out.println("Enter nodes: ");
        for (int i = 0; i < n; i++) {
            val = scanner.nextInt();
            head = insert(head, val);
        }
        print(head);
        head = reverse(head, k);
        print(head);
    }
}
