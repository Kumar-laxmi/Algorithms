//Problem statement :- Calculate Interquartile range from given number series 

package Java.Maths;
import java.io.*;
import java .util.*;

public class Interquartile_range {
    
      
    public static void main(String[] args) {

        System.out.println("Enter the size \n");
         Scanner sc = new Scanner(System.in);

        int n;
        n=sc.nextInt();

        int [] arr = new int[n];
        
        System.out.println("Enter elements");

        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }

        Arrays.sort(arr);
        
        int start = 0  , last = n-1;  // we assign 0 and n-1 as the index value for start and last index

        int Quartile1 , Quartile2 , Quartile3;

        int mid = (last - start)/2;   // Here we calculate median of our series

        System.out.println("Median of series as Quartile2 : "+ arr[mid]);

        Quartile1 =arr[(mid-0)/2];  //Here we calculate first half Quartile

        System.out.println("The Median of first half as Quartile1 : "+Quartile1);
  
        Quartile3 = arr[mid+1+(last-mid)/2];   //Here we calculate second half Quartile

        System.out.println("The Median of Second half as Quartile3 : "+Quartile3);

        System.out.println("The IQR value is "+(Quartile3 - Quartile1));
    }

}


// Case 1: INPUt :- 1  3  5  2  4  6

//        OUTPUT:- Median of series as Quartile2 : 3
//                 The Median of first half as Quartile1 : 2
//                 The Median of second half as Quartile2 : 5
//                 The IQR value is : 3
