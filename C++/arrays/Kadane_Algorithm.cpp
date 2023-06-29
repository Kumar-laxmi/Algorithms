/*
 ---------------------------------------------- Problem Statement --------------------------------------------------------
    Given an integer array nums, find the subarray  with the largest sum, and return its sum.
    
    Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.
    
    Example 2:
    Input: nums = [1]
    Output: 1
    Explanation: The subarray [1] has the largest sum 1.
    
    Example 3:
    Input: nums = [5,4,-1,7,8]
    Output: 23
    Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 ---------------------------------------------- Constraints --------------------------------------------------------
    1<= nums.length <= 105
    -10^4 <= nums[i] <= 10^4

 ------------------------------------------------- Complexities ----------------------------------------------------------

    Time Complexity  :- BigO(n) --> where n is the number of elements in input array
    Space Complexity :- BigO(1)

 ------------------------------------------------- Algorithm ----------------------------------------------------------
 The Kadane's algorithm is an efficient algorithm for finding the maximum subarray sum in a given array of numbers. 
 It was proposed by Jay Kadane in 1984. The algorithm has a time complexity of O(n), where n is the size of the array.

*/

#include<iostream>
#include<vector>
using namespace std;



int max_sum_subarray(vector<int>&vec){  // Kadane Algorithm
    int curr_sum = 0;    
    int max_sum = vec[0];
    for(int i=0; i<vec.size(); i++){
        curr_sum += vec[i]; // Add the current element to the current sum
        
        max_sum = max(max_sum, curr_sum); // Update the maximum sum if the current sum is greater

        curr_sum = max(curr_sum, 0); // If the current sum becomes negative, reset it to 0
        }

    return max_sum;  // Maximum sum of subarray 
}

int main() {
    

    vector<int>vec{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    cout<<max_sum_subarray(vec);


    return 0;
}