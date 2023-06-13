#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    return ptrA;
}

int main() {
    // Create the first linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* headA = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeA2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeA3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeA4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeA5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    headA->val = 1;
    headA->next = nodeA2;
    nodeA2->val = 2;
    nodeA2->next = nodeA3;
    nodeA3->val = 3;
    nodeA3->next = nodeA4;
    nodeA4->val = 4;
    nodeA4->next = nodeA5;
    nodeA5->val = 5;
    nodeA5->next = NULL;

    // Create the second linked list: 6 -> 7 -> 4 -> 5
    struct ListNode* headB = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeB2 = (struct ListNode*)malloc(sizeof(struct ListNode));

    headB->val = 6;
    headB->next = nodeB2;
    nodeB2->val = 7;
    nodeB2->next = nodeA4;

    // Find the intersection node
    struct ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        printf("Intersection node value: %d\n", intersection->val);
    } else {
        printf("No intersection found.\n");
    }

    // Clean up memory
    free(headA);
    free(nodeA2);
    free(nodeA3);
    free(nodeA4);
    free(nodeA5);
    free(headB);
    free(nodeB2);

    return 0;
}
