#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int pageFaults(int pages[], int n, int capacity)
{
    int s[MAX_SIZE] = {0};
    int indexes[MAX_SIZE] = {0};
    int page_faults = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (s[pages[i]] == 0)
        {
            if (capacity > 0)
            {
                s[pages[i]] = 1;
                capacity--;
                page_faults++;
                indexes[pages[i]] = i;
            }
            else
            {
                int min_index = i;
                int min_page = -1;
                for (j = 0; j < MAX_SIZE; j++)
                {
                    if (s[j] == 1 && indexes[j] < min_index)
                    {
                        min_index = indexes[j];
                        min_page = j;
                    }
                }
                s[min_page] = 0;
                s[pages[i]] = 1;
                page_faults++;
                indexes[pages[i]] = i;
            }
        }
    }
    return page_faults;
}

int main()
{
    int n, capacity, i;
    int pages[MAX_SIZE];
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the capacity: ");
    scanf("%d", &capacity);
    printf("Answer: %d\n", pageFaults(pages, n, capacity));
    return 0;
}
