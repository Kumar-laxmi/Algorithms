#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *mergeSortedLists(struct Node **head1, struct Node **head2)
{
    struct Node *p1 = *head1;
    struct Node *p2 = *head2;
    struct Node *dummyNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p3 = dummyNode;

    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    // Remaining nodes of first list
    if (p1 != NULL)
        p3->next = p1;

    // Remaining nodes of second list
    if (p2 != NULL)
        p3->next = p2;
    struct Node *mergedHead = dummyNode->next;
    free(dummyNode);
    return mergedHead;
}

void displayLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int lenA, lenB;
    printf("Enter the length of first linked list: ");
    scanf("%d", &lenA);

    printf("Enter the length of second linked list: ");
    scanf("%d", &lenB);

    // First Linked List

    int data;
    printf("Enter the data for the head node of the first list: ");
    scanf("%d", &data);
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    head1->data = data;
    head1->next = NULL;
    struct Node *tail1 = head1;

    // Inputting the data for the nodes other than the head
    printf("Enter data for the other nodes of the first list: ");
    for (int i = 1; i < lenA; i++)
    {
        scanf("%d", &data);
        tail1->next = (struct Node *)malloc(sizeof(struct Node));
        tail1 = tail1->next;
        tail1->data = data;
        tail1->next = NULL;
    }

    // Second Linked List
    printf("Enter the data for the head node of the second list: ");
    scanf("%d", &data);
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    head2->data = data;
    head2->next = NULL;
    struct Node *tail2 = head2;

    // Inputting the data for the nodes other than the head
    printf("Enter data for the other nodes of the second list: ");
    for (int i = 1; i < lenB; i++)
    {
        scanf("%d", &data);
        tail2->next = (struct Node *)malloc(sizeof(struct Node));
        tail2 = tail2->next;
        tail2->data = data;
        tail2->next = NULL;
    }

    struct Node *head = mergeSortedLists(&head1, &head2);
    displayLinkedList(head);

    // Freeing the allocated memory
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
