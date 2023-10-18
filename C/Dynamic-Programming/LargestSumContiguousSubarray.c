#include <stdio.h>

int maxSubArraySum(int arr[], int size) {
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];
    
    for (int i = 1; i < size; ++i) {
        maxEndingHere = (arr[i] > maxEndingHere + arr[i]) ? arr[i] : maxEndingHere + arr[i];
        maxSoFar = (maxEndingHere > maxSoFar) ? maxEndingHere : maxSoFar;
    }
    
    return maxSoFar;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubArraySum(arr, size);
    printf("Maximum contiguous sum is %d\n", maxSum);
    return 0;
}
