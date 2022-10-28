import java.util.Scanner;

/*
<----------------------------------PROBLEM------------------------------------>
Given a sorted array arr[] of n elements, write a function to search a given 
element x in arr[] and return the index of x in the array.

Variables used:
n = total number of elements in array.
arr = array initialized with the input size.
el = element to be searched in the array.
lt = left-most index of the search space.
rt = right-most index of the search space. 
*/

class binary_search {
    public static void main(String args[])
	{
        int n;
        int el;
        // Flag variable to keep a check if the element is found till then.
        boolean flag=false;
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Total no. of elements in array: ");
            n = s.nextInt();

            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = s.nextInt();
            }

            el = s.nextInt();
            int lt=0;
            int rt=n-1;
            while (lt<=rt) {
                // in order to prevent overflow of `int`, it has been written lt + (rt-lt)/2 instead of (lt+rt)/2;
                int mid = lt + (rt-lt)/2;
                // element is equal to mid, return the index
                if (arr[mid]==el) {
                    flag=true;
                    break;
                } 
                // element is larger than mid, then shift search space to right.
                else if (arr[mid]<el) {
                    lt = mid + 1;
                }
                // element is smaller than mid, then shift search space to left. 
                else{
                    rt = mid - 1;
                }
            }
            
            if(flag){
                System.out.println("Element found:)");
            }
            else{
                System.out.println("Element not found:(");
            }
        }		
	}
}
