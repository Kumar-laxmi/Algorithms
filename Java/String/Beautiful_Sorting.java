/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/* Problem Statement: Atul has been given a binary string ‘STR’ containing either ‘0’ or ‘1’. A binary string is called beautiful if it contains alternating 0s and 1s.
For Example:‘0101’, ‘1010’, ‘101’, ‘010’ are beautiful strings.
He wants to make ‘STR’ beautiful by performing some operations on it. In one operation, Atul can convert ‘0’ into ‘1’ or vice versa.
Your task is to determine the minimum number of operations Atul should perform to make ‘STR’ beautiful.

Time Complexity:- O(n) 
*/
import java.util.*;
import java.io.*;
// Method to count minimum number of operations that should perform to make ‘STR’ beautiful.
public class Beautiful_Sorting {
    public static void main(String args[]) {                 //Main Function
        Scanner sc = new Scanner(System.in);                //    iterating over array of all substrings
        int test;
        System.out.println("Enter total testcases: \n");    // For Test Cases
        test = sc.nextInt();
        while(test-->0)
        {
            String str;
            str = sc.next();
            System.out.println(Beautiful(str));
        }
    }
    public static int Beautiful(String str)                 // Function call   
    {
        int m = str.length();                       // Initalise a string
        int x1 = 0, x2 = 0;
        char s1 = '0', s2 = '1';
        for (int i = 0; i < m; i++) 
        {
            if (str.charAt(i) == '1')              // if number of ones,two and zero are equal in a substring
            {
                if (s1 == '0') 
                {
                    x1++;
                }
                else {
                    x2++;
                }
            }
            else 
            {
                if (s1 == '1') 
                {
                    x1++;
                }
                else 
                {
                    x2++;
                }
            }
            if (s1 == '1') 
            {
                s1 = '0';
                s2 = '1';
            }
            else 
            {
                s1 = '1';
                s2 = '0';
            }
        }
        if(x1<x2) return x1;
        else return x2;
    }
}