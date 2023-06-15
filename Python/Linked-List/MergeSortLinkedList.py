# =================================== Problem Statement ====================================
'''
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
'''
# =================================== Code with Python ======================================

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to merge two sorted linked lists
def merge(left, right):
    if left is None:
        return right
    if right is None:
        return left

    result = None
    if left.data <= right.data:
        result = left
        result.next = merge(left.next, right)
    else:
        result = right
        result.next = merge(left, right.next)

    return result

# Function to split the linked list into two halves
def split_list(head):
    slow = head
    fast = head

    # Move the fast pointer by two steps and the slow pointer by one step
    # When the fast pointer reaches the end, the slow pointer will be at the midpoint
    prev = None
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next

    # Disconnect the two halves by setting the next pointer of the previous node to None
    if prev:
        prev.next = None

    return slow

# Top-down merge sort on linked list
def merge_sort_top_down(head):
    # Base case: If the list is empty or contains only one element, it is already sorted
    if head is None or head.next is None:
        return head

    # Split the linked list into two halves
    mid = split_list(head)

    # Recursively sort the two halves
    left = merge_sort_top_down(head)
    right = merge_sort_top_down(mid)

    # Merge the sorted halves
    return merge(left, right)

# Bottom-up merge sort on linked list
def merge_sort_bottom_up(head):
    # Base case: If the list is empty or contains only one element, it is already sorted
    if head is None or head.next is None:
        return head

    # Function to merge two sorted linked lists
    def merge(left, right):
        dummy = Node(0)
        tail = dummy

        while left and right:
            if left.data <= right.data:
                tail.next = left
                left = left.next
            else:
                tail.next = right
                right = right.next
            tail = tail.next

        tail.next = left or right
        while tail.next:
            tail = tail.next

        return dummy.next

    # Function to split the linked list into sublists of size k
    def split_list(head, k):
        i = 1
        while i < k and head:
            head = head.next
            i += 1

        if head is None:
            return None

        temp = head.next
        head.next = None

        return temp

    # Get the length of the linked list
    def get_list_length(node):
        length = 0
        while node:
            length += 1
            node = node.next
        return length

    length = get_list_length(head)
    dummy = Node(0)
    dummy.next = head

    step = 1
    while step < length:
        current = dummy.next
        tail = dummy

        while current:
            left = current
            right = split_list(left, step)
            current = split_list(right, step)

            merged_head = merge(left, right)
            tail.next = merged_head

            while tail.next:
                tail = tail.next

        step *= 2

    return dummy.next

# Function to insert a node at the beginning of the linked list
def insert_node(head, data):
    new_node = Node(data)
    new_node.next = head
    return new_node

# Function to print the linked list
def print_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

# Test the merge sort implementation
head_top_down = None
head_bottom_up = None

# Insert nodes into the linked list
head_top_down = insert_node(head_top_down, 5)
head_top_down = insert_node(head_top_down, 2)
head_top_down = insert_node(head_top_down, 8)
head_top_down = insert_node(head_top_down, 1)
head_top_down = insert_node(head_top_down, 9)

head_bottom_up = insert_node(head_bottom_up, 5)
head_bottom_up = insert_node(head_bottom_up, 2)
head_bottom_up = insert_node(head_bottom_up, 8)
head_bottom_up = insert_node(head_bottom_up, 1)
head_bottom_up = insert_node(head_bottom_up, 9)

print("Original list:")
print_list(head_top_down)

# Merge sort using top-down approach
head_top_down = merge_sort_top_down(head_top_down)
print("Sorted list (Top-down):")
print_list(head_top_down)

# Merge sort using bottom-up approach
head_bottom_up = merge_sort_bottom_up(head_bottom_up)
print("Sorted list (Bottom-up):")
print_list(head_bottom_up)