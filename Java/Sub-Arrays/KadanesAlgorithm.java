//Code contributed by Gourav Dutta(Github username: GouravDutta-01)
/* Kadanes Algorithm
-Finds Max Subarray Sum
-Based on Iterative Dynamic Programming
-Time Complexity = O(n) */
/* Approach-
1)We take two variables- currSum and maxSum.
2)We keep traversing through the array and add each array elements to currSum and update maxSum when maxSum>current currSum.
3)In any step if currSum<0 then we will update currSum=0.
4)After iterating through all elements of array,the obtained maxSum is the Max Subarray Sum.
5)For arrays with all negative numbers we returned the maximum negative number.If it was not done,then regular Kadane Algorithm would have given 0 as output */


public class KadanesAlgorithm{
    public static void main(String args[]){
        int nums1[] = {2,-4,-5,-7,9,1,-1,4,2,5};  //array input(example A:array with atleast one non-negative number)
        kadanesAlgo(nums1);
        int nums2[] = {-2,-4,-5,-7,-9,-1,-1,-4,-2,-5};  //array input(example B:array with all negative numbers)
        kadanesAlgo(nums2);
    }
    public static void kadanesAlgo(int arr[]){
        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;
        //Checking if array consist of negative numbers only
        boolean flag = true;
        int maxNum = Integer.MIN_VALUE;
        for(int k=0; k<arr.length; k++){
            if(arr[k]>=0){  //Breaking the loop if atleast one non-negative number found in array
                flag = false; //updating flag value
                break;
            }
            maxNum = Math.max(maxNum, arr[k]); //Storing the maximum negative number  
        }
        //Implementing Regular Kadane's Algorithm
        for(int i=0; i<arr.length; i++){
            currSum += arr[i];
            if(currSum < 0){
                currSum = 0;
            }
            maxSum = Math.max(currSum, maxSum);
        }
        if(flag == false){  //for array containing atleast one non-negative number 
            System.out.println("Obtained Max Subarray Sum : " + maxSum); 
        }
        else{  //for array containing all negative numbers
            System.out.println("Obtained Max Subarray Sum : " + maxNum);  //Returning Max Negative Number as Max Subarray Sum 
        }
    }
}



