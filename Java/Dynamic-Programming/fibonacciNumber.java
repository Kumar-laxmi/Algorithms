// The Fibonacci numbers are the numbers in the following integer sequence.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

// the sequence of Fibonacci numbers is defined by the recurrence relation

//       Fn = Fn-1 + Fn-2
//               with seed values F0 = 0 and F1 = 1.
              
              
//                             fib(5)  
//                         /           \
//                      /                \
//                fib(4)                fib(3)   
//              /        \              /       \ 
//          fib(3)      fib(2)         fib(2)   fib(1)     ----> we are calculating fib(2) two times
//         /    \       /    \        /      \
//   fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)          ----> we are calculating fib(1) three times
//   /     \
// fib(1) fib(0)


// We can avoid the repeated work done by storing the Fibonacci numbers calculated so far.

// there are two approaches---
//     1.  top-down approach - iterative
//     2.  bottom-up approach - recursive
    
    
// 1. TOP-DOWM approach

public class fibonacci
{
   static int fib(int n)
    {
      /* Declaring an array to store Fibonacci numbers. */
      int f[] = new int[n + 1]; // 1 extra to handle case, n = 0
      
      /* 0th and 1st number of the series are 0 and 1*/
      f[0] = 0;
      f[1] = 1;
     
      for (int i = 2; i <= n; i++) {
         /* Add the previous 2 numbers in the series and store it */
          f[i] = f[i - 1] + f[i - 2];
      }
      
      return f[n];
    }
      
    public static void main (String args[]) {
        int n = 9;
        System.out.println(fib(n));
    }
}




// 2. BOTTOM-UP approach
class Solution {
    public int fib(int n) {
         /* Declaring an array to store Fibonacci numbers. */
        int[] dp = new int[n + 1];
      
        //initialising the array with -1
        for(int i = 0; i <= n; i++){
            dp[i] = -1;
        }
        return fibonacci(n, dp);
    }
  

    public int fibonacci(int n, int[] dp){
        
       // control statements to stop the recursion with seed values
        if(n == 0){
            return 0;
        } 
        if(n == 1) {
            return 1;
        }

        // checking whether we calculated it previously
        if(dp[n] != -1){
            return dp[n];
        }
        
         //calling the function for the values not calculated
        dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
        return dp[n];
    }
  
    public static void main (String args[]) {
        int n = 9;
        System.out.println(fib(n));
    }
}



