#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *Insert(struct Node *root){
    printf("Enter value to be entered : ");
    int val;
    scanf("%d", &val);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->key = val;

    if (val == -1)
        return NULL;

    printf("Enter value to left of %d : ", val);
    root->left = Insert(root->left);
    printf("Enter value to right of %d : ", val);
    root->right = Insert(root->right);

    return root;
}

void Display(int *V, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", V[i]);
}

void LeftView(struct Node *root, int level, int *res, int *index){
    if (!root)
        return;
    if (*index == level)
    {
        res[*index] = root->key;
        (*index)++;
    }
    LeftView(root->left, level + 1, res, index);
    LeftView(root->right, level + 1, res, index);
}

void RightView(struct Node *root, int level, int *res, int *index){
    if (!root)
        return;
    if (*index == level){
        res[*index] = root->key;
        (*index)++;
    }
    RightView(root->right, level + 1, res, index);
    RightView(root->left, level + 1, res, index);
}

void TopView(struct Node *root, int **res, int *size){
    if (!root)
        return;

    int minIdx = 0;
    int maxIdx = 0;

    struct NodeQueue
    {
        struct Node *node;
        int hd;
    };

    struct NodeQueue *queue = (struct NodeQueue *)malloc(sizeof(struct NodeQueue) * 1000);
    int front = 0, rear = -1;

    queue[++rear] = (struct NodeQueue){root, 0};

    while (front <= rear){
        struct NodeQueue f = queue[front++];

        if (f.hd < minIdx)
            minIdx = f.hd;
        else if (f.hd > maxIdx)
            maxIdx = f.hd;

        if (f.node->left)
            queue[++rear] = (struct NodeQueue){f.node->left, f.hd - 1};
        if (f.node->right)
            queue[++rear] = (struct NodeQueue){f.node->right, f.hd + 1};
    }

    *size = maxIdx - minIdx + 1;
    *res = (int *)malloc(sizeof(int) * (*size));

    for (int i = 0; i < *size; i++)
        (*res)[i] = 0;

    queue = (struct NodeQueue *)realloc(queue, sizeof(struct NodeQueue) * (rear + 1));
    front = 0;

    while (front <= rear){
        struct NodeQueue f = queue[front++];

        if ((*res)[f.hd - minIdx] == 0)
            (*res)[f.hd - minIdx] = f.node->key;
    }
    free(queue);
}

void BottomView(struct Node *root, int **res, int *size){
    if (!root)
        return;

    int minIdx = 0;
    int maxIdx = 0;

    struct NodeQueue
    {
        struct Node *node;
        int hd;
    };

    struct NodeQueue *queue = (struct NodeQueue *)malloc(sizeof(struct NodeQueue) * 1000);
    int front = 0, rear = -1;

    queue[++rear] = (struct NodeQueue){root, 0};

    while (front <= rear)
{
        struct NodeQueue f = queue[front++];

        if (f.hd < minIdx)
            minIdx = f.hd;
        else if (f.hd > maxIdx)
            maxIdx = f.hd;

        if (f.node->left)
            queue[++rear] = (struct NodeQueue){f.node->left, f.hd - 1};
        if (f.node->right)
            queue[++rear] = (struct NodeQueue){f.node->right, f.hd + 1};
    }

    *size = maxIdx - minIdx + 1;
    *res = (int *)malloc(sizeof(int) * (*size));

    for (int i = 0; i < *size; i++)
        (*res)[i] = 0;

    queue = (struct NodeQueue *)realloc(queue, sizeof(struct NodeQueue) * (rear + 1));
    front = 0;

    while (front <= rear){
        struct NodeQueue f = queue[front++];
        (*res)[f.hd - minIdx] = f.node->key;
    }
    free(queue);
}

int main(){
    struct Node *root = NULL;
    printf("Enter binary tree nodes and for no node enter -1\n\n");
    root = Insert(root);

    int *L = NULL;
    int *R = NULL;
    int *T = NULL;
    int *B = NULL;
    int usrchoice = 0;

    while (1){
        printf("\n\n1.Left View\n2.Right View\n3.Top View\n4.Bottom View\n5.Exit\n");
        printf("Enter the choice of operation to be implemented : ");
        scanf("%d", &usrchoice);

        switch (usrchoice){
        case 1:{
            L = (int *)malloc(sizeof(int) * 1000);
            int lIndex = 0;
            LeftView(root, 0, L, &lIndex);
            Display(L, lIndex);
            free(L);
            break;
        }

        case 2:{
            R = (int *)malloc(sizeof(int) * 1000);
            int rIndex = 0;
            RightView(root, 0, R, &rIndex);
            Display(R, rIndex);
            free(R);
            break;
        }

        case 3:{
            int tSize = 0;
            T = (int *)malloc(sizeof(int) * 1000);
            TopView(root, &T, &tSize);
            Display(T, tSize);
            free(T);
            break;
        }

        case 4:{
            int bSize = 0;
            B = (int *)malloc(sizeof(int) * 1000);
            BottomView(root, &B, &bSize);
            Display(B, bSize);
            free(B);
            break;
        }

        case 5:
            exit(1);

        default:
            printf("Enter a valid choice : ");
            break;
        }
    }
    return 0;
}