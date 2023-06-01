/*Given a rod of length n and a list of rod prices of length i, where 1 <= i <= n, find the optimal way to cut the rod into smaller rods to maximize profit.*/

// A Dynamic Programming solution for Rod cutting problem
#include <limits.h>
#include <stdio.h>
 
// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
    int val[n + 1];
    val[0] = 0;
    int i, j;
 
    // Build the table val[] in bottom up manner and return the last entry
    // from the table
    for (i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (j = 0; j < i; j++)
            max_val = max(max_val, price[j] + val[i - j - 1]);
        val[i] = max_val;
    }
 
    return val[n];
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d", cutRod(arr, size));
    getchar();
    return 0;
}