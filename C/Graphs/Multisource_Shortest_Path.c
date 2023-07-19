#include <stdio.h>
#include <stdlib.h>
#define N 1005
int adj[N][N];

typedef struct {
    int arr[N];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue* q) {
    return (q->rear == N - 1);
}

void enqueue(Queue* q, int node) {
    
    if (isFull(q)) {
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->arr[q->rear] = node;
}

int pop(Queue* q) {
    
    if (isEmpty(q)) {
        return -1;
    }

    int node = q->arr[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }

    return node;
}

int front(Queue* q) {
    
    if (isEmpty(q)) {
        return -1;
    }

    return q->arr[q->front];
}

int size(Queue* q) {
    if (isEmpty(q)) {
        return 0;
    }

    return q->rear - q->front + 1;
}


int main() {

    Queue* q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);

    int n;
    scanf("%d",&n);
    
    

    int m;
    scanf("%d",&m);

    int s;
    scanf("%d",&s);

    int sources[s];

    for(int i = 0;i<s;i++) {
        int src;
        scanf("%d",&src);
        sources[i] = src;
    }

    while(m--) {
        int u,v;
        scanf("%d",&u);
        scanf("%d",&v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int vis[n+1];

    for(int i = 1;i<=n;i++) {
        vis[i] = 0;
    }

    int dist[n+1];

    for(int i = 1;i<=n;i++) {
        dist[i] = 1000000000;
    }

    for(int i = 0;i<s;i++) {
        int src= sources[i];
        enqueue(q,src);
        vis[src] = 1;
    }

    int lvl = 0;

    while(size(q)) {
        int sz = size(q);
        while(sz--) {
            int node = pop(q);
            dist[node] = lvl;

            for(int it = 1;it<=n;it++) {
                if(adj[node][it]) {
                    
                    if(vis[it]) continue;

                    vis[it] = 1;
                    enqueue(q,it);

                }
            }
        }

        lvl++;
    }

    for(int i = 1;i<=n;i++) {
        printf("%d: ",i);
        printf("%d",dist[i]);
        printf("\n");
    }

    return 0;
}