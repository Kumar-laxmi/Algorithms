/* A circular linked list is a type of linked list in which the first and the last nodes are also connected to each other to form a circle. 
In this the address of the last node consists of the address of the first node.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{

    int data;
    struct node* next;
}*first=NULL;
//For Creation of Linked List
void create(int A[],int n)
{
  struct node* last=NULL;
  first=(struct node*)malloc(sizeof(struct node));
  first->data=A[0];
  first->next=NULL;
  last=first;
  first->next=first;//To form a circle
  for(int i=1;i<n;i++)//To add further nodes
  {
     struct node* temp=(struct node*)malloc(sizeof(struct node));
     temp->data=A[i];
     temp->next=NULL;
     last->next=temp;
     last=temp;
     last->next=first;

  }
}
//For Insertion Of Element in Linked List
void insert(int pos,int key)
{
    struct node* p=first;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
   if(pos==0)//If we want to insert node in the beginning
   {
       while(p->next!=first)
       {
           p=p->next;
       }
       p->next=temp;
     temp->next=first;
     first=temp;

   }
   else
   {

     for(int i=1;i<pos;i++)
     {
         p=p->next;
     }
     temp->next=p->next;
     p->next=temp;
   }
}
//For performing Deletion In Linked List
int deletei(int pos)
{
    struct node* p=first;
    struct node* q;
    if(pos==0)//If we want to delete the node from the beginning
    {
        while(p->next!=first)
        {
            p=p->next;
        }
        q=first;
        p->next=first->next;
        first=first->next;
        free(q);
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=p->next->next;
        free(q);
    }
}
//For printing the elements in Linked List
void display(struct node* p)
{
do
{
        printf("%d ",p->data);//for printing p's data
        p=p->next;//for moving p ahead

}while(p!=first);
}
int main()
{
    int A[]={2,3,4,5,6};

    create(A,5);//Calling create function
     printf("Displaying the Circular Linked List after Creation\n");
    display(first);
    insert(5,12);//calling insert function
     printf("\nDisplaying the Circular Linked List after Insertion at a particular position \n");
    display(first);
    deletei(4);//calling delete function
     printf("\nDisplaying the Circular Linked List after Deletion from a particular position \n");
    display(first);
}
