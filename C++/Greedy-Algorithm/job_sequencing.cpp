#include<bits/stdc++.h>
using namespace std;

bool static comp(vector<int> &a, vector<int> &b) {      //custom comparator to sort the array 
    return a[2] > b[2];                                 //with respect to profit
}

int jobScheduling(vector<vector<int>> &arr, int n) {

    sort(arr.begin(), arr.end(), comp);     //sorting the array on the basis of profit
        
    int maxi = INT_MIN;     //finding the max deadline
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i][1]);
    }

    vector<int> jobSeq(maxi+1, -1);     //initialising the jobSeq array with -1 to find the 1st 
    int profit = 0;                     //spot which is empty

    for(int i = 0; i < n; i++) {
        for(int j = arr[i][1]; j > 0; j--) {    //traversing the array from back side and filling 
            if(jobSeq[j] == -1) {               //the first empty position eith that job ID
                jobSeq[j] = arr[i][0];
                profit += arr[i][2];
                break;
            }
        }
    }
    return profit;      //returning the max profit
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(3));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin>>arr[i][j];             //taking input as {JobID, Deadline, Profit}
        }
    }
    cout<< jobScheduling(arr, n) <<endl;    //printing the maximum profit
    return 0;
}