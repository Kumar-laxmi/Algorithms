//This code takes input of three sides of a traingle from the user and returns it's are which is calculated using Heron's Formula. In symbols, if a, b, and c are the lengths of the sides: Area = Square root of√s(s - a)(s - b)(s - c) where s is half the perimeter, or (a + b + c)/2.

import java.util.Scanner;
 
public class heronsFormula { 
 
    public static void main(String[] args) {
        double s1, s2, s3, area, S;
        // Scanner scanner;
        Scanner sc = new Scanner(System.in);
        // Take input from user
        System.out.println("Enter Three Sides of a Triangle");
        s1 = sc.nextDouble();
        s2 = sc.nextDouble();
        s3 = sc.nextDouble();
 
        S = (s1 + s2 + s3) / 2;
        area = Math.sqrt(S * (S - s1) * (S - s2) * (S - s3));
 
        System.out.format("The Area of triangle = %.2f\n", area);
        sc.close();
    }
}
