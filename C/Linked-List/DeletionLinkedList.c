#include<stdio.h>
#include<stdlib.h>

 struct Node{
 	int data;
 	struct Node *next;
 };
 

struct Node *DeleteFirstNode(struct Node *head){
	struct Node*ptr=head;
	head=head->next;
	free(ptr);
	return head;
}
void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node *Deletebetween(struct Node *head,int index){
    struct Node *ptr=head;
    struct Node *p=head->next;

    int i;
    for(i=0;i<index-1;i++){
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;


    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=5;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=55;
    third->next=fourth;

    fourth->data=32;
    fourth->next=NULL;
    

    linkedlisttraversal(head);
    printf("\n");
    
	head=Deletebetween(head,2);
    linkedlisttraversal(head);
	return 0;
}
 
