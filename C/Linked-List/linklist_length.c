/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms*/
#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
    int data;
    struct Node* next;
};
// Function to find the length of a singly linked list
int findLength(struct Node* head) 
{
    int count = 0;
    struct Node* current = head;
    while (current != NULL) 
    {
        count++;
        current = current->next;
    }
    return count;
}
int main()
{
    // Creating an empty linked list
    struct Node* head = NULL;
    // Reading input from the user to create the linked list
    printf("Enter the number of nodes in the linked list: ");
    int n;
    scanf("%d", &n);
    if (n > 0) 
    {
        printf("Enter the data for each node: ");
        struct Node* prev = NULL;
        for (int i = 0; i < n; i++) {
            struct Node* current = (struct Node*) malloc(sizeof(struct Node));
            scanf("%d", &current->data);
            current->next = NULL;
            if (prev == NULL) {
                head = current;
            } else {
                prev->next = current;
            }
            prev = current;
        }
    }
    // Finding the length of the linked list
    int length = findLength(head);
    // Printing the length of the linked list
    printf("Length of the linked list is: %d\n", length);
    return 0;
}