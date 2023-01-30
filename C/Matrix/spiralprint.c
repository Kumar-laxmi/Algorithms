#include <stdio.h>
#include <malloc.h>

// Spiral traversal of matrices / 2D arrays

// The algorithm starts from the top left corner of the array, and traverses the first row from left to right. Once it traverses the whole row it does not need to revisit it, thus, it increments the top corner index.
// Once complete, it traverses the rightmost column top to bottom. Again, once this completes, there is no need to revisit the rightmost column, thus, it decrements the right corner index.
// Next, the algorithm traverses the bottommost row and decrements the bottom corner index afterward.
// Lastly, the algorithm traverses the leftmost column, incrementing the left corner index once it’s done.

void spiralPrint(int **matrix,int m,int n) {
    int i=0,j=0,num=1;
    int counter1=n,counter2=m;
    while (counter1 > 0 || counter2>0) {
        if (m == n && counter1==1) {
            printf("%d ",matrix[n/2][n/2]);
        } else {
            int k;
            for (k=1;k<counter1;k++) {
                printf("%d ",matrix[i][j++]);
            }
            for (k=1;k<counter2;k++) {
                printf("%d ",matrix[i++][j]);
            }
            for (k=1;k<counter1;k++) {
                printf("%d ",matrix[i][j--]);
            }
            for (k=1;k<counter2;k++) {
                printf("%d ",matrix[i--][j]);
            }
            i++;j++;
        }
        counter1-=2;
        counter2-=2;
    }
}

int main() {
    int m,n;
    printf("Enter no of rows and columns: ");
    scanf("%d %d",&m,&n);

    int **matrix = (int **)malloc(sizeof(int *)*m);
    for (int i=0;i<m;i++) {
        matrix[i] = (int *)malloc(sizeof(int)*n);
        printf("Enter elements of row %d: ",i+1);
        for (int j=0;j<n;j++) {
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("Spiral Traversal looks like: ");
    spiralPrint(matrix,m,n);
    
    printf("\n");
    return 0;
}