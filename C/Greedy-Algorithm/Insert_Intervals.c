/*
Name: Aryaman Singh
Repository name: Algorithms

Problem Statement: Given a sorted array of non-overlapping intervals where intervals[i]=[starti,endi] and a new interval=[start,end], insert the new interval 
into the array while maintaining the sort order and ensuring that there are no overlapping intervals. Return the updated array after the insertion.

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
*/

#include <stdio.h>
#include <stdlib.h>

// Function for inserting the new interval
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    // new 2D array named ans that will store the final intervals after inserting
    int** ans = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnSize = 0;
    
    int i = 0;

    // it starts a loop that iterates over the intervals array from index 0 to index intervalsSize-1.
    for (i = 0; i < intervalsSize; i++) {
        // if the end of the current interval (intervals[i][1]) is less than the start of the new interval (newInterval[0]), it means there is no overlap,
        // so the current interval is added to the ans array.
        if (intervals[i][1] < newInterval[0]) {
            ans[*returnSize] = (int*)malloc(2 * sizeof(int));
            ans[*returnSize][0] = intervals[i][0];
            ans[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }

        // if the start of the current interval (intervals[i][0]) is greater than the end of the new interval (newInterval[1]), it means there is no overlap,
        // so the new interval is added to the ans array, and the new interval is updated to the current interval.
        else if (intervals[i][0] > newInterval[1]) {
            ans[*returnSize] = (int*)malloc(2 * sizeof(int));
            ans[*returnSize][0] = newInterval[0];
            ans[*returnSize][1] = newInterval[1];
            (*returnSize)++;

            newInterval[0] = intervals[i][0];
            newInterval[1] = intervals[i][1];
        }

        // if there is an overlap between the current interval and the new interval. It updates the start of the new interval to the minimum value
        // between the current start and new start, and updates the end of the new interval to the maximum value between the current end and new end.
        else {
            newInterval[0] = (newInterval[0] < intervals[i][0]) ? newInterval[0] : intervals[i][0];
            newInterval[1] = (newInterval[1] > intervals[i][1]) ? newInterval[1] : intervals[i][1];
        }
    }

    // it adds the final merged interval (new interval) to the ans array.
    ans[*returnSize] = (int*)malloc(2 * sizeof(int));
    ans[*returnSize][0] = newInterval[0];
    ans[*returnSize][1] = newInterval[1];
    (*returnSize)++;

    // Setting column size for returnColumnSizes
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return ans;
}

// Main function
int main() {
    int intervalsSize = 5;
    int intervalsColSize = 2;
    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    intervals[0] = (int*)malloc(intervalsColSize * sizeof(int));
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1] = (int*)malloc(intervalsColSize * sizeof(int));
    intervals[1][0] = 3;
    intervals[1][1] = 5;
    intervals[2] = (int*)malloc(intervalsColSize * sizeof(int));
    intervals[2][0] = 6;
    intervals[2][1] = 7;
    intervals[3] = (int*)malloc(intervalsColSize * sizeof(int));
    intervals[3][0] = 8;
    intervals[3][1] = 10;
    intervals[4] = (int*)malloc(intervalsColSize * sizeof(int));
    intervals[4][0] = 12;
    intervals[4][1] = 16;

    int newIntervalSize = 2;
    int* newInterval = (int*)malloc(newIntervalSize * sizeof(int));
    newInterval[0] = 4;
    newInterval[1] = 8;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** final = insert(intervals, intervalsSize, &intervalsColSize, newInterval, newIntervalSize, &returnSize, &returnColumnSizes);

    int i, j;
    for (i = 0; i < returnSize; i++) {
        printf("{");
        for (j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", final[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("}\n");
    }

    // Free memory
    for (i = 0; i < intervalsSize; i++) {
        free(intervals[i]);
    }
    free(intervals);
    free(newInterval);

    for (i = 0; i < returnSize; i++) {
        free(final[i]);
    }
    free(final);
    free(returnColumnSizes);

    return 0;
}







