/*
PROBLEM STATEMENT : Perform an order-agnostic binary search on a sorted array. The only way it is different from a regular binary search is that we don't know whether the array is sorted in sorted in descending or ascending order.

INPUT FROM USER :
 * arr -> The sorted array to search in.
 * n -> The total number of elements inside the array.
 * key -> The value to search for.

OUTPUT :
* Print the index of the key value in the array if found, -1 otherwise. 


PREREQUISITE : The function assumes that the input array is sorted in either ascending or descending order. If the array is not sorted , the program may not produce correct results.

COMPLEXITY :
*Time Complexity : O(log(n))
*Space Complexity : O(1)

PSEUDOCODE :
1. Input the array from the user.
2. Input the key to be searched inside the array.
3. Call the function order_agnostic_binary_search() with the array, size of the array and the key as the parameters.
4. The function order_agnostic_binary_search() will determine whether the array is sorted in ascending or descending order and then call the appropriate function for each case.
5.(A) The function ascending_binary_search() will perform binary search on the array if it is sorted in ascending order.
5.(B) The function descending_binary_search() will perform binary search on the array if it is sorted in descending order.
6. Store the result returned by the function order_agnostic_binary_search() in a variable 'result'.
7. If the value of 'result' is -1, print "Target value not found in the array.".
8. Else print the index at which the key to search for is found in the array.
*/

import java.util.Scanner;

public class Order_Agnostic_Binary_Search {
    public static int orderAgnosticBinarySearch(int[] arr, int target) {
        // Determine the order (ascending or descending) based on the first two elements
        boolean isAscending = arr[0] <= arr[1];

            if (isAscending) {
                return ascending_binary_search(arr, target);
            } else {
                return descending_binary_search(arr, target);
            }
    }

    public static int ascending_binary_search(int[] arr, int target){
        int left = 0;
        int right = arr.length - 1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1; // Target value not found in the array
    }

    public static int descending_binary_search(int[] arr, int target){
        int left = 0;
        int right = arr.length - 1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1; // Target value not found in the array
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] arr = new int[size];
        System.out.println("Enter the array elements in sorted order:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the target value to search: ");
        int target = scanner.nextInt();


        int result = orderAgnosticBinarySearch(arr, target);

        if (result == -1) {
            System.out.println("Target value not found in the array.");
        } else {
            System.out.println("Target value found at index: " + result);
        }

        scanner.close();
    }
}

