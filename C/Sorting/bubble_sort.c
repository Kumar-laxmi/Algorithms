#include <stdio.h>

int main()
{
    int a[20], n, i, j, temp, k, s;

    
    printf("ENTER THE SIZE OF ARRAY: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ELEMENTS: ");
        scanf("%d", &a[i]);
    }

    for (s = 0; s < n - 1; s++)
    {

        for (k = 0; k < n - 1; k++)
        {
            if (a[k] > a[k + 1])
            {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }

    for (j = 0; j < n; j++)
    {
        printf("%d\t", a[j]);
    }
}