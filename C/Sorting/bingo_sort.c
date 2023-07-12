#include <stdio.h>

void bingoSort(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    int *flags = (int *)calloc(max - min + 1, sizeof(int));
    for (i = 0; i < n; i++)
        flags[arr[i] - min] = 1;
    int index = 0;
    for (i = 0; i < max - min + 1; i++)
    {
        if (flags[i])
        {
            arr[index] = i + min;
            index++;
        }
    }
    free(flags);
}

int main()
{
    printf("Enter the length of the array: ");
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    bingoSort(a, n);
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}
