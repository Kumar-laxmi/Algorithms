# Path: Python\Searching\sublist_search.c
# Python program to check whether the first list is present in 2nd list or not, when two linked lists are given.
# Time-Complexity: O(M*N), where M is the number of nodes in the second list and N in the first.
# Auxiliary-Space: O(1).


# Class representing a node in the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Class representing the linked list


class SingleLinkedList:
    def __init__(self):
        self.head = None

    # Function to insert a node at the end of the linked list
    def insertAtEnd(self, data):
        newNode = Node(data)

        # If the list is empty, make the new node the head
        if self.head is None:
            self.head = newNode
            return

        # Traverse to the last node
        temp = self.head
        while temp.next:
            temp = temp.next

        # Insert the new node at the end
        temp.next = newNode

    # Function to display the linked list
    def displayList(self):
        temp = self.head
        if temp is None:
            print("NULL", end="")
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

    # Returns true if first list is present in second list else false
    def isSublist(self, list1, list2):
        # If list1 and list2 are null (Empty), list1 is sublist of list2
        if list1.head is None and list2.head is None:
            return True

        # Else, if list1 is null and list2 is not, return false
        if list1.head is None or (list1.head is not None and list2.head is None):
            return False

        # current1 is to traverse in list1 and current2 in list2
        current1 = list1.head
        current2 = list2.head

        # Traverse the second list by picking nodes one by one
        while list2.head:
            # Initialize current2 pointer with the current node of the second list
            current2 = list2.head

            # Start matching the first list with the second list
            while current1:
                # If the second list becomes empty and the first list does not, return false
                if current2 is None:
                    return False

                # If the data part is the same, go to the next nodes of both lists
                elif current1.data == current2.data:
                    current1 = current1.next
                    current2 = current2.next

                # If they are not equal, break the loop
                else:
                    break

            # Returns True, If list1 is traversed completely (till the end)
            # Indicating that list1 is found
            if current1 is None:
                return True

            # Initialize current1 pointer with first again
            current1 = list1.head

            # Move to the next node of the second list
            list2.head = list2.head.next

        return False

# Program starts here 
# Create the first linked list
list1 = SingleLinkedList()

# Size of list1
N = int(input("No of Nodes in the first list: "))

for i in range(N):
    data = int(input("data {}: ".format(i + 1)))

    list1.insertAtEnd(data)
print()

# Create the second linked list
list2 = SingleLinkedList()

# Size of list2
M = int(input("No of Nodes in the second list: "))

for i in range(M):
    data = int(input("data {}: ".format(i + 1)))

    list2.insertAtEnd(data)
print()

# Display the first linked list
print("List 1: ", end="")
list1.displayList()

# Display the second linked list
print("List 2: ", end="")
list2.displayList()
print()

# Check if the first list is a sublist of the second list
result = list1.isSublist(list1, list2)
print("Is the first list a sublist of the second list? ", end="")

if result:
    print("True")
else:
    print("False")
