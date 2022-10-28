#include<stdio.h>
#include <conio.h>

void floyd_warshall(int a[][6])
{
    int i, j, k;
    for (k = 0; k < 6; k++)
    {
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if ((a[i][k] * a[k][j] != 0) && (i != j))
                {
                    if ((a[i][k] + a[k][j] < a[i][j]) || (a[i][j] == 0))
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < 6; i++)
    {
        printf("\nMINIMUM COST WITH RESPECT TO NODE: ",i,"\n");
        for (j = 0; j < 6; j++)
        {
            printf(a[i][j],"\t");
        }
 
    }
}
int main()
{

    int a[6][6];

    printf("---------ENTER VALUES OF ADJACENCY MATRIX------------\n\n");
    for (int i = 0; i < 6; i++)
    {
        printf("ENTER THE VALUES FOR ",(i+1)," ROW: \n");
        for (int j = 0; j < 6; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    floyd_warshall(a);
    getch();
}