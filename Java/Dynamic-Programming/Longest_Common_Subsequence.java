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