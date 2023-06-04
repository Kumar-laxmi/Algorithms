/*
  This JAVA code takes an integer from the user and returns the reverse of it.
  -author~ Akhil Agrawal
  Github :- @swastik-akhil
  This code in JAVA is a program that takes an integer input from the user and reverses it. Here's a brief explanation of the code:

1. The `ReverseInteger` class is defined, which contains two methods: `reverse` and `main`.

2. The `reverse` method takes an integer `num` as input. It converts the integer to a string representation using `String.valueOf(num)`. Then, it creates a `StringBuilder` object named `reversed` and initializes it with the reversed version of the string using the `reverse()` method of the `StringBuilder` class.

3. The reversed string is converted back to a regular string using `reversed.toString()` and returned as the result of the `reverse` method.

4. In the `main` method:
   - A `Scanner` object named `scanner` is created to read user input from the console.
   - The user is prompted to enter an integer.
   - The entered integer is read using `scanner.nextInt()` and stored in the variable `number`.
   - The `Scanner` object is closed using `scanner.close()` to release system resources.
   - The `reverse` method is called with the `number` as an argument, and the returned reversed string is stored in the `reversedNumber` variable.
   - The original number and the reversed number are displayed to the console using `System.out.println`.

5. The program terminates after displaying the original and reversed numbers.

Overall, the code provides a simple way to reverse an integer input by converting it to a string, reversing the string using a `StringBuilder`, and converting it back to a string.

*/

import java.util.Scanner;

public class ReverseInteger {
    public static String reverse(int num) {
        String strNum = String.valueOf(num);
        StringBuilder reversed = new StringBuilder(strNum).reverse();

        return reversed.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int number = scanner.nextInt();
        scanner.close();

        String reversedNumber = reverse(number);
        System.out.println("Original number: " + number);
        System.out.println("Reversed number: " + reversedNumber);
    }
}
