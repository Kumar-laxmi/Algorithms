/*Name :  Hardik Goyal
Github username : HardikGoyal2003
Repositary name : Algorithms
*/
/*What is a strong number?
A strong number is a positive integer whose sum of factorials of its digits equals the number itself. In other words, if we take the 
digits of a number and calculate the factorial of each digit, then sum those factorials, and the result is the same as the original number, 
then that number is called a strong number.

Problem Statement : To Check Given number is Strong Number or not.
EXAMPLE : 
1)
Input:  145
Output: "It is a Strong Number"
*/
import java.util.Scanner;
public class Number {
  public static void main(String[] args){
        int n,factorial=1,sum=0;
        System.out.println("Enter Number");
        Scanner in = new Scanner(System.in);
        n=in.nextInt();
        int copy=n;
        while (n>0)
        {
            int rem = n%10;
            n/=10;
            for (int i=1; i <=rem; i++)
            {
                factorial*=i; 
            }
            sum+=factorial;
            factorial=1;        
        }
        if (copy==sum)
        {
            System.out.println("It is Strong Number");
        }
        else
        {
            System.out.println("It is not a Strong Number");
        }
  }
}
