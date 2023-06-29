#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* bottom;
};

// Print Linked List
void printLinkedList(struct Node* Node)
{
	while (Node != NULL)
	{
		printf("%d ", Node->data);
		Node = Node->bottom;
	}
}

struct Node* FlattenLinkedList(struct Node* root)
{
	// Initialize the head pointers
	struct Node* head1 = root;
	struct Node* head2 = root->next;
	root = root->next;

	while (root != NULL) {
		// Initialize head and tail for the new flattened list
		struct Node* head = NULL;
		struct Node* tail = NULL;

		// Merge the two sorted linked lists
		while (head1 != NULL && head2 != NULL) {
			if (head1->data < head2->data) {
				// Create a new node for the merged list
				struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->data = head1->data;
				newNode->next = NULL;
				newNode->bottom = NULL;

				// Append the new node to the merged list
				if (head == NULL && tail == NULL) {
					head = newNode;
					tail = newNode;
				}
				else {
					tail->bottom = newNode;
					tail = tail->bottom;
				}

				head1 = head1->bottom;
			}
			else {
				// Create a new node for the merged list
				struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->data = head2->data;
				newNode->next = NULL;
				newNode->bottom = NULL;

				// Append the new node to the merged list
				if (head == NULL && tail == NULL) {
					head = newNode;
					tail = newNode;
				}
				else {
					tail->bottom = newNode;
					tail = tail->bottom;
				}

				head2 = head2->bottom;
			}
		}

		// Append the remaining nodes of the linked lists
		while (head1 != NULL) {
			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = head1->data;
			newNode->next = NULL;
			newNode->bottom = NULL;

			if (head == NULL && tail == NULL) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->bottom = newNode;
				tail = tail->bottom;
			}

			head1 = head1->bottom;
		}
		// Append the remaining nodes of the linked lists
		while (head2 != NULL) {
			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = head2->data;
			newNode->next = NULL;
			newNode->bottom = NULL;

			if (head == NULL && tail == NULL) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->bottom = newNode;
				tail = tail->bottom;
			}

			head2 = head2->bottom;
		}

		// Move to the next level
		root = root->next;
		head1 = head;
		head2 = root;
	}

	return head1;
}

int main(void) {
	int t;
	printf("Enter No of attempts: \n");
	scanf("%d", &t);

	while (t--) {
        // Initialize flags and pointer 
		int n, m, flag = 1, flag1 = 1;
		struct Node* temp = NULL;
		struct Node* head = NULL;
		struct Node* pre = NULL;
		struct Node* tempB = NULL;
		struct Node* preB = NULL;
        // Taking Input 
		printf("Enter size of horizontal Linkedlist: \n");
		scanf("%d", &n);
		int work[n];
		printf("Elements in Horizontal Linkedlist: \n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &work[i]);
		}
		for (int i = 0; i < n; i++) {
			m = work[i];
			--m;
			int data;
			printf("Enter Head For Bottom LinkedList: \n");
			scanf("%d", &data);
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->data = data;
			temp->next = NULL;
			temp->bottom = NULL;

			if (flag) {
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else {
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			printf("Enter Bottom Linkedlist Elements: \n");
			for (int j = 0; j < m; j++) {
				int temp_data;
				scanf("%d", &temp_data);
				tempB = (struct Node*)malloc(sizeof(struct Node));
				tempB->data = temp_data;
				tempB->next = NULL;
				tempB->bottom = NULL;

				if (flag1) {
					temp->bottom = tempB;
					preB = tempB;
					flag1 = 0;
				}
				else {
					preB->bottom = tempB;
					preB = tempB;
				}
			}
		}

		// Flattening and printing the linked list
		struct Node* root = FlattenLinkedList(head);
		printLinkedList(root);
		printf("\n");
	}

	return 0;
}
