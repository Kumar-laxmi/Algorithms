// Java program to check if the number is an Armstrong number or not

import java.util.Scanner;
import java.lang.Math;

class armstrong{
    // Function to return the number of digits of a number
    static int digits(long number){
        int d = 0;
        while (number > 0){
            number = number/10;
            d++;
        }
        return d;
    }

    // Function to find the sum of digits with the power of length
    static int sumPowerOflen(long number, int length){
        int sum = 0;
        while(number > 0){
            int r = (int)(number%10);
            sum += Math.round(Math.pow(r, length));
            number /= 10;
        }
        return sum;
    }

    public static void main(String[] args) {
        // Scanner object to take input
        Scanner input = new Scanner(System.in);
        long number;
        System.out.print("Enter a number to check if it is armstrong or not: ");
        number = input.nextLong();

        // Calling digits() function
        int length = digits(number);

        // Calling sumPowerOflen() function
        int sum = sumPowerOflen(number, length);

        // Checking if sum is equal to the given number
        if (sum == number)
            System.out.println(number + " is an Armstrong number");
        else
            System.out.println(number + " is not an Armstrong number");
        
        // Closing the input object
        input.close();

        return;
    }
}

/*******************************************************
Case 1:
Enter a number to check if it is armstrong or not: 153
153 is an Armstrong number

Case 2:
Enter a number to check if it is armstrong or not: 233
233 is not an Armstrong number

Case 3:
Enter a number to check if it is armstrong or not: 1634
1634 is an Armstrong number
*******************************************************/