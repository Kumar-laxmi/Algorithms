// =================================== Problem Statement ====================================
/*
 Task: Sorting Algorithm for Linked List

 Sol: The problem to sort the linked can be done via folowing methods

    Method 1)  One of the brute force solution is to convert the linked list into an array, sort the array using a standard sorting algorithm, and then rebuild the linked list using the sorted values. This approach may be simpler to implement but requires additional memory to store the array.
    Time Complexity - O(n logn) , Space Complexity - O(n)

    Method 2) Quick Sort can be applied to a linked list by selecting a pivot, partitioning the list into smaller and greater elements, and recursively sorting the partitions. The main challenge lies in rearranging the nodes during the partitioning step, as random access is not available. Despite this, Quick Sort remains an efficient sorting algorithm for linked lists with an average Time complexity of O(n log n) but in worst case O(n^2) and a Space complexity of O(log n).

    Method 3) Merge Sort can be applied to a linked list by recursively dividing it into smaller sublists, sorting each sublist individually, and then merging the sorted sublists back together. The merging process takes advantage of the sorted order of the sublists, resulting in a sorted linked list. Merge Sort is efficient for linked lists, with a time complexity of O(n log n) and a space complexity of O(log n) due to the recursive nature of the algorithm.

    Among the sorting algorithms suitable for linked lists, Merge Sort stands out as the most suitable choice. Merge Sort is a popularly known algorithm that follows the Divide and Conquer strategy. It can be implemented by recursively dividing the linked list, sorting each sublist, and merging them back together. However, even within Merge Sort, there are two approaches to consider:

    Approach 1) The recursive approach using top-down merging.

        - Recursively split the original list into two halves. The split continues until there is only one node in the linked list (Divide phase). To split the list into two halves, we find the middle of the linked list using the Fast and Slow pointer approach.

        - Recursively sort each sublist and combine it into a single sorted list (Merge Phase).

    Time Complexity: O(n logn) , Space Complexity: O(logn) for recursive stack space.

    Approach 2) The iterative approach using bottom-up merging.

        - Start with splitting the list into sublists of size 1.Each adjacent pair of sublists of size 1 is merged in sorted order. After the first iteration, we get the sorted lists of size 2.

        - A similar process is repeated for a sublist of size 2.In this way, we iteratively split the list into sublists of size 1, 2, 4, 8, and so on until we reach n.

        - To split the list into two sublists of given size beginning from start, we use two pointers: mid and end. Mid and end reference the start and end of the second linked list, respectively.

        - Merge the lists in sorted order as discussed in Approach 1.

        - As we iteratively split the list and merge, we have to keep track of the previous merged list using pointer tail and the next sublist to be sorted using pointer nextSubList.

    Time Complexity: O(n logn) , Space Complexity: O(1) only reference pointer.

    We are going to implemet both Approaches below
*/
// =================================== Code with Java =======================================


public class MergeSortLinkedList {
    private static class Node {
        int data;
        Node next;

        Node(int value) {
            data = value;
            next = null;
        }
    }
    // Function to merge two sorted linked lists
    private static Node merge(Node left, Node right) {
        if (left == null)
            return right;
        if (right == null)
            return left;

        Node result;
        if (left.data <= right.data) {
            result = left;
            result.next = merge(left.next, right);
        } else {
            result = right;
            result.next = merge(left, right.next);
        }

        return result;
    }

    // Function to split the linked list into two halves
    private static Node[] splitList(Node head) {
        Node slow = head;
        Node fast = head.next;
        Node[] halves = new Node[2];

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        halves[0] = head;
        halves[1] = slow.next;
        slow.next = null;

        return halves;
    }

    // Top-down merge sort on linked list
    private static Node mergeSortTopDown(Node head) {
        if (head == null || head.next == null)
            return head;

        Node[] halves = splitList(head);

        Node left = mergeSortTopDown(halves[0]);
        Node right = mergeSortTopDown(halves[1]);

        return merge(left, right);
    }

    // Bottom-up merge sort on linked list
    private static Node mergeSortBottomUp(Node head) {
        if (head == null || head.next == null)
            return head;

        int listSize = getListSize(head);
        Node dummy = new Node(0);
        dummy.next = head;

        for (int blockSize = 1; blockSize < listSize; blockSize *= 2) {
            Node current = dummy.next;
            Node tail = dummy;

            while (current != null) {
                Node left = current;
                Node right = split(current, blockSize);
                current = split(right, blockSize);

                Node merged = merge(left, right);
                tail.next = merged;

                while (tail.next != null)
                    tail = tail.next;
            }
        }

        return dummy.next;
    }

    // Function to split the linked list into two parts of given size
    private static Node split(Node head, int size) {
        if (head == null)
            return null;

        Node current = head;
        for (int i = 1; current.next != null && i < size; i++)
            current = current.next;

        Node remaining = current.next;
        current.next = null;
        return remaining;
    }

    // Function to get the size of the linked list
    private static int getListSize(Node head) {
        int size = 0;
        Node current = head;

        while (current != null) {
            size++;
            current = current.next;
        }

        return size;
    }

    // Function to insert a new node at the beginning of the linked list
    private static Node insertNode(Node head, int value) {
        Node newNode = new Node(value);
        newNode.next = head;
        return newNode;
    }

    // Function to print the linked list
    private static void printList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node headTopDown = null;
        Node headBottomUp = null;

        // Insert nodes into the linked list
        headTopDown = insertNode(headTopDown, 5);
        headTopDown = insertNode(headTopDown, 2);
        headTopDown = insertNode(headTopDown, 8);
        headTopDown = insertNode(headTopDown, 1);
        headTopDown = insertNode(headTopDown, 9);

        headBottomUp = insertNode(headBottomUp, 5);
        headBottomUp = insertNode(headBottomUp, 2);
        headBottomUp = insertNode(headBottomUp, 8);
        headBottomUp = insertNode(headBottomUp, 1);
        headBottomUp = insertNode(headBottomUp, 9);

        System.out.print("Original list: ");
        printList(headTopDown);

        // Merge sort using top-down approach
        headTopDown = mergeSortTopDown(headTopDown);
        System.out.print("Sorted list (Top-down): ");
        printList(headTopDown);

        // Merge sort using bottom-up approach
        headBottomUp = mergeSortBottomUp(headBottomUp);
        System.out.print("Sorted list (Bottom-up): ");
        printList(headBottomUp);
    }
}