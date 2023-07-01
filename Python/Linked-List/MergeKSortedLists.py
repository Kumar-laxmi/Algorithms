# =================================== Problem Statement ====================================
'''
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
'''
# ================================== Code with Python =======================================
import heapq

# Node class for the linked list
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Comparator class for the priority queue
class CompareNode:
    def __init__(self, node):
        self.node = node

    def __lt__(self, other):
        return self.node.val < other.node.val

# Function to merge two sorted linked lists iteratively
def mergeTwoLists(l1, l2):
    dummy = ListNode(0)
    tail = dummy

    while l1 and l2:
        if l1.val <= l2.val:
            tail.next = l1
            l1 = l1.next
        else:
            tail.next = l2
            l2 = l2.next
        tail = tail.next

    tail.next = l1 or l2
    return dummy.next

# Function to merge k sorted linked lists using divide and conquer
def mergeKListsDivideConquer(lists, left, right):
    if left == right:
        return lists[left]
    elif left < right:
        mid = left + (right - left) // 2
        l1 = mergeKListsDivideConquer(lists, left, mid)
        l2 = mergeKListsDivideConquer(lists, mid + 1, right)
        return mergeTwoLists(l1, l2)
    else:
        return None

# Function to merge k sorted linked lists using priority queue
def mergeKListsPriorityQueue(lists):
    pq = []
    heapq.heapify(pq)

    # Push the heads of all lists into the priority queue
    for lst in lists:
        if lst:
            heapq.heappush(pq, CompareNode(lst))

    dummy = ListNode(0)
    tail = dummy

    # Start merging the lists
    while pq:
        node = heapq.heappop(pq).node

        tail.next = node
        tail = tail.next

        if node.next:
            heapq.heappush(pq, CompareNode(node.next))

    return dummy.next

# Function to merge k sorted linked lists using iterative merging
def mergeKListsIterative(lists):
    if not lists:
        return None

    interval = 1
    while interval < len(lists):
        for i in range(0, len(lists) - interval, interval * 2):
            lists[i] = mergeTwoLists(lists[i], lists[i + interval])
        interval *= 2

    return lists[0]

# Function to print a linked list
def printList(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

# Create example linked lists for divide and conquer
list1 = ListNode(1)
list1.next = ListNode(4)
list1.next.next = ListNode(5)

list2 = ListNode(1)
list2.next = ListNode(3)
list2.next.next = ListNode(4)

list3 = ListNode(2)
list3.next = ListNode(6)

lists1 = [list1, list2, list3]

# Merge using divide and conquer
mergedListDC = mergeKListsDivideConquer(lists1, 0, len(lists1) - 1)
print("Merged list (Divide and Conquer): ", end="")
printList(mergedListDC)

# Create example linked lists for priority queue
list4 = ListNode(2)
list4.next = ListNode(5)
list4.next.next = ListNode(6)

list5 = ListNode(1)
list5.next = ListNode(2)
list5.next.next = ListNode(9)

list6 = ListNode(3)
list6.next = ListNode(4)

lists2 = [list4, list5, list6]

# Merge using priority queue
mergedListPQ = mergeKListsPriorityQueue(lists2)
print("Merged list (Priority Queue): ", end="")
printList(mergedListPQ)

# Create example linked lists for iterative merging
list7 = ListNode(7)
list7.next = ListNode(9)
list7.next.next = ListNode(10)

list8 = ListNode(2)
list8.next = ListNode(5)
list8.next.next = ListNode(7)

list9 = ListNode(3)
list9.next = ListNode(5)

lists3 = [list7, list8, list9]

# Merge using iterative merging
mergedListIterative = mergeKListsIterative(lists3)
print("Merged list (Iterative Merging): ", end="")
printList(mergedListIterative)

# Clean up memory
list1 = None
list2 = None
list3 = None
list4 = None
list5 = None
list6 = None
list7 = None
list8 = None
list9 = None