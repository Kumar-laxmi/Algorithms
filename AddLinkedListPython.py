'''
     Addition of 2 Linked List in Python.

    * Problem:-
    * Given two non-empty linked lists representing two non-negative integers.
    * The digits are stored in reverse order, and each of their nodes contains a
    * single digit.
    * Add the two numbers and return the sum as a linked list.The two numbers do
    * not contain any leading zero, except the number 0 itself.
    * 
    * Problem Link :- https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
    * Time complexity
    * O(n+m)-> Where, n is length of l1 and m is length of l2. Thus, it is equal to
    * max of n and m
    * 
    * Space complexity
    * O(n)--> In creating another linked list where answer is stored
    * 
    * Ex:-
    * Input: l1 = [2,4,3], l2 = [5,6,4]
    * Output: [7,0,8]
    * Explanation: 342 + 465 = 807.

'''
class Solution:
    #Function to add two numbers represented by linked list.
    def addTwoLists(self, first, second):
        def reverse(head):
            prev =None
            while(head):
                next = head.next
                head.next = prev
                prev = head
                head = next    
            return prev
            
        first = reverse(first)
        second = reverse(second)
        new = Node(0)
        dummy = new
        carry = 0
        while(first!=None and second!=None):
            sum = first.data + second.data+ carry
            carry = sum//10
            dummy.next = Node(sum%10)
            dummy = dummy.next
            first = first.next
            second = second.next
            
        while(first):
            s = first.data + carry
            carry = s//10
            dummy.next = Node(s%10)
            dummy=dummy.next
            first = first.next
            
        while(second):
            s = second.data + carry
            carry = s//10   
            dummy.next = Node(s%10)
            dummy=dummy.next
            second = second.next
            
        if carry==1:
            dummy.next =Node(1)
            
        return reverse(new.next)
# Node class 
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
# LInkedLIst Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # creates a new node with given value and appends it at the end of the linked list
    def insert(self,val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head 
        else:
            self.tai.next = Node(val)
            self.tail = self.tail.next 
# prints the elments of linked list starting with the head 
def printList(n):
    while n: 
        print(n.data,end=" ")
        n = n.next 
    print()

if __name__ == '__main__':
    for i in range(int(input())):
        n = int(input())
        arr1 = (int(x) for x in input().split())
        LL1 = LinkedList()
        for j in arr1:
            LL1.insert(j)
        m = int(input())
        arr2 = (int(x) for x in input().split())
        LL2 = LinkedList()
        for j in arr2:
            LL2.insert(i)
        res = Solution().addTwoLists(LL1.head,LL2.head)
        printList(res)
