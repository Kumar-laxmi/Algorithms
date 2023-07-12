/*
------------------------------------- Lucas Lehmer Series -------------------------------------

Approach
1. In this series, 4 is the starting term i.e., 0th term

2. By considering 4 as the 0th terms, then calculate the nth term of lucas-lehmer series.

3. To calculate the nth term use the formula, ``` nextTerm = currentTerm * currentTerm - 2 ```

4. Using this formula, we can find the nth term of lucas-lehmer series.

Below is the implementation of lucas-lehmer series in JAVA
*/

// Program starts
import java.util.*;

public class Lucas_Lehmer_Series {

    // Function to calculate the series upto the nth term
    static void LucasLehmer(int n) {
  
        // the 0th term of the series is 4.
        long currentTerm = 4;
  
        // create an array to store the terms.
        ArrayList<Long> series = new ArrayList<>();
  
        // compute each term and add it to the array.
        series.add(currentTerm);
        for (int i = 0; i < n; i++) {
            currentTerm = currentTerm * currentTerm - 2;
            series.add(currentTerm);
        }
  
        // print out the terms one by one.
        for (int i = 0; i <= n; i++) {
            System.out.println("Term " + i + ": " + series.get(i));
        }
        System.out.println('\n');
    }
  
    // Main driver function
    public static void main(String[] args) {
        // nth term upto which user want to display the lucas-lehmer series
        Scanner scanner = new Scanner(System.in);
        
        // Taking input from the user
        System.out.print("\nEnter the value of n: ");
        int n = scanner.nextInt();
        scanner.close();
        
        System.out.println("\n######## Lucas-Lehmer Series ########\n");

        // Function triggered to calculate the lucas-lehmer series upto the nth term
        LucasLehmer(n);
    }
}

// This code is contributed by Avdhesh Varshney (https://github.com/Avdhesh-Varshney)
