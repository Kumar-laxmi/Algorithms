// C Program to find dfs traversal starting from a vertex.

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

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

// DFS
void dfs(listNode* adj[],bool visited[],int vertex)
{

    printf("%d ",vertex);
    visited[vertex] = true;
    listNode* head = adj[vertex];
    while (head)
    {
        if(!visited[head->node])
            dfs(adj,visited,head->node);
        head = head->next;
    }
}

int main()
{
    int numberofVertices,numberofEdges,source,dest,startingNode;
    printf("\nDFS for Directed Graphs\nNodes are considered from 0 to n-1 \n\n");
    printf("Enter Number of Nodes : ");
    scanf("%d",&numberofVertices);
    printf("\nEnter Number of Edges : ");
    scanf("%d",&numberofEdges);

    // Adjacency List to store neighbouring nodes; Array of pointers,think of each as list which contains neigbours to the vertex given by the index of the array.
    listNode **adjList = (listNode**) malloc(sizeof(listNode*) * numberofVertices);
    listNode **lastNode = (listNode**)malloc(sizeof(listNode*) * numberofVertices); // storing last pointer for faster insertion

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
    printf("\nDFS Traversal from % d: \n ",startingNode);
    dfs(adjList,visited,startingNode);
    return 0;
}