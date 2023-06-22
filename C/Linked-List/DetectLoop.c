/*
Given a linked list, check if the linked list has loop(cycle) or not.

Example: Head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3
Output: True

Solution:
1. Traverse the list one by one and keep putting the node addresses in a Hash Table.
2. At any point, if NULL is reached then return false.
3. If next of current node points to any of the previously stored nodes in Hash then return true.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Linked List Node
struct node {
    int val;
    struct node* next;
};

// Display linked list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Function to detect loop in a linked list
bool detect_loop(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create an empty linked list
    struct node* head = NULL;
    struct node* tail = NULL;
    printf("Enter the nodes (Enter -1 to stop): ");
    while (true) {
        int data;
        scanf("%d", &data);
        if (data == -1)
            break;
        struct node* newnode = createNode(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    // Create a loop in linked list
    tail->next = head->next->next;

    if (detect_loop(head))
        printf("Loop detected\n");
    else
        printf("No loop detected\n");

    return 0;
}
