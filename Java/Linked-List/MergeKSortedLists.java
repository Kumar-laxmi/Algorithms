// =================================== Problem Statement ====================================
/*
 Task: Merge K sorted Linked List

 Sol: The problem to merge K sorted List can be done via folowing methods

    Method 1) Brute Force (Array Conversion and Sorting)

    Algorithm:
        1) Traverse each linked list and store the elements in an array.
        2) Merge all the arrays into one sorted array using any standard sorting algorithm.3) Create a new linked list and populate it with the elements from the sorted array in the correct order.

    Time Complexity: O(N log N) , Space Complexity: O(N) where N is the total number of elements across all the linked lists.

    Method 2) Using a Priority Queue (Min-Heap)

    Algorithm:
        1) Create a min-heap.
        2) Insert the first element from each linked list into the min-heap.
        3) Pop the minimum element from the min-heap (smallest among all current elements).4) Append the popped element to the final merged linked list.
        5) If there are more elements in the linked list from which the popped element came, insert the next element into the min-heap.
        6) Repeat steps 3-5 until the min-heap is empty.

    Time Complexity: O(N log k) ,Space Complexity: O(k) where N is the total number of elements across all the linked lists and k is the number of linked lists.

    Method 3) Divide and Conquer (Pairwise merging)

    Algorithm:
        1) Divide the k linked lists into two halves.
        2) Recursively merge the two halves using the same merging process.
        3) Repeat step 2 until there is only one merged linked list.

    Time Complexity: O(N log k), Space Complexity: O(log k) where N is the total number of elements across all the linked lists and k is the number of linked lists.

    Method 4) Iterative Merging

    Algorithm:
        1) Start with an empty merged linked list.
        2) Pick the first two linked lists and merge them using a helper function that merges two sorted lists.
        3) Append the merged list to the end of the list of remaining linked lists.
        4) Remove the first two linked lists from the list of remaining linked lists.
        5) Repeat steps 2-4 until there is only one merged linked list.

    Time Complexity: O(Nk), Space Complexity: O(1) where N is the total number of elements across all the linked lists and k is the number of linked lists.

    Conclusion:
        - If the number of linked lists (k) is relatively small or memory usage is a concern, the Priority Queue method (Min-Heap) is a suitable choice. It has a lower space complexity compared to the brute force method and provides efficient merging of elements.
        - If memory usage is a concern and the linked lists are already sorted, the Iterative Merging method can be considered. It has a constant space complexity and requires no additional data structures.
        - If the number of linked lists is large and memory usage is not a concern, the Divide and Conquer method provides an efficient solution. It has a similar time complexity to the Priority Queue method but may have a higher constant factor due to recursive calls.
        - The Brute Force method can be used if there are no constraints on memory usage and an existing sorting algorithm is readily available. It may be suitable for small inputs or situations where simplicity is preferred over optimization.

    Ultimately, the choice of algorithm depends on the specific requirements.
    We are going to implemet 3 Approaches below
*/
// =================================== Code with Java =======================================
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class MergeKSortedLists {
    // Node structure for the linked list
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    // Comparator class for the priority queue
    static class ListNodeComparator implements Comparator<ListNode> {
        public int compare(ListNode lhs, ListNode rhs) {
            return lhs.val - rhs.val;
        }
    }

     //Function to merge two sorted linked lists iteratively.
    private static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }

        tail.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }
    
     //Function to merge k sorted linked lists using divide and conquer.
    private static ListNode mergeKListsDivideConquer(List<ListNode> lists, int left, int right) {
        if (left == right) {
            return lists.get(left);
        } else if (left < right) {
            int mid = left + (right - left) / 2;
            ListNode l1 = mergeKListsDivideConquer(lists, left, mid);
            ListNode l2 = mergeKListsDivideConquer(lists, mid + 1, right);
            return mergeTwoLists(l1, l2);
        } else {
            return null;
        }
    }

     //Function to merge k sorted linked lists using a priority queue.
    private static ListNode mergeKListsPriorityQueue(List<ListNode> lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>(new ListNodeComparator());

        // Push the heads of all lists into the priority queue
        for (ListNode list : lists) {
            if (list != null) {
                pq.offer(list);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        // Start merging the lists
        while (!pq.isEmpty()) {
            ListNode node = pq.poll();

            tail.next = node;
            tail = tail.next;

            if (node.next != null) {
                pq.offer(node.next);
            }
        }

        return dummy.next;
    }

     //Function to merge k sorted linked lists using iterative merging.
    private static ListNode mergeKListsIterative(List<ListNode> lists) {
        if (lists.isEmpty()) {
            return null;
        }

        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval * 2) {
                lists.set(i, mergeTwoLists(lists.get(i), lists.get(i + interval)));
            }
            interval *= 2;
        }

        return lists.get(0);
    }

    //Function to print a linked list.
    private static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create example linked lists for divide and conquer
        ListNode list1 = new ListNode(1);
        list1.next = new ListNode(4);
        list1.next.next = new ListNode(5);

        ListNode list2 = new ListNode(1);
        list2.next = new ListNode(3);
        list2.next.next = new ListNode(4);

        ListNode list3 = new ListNode(2);
        list3.next = new ListNode(6);

        List<ListNode> lists1 = new ArrayList<>();
        lists1.add(list1);
        lists1.add(list2);
        lists1.add(list3);

        // Merge using divide and conquer
        ListNode mergedListDC = mergeKListsDivideConquer(lists1, 0, lists1.size() - 1);
        System.out.print("Merged list (Divide and Conquer): ");
        printList(mergedListDC);

        // Create example linked lists for priority queue
        ListNode list4 = new ListNode(2);
        list4.next = new ListNode(5);
        list4.next.next = new ListNode(6);

        ListNode list5 = new ListNode(1);
        list5.next = new ListNode(2);
        list5.next.next = new ListNode(9);

        ListNode list6 = new ListNode(3);
        list6.next = new ListNode(4);

        List<ListNode> lists2 = new ArrayList<>();
        lists2.add(list4);
        lists2.add(list5);
        lists2.add(list6);

        // Merge using priority queue
        ListNode mergedListPQ = mergeKListsPriorityQueue(lists2);
        System.out.print("Merged list (Priority Queue): ");
        printList(mergedListPQ);

        // Create example linked lists for iterative merging
        ListNode list7 = new ListNode(7);
        list7.next = new ListNode(9);
        list7.next.next = new ListNode(10);

        ListNode list8 = new ListNode(2);
        list8.next = new ListNode(5);
        list8.next.next = new ListNode(7);

        ListNode list9 = new ListNode(3);
        list9.next = new ListNode(5);

        List<ListNode> lists3 = new ArrayList<>();
        lists3.add(list7);
        lists3.add(list8);
        lists3.add(list9);

        // Merge using iterative merging
        ListNode mergedListIterative = mergeKListsIterative(lists3);
        System.out.print("Merged list (Iterative Merging): ");
        printList(mergedListIterative);
    }
}