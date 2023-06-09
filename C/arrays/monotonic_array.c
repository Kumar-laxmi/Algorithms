#include <stdio.h>
#include <stdbool.h>

bool isMonotonic(int nums[], int n) {
    int s = 0, e = n - 1;
    while (s < e) {
        if (nums[s] <= nums[s + 1] && nums[s] <= nums[e] && e == n - 1) {
            s++;
        }
        else if (nums[e] <= nums[e - 1] && nums[e] <= nums[s] && s == 0) {
            e--;
        }
        else {
            break;
        }
    }
    if (s == n - 1 || e == 0) {
        return true;
    }
    return false;
}

int main() {
    int n;
    printf("enter no of elements in array: ");
    scanf("%d", &n);

    int nums[n];
    printf("enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (isMonotonic(nums, n)) {
        printf("the array is monotonic\n");
    }
    else {
        printf("the array is not monotonic\n");
    }

    return 0;
}
// MONOTONIC ARRAY IN C
// This Program Tells if an array is monotonic or not.
