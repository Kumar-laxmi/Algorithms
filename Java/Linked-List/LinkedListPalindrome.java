/*
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

*/


//this program assumes there will be atleast one node in linked list

import java.util.*;

class LinkedListPalindrome
{
	Node head;

	// Linked list Node
	class Node
	{
		int data;
		Node next;
		Node(int d)
		{
			data = d;
			next = null;
		}
	}

	// Inserts a new Node at front
	// of the list.
	public void insert(int val){
		Node newnode = new Node(val);

		if(head==null){
		head=newnode;
	    }
	    else{
		    Node ptr= head;
		    while(ptr.next!=null){
			    ptr=ptr.next;
		    }
		    ptr.next=newnode;
	    }
		
	}


	public void display(){
		Node ptr = head;
		while (ptr != null){
			System.out.print(ptr.data + " ");
			ptr= ptr.next;
		}
        System.out.println();
	}
    
    //to check LL is palindrome or not
    public boolean checkPalindrome() {
        Node slow=head;
        Node fast = head;

        //single node in LL
        if(head.next==null){
            return true;
        }

        //slow will point to middle node
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast= fast.next.next;
        }
        Node curr = slow;
        Node prev = null;
        Node nxt = null;
       
        //reversing the second half of LL ex. 3->2->1->NULL will become  NULL<-3<-2<-1
        while(curr!=null){
            nxt = curr.next;
            curr.next=prev;
            prev = curr;
            curr = nxt;
        }
        
        //slow is pointing to starting node of 2nd half and fast is pointing to starting node of 1st half
        slow =prev;
        fast=head;

        //comparing slow->data with fast->data while slow does not reach to the middle
        while(slow!=null){
            if(slow.data!=fast.data){
                return false;
            }
            slow= slow.next;
            fast=fast.next;
        }
        return true;
    }
    
    
	// Driver code
	public static void main(String[] args)
	{
		// Start with the empty list
		LinkedList llist = new LinkedList();
        
        
        int n;
        System.out.print("Enter no. of nodes in Linked List: ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int node;
    
        for(int i=0; i<n; i++){
            node = sc.nextInt();
            llist.insert(node);
         }

	    llist.display();
		
		if(llist.checkPalindrome()){
	        System.out.println("List is palindrome");
	    }
	    else{
	        System.out.println("List is not palindrome");
	    }
	}
	
	
}

