Reversing a linked list using iterative approach
#node of singly linked list

class Node:
    
    #constructor used to initialize the node object
    
    def __init__(self, value):
        
        self.value = value
        
        self.next = None


class l_list:

    #head initialization
    
    def __init__(self):
        
        self.head = None
        
        self.l_node = None

# inserting a new node at the beginning
    
  def append(self,value):
        
      if self.l_node is None:
            
          self.head = Node(value)
            
          self.l_node = self.head
        
      else:
            
          self.l_node.next = Node(value)
            
          self.l_node = self.l_node.next

      #function to print the linkedlist
    
    def show(self):
        
        c=self.head
        
        while c:
            
            print(c.value, end=' ')
            
            c=c.next

#function to reverse the linked list

def reverse(linked_list):
    
    prev = None
    
    c = linked_list.head
    
    if c is None:
        
        return
    
    after = c.next
    
    while after:
        
        c.next = prev
        
        prev = c
        
        c = after
        
        after = after.next
    
    c.next = prev
    
    linked_list.head = c

#driver code

linked_list = l_list()

a=int(input("Enter number of elements of linked list: "))

print("Enter data of linked list one at a time: ")

for i in range(a):
    
    value=int(input())
    
    linked_list.append(value)


reverse(linked_list)

print("The reversed linked list is: ")

linked_list.show()

Time Complexity of reversing a linked list is O(n)  
