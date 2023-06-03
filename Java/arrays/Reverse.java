//Time Complexity: O(n)

// java program to reverse an array
public class Reverse {
      
   // Function to reverse arr[] from start to end
    static void reverseArray(int arr[], int start, int end)
    {
        int temp;
        while (start < end)
        {
            temp = arr[start]; 
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        } 
    }     
       
    // Function to print an array
    static void printArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
             System.out.print(arr[i] + " ");
         System.out.println();
    } 
  
    //Sample Input-Output
    public static void main(String args[]) {
          
        int array[] = {1, 2, 3, 4, 5, 6};
        System.out.print("Original array is: \n");
        printArray(array, 6);
        reverseArray(array, 0, 5);
        System.out.print("Reversed array is: \n");
        printArray(array, 6); 
         
    }
}
