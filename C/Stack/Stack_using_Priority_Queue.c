// ====================== Problem Statement ==========================
/*
Here we will take the numbers input from user and with the help of priority queue we need to implement stack.
Priority queue is a special type of queue in which the numbers are dequeue based on their priority. Every no has some priority along with its data.
The data having the highest priority is popped first.
In priority queue, we assign priority to the elements that are being pushed. A stack requires elements to be processed in Last in First Out manner.
The idea is to associate a count that determines when it was pushed. This count works as a key for the priority queue. So the implementation of 
stack uses a priority queue of pairs, with the first element serving as the key.
For ex:
User enters input : 4 1 2
so in queue -> [(2,3) (1,2) (4,1)]
*/

// // ====================== Code with C ==========================

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct Queue{
    int info;
    int priority;
    struct Queue *next;
}queue;

//storing the count of no of elements in queue and act as a key for priority
int count=0;

queue *head=NULL;

//function to insert element in queue
void push(int data){
	//newnode pointing new node storing new element of queue
    queue *newnode=(queue*)malloc(sizeof(queue));
    newnode->info=data;
    newnode->priority=++count;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

//function to delete element from queue
void pop(){
    queue *ptr;
    if(head==NULL){
        printf("Deletion is not possible\n");
    }
    else{
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        free(ptr);
    }
}

//function to find top element
int peek(){
    if(head==NULL){
        printf("Empty Stack\n");
        return INT_MAX;    
    }
    else{
        return head->info;
    }
}

int main(){
    int element,choice,temp;
    printf("Enter choice :\n");
    printf("1-push 2-pop 3-peek\n");
    scanf("%d",&choice);//choice is used to store the value of next function to pe performed
    while(choice!=0)
    {
    	if(choice==1)//insert element
    	{
            printf("Enter Element :");
            scanf("%d",&element);
            push(element);
		}
        else if(choice==2)//delete element
        {
        	pop();
		}
		else if(choice == 3)//find topmost element
		{
			temp=peek();
            if(temp!=INT_MAX)
			printf("%d\n",temp);
		}
		else if(choice == 0)//terminate the loop
		{
			break;
		}
		else
		{
			printf("Invalid Choice\n");
		}
		printf("Enter choice :\n");
        printf("0-To Exit 1-push 2-pop 3-peek\n");
        scanf("%d",&choice);
	}
    return 0;
}
