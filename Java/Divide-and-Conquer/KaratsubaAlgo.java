/*
  ------------------------------------------- The Problem Statement ------------------------------------------------------

    INPUT :- Two numbers number1 and number2 with n digits where n is a power of 2

    OUTPUT :- The product of number1 and number2

  ----------------------------- The Problem of normally multiplying two large numbers ------------------------------------

    To multiply two numbers in computer we used the symbol * to get the result. It is not a problem for small numbers but when the size
    of the number gets increased the disaster starts. The problem comes while multiplying two large numbers using asterisk is, each number
    has to cover a 'n' iterations (where n is the length of the other number) for all the 'n' digits of that number it increases the
    time complexity of the program to BigO(n^2). This is where the Karatsuba algorithm comes into picture where it reduces the
    time complexity of multiplying two numbers to BigO(n^1.585)

  ------------------------------------------------ The Karatsuba ---------------------------------------------------------

    The karatsuba Algorithm is a divide and conquer algorithm as similar to the merge sort. When I say about Divide and Conquer you thinked it right,
    it is RECURSION. Karatsuba Algorithm recursively compute result of that product of two large numbers by breaking down the numbers into halves
    and computing the product of that two halves on top of that using that partial products to calculate the total product by summing it together.
    That is how we get the product of two numbers in Karatsuba algorithm.

  --------------------------------------------- The Karatsuba Algorithm --------------------------------------------------

  Example : 123456 * 456789   --> x * y  where x and y are constants

  x = 123456 --> 123000 + 456 --> ( 123 * 10^3 ) + 456
  The general form of the number can be written as --> ( a * 10^(n/2) ) + b, where a and b are constants.
  Similarly for the other number 456789.
  y = 456789 --> 456000 + 789 --> ( 456 * 10^3 ) + 789
  The general form of the number can be written as --> ( c * 10^(n/2) ) + d, where c and d are constants.

  x*y = (( a * 10^(n/2) ) + b) * (( c * 10^(n/2) ) + d)
  Solving it we get,
  x*y = ac * 10^ 2(n/2) + (ad+bc) * 10^(n/2) + bd
  For finding the ac,bd and ad+bc we need to recursively call the function of karatsuba written below.
  For easy identification, I used the same a,b,c,d convention in variable names of the karatsuba function.

*/

//Importing Scanner Class to get input from the user.
import java.util.Scanner;
public class KaratsubaAlgo {
    public static void main(String[] args) {

        // Reading two large numbers using scanner class
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first number = ");
        long number1 = sc.nextLong();
        System.out.println("Enter second number = ");
        long number2 = sc.nextLong();

        // Calling the karatsuba method which is implemented below
        System.out.println("The multiplied result of two numbers is = " + karatsuba(number1,number2));

        // Closing the scanner class
        sc.close();
    }

    // The karatsuba function which multiplies the two numbers
    // To keep the function safe and accessible inside this class only, I declared it as private you can declare it as public too.
    private static long karatsuba(long number1, long number2) {

        // (The termination of the recursion running) or (the BASE CASE of the recursion)
        if(number1 < 10 || number2 < 10)
        {
            return number1*number2;
        }

        // Converting long to string find the length of that number
        String num1 = Long.toString(number1);
        long n1 = num1.length();

        // Converting long to string find the length of that number
        String num2 = Long.toString(number2);
        long n2 = num2.length();

        // Finding the maximum length of the two numbers a and b
        long length = Math.max(n1,n2);

        // For splitting the number into two halves we need the length to be divided by 2
        long half_length = length/2;

        // To understand the naming convention of these variables below refer to the heading of the karatsuba algorithm above.
        long a = number1 / (long)Math.pow(10, half_length);
        long b = number1 % (long)Math.pow(10, half_length);
        long c = number2 / (long)Math.pow(10, half_length);
        long d = number2 % (long)Math.pow(10, half_length);

        // Recursively computing the partial product of the numbers for finding the values of ac, bd and ac+bd
        long ac = karatsuba(a, c);
        long ac_bd = karatsuba(a + b, c + d);
        long bd = karatsuba(b, d);

        // ac * 10^ 2(n/2) + (ad+bc) * 10^(n/2) + bd   this formula is used below to find the product of the two large numbers.
        return (long)Math.pow(10, 2 * half_length) * ac + (long)Math.pow(10, half_length) * (ac_bd - ac - bd) + bd;

    }
}
