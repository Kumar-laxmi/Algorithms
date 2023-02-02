"""
    Problem Statement
Given a singly linked list, we have to check whether it is palindrome or not.
Linked lists  is palindrome if it has the same order of elements when traversed forwards and backward​.
For example- 1->2->2->1 is palindrome while 1->2->3 is not palindrome

    Algorithm:-
    1. First find the middle of the linked list using Floyd's Cycle Detection Algorithm.
       In this, we travel through the linked list with two pointers, fast pointer is moving twice as fast as the 
       slow pointer. When the fast pointer reaches the end of the list, the slow pointer must then be in the middle.
    2.With slow now at the middle, we can reverse the second half of the list.
      Follow the steps to reverse the second half-

    Initialize three pointers prev as NULL, curr as slow, and next as NULL.
    Iterate through the linked list. In a loop, do the following:
    Before changing the next of curr, store the next node 
        next = curr -> next
    Now update the next pointer of curr to the prev 
        curr -> next = prev 
    Update prev as curr and curr as next 
        prev = curr 
        curr = next 

    3.Now, set fast to head of linked list and slow to prev(end of linked list) and compare fast->data with slow->data until slow!=NULL.

"""

#LL structure
class Node:
    def __init__(self,val):
        self.data = val
        self.next = None

class Linkedlist:
    def __init__(self):
        self.head =None
    
    #insert node in LL
    def insert(self, val):
        newnode = Node(val)
        
        if self.head is None:
            self.head = newnode
        else:
            ptr =self.head
            while ptr.next!=None:
                ptr=ptr.next
            ptr.next = newnode
    
    #display LL
    def display(self):
        ptr = self.head
        while ptr!=None:
            print(ptr.data, end="->")
            ptr = ptr.next
        print()
    
    def checkPalindrome(self):
        slow =self.head
        fast = self.head
        
        if self.head.next is None:
            return True
        while(fast!=None and fast.next!=None):
            slow=slow.next
            fast=fast.next.next
        
        curr=slow
        nxt=None
        pre=None
        
        while curr!=None:
            nxt=curr.next
            curr.next=pre
            pre=curr
            curr=nxt
        
        slow=pre
        fast=self.head
        
        while slow!=None:
            if slow.data!=fast.data:
                return False
            slow=slow.next
            fast=fast.next
        
        return True
        
        
        
        
        
ll = Linkedlist()
print("Enter no. of nodes in linked list")
n = int(input())
lst=[]
print("Enter value of each node")

lst = list(map(int, input().split()))

for i in range(n):
    ll.insert(lst[i])
        
ll.display()

if ll.checkPalindrome():
    print("List is Palindrome")
else:
    print("List is not Palindrome")