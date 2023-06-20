
// Java program to print a fraction
// in Egyptian Form using Greedy
// Algorithm
import java.util.*;

class Egyptian_Fraction {

    static void printEgyptian(int nr, int dr) {
        // If either numerator or
        // denominator is 0
        if (dr == 0 || nr == 0) {
            return;
        }

        // If numerator divides denominator, then simple division makes the fraction in
        // 1/n form
        if (dr % nr == 0) {
            System.out.print("1/" + dr / nr);
            return;
        }

        // If denominator divides numerator, then the given number is not fraction
        if (nr % dr == 0) {
            System.out.print(nr / dr);
            return;
        }

        // If numerator is more than denominator
        if (nr > dr) {
            System.out.print(nr / dr + " + ");
            printEgyptian(nr % dr, dr);
            return;
        }

        // We reach here dr > nr and dr%nr is non-zero. Find ceiling of dr/nr and print
        // it as first fraction
        int n = dr / nr + 1;
        System.out.print("1/" + n + " + ");

        // Recur for remaining part
        printEgyptian(nr * n - dr, dr * n);
    }

    // Driver Code
    public static void main(String[] args) {
        int nr, dr;
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter Numerator");
            nr = sc.nextInt();
            System.out.println("Enter Denominator");
            dr = sc.nextInt();
        }
        // Calling the function and printing the corresponding Egyptian Fraction
        // Representation
        System.out.print(
                "Egyptian Fraction Representation of " + nr
                        + "/" + dr + " is\n ");
        printEgyptian(nr, dr);
    }
}
