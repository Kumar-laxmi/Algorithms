# Python program to detect and remove loop in linked list

class Node:

	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:

	def __init__(self):
		self.head = None

	def detectAndRemoveLoop(self):
		slow_p = fast_p = self.head
		
		while(slow_p and fast_p and fast_p.next):
			slow_p = slow_p.next
			fast_p = fast_p.next.next

			if slow_p == fast_p:
				self.removeLoop(slow_p)
		
				# Return 1 to indicate that loop is found
				return 1
		
		# Return 0 to indicate that there is no loop
		return 0

	def removeLoop(self, loop_node):
		ptr1 = loop_node
		ptr2 = loop_node
		
		k = 1
		while(ptr1.next != ptr2):
			ptr1 = ptr1.next
			k += 1

		
		ptr1 = self.head
		
		ptr2 = self.head
		for i in range(k):
			ptr2 = ptr2.next

		while(ptr2 != ptr1):
			ptr1 = ptr1.next
			ptr2 = ptr2.next

		while(ptr2.next != ptr1):
			ptr2 = ptr2.next

		ptr2.next = None

	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	def printList(self):
		temp = self.head
		while(temp):
			print(temp.data, end = ' ')
			temp = temp.next


# Driver program
llist = LinkedList()
llist.push(10)
llist.push(4)
llist.push(15)
llist.push(20)
llist.push(50)

# Create a loop for testing
llist.head.next.next.next.next.next = llist.head.next.next

llist.detectAndRemoveLoop()

print("Linked List after removing loop")
llist.printList()

