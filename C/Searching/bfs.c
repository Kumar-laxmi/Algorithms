// C Program to find bfs traversal starting from a vertex.

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


// Global pointer variables for managing queue
int front = -1, rear = -1;

typedef struct listNode
{
    int node;
    struct listNode *next;
} listNode;

// function to add edge to the existing graph
void addEdge(listNode* adjList[],listNode* lastNode[],int source,int target)
{
    // adding edge to the source node for the first time
    if(lastNode[source] == NULL){
        lastNode[source] = (listNode*)malloc(sizeof(listNode));
        adjList[source] = lastNode[source];
    }
    
    else {
        lastNode[source]->next = (listNode*)malloc(sizeof(listNode));
        lastNode[source] = lastNode[source]->next;
    }
    lastNode[source]->node = target;
    lastNode[source]->next = NULL;
}

// Operations for Queue
void Push(int queue[],int vertex)
{
    if(front == -1)
        front = 0;
    rear += 1;
    queue[rear] = vertex;
}

void Pop()
{
    front += 1;
}

int Peek(int queue[])
{
    return queue[front];
}

bool isEmpty()
{
    if(front == -1)
        return true;
    else
        return front > rear ? true : false;
}

int main()
{
    int numberofVertices,numberofEdges,source,dest,startingNode;
    printf("\nBFS for Directed Graphs\nNodes are considered from 0 to n-1 \n\n");
    printf("Enter Number of Nodes : ");
    scanf("%d",&numberofVertices);
    printf("\nEnter Number of Edges : ");
    scanf("%d",&numberofEdges);

    // Adjacency List to store neighbouring nodes; Array of pointers,think of each as list which contains neigbours to the vertex given by the index of the array.
    listNode **adjList = (listNode**) malloc(sizeof(listNode*) * numberofVertices);
    listNode **lastNode = (listNode**)malloc(sizeof(listNode*) * numberofVertices); // storing last pointer for faster insertion

    // Declaring queue
    int queue[numberofVertices];

    // visited array
    bool visited[numberofVertices];

    // initialiazing null and marking every vertex visited as false;
    for (int i = 0; i < numberofVertices; i++)
    {
        adjList[i] = NULL;
        lastNode[i] = NULL;
        visited[i] = false;
    }

    printf("Enter edges with source and target : \n");
    while (numberofEdges--)
    {
        scanf("%d%d",&source,&dest);
        // checking for a valid edge and no self loop
        if (source >= 0 && source < numberofVertices && dest >= 0 && dest < numberofVertices && source != dest)
        {
            addEdge(adjList,lastNode,source,dest);
        }
        else
        {
            printf("\nEdge combination not valid,Enter again : \n");
            numberofEdges += 1;
        }
    }
 
    printf("\nEnter the starting vertex for traversal : ");
    scanf("%d",&startingNode);
    Push(queue,startingNode);
    visited[startingNode] = true;

    printf("\nBFS Traversal from %d : \n",startingNode);
    // BFS
    while (!isEmpty())
    {
        int front = Peek(queue);
        printf("%d ",front);
        listNode* head = adjList[front];
        while (head) // iterating over the list to find all the neighbours to the node.
        {
            if(!visited[head->node]){
                visited[head->node] = true;  // marking node as visited.
                Push(queue,head->node);      // pushing to queue for further traversal.
            }
            head = head->next;
        }
        Pop();
    }
    return 0;
}