import java.util.Scanner;

public class CaesarCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Encrypt\n2. Decrypt\nEnter your choice: ");
        int choice = sc.nextInt();
        sc.nextLine();

        if (choice == 1) {
            System.out.print("Enter a message to be encrypted: ");
            String message = sc.nextLine();
            System.out.print("Enter a shift value: ");
            int shift = sc.nextInt();

            String encryptedMessage = encrypt(message, shift);
            System.out.println("Encrypted message: " + encryptedMessage);
        } else if (choice == 2) {
            System.out.print("Enter a message to be decrypted: ");
            String message = sc.nextLine();
            System.out.print("Enter a shift value: ");
            int shift = sc.nextInt();

            String decryptedMessage = decrypt(message, shift);
            System.out.println("Decrypted message: " + decryptedMessage);
        } else {
            System.out.println("Invalid choice");
        }
    }

    public static String encrypt(String message, int shift) {
        char[] chars = message.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (Character.isLetter(chars[i])) {
                char ch = (char) (chars[i] + shift);
                if (Character.isLowerCase(chars[i])) {
                    if (ch > 'z') {
                        ch = (char) (ch - 26);
                    }
                } else {
                    if (ch > 'Z') {
                        ch = (char) (ch - 26);
                    }
                }
                chars[i] = ch;
            }
        }
        return new String(chars);
    }

    public static String decrypt(String message, int shift) {
        char[] chars = message.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (Character.isLetter(chars[i])) {
                char ch = (char) (chars[i] - shift);
                if (Character.isLowerCase(chars[i])) {
                    if (ch < 'a') {
                        ch = (char) (ch + 26);
                    }
                } else {
                    if (ch < 'A') {
                        ch = (char) (ch + 26);
                    }
                }
                chars[i] = ch;
            }
        }
        return new String(chars);
    }
}
