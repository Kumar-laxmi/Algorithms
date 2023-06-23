/**----------------------------------------------Introduction---------------------------------------------------------------------------
 * The Exponential_search class provides an implementation of the exponential search algorithm in Java.
 * It can be used to search for an element in a sorted array.
 */

 /*----------------------------------------------Algorithm------------------------------------------------------------------------------
  * The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until 
  last element of a subarray is not greater. Once we find an index i (after repeated doubling of i), we know that the
   element must be present between i/2 and i
  */
  import java.util.*;
public class Exponential_search {

    /**
     * Performs binary search within a specified range of a sorted array.
     *
     *  arr    The sorted array to be searched.
     * target The element to be searched for.
     *  left   The left boundary of the search range.
     *  right  The right boundary of the search range.
     *  The index of the target element if found, otherwise -1.
     */
    private static int binarySearch(int[] arr, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Element not found
    }

    /*
     fuction to perform exponential search.
     */
    public static int exponentialSearch(int[] arr, int target) {
        if (arr[0] == target) {
            return 0;
        }

        int n = arr.length;
        int i = 1;
        while (i < n && arr[i] <= target) {
            i *= 2;//jumps to the two timed index.
        }

        return binarySearch(arr, target, i / 2, Math.min(i, n - 1));
    }



    /*
      A sample usage of the Exponential_search class to perform exponential search.
     */
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       int temp=0;
       System.out.println("Enter the number of elements:");
        int n = sc.nextInt();
         int[]arr=new int[n];
            // values of  array
            System.out.println("Enter the elements of  array:");
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
           for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j<arr.length;j++){
               if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
             }
           }
           }

        System.out.println("Enter the target element:");
        int target = sc.nextInt();

        int result = exponentialSearch(arr, target);
        if (result == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at index " + result);
        }
    }
}