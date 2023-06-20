#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int pageFaults(int pages[], int n, int capacity) {
    int s[capacity];
    int indexes[capacity];
    int page_faults = 0;

    // Initialize set and indexes array with -1
    for (int i = 0; i < capacity; i++) {
        s[i] = -1;
        indexes[i] = -1;
    }

    // Start from initial page
    for (int i = 0; i < n; i++) {
        // Check if the set can hold more pages
        if (i < capacity) {
            // Insert it into set if not present already, which represents page fault
            int j;
            for (j = 0; j < capacity; j++) {
                if (s[j] == pages[i]) {
                    break;
                }
                if (s[j] == -1) {
                    s[j] = pages[i];
                    page_faults++;
                    break;
                }
            }
            indexes[pages[i]] = i;
        }
        // If the set is full, then need to perform LRU
        else {
            // Check if current page is not already present in the set
            int found = 0;
            for (int j = 0; j < capacity; j++) {
                if (s[j] == pages[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                int lru = INT_MAX;
                int val;
                for (int j = 0; j < capacity; j++) {
                    if (indexes[s[j]] < lru) {
                        lru = indexes[s[j]];
                        val = s[j];
                    }
                }
                // Remove the least recently used page
                for (int j = 0; j < capacity; j++) {
                    if (s[j] == val) {
                        s[j] = pages[i];
                        break;
                    }
                }
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }

    return page_faults;
}

int main() {
    int n;
    printf("Enter the length of array: ");
    scanf("%d", &n);

    int* pages = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    int capacity;
    printf("Enter the capacity: ");
    scanf("%d", &capacity);

    printf("Answer: %d\n", pageFaults(pages, n, capacity)-1);

    free(pages);
    return 0;
}
