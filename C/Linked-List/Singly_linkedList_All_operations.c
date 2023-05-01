#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//-------------insertng at the beginning of node---------------------------
struct node *insertAtBeginning(struct node *head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (head != NULL)
        temp->next = head;

    head = temp;
    return head;
}

//---------------------inserting node at end--------------------------
struct node* insertAtEnd(struct node* head,int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node* temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
    return head;
}

//---------------------printing nodes---------------------------------
void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

//------------------printing data using recursion----------------------
void printRecursion(struct node* head){
    if(head==NULL){
        return;
    }
    printf("%d ",head->data);
    printRecursion(head->next);
}

//------------------printing reverse data using recursion-------------------
void printReverseRecursion(struct node* head){
    if(head==NULL){
        return;
    }
    printReverseRecursion(head->next);
    printf("%d ",head->data);
}

//------------------------deleting nth node ----------------------------
void delete (struct node *head, int n)
{
    struct node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next; // for changing node 1st to 2nd
        free(temp1);
        return;
    }

    for (int i = 0; i < n - 2; i++)
        temp1 = temp1->next; // moving to n-1 th node for deleting nth node

    struct node *temp2;
    temp2 = temp1->next;       //  moving to  n+1 th node
    temp1->next = temp2->next; // assigning address of n+1 th to n-1 th node
    free(temp2);  
}

//-------------------reversing node------------------------------------
struct node *reverse(struct node *head)
{
    struct node *prev, *curr, *nxt;
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
    return head;
}
 
//-----------------------sorting data in ascending order--------------------------
void sortdata(struct node *head){
    struct node *curr=head;
    struct node *nxt=NULL;
    if(head==NULL){
        return;
    }
    else{
        while(curr!=NULL){
            nxt=curr->next;

            while(nxt!=NULL){
                if(curr->data > nxt->data){
                    int temp=curr->data;
                    curr->data=nxt->data;
                    nxt->data=temp;
                }
                nxt=nxt->next;
            }
            curr=curr->next;
        }
    }
}

//----------------------main function--------------------------------
int main()
{
    struct node *head = NULL;
    printf("enter the no of node\n");
    int n, x, i;
    scanf("%d", &n);

    printf("enter the values\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertAtBeginning(head, x);
        // head = insertAtEnd(head, x);
    }
    // int n1;
    // printf("enter node number to delete\n");
    // scanf("%d", &n1);
    // delete (head, n1);
    // print(head);


    // head=reverse(head);
    // print(head);

    printRecursion(head);

    // printReverseRecursion(head);
    // sortdata(head);

    // print(head);
}