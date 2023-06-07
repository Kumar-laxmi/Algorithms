#include <iostream>
#include <climits>
using namespace std;

int minJumps(int arr[], int n) {
    // Create an array to store the minimum number of jumps required to reach each position
    int dp[n];

    // Initialize all values in dp[] to infinity except the first position
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
    }

    // Calculate the minimum number of jumps required for each position
    for (int i = 1; i < n; i++) {
        // Check all positions before the current position to find the minimum jumps
        for (int j = 0; j < i; j++) {
            // If it is possible to reach the current position from position j
            if (j + arr[j] >= i) {
                // Update the minimum jumps required if a smaller value is found
                if (dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }

    // If the last element in dp[] is still infinity, it means it is not reachable
    // Otherwise, return the minimum number of jumps required to reach the end
    if (dp[n - 1] == INT_MAX) {
        return -1; // Not reachable
    } else {
        return dp[n - 1];
    }
}

int main() {
    int arr[] = {2, 3, 1, 1, 4}; // Example input array
    int n = sizeof(arr) / sizeof(arr[0]);

    int minJumpsRequired = minJumps(arr, n);

    cout << "Minimum number of jumps required: " << minJumpsRequired << endl;

    return 0;
}
