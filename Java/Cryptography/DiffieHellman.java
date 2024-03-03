import java.util.Scanner;

class DiffieHellman {
 
    // Power function to return value of a ^ b mod P
    private static long power(long base, long exponent, long modulus)
    {
        if (exponent == 1)
            return base;
        else
            return (((long)Math.pow(base, exponent)) % modulus);
    }
 
    // Driver code
    public static void main(String[] args)
    {
        long prime, primitiveRoot, privateKeyUser1, privateKeyUser2, publicKeyUser1, publicKeyUser2, secretKeyUser1, secretKeyUser2;
        
        Scanner scanner = new Scanner(System.in);
 
        // Both the persons will agree upon the public keys: prime and primitiveRoot
        System.out.print("Enter a prime number (P): ");
        prime = scanner.nextLong();
 
        System.out.print("Enter a primitive root (G) for P: ");
        primitiveRoot = scanner.nextLong();
 
        // User 1 will choose the private key
        System.out.print("Enter the private key for User 1: ");
        privateKeyUser1 = scanner.nextLong();
 
        long generatedKeyUser1 = power(primitiveRoot, privateKeyUser1, prime); // gets the generated key
 
        // User 2 will choose the private key
        System.out.print("Enter the private key for User 2: ");
        privateKeyUser2 = scanner.nextLong();
 
        long generatedKeyUser2 = power(primitiveRoot, privateKeyUser2, prime); // gets the generated key
 
        // Generating the public keys
        publicKeyUser1 = generatedKeyUser1;
        publicKeyUser2 = generatedKeyUser2;
 
        System.out.println("\nPublic key of User 1: " + publicKeyUser1);
        System.out.println("Public key of User 2: " + publicKeyUser2);
 
        // Generating the secret keys
        secretKeyUser1 = power(publicKeyUser2, privateKeyUser1, prime); // Secret key for User 1
        secretKeyUser2 = power(publicKeyUser1, privateKeyUser2, prime); // Secret key for User 2
 
        System.out.println("\nSecret key for User 1: " + secretKeyUser1);
        System.out.println("Secret key for User 2: " + secretKeyUser2);
    }
}
