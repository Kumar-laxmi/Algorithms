#include <stdio.h>

int main()
{
    int a[20], n, i, j, temp, k, s;

    // Taking size of array as input
    printf("ENTER THE SIZE OF ARRAY: ");
    scanf("%d", &n);

    // Taking array elements as input
    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ELEMENTS: ");
        scanf("%d", &a[i]);
    }

    // selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[smallest] > a[j])
            {
                smallest = j;
            }
        }

        // swapping
        int temp = a[smallest];
        a[smallest] = a[i];
        a[i] = temp;
    }

    // Printing sorted array
    printf("SORTED ARRAY: ");
    for (j = 0; j < n; j++)
    {
        printf("%d\t", a[j]);
    }
}