/*
    Binary Search is usally done on a 1D array but there can be multiple approaches to conduct a binary search in a 2D array. For eg,
    1. Convert the 2D array into a 1D array and conduct the search. 
        Time Complexity: O(Logm+Logn)
        Space Complexity: O(m+n)

    2. Another efficient approach is to virtualize the 2D array into a 1D array by using % and / operators to determine the indexes, and then 
        apply Binary Search in that virtual 1D array. 
        The following code follows this approach.
        Time Complexity: O(Logmn)
        Space Complexity : O(1).
*/
import java.util.*;
class Binary_search_2D_Matrix
{
    boolean searchBinary(int[][] arr,int target){
        int row=arr.length;
        int col=arr[0].length;

        int s=0;
        int e=row*col-1;

        int mid=s+(e-s)/2;

        while(s<=e){
            int element= arr[mid/col][mid%col];//[mid/c][mid%c] will give the middle index of the virtual 1D array 
    
            if(target==element) return true;//If found return true
    
            else if(target > element) s=mid+1;//Target is in the lower half of the matrix so starting index updates.
    
            else e=mid-1; // Target is in the upper half of the matrix so ending index updates.
    
            mid=s+(e-s)/2;// Updating the middle value to the updated starting and ending indexes.
        }
        return false;
    }
    public static void main(String[] args) {
        Binary_search_2D_Matrix obj = new Binary_search_2D_Matrix();
        Scanner sc= new Scanner(System.in);
        //Dimension input from the user
        System.out.println("Enter the dimensions of the matrix: ");
        int r=sc.nextInt();
        int c=sc.nextInt();
        int arr[][]=new int[r][c];

        System.err.println("Enter the elements: ");
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr[i][j]=sc.nextInt();
            }
        }
        System.out.println("Enter the element to be searched : ");
        int target=sc.nextInt();

        boolean ans=obj.searchBinary(arr, target);
        // If found then the function will return true
        if(ans){
            System.err.println("Element found");
        }
        else{
            System.out.println("Element not found");
        }
        sc.close();
    }
}