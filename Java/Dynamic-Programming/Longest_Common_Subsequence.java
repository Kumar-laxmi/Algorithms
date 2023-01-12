//Approach 
//        This code is a Java program that calculates the longest common subsequence (LCS) of two strings.
//        The LCS is the longest sequence of characters that appear in the same order in both strings.
//
//        The main function of the code is in the class "Solution", which defines a function called "lcs"
//        that takes four arguments: two integers "m" and "n" representing the lengths of the two strings, 
//        and the two strings themselves "s1" and "s2". It uses a 2-D dp table called dp with size of m+1, n+1 
//        and initialize them with -1.
//
//        The function implements a recursive approach with the help of dp array and base case as if the length of one of the strings is 0 the LCS is 0.
//        If the current characters of both strings are same it will take 1+ LCS(m-1, n-1) and if not it will take the max of LCS(m-1, n) and LCS(m, n-1).
//
//        The main method of the class Longest_Common_Subsequence takes an integer as input (number of test cases),
//        then reads two integers as the length of two strings, reads two strings as input and constructs an object of the Solution class.
//        Then it calls the lcs method of the Solution class and prints the value returned by the method.
//
//        The code uses dynamic programming (DP) to solve the problem, by using a 2-D array to store the values of subproblems and avoid redundant computations.
//        The array is filled row by row, with each cell corresponding to the LCS of a suffix of s1 and a suffix of s2.
//
//        In short, this code finds the longest common subsequence between two input strings 
//        using dynamic programming with the help of a 2-D dp table. The time complexity of the program is O(mn)

import java.util.*;
import java.lang.*;
import java.io.*;

//Main class
class Longest_Common_Subsequence{
	public static void main (String[] args) {

		Scanner sc=new Scanner(System.in);
		int test=sc.nextInt();
		while(test-- > 0){
		    int p=sc.nextInt();             // Take size of both the strings as input
		    int q=sc.nextInt();
		    
		    String s1=sc.next();            // Take both the string as input
	        String s2=sc.next();
		    
		    Solution obj = new Solution();
		    
		    System.out.println(obj.lcs(p, q, s1, s2));
		}
        sc.close();
	}
}
 


class Solution
{
    public static int lcs(int m,int n,String s1,String s2,int dp[][]){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s1.charAt(m-1)==s2.charAt(n-1)){
            return dp[m][n]=1+lcs(m-1,n-1,s1,s2,dp);
        }else{
            return dp[m][n]=Math.max(lcs(m-1,n,s1,s2,dp),lcs(m,n-1,s1,s2,dp));
        }
    }
    int lcs(int x, int y, String s1, String s2)
    {
        // your code here
         int dp[][]=new int [x+1][y+1];
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                dp[i][j]=-1;
            }
        }
        return lcs(x ,y ,s1,s2 ,dp );
    }
    
}
