Reversing a linked list using iterative approach

#include<stdio.h>

#include<stdlib.h>

//Node structure of the linked list

struct Node{
    
  int value;
    
  struct Node* next;

};


//Reverse the linked list function

void reverse(struct Node** head)

{
    
  struct Node* p=NULL;
    
  struct Node* c=*head;
    
  struct Node* next=NULL;
    
  while(c!=NULL){
     
   //stroring the next address of current node
    next=c->next;
     
    //reversing the current node's ponter
    c->next=p;
    
    //moving the pointer on position ahead
    p=c;
        
    c=next;
    
  }
    
  *head=p;

}

//To push a node in linked list

void push(struct Node** head, int val){

  struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

  newnode->value=val;

  newnode->next=(*head);

  *head=newnode;

}

//Printing function-to print the linked list

void show(struct Node* h){
    
  struct Node* t=h;
    
  while(t!=NULL){
        
    printf("%d ", t->value);
        
    t=t->next;
    
  }


}



int main()

{
//empty list
  struct Node* h = NULL;


  push(&h, 25);

  push(&h, 36);

  push(&h, 44);

  push(&h, 50);

  push(&h, 17);

  push(&h, 66);


  printf("Linked list before reversal:\n");

  show(h);

  reverse(&h);

  printf("\nLinked list after reversal:\n");

  show(h);

}

Time Complexity of reversing a linked list is O(n) 
