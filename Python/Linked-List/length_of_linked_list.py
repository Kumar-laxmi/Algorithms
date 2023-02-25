"""
Algorithm:
    1. Initialize a counter variable to 0.
    2. Start at the head of the linked list.
    3. While the current node is not None:
     a. Increment the counter variable by 1.
     b. Set the current node to the next node in the list.
    4. Return the final value of the counter variable as the length of the linked list.
Input:
    An arbitraty number of inputs asking for the data in the nodes of the linked list.
    If nothing is entered in data value for the node, the code will give us output.
Output:
    Output is the number of nodes present in the created linked list.
"""

"""Define the Node class to represent a single node in the linked list"""
class Node:
    def __init__(self, data):
        self.data = data  # Set the data value in the node
        self.next = None  # Initialize the node's next pointer to None

"""Define the LinkedList class to represent the entire linked list"""
class LinkedList:
    def __init__(self):
        self.head = None  # Initialize the list's head pointer to None

    """Define a method to append a new node to the end of the list"""
    def append(self, data):
        new_node = Node(data)  # Create a new node with the given data value
        if self.head is None:  # If the list is empty, set the head pointer to the new node
            self.head = new_node
            return
        current_node = self.head  # Otherwise, traverse the list to find the last node
        while current_node.next:
            current_node = current_node.next
        current_node.next = new_node  # Set the last node's next pointer to the new node

    """Define a method to find the length of the list"""
    def length(self):
        count = 0  # Initialize a counter variable to 0
        current_node = self.head  # Start at the head of the list
        while current_node:  # Traverse the list until the end is reached
            count += 1  # Increment the counter for each node visited
            current_node = current_node.next
        return count  # Return the final value of the counter

"""Create a new linked list and take input from the user to add nodes to it"""
my_list = LinkedList()

while True:
    data = input("Enter a data value to add to the list (or press enter to stop): ")
    if data == "":  # If the user presses enter without entering any data, stop adding nodes
        break
    my_list.append(int(data))  # Convert the user input to an integer and add it to the list

"""Find the length of the list and print the result"""
length = my_list.length()
print("The length of the list is:", length)
