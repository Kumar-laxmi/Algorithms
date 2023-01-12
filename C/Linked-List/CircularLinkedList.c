# include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *ptr = head;
    printf("Element is %d\n",ptr->data);
    ptr = ptr->next;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

struct Node * insert_between(struct Node * head,int data , int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;
};

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head ->next=second;

    second->data = 10;
    second->next = third;

    third->data = 25;
    third->next = head;

    display(head);
    head = insert_between(head,45,2);

    display(head);

    return 0;
}