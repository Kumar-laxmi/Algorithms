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


//this program assumes there will be atleat one node in linked list
#include<stdio.h>
#include<stdlib.h>

// structure of LL
typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* head=NULL;

//to create and insert node of given value in LL
void insert(int val){
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		Node* ptr= head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
	
}

//to check LL is palindrome or not
void display(){
	Node* ptr=head;
	while(ptr!=NULL){
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

//to check LL is palindrome or not
int checkPalindrome() {
        Node* slow=head;
        Node* fast = head;

        //single node in LL
        if(head->next==NULL){
            return 1;
        }

        //slow will point to middle node
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        Node *curr = slow;
        Node* prev = NULL;
        Node* nxt = NULL;
       
        //reversing the second half of LL ex. 3->2->1->NULL will become  NULL<-3<-2<-1
        while(curr!=NULL){
            nxt = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;
        }
        
        //slow is pointing to starting node of 2nd half and fast is pointing to starting node of 1st half
        slow =prev;
        fast=head;

        //comparing slow->data with fast->data while slow does not reach to the middle
        while(slow!=NULL){
            if(slow->data!=fast->data){
                return 0;
            }
            slow= slow->next;
            fast=fast->next;
        }
        return 1;
    }


int main(){
	//creating a LL
	int n;
    printf("Enter no. of nodes in Linked List: ");
    scanf("%d", &n);
    int node;
    printf("Enter the value of each node:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &node);
        insert(node);
    }
    
    display();
    if(checkPalindrome()==1){
        printf("List is Palindrome");
    }
    else{
        printf("List is not Palindrome");
    }
	return 0;
}
