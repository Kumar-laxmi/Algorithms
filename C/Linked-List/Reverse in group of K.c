#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct Node* insert(struct Node* head, int val) {
    struct Node* temp = createNode(val);
    if (head == NULL) {
        temp->next = head;
        return temp;
    }

    struct Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->next = NULL;
    return head;
}

struct Node* reverseinK(struct Node* head, int k) {
    struct Node* curr = head;
    struct Node* prevFirst = NULL;
    int isFirstPass = 1;

    while (curr != NULL) {
        struct Node* first = curr;
        struct Node* prev = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            struct Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass) {
            head = prev;
            isFirstPass = 0;
        }
        else
            prevFirst->next = prev;
        prevFirst = first;
    }
    return head;
}

void print(struct Node* head) {
    struct Node* curr = head;
    printf("\n\n");
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, k;
    printf("Enter n, k : ");
    scanf("%d %d", &n, &k);
    printf("Enter nodes : \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }
    print(head);
    head = reverseinK(head, k);
    print(head);
    return 0;
}
