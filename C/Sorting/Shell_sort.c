#include<stdio.h>
#include<stdlib.h>

void ShellSort(int A[],int n)
{
    int i,j,gap;int temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)//shifting elements
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;

        }
    }
}
int main()
{
    int A[10],n=10,i;
    printf("Enter elements to be sorted using shell sort\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    ShellSort(A,n);
    printf("The elements in sorted order are displayed as:-\n");
    for(int i=0;i<10;i++)
        printf("%d\n",A[i]);// printing elements in sorted order
    printf("\n");
    return 0;
}
