// =================================== Problem Statement ====================================
/*
 Task: Merge K sorted Linked List

 Sol: The problem to merge K sorted List can be done via folowing methods

    Method 1) Brute Force (Array Conversion and Sorting)

    Algorithm:
        1) Traverse each linked list and store the elements in an array.
        2) Merge all the arrays into one sorted array using any standard sorting algorithm.3) Create a new linked list and populate it with the elements from the sorted array in the correct order.

    Time Complexity: O(N log N) , Space Complexity: O(N) where N is the total number of elements across all the linked lists.

    Method 2) Using a Priority Queue (Min-Heap)

    Algorithm:
        1) Create a min-heap.
        2) Insert the first element from each linked list into the min-heap.
        3) Pop the minimum element from the min-heap (smallest among all current elements).4) Append the popped element to the final merged linked list.
        5) If there are more elements in the linked list from which the popped element came, insert the next element into the min-heap.
        6) Repeat steps 3-5 until the min-heap is empty.

    Time Complexity: O(N log k) ,Space Complexity: O(k) where N is the total number of elements across all the linked lists and k is the number of linked lists.

    Method 3) Divide and Conquer (Pairwise merging)

    Algorithm:
        1) Divide the k linked lists into two halves.
        2) Recursively merge the two halves using the same merging process.
        3) Repeat step 2 until there is only one merged linked list.

    Time Complexity: O(N log k), Space Complexity: O(log k) where N is the total number of elements across all the linked lists and k is the number of linked lists.

    Method 4) Iterative Merging

    Algorithm:
        1) Start with an empty merged linked list.
        2) Pick the first two linked lists and merge them using a helper function that merges two sorted lists.
        3) Append the merged list to the end of the list of remaining linked lists.
        4) Remove the first two linked lists from the list of remaining linked lists.
        5) Repeat steps 2-4 until there is only one merged linked list.

    Time Complexity: O(Nk), Space Complexity: O(1) where N is the total number of elements across all the linked lists and k is the number of linked lists.

    Conclusion:
        - If the number of linked lists (k) is relatively small or memory usage is a concern, the Priority Queue method (Min-Heap) is a suitable choice. It has a lower space complexity compared to the brute force method and provides efficient merging of elements.
        - If memory usage is a concern and the linked lists are already sorted, the Iterative Merging method can be considered. It has a constant space complexity and requires no additional data structures.
        - If the number of linked lists is large and memory usage is not a concern, the Divide and Conquer method provides an efficient solution. It has a similar time complexity to the Priority Queue method but may have a higher constant factor due to recursive calls.
        - The Brute Force method can be used if there are no constraints on memory usage and an existing sorting algorithm is readily available. It may be suitable for small inputs or situations where simplicity is preferred over optimization.

    Ultimately, the choice of algorithm depends on the specific requirements.
    We are going to implemet 3 Approaches below
*/
// =================================== Code with C ==========================================
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode dummy;
    struct ListNode *tail = &dummy;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Function to merge k sorted linked lists using divide and conquer approach
struct ListNode *mergeKListsDivideConquer(struct ListNode **lists, int left, int right)
{
    if (left == right)
    {
        return lists[left];
    }
    else if (left < right)
    {
        int mid = left + (right - left) / 2;
        struct ListNode *l1 = mergeKListsDivideConquer(lists, left, mid);
        struct ListNode *l2 = mergeKListsDivideConquer(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
    else
    {
        return NULL;
    }
}

// Function to merge k sorted linked lists iteratively
struct ListNode *mergeKListsIterative(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
    {
        return NULL;
    }

    int interval = 1;
    while (interval < listsSize)
    {
        for (int i = 0; i + interval < listsSize; i += interval * 2)
        {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }

    return lists[0];
}

// Function to print the elements of a linked list
void printList(struct ListNode *head)
{
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Priority Queue Node
struct PQNode
{
    struct ListNode *node;
    struct PQNode *next;
};

// Function to add a node to the priority queue based on node values
void addToPriorityQueue(struct PQNode **queue, struct ListNode *node)
{
    struct PQNode *newNode = (struct PQNode *)malloc(sizeof(struct PQNode));
    newNode->node = node;
    newNode->next = NULL;

    if (*queue == NULL || node->val < (*queue)->node->val)
    {
        newNode->next = *queue;
        *queue = newNode;
    }
    else
    {
        struct PQNode *current = *queue;
        while (current->next != NULL && current->next->node->val <= node->val)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to merge k sorted linked lists using a priority queue
struct ListNode *mergeKListsPriorityQueue(struct ListNode **lists, int k)
{
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    struct PQNode *queue = NULL;

    // Add the first nodes of each list to the priority queue
    for (int i = 0; i < k; i++)
    {
        if (lists[i] != NULL)
        {
            addToPriorityQueue(&queue, lists[i]);
        }
    }

    // Merge the lists by continuously extracting the minimum node from the priority queue
    while (queue != NULL)
    {
        struct PQNode *minNode = queue;
        tail->next = minNode->node;
        tail = tail->next;

        // Add the next node from the list containing the minimum node
        if (minNode->node->next != NULL)
        {
            addToPriorityQueue(&queue, minNode->node->next);
        }

        queue = queue->next;
    }

    return dummy.next;
}

int main()
{
    // Create example linked lists for divide and conquer
    struct ListNode *list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->next->val = 4;
    list1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->next->next->val = 5;
    list1->next->next->next = NULL;

    struct ListNode *list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    struct ListNode *list3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list3->val = 2;
    list3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list3->next->val = 6;
    list3->next->next = NULL;

    struct ListNode *lists1[3] = {list1, list2, list3};

    // Merge using divide and conquer
    struct ListNode *mergedListDC = mergeKListsDivideConquer(lists1, 0, 2);
    printf("Merged list (Divide and Conquer): ");
    printList(mergedListDC);

    // Create example linked lists for iterative merging
    struct ListNode *list4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list4->val = 2;
    list4->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list4->next->val = 5;
    list4->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list4->next->next->val = 6;
    list4->next->next->next = NULL;

    struct ListNode *list5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list5->val = 1;
    list5->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list5->next->val = 2;
    list5->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list5->next->next->val = 9;
    list5->next->next->next = NULL;

    struct ListNode *list6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list6->val = 4;
    list6->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list6->next->val = 7;
    list6->next->next = NULL;

    struct ListNode *lists2[3] = {list4, list5, list6};

    // Merge using iterative merging
    struct ListNode *mergedListIter = mergeKListsIterative(lists2, 3);
    printf("Merged list (Iterative): ");
    printList(mergedListIter);

    // Create example linked lists for priority queue merging
    struct ListNode *list7 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list7->val = 2;
    list7->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list7->next->val = 3;
    list7->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list7->next->next->val = 6;
    list7->next->next->next = NULL;

    struct ListNode *list8 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list8->val = 1;
    list8->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list8->next->val = 4;
    list8->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list8->next->next->val = 5;
    list8->next->next->next = NULL;

    struct ListNode *list9 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list9->val = 3;
    list9->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list9->next->val = 7;
    list9->next->next = NULL;

    struct ListNode *lists3[3] = {list7, list8, list9};

    // Merge using priority queue merging
    struct ListNode *mergedListPQ = mergeKListsPriorityQueue(lists3, 3);
    printf("Merged list (Priority Queue): ");
    printList(mergedListPQ);

    return 0;
}