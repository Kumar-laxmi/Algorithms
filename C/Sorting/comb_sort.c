#include <stdio.h>
#include <stdbool.h>

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int a[], int n)
{
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                int temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
                swapped = true;
            }
        }
    }
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
    combSort(a, n);
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}
