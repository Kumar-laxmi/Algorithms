//     LongestCommonSubsequence

//      Approach for solvering the Problem
//        1. Create a 2D array “dp” with rows and columns equal to the length of each input string plus 1.
//        2. Initialize the first row and column of the dp array to 0.
//        3. Iterate through the rows of the dp array, starting from 1.
//        4. Within the outer loop, iterate through the columns of the dp array, also starting from 1.
//        5. If the character at the current row of the first input string is equal to the character at the current column of the second input string, set the current element of the dp array to the 
//            value of the element above-left of the current element, plus 1.
//        6. Else, set the current element of the dp array to the maximum value of the element above or to the left of the current element.
//        7. After the nested loops, the last element of the dp array will contain the length of the LCS.
//        8. To find the actual LCS, initialize an empty string and iterate through the dp array, starting from the last element and going towards the first element.
//        9. At each step, if the current element is not equal to the element above or to the left of it, 
//           add the character at the current position of the corresponding input string to the LCS string and move diagonally to the left and up.
//        10.Else, move either up or left, whichever element is greater.
//        11.Reverse the LCS string to get the final result.

package Java_practice.Dynamic_Programming;
import java.util.*;
import java.lang.*;
import java.io.*;
 class LongestCommonSubsequence {
         public static void main (String[] args) {

             Scanner sc=new Scanner(System.in);
             int test=sc.nextInt();
             while(test-- > 0){
                 int p=sc.nextInt();             // Take size of both the strings as input
                 int q=sc.nextInt();

                 String s1=sc.next();            // Take both the string as input
                 String s2=sc.next();

                   public static int lcss(int m,int n,String s1,String s2,int dp[][]){
             if(m==0 || n==0){
                 return 0;
             }
             if(dp[m][n]!=-1){
                 return dp[m][n];
             }
             if(s1.charAt(m-1)==s2.charAt(n-1)){
                 return dp[m][n]=1+lcss(m-1,n-1,s1,s2,dp);
             }else{
                 return dp[m][n]=Math.max(lcss(m-1,n,s1,s2,dp),lcss(m,n-1,s1,s2,dp));
             }
         }
         //Function to find the length of longest common subsequence in two strings.
         int lcs(int x, int y, String s1, String s2)
         {
             // your code here
             int dp[][]=new int [x+1][y+1];
             for(int i=1;i<=x;i++){
                 for(int j=1;j<=y;j++){
                     dp[i][j]=-1;
                 }
             }
             return lcss(x ,y ,s1,s2 ,dp );
         }

                 System.out.println(lcs(p, q, s1, s2));
             }
             sc.close();
         }
     }
 
