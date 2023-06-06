import java.util.Scanner; // Importing scanner class to get input
public class ModularExponentiation {
    public static void main(String[] args) {
        // Initializing the scanner class
        Scanner sc = new Scanner(System.in);
        // Reading the base,power,modulo values from the user.
        System.out.print("Enter the base value = ");
        int base = sc.nextInt();
        System.out.print("Enter the power value = ");
        int power = sc.nextInt();
        System.out.print("Enter the modulo value = ");
        int modulo = sc.nextInt();
        // Calling the function to perform the modular exponentiation
        modularExponentiation(base, power, modulo);
    }
    private static void modularExponentiation(int base, int power, int modulo) {
        // Update base if it is more than or equal to modulo
        base = base % modulo;
        // Initializing the result variable to store the modular exponentiation value.
        int result = 1;
        // In case base is divisible by modulo
        if (base == 0) {
            System.out.println(0);
        }
        while (power > 0)
        {
            // If power is odd, multiply base with result
            if ((power & 1) != 0) {
                result = (result * base) % modulo;
            }
            // power must be even now
            // power = power/2
            power = power >> 1;
            base = (base * base) % modulo;
        }
        // Printing the modular exponentiation value.
        System.out.println("Modular Exponentiation = " + result);
    }
}
