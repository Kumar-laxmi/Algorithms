#include <stdio.h>

// macro defining maximum capacity of the array
#define MAX 100

// this function is returning the value which is greater in between a and b.
int max_getter(int a, int b)
{
    return a >= b ? a : b;
}

// returning the maximum subarray sum
int kadanes_algo(int n, int arr[])
{
    // maximum subarray sum is denoted by max_sum
    int max_sum = -1e9;

    // sum so far is stored in curr_sum
    int curr_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        // adding arr[i] to the curr_sum
        curr_sum += arr[i];

        // if max_sum is greater than curr_sum then we are updating max_sum
        max_sum = max_getter(curr_sum, max_sum);

        // if curr_sum < 0 we are making it 0 again.
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }

    // retunrning maximum subarray sum
    return max_sum;
}

int main()
{
    // declaring n -> number of elements in the array and array having capacity of MAX elements
    int n, arr[MAX];
    printf("Enter the number of elements in the array\n");
    // taking input the number of elements
    scanf("%d", &n);

    // taking input the elemnets of the array
    printf("Enter the elements in the array\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    // calling function kadanes_algo to get maximum subarray sum
    printf("Maximum subarray sum is: %d", kadanes_algo(n, arr));

    return 0;
}
