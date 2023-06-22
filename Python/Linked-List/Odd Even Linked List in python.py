'''Author: Abhay Saxena
Github username: YourFatherDumb
Topic: Odd Even Linked List in java and python'''


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def odd_even_linked_list(head):
    # Handle the edge case of an empty list or a list with only one node
    if not head or not head.next:
        return head

    # Initialize two dummy nodes for odd and even indices
    odd_dummy = ListNode(0)
    even_dummy = ListNode(0)

    # Keep track of the current nodes for odd and even indices
    odd_curr = odd_dummy
    even_curr = even_dummy

    # Variable to determine if the current node is odd or even
    is_odd = True

    # Traverse the linked list
    while head:
        if is_odd:
            odd_curr.next = head
            odd_curr = odd_curr.next
        else:
            even_curr.next = head
            even_curr = even_curr.next

        # Toggle the is_odd variable for the next iteration
        is_odd = not is_odd
        head = head.next

    # Connect the odd and even lists
    odd_curr.next = even_dummy.next
    even_curr.next = None

    # Return the reordered list
    return odd_dummy.next

# Function to create a linked list from a list of values
def create_linked_list(nums):
    dummy = ListNode(0)
    curr = dummy
    for num in nums:
        curr.next = ListNode(num)
        curr = curr.next
    return dummy.next

# Function to print the values of a linked list
def print_linked_list(head):
    curr = head
    while curr:
        print(curr.val, end=" ")
        curr = curr.next
    print()

# Get the input from the user
nums = input("Enter the values of the linked list (space-separated): ").split()
nums = [int(num) for num in nums]

# Create the linked list
head = create_linked_list(nums)

# Call the function to reorder the list
reordered_list = odd_even_linked_list(head)

# Print the reordered list
print("Reordered List:")
print_linked_list(reordered_list)
