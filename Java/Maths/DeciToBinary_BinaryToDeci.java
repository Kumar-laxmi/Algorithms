//Decimal to Binary Converter and vice-versa & JAVA

import java.util.*;

public class DeciToBinary_BinaryToDeci {
    public static void main(String[] args) {
        // Scanner object to take input
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter 1 for Decimal to Binary converter.");
        System.out.println("Please enter 2 for Binary to Decimal converter.");
        int c = sc.nextInt();
        switch (c) {


            //when entered 1
            //Decimal to binary
            case 1:
                System.out.println("Enter the Decimal Number");
                int decimalNumber = sc.nextInt();
                String binaryNumber = decimalToBinary(decimalNumber);
                System.out.println("Binary representation of " + decimalNumber + " is: " + binaryNumber);
                break;


            //when entered 1
            //Decimal to binary
            case 2:
                System.out.println("Enter the Binary Number");
                String binary = sc.next();
                int decimalNum = binaryToDecimal(binary);
                System.out.println("Decimal representation of " + binary + " is: " + decimalNum);
                break;


            //when entered invalid input
            default:
                System.out.println("You did not enter either 1 or 2.");
        }
    }


    // Function to Convert Decimal to binary
    public static String decimalToBinary(int decimal) {
        if (decimal == 0) {
            return "0"; // Special case for decimal number 0
        }

        StringBuilder binary = new StringBuilder();
        while (decimal > 0) {
            int remainder = decimal % 2;
            binary.insert(0, remainder); // Insert the remainder at the beginning of the string
            decimal /= 2;
        }

        return binary.toString();
    }


    // Function to Convert Binary to decimal
    public static int binaryToDecimal(String binary) {
        int decimal = 0;
        int power = 0;

        for (int i = binary.length() - 1; i >= 0; i--) {
            int digit = Character.getNumericValue(binary.charAt(i));
            decimal += digit * Math.pow(2, power);
            power++;
        }

        return decimal;
    }
}
/*******************************************************
 Case 1:
 Enter the Decimal Number
 42
 Binary representation of 42 is: 101010

 Case 2:
 Enter the Binary Number
 100
 Decimal representation of 100 is: 4

 default:
 You did not enter either 1 or 2.
 *******************************************************/