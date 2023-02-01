#include<stdio.h>
#include<malloc.h>

int **copyRelation(int **original,int n) { 
    // Creating a copy of original relation so it does not modify original
    int **relation = (int **)malloc(sizeof(int *)*n);
    for (int i=0;i<n;i++) {
        relation[i] = (int *)malloc(sizeof(int)*n);
        for (int j=0;j<n;j++) relation[i][j] = original[i][j];
    }
    return relation;
}

void freeRelation(int **relation,int n) {
    // freeing memory allocated to relation
    for (int i=0;i<n;i++) free(relation[i]);
    free(relation);
}

void displayRelation(int **relation,int n) {
    // Displaying relation
    int first=1;
    printf("{");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (relation[i][j] == 1) {
                if (!first) printf(",");
                printf("(%d,%d)",i,j);
                first = 0;
            }
        }
    }
    printf("}\n");
}

void reflexiveClosure(int **relation,int n) {
    relation = copyRelation(relation,n);
    for (int i=0;i<n;i++) {
        //  Setting all (i,i) pairs to 1
        relation[i][i] = 1; 
    }
    printf("Reflexive closure: ");
    displayRelation(relation,n);
    freeRelation(relation,n);
}

void symmetricClosure(int **relation,int n) {
    relation = copyRelation(relation,n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            // Setting (j,i) pair to 1 for every (i,j) pair
            if (relation[i][j] == 1 && relation[j][i] == 0) relation[j][i] = 1;
        }
    }

    printf("Symmetric closure: ");
    displayRelation(relation,n);
    freeRelation(relation,n);
}

void transitiveClosure(int **relation,int n) {
    // Using warshall algorithm
    relation = copyRelation(relation,n);
    for (int k=0;k<n;k++) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                // if transitive edge through k then add it to relation
                if (relation[i][k] == 1 && relation[k][j] == 1) relation[i][j] = 1;
            }
        }
    }

    printf("Transitive closure: ");
    displayRelation(relation,n);
    freeRelation(relation,n);
}

void takeInput(int **relation,int n) {
    char ch='y';
    while (ch == 'y' || ch == 'Y') {
        int x,y;
        printf("Enter pair (x,y): ");
        scanf("%d %d",&x,&y);
        if (x<0 || x>=n || y<0 || y>=n) printf("Invalid pair");
        else relation[x][y] = 1;
        printf("Do u want to continue(Y/y): ");
        scanf(" %c",&ch);
    }
}

int main() {
    int n;
    printf("Enter no of elements in set on which relation is: ");
    scanf("%d",&n);
    printf("Elements are from 0 to %d\n",n-1);
    int **relation = (int **)malloc(sizeof(int *)*n);
    for (int i=0;i<n;i++) relation[i] = (int *)malloc(sizeof(int)*n);
    takeInput(relation, n);
    printf("Relation is ");
    displayRelation(relation,n);
    reflexiveClosure(relation,n);
    symmetricClosure(relation,n);
    transitiveClosure(relation,n);
    return 0;
}