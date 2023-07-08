#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
bool detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
 
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
 
    return false;
}
 
int main() {
    struct Node* head = NULL;
    int n, x;
 
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &x);
        push(&head, x);
    }
 
    head->next->next->next->next = head;
 
    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle detected in the linked list.\n");
    }
 
    return 0;
}
