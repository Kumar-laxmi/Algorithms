import java.util.Scanner;

/*
<----------------------------------PROBLEM------------------------------------>
Given an array arr[] of n elements, write a function to search a given element el in arr[].

Variables used:
n = total number of elements in array
arr = array initialized with the input size
el = element to be searched in the array. 
*/

class linear_search {
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
            for (int i = 0; i < n; i++) {
                if (arr[i] == el){
                    flag=true;
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
