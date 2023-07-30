// Path: Java\Cryptography\PlayfairCipher.java
// Java program to implement playfair cipher algorithm.

// The Playfair cipher algorithm is a symmetric encryption technique that uses a 5x5 grid of letters to encrypt plaintext.
// It employs the rules of letter substitution and rearrangement based on pairs of letters to generate ciphertext.

// Rules for Encryption using playfair cipher Algorithm
// 1). 5 X 5 matrix -> Table
// 2). Digraphs (3 conditions):
// i). same row
// ii). same column
// iii). different row and column

import java.util.Scanner;

public class PlayfairCipher {
    private static final int SIZE = 5;

    // Function to prepare the input string
    private static String prepareString(String line) {
        StringBuilder preparedString = new StringBuilder();
        int len = line.length();
        for (int i = 0; i < len; i++) {
            char ch = line.charAt(i);
            ch = Character.toUpperCase(ch);
            if (ch == 'J')
                ch = 'I';
            else if (ch == ' ')
                continue;
            preparedString.append(ch);
        }
        return preparedString.toString();
    }

    // Function to construct the table based on the key
    private static void constructTable(String key, char[][] table) {
        int[] visited = new int[26];
        int row = 0, col = 0;
        int len = key.length();

        // First, fill the key in the table
        for (int i = 0; i < len; i++) {
            char ch = key.charAt(i);
            if (visited[ch - 'A'] == 0) {
                table[row][col] = ch;
                visited[ch - 'A'] = 1;
                if (col == SIZE - 1) {
                    row++;
                    col = 0;
                } else
                    col++;
            }
        }

        // Then, fill the remaining characters from A to Z
        for (int i = 0; i < 26; i++) {
            if (visited[i] == 0) {
                char ch = (char) (i + 'A');
                if (ch == 'J')
                    continue;
                table[row][col] = ch;
                visited[i] = 1;
                if (col == SIZE - 1) {
                    row++;
                    col = 0;
                } else
                    col++;
            }
        }
    }

    // Function to split the plain text into digraphs
    private static String[] digraphPlainText(String plainText) {
        int len = plainText.length();
        StringBuilder preparedString = new StringBuilder();
        for (int i = 0; i < len; i++) {
            char ch = plainText.charAt(i);
            preparedString.append(ch);
            if (i == len - 1 || ch == plainText.charAt(i + 1)) {
                preparedString.append('X');
            } else {
                preparedString.append(plainText.charAt(i + 1));
                i++;
            }
        }
        String digraphPlainText = preparedString.toString();

        // Split the digraphs into an array
        int digraphCount = digraphPlainText.length() / 2;
        String[] digraphs = new String[digraphCount];
        for (int i = 0, j = 0; i < digraphCount; i++, j += 2) {
            digraphs[i] = digraphPlainText.substring(j, j + 2);
        }
        return digraphs;
    }

    // Function to get the coordinates of a character in the table
    private static void getCoordinates(char[][] table, char ch, int[] coordinates) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (table[i][j] == ch) {
                    coordinates[0] = i;
                    coordinates[1] = j;
                    return;
                }
            }
        }
        coordinates[0] = -1;
        coordinates[1] = -1;
    }

    // Function to encrypt the plain text
    private static String encrypt(String[] digraphs, char[][] table) {
        StringBuilder cipherText = new StringBuilder();
        for (String digraph : digraphs) {
            int row1, col1, row2, col2;
            char ch1 = digraph.charAt(0);
            char ch2 = digraph.charAt(1);
            int[] coordinates1 = new int[2];
            int[] coordinates2 = new int[2];

            getCoordinates(table, ch1, coordinates1);
            getCoordinates(table, ch2, coordinates2);

            row1 = coordinates1[0];
            col1 = coordinates1[1];
            row2 = coordinates2[0];
            col2 = coordinates2[1];

            // Case 1: Same row
            if (row1 == row2) {
                col1 = (col1 + 1) % SIZE;
                col2 = (col2 + 1) % SIZE;
            }
            // Case 2: Same column
            else if (col1 == col2) {
                row1 = (row1 + 1) % SIZE;
                row2 = (row2 + 1) % SIZE;
            }
            // Case 3: Rectangle
            else {
                int temp = col1;
                col1 = col2;
                col2 = temp;
            }

            cipherText.append(table[row1][col1]);
            cipherText.append(table[row2][col2]);
        }
        return cipherText.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Key: ");
        String key = scanner.nextLine().toUpperCase();

        System.out.print("Enter Plain Text: ");
        String plainText = scanner.nextLine().toUpperCase();

        String preparedKey = prepareString(key);
        String preparedPlainText = prepareString(plainText);

        char[][] table = new char[SIZE][SIZE];
        constructTable(preparedKey, table);

        String[] digraphs = digraphPlainText(preparedPlainText);

        String cipherText = encrypt(digraphs, table);

        System.out.println("\nCipher Text: " + cipherText);
        System.out.print("\nDeciphered text: ");
        for (String d : digraphs) {
            System.out.print(d);
        }
        System.out.println();

        scanner.close();
    }
}