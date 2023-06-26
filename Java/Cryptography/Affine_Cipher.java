//AFFINE CIPHER
//The Affine cipher is a standard substitution cipher.
//Encryption:
//        Cipher Text, C=(aX+b) mod 26
//        where a, b are key values and X is letter to be encrypted.
//Decryption:
//        Plain Text, X=[a^-1(C-b)] mod 26
//        where alphabets from (a-z) are numbered sequentially from (0-25).

import java.math.BigInteger;
import java.util.Scanner;

public class Affine_Cipher{
    static int a, b; //Keys for affine cipher
    static int m = 26;//total number of alphabets

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter plain text:");
        String plainText = sc.nextLine();

        System.out.println("Enter keys a and b:");
        a = sc.nextInt();
        b = sc.nextInt();

        if (!isCoprime(a, m)) {
            System.out.println("Key 'a' and modulus 'm' are not coprime. Choose different keys.");
            return;
        }

        StringBuilder ciphertext = cipher(plainText);
        System.out.println("Cipher Text after Encryption:");
        System.out.println(ciphertext);

        StringBuilder decryptedText = decipher(ciphertext);
        System.out.println("Decrypted Text/Plain Text after Decryption:");
        System.out.println(decryptedText);
    }

    static StringBuilder cipher(String plain_text) {
        StringBuilder ciphertext = new StringBuilder();
        for (int i = 0; i < plain_text.length(); i++) {
            char t = plain_text.charAt(i);
            int alphaVal = (int) t - 97; // 'a' has ASCII value 97
            int c = (a * alphaVal + b) % m;
            char changedChar = (char) (c + 97);
            ciphertext.append(changedChar);
        }
        return ciphertext;
    }

    static StringBuilder decipher(StringBuilder ciphertext) {
        StringBuilder plaintext = new StringBuilder();
        BigInteger inverseA = BigInteger.valueOf(modInverse(a, m));

        for (int i = 0; i < ciphertext.length(); i++) {
            char c = ciphertext.charAt(i);
            int alphaVal = (int) c - 97;
            int decipherT = (inverseA.intValue() * (alphaVal - b + m)) % m;
            char changedChar = (char) (decipherT + 97);
            plaintext.append(changedChar);
        }
        return plaintext;
    }

    static boolean isCoprime(int a, int b) {
        return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue() == 1;
    }

    static int modInverse(int a, int m) {
        BigInteger bigA = BigInteger.valueOf(a);
        BigInteger bigM = BigInteger.valueOf(m);
        return bigA.modInverse(bigM).intValue();
    }
}
