// C program for the all operations in the Doubly Linked List
 
#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *prev;
  struct node *next;
};
struct node* head = NULL;

void traversal()
{
	// List is empty
	if (head == NULL) {
		printf("\nList is empty\n");
		return;
	}
	// Else print the Data
	struct node* temp;
	temp = head;
	while (temp != NULL) {
		printf("Data = %d\n", temp->data);
		temp = temp->next;
	}
}

 
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->data = data;
	temp->prev = NULL;

	
	temp->next = head;
	head = temp;
}


void insertAtEnd()
{
	int data;
	struct node *temp, *ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->data = data;
	temp->next = NULL;
	ptr = head;


  
	if (head == NULL) {

		head = temp;
	}


	else {
		while (ptr->next != NULL)
			ptr = ptr->next;
		temp->prev = ptr;
		ptr->next = temp;
	}
}


void insertAtPosition()
{
	int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;


	printf("\nEnter position : ");
	scanf("%d", &pos);
	


	if (head == NULL) {
		head = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}else if (pos == 1) {
	insertAtFront();
	}else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->data = data;
	temp = head;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

void deleteFirst()
{
	struct node* temp;
	if (head == NULL)
		printf("\nList is empty\n");
	else {
		temp = head;
		start = head->next;
		if (head != NULL)
			head->prev = NULL;
		free(temp);
	}
}


void deleteEnd()
{
	struct node* temp;
	if (head == NULL)
		printf("\nList is empty\n");
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	if (head->next == NULL)
		head = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}

void deletePosition()
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = head;

	
	if (head == NULL)
		printf("\nList is empty\n");
	else {
		printf("\nEnter position : ");
		scanf("%d", &pos);

		
		if (pos == 1) {
			deleteFirst(); 
			if (head != NULL) {
				head->prev = NULL;
			}
			free(position);
			return;
		}

	
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;

		
		free(position);
	}
}

int main()
{
	int choice;
	while (1) {

		printf("\n\t1 To see list\n");
		printf("\t2 For insertion at"
			" starting\n");
		printf("\t3 For insertion at"
			" end\n");
		printf("\t4 For insertion at "
			"any position\n");
		printf("\t5 For deletion of "
			"first element\n");
		printf("\t6 For deletion of "
			"last element\n");
		printf("\t7 For deletion of "
			"element at any position\n");
		printf("\t8 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traversal();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;

		case 8:
			exit(1);
			break;
		default:
			printf("Wrong Choice \n");
			continue;
		}
	}
	return 0;
}
