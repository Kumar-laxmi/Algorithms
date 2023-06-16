//O(n) time | O(n) space
#include <stdio.h>
#include <stdbool.h>

bool zeroSumSubarray(int nums[], int n) {
    int sums[n]; // Array to store cumulative sums
    int currentSum = 0; // Variable to store the current sum
    for (int i = 0; i < n; i++) {
        currentSum += nums[i]; // Add the current number to the current sum
        if (currentSum == 0) {
            // If current sum is zero, then there is a zero sum subarray
            return true;
        }
        for (int j = 0; j < i; j++) {
            if (sums[j] == currentSum) {
                // If current sum already exists in the array, then there is a zero sum subarray
                return true;
            }
        }
        sums[i] = currentSum; // Store the current sum in the array
    }
    return false; // No zero sum subarray found
}

int main() {
    int nums[] = { 4, 2, -3, 1, 6 };
    int n = sizeof(nums) / sizeof(nums[0]);

    if (zeroSumSubarray(nums, n)) {
        printf("Subarray with zero sum exists\n");
    } else {
        printf("Subarray with zero sum does not exist\n");
    }
    return 0;
}
