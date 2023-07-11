// C program to remove a loop from the linked list  
#include <stdio.h>  
#include <stdlib.h>  
  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;    
struct node* create_node(int value)  
{  
   // creating a temp variable of type node..   
   struct node *temp = (struct node*)malloc(sizeof(struct node));  
        temp->data = value;  
        temp->next = NULL;  
        return temp;  
   
          
}   
int detect_loop(struct node *ptr)  
{  
   struct node *fast;  
   struct node *slow; 
   fast = slow = ptr;  
   while (slow && fast && fast->next)  
   {  
       slow = slow->next;  
       fast = fast->next->next;  
      
    if(slow==fast)  
       {  
           removeloop(slow, head);   
           return 1;  
       }  
    }  
}  
  
void removeloop(struct node *slow, struct node *head)  
{  
    struct node *p1;  
    struct node *p2;  
    p1 = slow;  
    p2 = head;  
      
while(p1->next!=p2->next)  
    {  
        p1 = p1->next;  
        p2 = p2->next;  
    }  
    p1->next = NULL;  
      
}  
void display(struct node *temp)  
{  
   while (temp !=NULL)  
    {  
        printf("%d, ", temp->data);  
        temp = temp->next;  
    }  
}  
int main()  
{  
    head = create_node(50);  
    head->next = create_node(20);  
    head->next->next = create_node(15);  
    head->next->next->next = create_node(4);  
    head->next->next->next->next = create_node(10);  
   /* Create a loop for testing */  
    head->next->next->next->next->next = head->next->next;  
    detect_loop(head);  
    display(head);  
   return 0;  
} 