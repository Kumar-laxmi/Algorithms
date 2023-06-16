//O(n) time | O(n) space
#include <iostream>
#include <unordered_set>
using namespace std;

bool zeroSumSubarray(int nums[], int n) {
    unordered_set<int> sums; // Set to store cumulative sums
    int currentSum = 0; // Variable to store the current sum
    for (int i = 0; i < n; i++) {
        currentSum += nums[i]; // Add the current number to the current sum
        if (currentSum == 0 || sums.count(currentSum) || nums[i] == 0) {
            // If current sum is zero or already exists in the set, or the current number is zero,
            // then there is a zero sum subarray
            return true;
        }
        sums.insert(currentSum); // Add the current sum to the set
    }
    return false; // No zero sum subarray found
}

int main() {
    int nums[] = { 4, 2, -3, 1, 6 };
    int n = sizeof(nums) / sizeof(nums[0]);

    if (zeroSumSubarray(nums, n)) {
        cout << "Subarray with zero sum exists";
    } else {
        cout << "Subarray with zero sum does not exist";
    }
    return 0;
}
