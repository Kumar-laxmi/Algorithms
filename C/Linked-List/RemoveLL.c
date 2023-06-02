#include <stdio.h>  
#include <stdlib.h>  
// creating a structure of a node  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
// creating a node in a linked list..  
struct node* create_node(int value)  
{  
   // creating a temp variable of type node..   
   struct node *temp = (struct node*)malloc(sizeof(struct node));  
        temp->data = value;  
        temp->next = NULL;  
        return temp;  
   
          
}  
// detecting a node that creates a loop in the linked list..  
int detect_loop(struct node *ptr)  
{  
   struct node *fast; // declaration of fast pointer of type node..  
   struct node *slow; // declaration of slow pointer of type node..  
   fast = slow = ptr;  
   while (slow && fast && fast->next)  
   {  
       slow = slow->next;  
       fast = fast->next->next;  
    // checking whether slow is equal to fast or not.   
    if(slow==fast)  
       {  
           removeloop(slow, head); // calling removeloop() function.  
           return 1;  
       }  
    }  
}  
  
// Removing a loop from the linked list..  
void removeloop(struct node *slow, struct node *head)  
{  
    struct node *p1;  
    struct node *p2;  
    p1 = slow;  
    p2 = head;  
      
// while loop will execute till the p1.next is not equal to p2.next..  
while(p1->next!=p2->next)  
    {  
        p1 = p1->next;  
        p2 = p2->next;  
    }  
    p1->next = NULL;  
      
}  
// display the linked list..  
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
    head = create_node(12);  
    head->next = create_node(20);  
    head->next->next = create_node(35);  
    head->next->next->next = create_node(40);  
    head->next->next->next->next = create_node(15);  
   /* Create a loop for testing */  
    head->next->next->next->next->next = head->next->next;  
    detect_loop(head);  
    display(head);  
   return 0;  
}   