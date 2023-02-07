/*********************************************************************
 
                        FACTORIAL PROGRAM                         
Factorial is represented by !. It is calculated by mutiplying natural
numbers upto that number, i.e., n! = 1 x 2 x 3... x n. 
(n should be positive)
Note: 0! = 1 and 1! = 1

**********************************************************************/

import java.util.Scanner; // scanner class

public class Main
{
    static int factorial(int num){
        if(num == 0 || num == 1) // factorial of 0 and 1 is 1
            return 1;
        else // if num > 1
            return (num * factorial(num - 1));
    }

	public static void main(String[] args) {
	    
	    Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number:");
        int num = scan.nextInt(); //factorial of this no will be calculated
        System.out.println("Factorial of " + num + " is " + factorial(num));
	}
}
