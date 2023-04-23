// Java program to reverse a number
/*
        Example 1: Given number is : 3456
        Output:  Reverse of given number is : 6543
        
        Example 2: Given number is : -5432
        Output:  Reverse of given number is : -2345
 */
import java.util.Scanner;

public class ReverseInteger {

    public static void main(String[] args) {
        // Scanner object to take input
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number to reverse: ");
        int num = input.nextInt();

        //reverse of number is sorted in revNum by calling reverseInt() method
        int revNum = reverseInt(num);
        System.out.print("Reverse of a given number is: " + revNum);

    }
    static int reverseInt(int n){
        //check: if the number is negative
        boolean negativeNum = false;
        // if a given number is less than 0, it means given number is negative;
        if(n < 0){
            negativeNum = true;
            n = -n;
        }
        int revDigit = 0;
        int preRevDigit = 0;
        // Iterative function to reverse digits of num
        //logic of reversing a number
        while(n > 0){

            int curDigit = n%10;
            revDigit = (revDigit * 10) + curDigit;
            // checking if the reverse overflowed or not.
            // The values of (rev_num - curr_digit)/10 and
            // prev_rev_num must be same if there was no
            // problem.
            if((revDigit - curDigit) / 10 != preRevDigit){
                return 0;
            }
            preRevDigit = revDigit;
            n /= 10;
        }

        // if given number is negative then, multiply -1 with reverse number
        if(negativeNum){
            //return the reverse number with negative sign
            return -1 * revDigit;
        }
        // else given number is positive, just return the reverse of that number
        else{
            //return the reverse number
            return revDigit;
        }
    }

}
