/*
-----------------------------Problem Statement-----------------------------
There are two singly linked lists and the end of one linked list
is connected to the second list.Find the point of intersection of
these two linked lists.

Example: List1: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
         List2: 8 -> 9 -> 5 -> 6 -> 7
Output: Intersection point is 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linked List Node
typedef struct node {
    int val;
    struct node* next;
} node;

// Display linked list
void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Insert node at the end of linked list
void insertattail(node** head, node** tail, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->val = data;
    temp->next = NULL;
    
    if (*head == NULL) {
        *head = temp;
        *tail = temp;
        return;
    }
    (*tail)->next = temp;
    *tail = temp;
}

// Function to find intersection point of two linked lists
//Using 2 pointers -> O(n) time and O(1) space
node* IntersectionNode(node* headA, node* headB) {
    node* ptr1 = headA;
    node* ptr2 = headB;
        
    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? headB : ptr1->next;
        ptr2 = (ptr2 == NULL) ? headA : ptr2->next;
    }
    return ptr1;
}

int main() {
    // Create an empty linked list
    node* head1 = NULL;
    node* tail1 = NULL;

    // Insert nodes in linked list
    printf("Enter the number of nodes in linked list 1: ");
    int n1;
    scanf("%d", &n1);
    printf("Enter the nodes of linked list 1: ");
    for (int i = 0; i < n1; i++) {
        int data;
        scanf("%d", &data);
        insertattail(&head1, &tail1, data);
    }

    // Create an empty linked list
    node* head2 = NULL;
    node* tail2 = NULL;

    // Insert nodes in linked list
    printf("Enter the number of nodes in linked list 2: ");
    int n2;
    scanf("%d", &n2);
    printf("Enter the nodes of linked list 2: ");
    for (int i = 0; i < n2; i++) {
        int data;
        scanf("%d", &data);
        insertattail(&head2, &tail2, data);
    }

    // Create a random intersection point
    srand(time(0));
    int pos = rand() % n1 + 1;
    node* temp = head1;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    tail2->next = temp;

    // Display linked lists
    printf("Linked list 1: ");
    display(head1);
    printf("Linked list 2: ");
    display(head2);

    // Find intersection point
    node* intersection = IntersectionNode(head1, head2);
    if (intersection) {
        printf("Intersection point is: %d\n", intersection->val);
        printf("Linked list after intersection point: ");
        display(intersection);
    }
    else {
        printf("No intersection point\n");
    }
    return 0;
}
