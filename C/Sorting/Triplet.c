/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
// Problem Statement: C++ program to find find the minimum number of jumps to reach the other end of the array starting from the 0th index. 
// And if the end isn’t reachable, return -1 as the output.
//Example:Given an array and a value, find if there is a triplet in the array whose sum is equal to the given value. 
If there is such a triplet present in the array, then print the triplet and return true. Else return false.
EXAMPLES:
1] Input: array = { 7, 10, 6, 14, 4, 9 }, sum = 25;
Output: Triplet is 4, 7, 14 */
// C program to find a triplet
#include <stdio.h>
#include <stdlib.h>
// function that prints triplets
int Triplet(int A[], int arr_size, int sum)
{
    int x, y;
    // Sort the elements of the array in ascending order
    qsort(A, arr_size, sizeof(int), cmpfunc);
    // Fix the first element of the triplet and find all other possible elements
    for (int i = 0; i < arr_size - 2; i++) 
    {
        // For the other two elements, start two index variables from two ends of the array and move them toward each other
        x = i + 1; // index of the first element of the remaining elements
        y = arr_size - 1; // index of the last element
        while (x < y) 
		{
            // If the triplet's sum equals the given sum, print it and return 1
            if (A[i] + A[x] + A[y] == sum) 
            {
                printf("Triplet is %d, %d, %d\n", A[i], A[x], A[y]);
                return 1;
            }
            // If the triplet's sum is less than the given sum, move the left pointer to the right
            else if (A[i] + A[x] + A[y] < sum)
                x++;
            // If the triplet's sum is greater than the given sum, move the right pointer to the left
            else
                y--;
        }
    }
    // If no triplet is found, return 0
    return 0;
}
// Comparison function used by qsort to sort the array in ascending order
int cmpfunc(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
// Main function
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter %d integers in the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int sum;
    printf("Enter the sum value: ");
    scanf("%d", &sum);
    int arr_size = sizeof(A) / sizeof(A[0]);
    Triplet(A, arr_size, sum);
    return 0;
}
