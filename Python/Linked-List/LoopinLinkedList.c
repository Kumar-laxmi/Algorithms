/* Name : Abhinav kumar
Github username : Abhinavcode13
Repository name : Algorithms
Problem : Detect loop in a linked list 
Issue Number : #122
Language used : Python

//Algorithm

In this code, the Node class is defined to represent a linked list node. The detect_loop() function is defined to detect a loop in the linked list using Floyd's Cycle-Finding Algorithm.

The main() function takes user input for the number of elements in the linked list and for each node value, creates a new node for it, and connects it to the previous node using the next pointer. It then tests if there is a loop in the linked list using the detect_loop() function and prints the result to the console.

*/

-------------------------------------------------------------------------//Python code begins here---------------------------------------------------------------------------

# Define the structure of a linked list node
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to detect a direct loop in a linked list
def detect_loop(head):
    slow = head
    fast = head
    while slow and fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

# Main function to take user input for a linked list and test the loop detection
def main():
    head = None
    tail = None
    n = int(input("Enter the number of elements: "))
    for i in range(n):
        value = int(input("Enter the value for node {}: ".format(i+1)))
        new_node = Node(value)
        if head is None:
            head = tail = new_node
        else:
            tail.next = new_node
            tail = new_node
    if detect_loop(head):
        print("Loop Detected!")
    else:
        print("No Loop Detected.")

if __name__ == '__main__':
    main()
