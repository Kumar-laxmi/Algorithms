#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
# Function to find the length of a singly linked list
def find_length(head):
    count = 0
    current = head
    while current != None:
        count += 1
        current = current.next
    return count
# Creating an empty linked list
head = None
# Reading input from the user to create the linked list
n = int(input("Enter the number of nodes in the linked list: "))
if n > 0:
    prev = None
    for i in range(n):
        data = int(input("Enter the data for node " + str(i+1) + ": "))
        current = Node(data)
        if prev == None:
            head = current
        else:
            prev.next = current
        prev = current
# Finding the length of the linked list
length = find_length(head)
# Printing the length of the linked list
print("Length of the linked list is:", length)