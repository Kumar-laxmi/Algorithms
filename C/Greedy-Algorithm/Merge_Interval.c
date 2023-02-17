/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
//Problem Statement : Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
//and return an array of the non-overlapping intervals that cover all the intervals in the input.
// C program to merge overlapping Intervals in
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// An Interval
typedef struct IntL {
    int x, z;
} Interval;
// Function used in sort
int mp(const void* a, const void* b)
{
    Interval* data_1 = (Interval*)a;
    Interval* data_2 = (Interval*)b;
    return (data_1->x - data_2->x);
}
// Find maximum between two numbers.
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
void MI(Interval arr[], int n)
{
    // Sort Intervals in increasing order of
    // start time
    qsort(arr, n, sizeof(Interval), mp);
    int index = 0; // Stores index of last element
    // in output array (modified arr[])
    // Traverse all input Intervals
    for (int i = 1; i < n; i++) {
        // If this is not first Interval and overlaps
        // with the previous one
        if (arr[index].z >= arr[i].x) {
            // Merge previous and current Intervals
            arr[index].z = max(arr[index].z, arr[i].z);
        }
        else {
            index++;
            arr[index] = arr[i];
        }
    }
    // Now arr[0..index-1] stores the merged Intervals
    printf("\n The Merged Intervals are: ");
    for (int i = 0; i <= index; i++)
        printf("[%d, %d]", arr[i].x, arr[i].z);
}
// Driver program
int main()
{
    Interval arr[]
        = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    MI(arr, n);
    return 0;
}