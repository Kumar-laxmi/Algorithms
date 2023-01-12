/* 
    𝗕𝗼𝘆𝗲𝗿-𝗠𝗼𝗼𝗿𝗲 𝗠𝗮𝗷𝗼𝗿𝗶𝘁𝘆 𝗩𝗼𝘁𝗶𝗻𝗴 𝗔𝗹𝗴𝗼𝗿𝗶𝘁𝗵𝗺

    This algorithm helps us to find the Majority Element that occurs more than N/2 times

    Suppose, 
    Input: nums[] = {2,2,1,1,1,2,2} with N(size as 7)  (𝗮𝘀𝘀𝘂𝗺𝗶𝗻𝗴: 𝘁𝗵𝗲𝗿𝗲 𝗶𝘀 𝗮 𝗺𝗮𝗷𝗼𝗿𝗶𝘁𝘆 𝗲𝗹𝗲𝗺𝗲𝗻𝘁)

    • N/2: 7/2 → 3 (floor value is taken) 
    • Count of 2 in nums → 4 (2 occurs more than 2 times( > N/2 times) thus 2 is the majority element)
    • Count of 1 in nums → 3


    Moore’s Voting Algorithm solves this problem in the most optimal way i.e. Time Complexity= O(N), Space Complexity= O(1)

    The algorithm works in two parts:
    The first pass finds an element as the majority element and a second pass is used to verify that the element found in the first pass is a majority.
    
    -------------------
    𝗔𝗽𝗽𝗿𝗼𝗮𝗰𝗵 𝗼𝗳 𝘀𝗼𝗹𝘃𝗶𝗻𝗴: 

    1. Initialize 2 variables: 
        1. Count –  for tracking the count of element
        2. Element – for which element we are counting

    2. Traverse through the nums array.
        1. If Count is 0 then initialize the current traversing integer of the array as Element 
        2. If the traversing integer of the array and Element is the same, increase the Count by 1
        3. If they are different decrease the Count by 1

    3. The integer present in Element is the result we are expecting 

    
    𝗕𝗮𝘀𝗶𝗰 𝗜𝗻𝘁𝘂𝗶𝘁𝗶𝗼𝗻: Since we know that if the candidate is in majority, it occurs more than N/2 times thus the remaining elements definitely occurs less than N/2 times
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMajorityElement(vector<int>& nums) {
        int count= 0;       // 1st step 
        int element= 0;     // 1st step

        for (int num: nums) {   // traversing the vector
            if (count == 0) {   // this means that there are an equal number of occurrences for different elements, which should not be the case for the element to be the majority one 
                element= num;   // hence we select the present element as the majority element and continue the same till all elements are finished
            }
            if(num == element) count += 1;  // increase count if the present element is the same as the selected majority element
            else count -= 1;    // we decrease the count since we get the occurrence of any other element, according to the intuition
        }

        // we don't need to check whether the selected majority element occurs more than 2 times since we have assumed there is a majority element in the given input
        return element;
    }
};

// Main Function --> Driver code

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);     // Note: there must be a majority element
    for(auto &it: arr){      // Use this as sample input: 7 2 2 1 1 1 2 2 
      cin >> it;
    }

    Solution s1;            // creating obj of class Solution

    int majorityElement = s1.findMajorityElement(arr);  
    
	  cout<<"\nMajority element is "<<majorityElement;

    return 0;
}
