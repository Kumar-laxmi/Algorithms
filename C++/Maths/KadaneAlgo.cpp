#include<iostream>
#include<stdio.h>
using namespace std;

// function implementing Kadane's Algorithm
int maxSum(int *ar, int *n) {
    int maxSum = INT_MIN, maxSumCurrIdx = 0;
    for(int i = 0; i < *n; i++) {
        maxSumCurrIdx += ar[i];
        maxSum = maxSum < maxSumCurrIdx ? maxSumCurrIdx : maxSum;
        maxSumCurrIdx = maxSumCurrIdx < 0 ? 0 : maxSumCurrIdx;
    }
    return maxSum;
}

int main() {
    // input code
    int n, sum;
    cout << "Enter array size : ";
    cin >> n;
    cout << "\nEnter array elements : ";
    int ar[n];
    for(int i = 0; i < n; i++) scanf("%d", &ar[i]);

    // function call & output
    cout << "Max Sum : " << maxSum(ar, &n);
    return 0;
}
