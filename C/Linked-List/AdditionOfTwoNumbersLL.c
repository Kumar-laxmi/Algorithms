#include <stdio.h>
#include <stdlib.h>
/*

#Addition of two numbers Linked-List C #1317

The code defines a structure ListNode to represent a node of the linked list. Each node contains an integer value (val) and a pointer to the next node (next).

The function addTwoNumbers is the main function responsible for adding the two numbers represented as linked lists. However, the implementation of this function is not provided in the template. You need to implement this logic based on the requirements of adding two numbers as linked lists.

The function makeList is used to create a linked list with a given number of nodes. It prompts the user to enter the values of the nodes and constructs the linked list accordingly.

The function printList is used to print the values of the nodes in a linked list.

In the main function, the user is prompted to enter the number of digits in the first and second linked lists. The functions makeList are then called to create the respective linked lists based on the user input.

After that, the addTwoNumbers function is called with the two linked lists as parameters to perform the addition of the numbers.

Finally, the result is printed using the printList function.

Sample Input:
5
1 0 3 2 5
3
1 2 4
Sample Output:
10358



*/
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = head;

    while (current != NULL)
    {
        struct ListNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode *current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }

    if (carry > 0)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;

        current->next = newNode;
    }

    struct ListNode *result = reverseList(dummy->next);
    free(dummy);

    return result;
}

struct ListNode *makeList(int n)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = NULL;
    struct ListNode *prev = dummy;

    printf("Enter the values of the nodes (separated by spaces): ");
    for (int i = 0; i < n; i++)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &(newNode->val));
        newNode->next = NULL;

        prev->next = newNode;
        prev = prev->next;
    }

    return dummy->next;
}

void printList(struct ListNode *node)
{
    while (node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

void freeList(struct ListNode *node)
{
    while (node != NULL)
    {
        struct ListNode *temp = node;
        node = node->next;
        free(temp);
    }
}

int main()
{
    int choice;
    struct ListNode *head1;
    struct ListNode *head2;
    struct ListNode *result;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add two numbers represented as linked lists\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n1, n2;

            printf("Enter the number of digits in the first linked list: ");
            scanf("%d", &n1);
            head1 = makeList(n1);

            printf("Enter the number of digits in the second linked list: ");
            scanf("%d", &n2);
            head2 = makeList(n2);

            result = addTwoNumbers(head1, head2);

            printf("Result: ");
            printList(result);

            freeList(head1);
            freeList(head2);
            freeList(result);

            break;
        }

        case 2:
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}
