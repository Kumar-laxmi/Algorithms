import java.util.HashMap;
import java.util.Map;

public class ColumnarTranspositionCipher {

    // Key for Columnar Transposition
    private static final String key = "HACK";
    private static final Map<Character, Integer> keyMap = new HashMap<>();

    private static void setPermutationOrder() {
        // Add the permutation order into the map
        for (int i = 0; i < key.length(); i++) {
            keyMap.put(key.charAt(i), i);
        }
    }

    // Encryption
    private static String encryptMessage(String msg) {
        int row, col, j;
        StringBuilder cipher = new StringBuilder();

        // Calculate the number of columns in the matrix
        col = key.length();

        // Calculate the maximum number of rows in the matrix
        row = msg.length() / col;

        if (msg.length() % col != 0) {
            row += 1;
        }

        char[][] matrix = new char[row][col];

        for (int i = 0, k = 0; i < row; i++) {
            for (j = 0; j < col;) {
                if (msg.charAt(k) == '\0') {
                    // Adding the padding character '_'
                    matrix[i][j] = '_';
                    j++;
                }

                if (Character.isAlphabetic(msg.charAt(k)) || msg.charAt(k) == ' ') {
                    // Adding only space and alphabets into the matrix
                    matrix[i][j] = msg.charAt(k);
                    j++;
                }
                k++;
            }
        }

        for (Map.Entry<Character, Integer> entry : keyMap.entrySet()) {
            j = entry.getValue();

            // Getting ciphertext from the matrix column-wise using the permuted key
            for (int i = 0; i < row; i++) {
                if (Character.isAlphabetic(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_') {
                    cipher.append(matrix[i][j]);
                }
            }
        }

        return cipher.toString();
    }

    // Decryption
    private static String decryptMessage(String cipher) {
        // Calculate the number of rows and columns for the cipher matrix
        int col = key.length();
        int row = cipher.length() / col;
        char[][] cipherMat = new char[row][col];

        // Add characters into the matrix column-wise
        int k = 0;
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                cipherMat[i][j] = cipher.charAt(k++);
            }
        }

        // Update the order of the key for decryption
        int index = 0;
        for (Map.Entry<Character, Integer> entry : keyMap.entrySet()) {
            entry.setValue(index++);
        }

        // Arrange the matrix column-wise according to the permutation order by adding
        // into a new matrix
        char[][] decCipher = new char[row][col];
        int l = 0, j;
        for (; l < key.length();) {
            j = keyMap.get(key.charAt(l++));
            for (int i = 0; i < row; i++) {
                decCipher[i][j] = cipherMat[i][l - 1];
            }
        }

        // Get the original message from the matrix
        StringBuilder msg = new StringBuilder();
        for (int i = 0; i < row; i++) {
            for (int j1 = 0; j1 < col; j1++) {
                if (decCipher[i][j1] != '_') {
                    msg.append(decCipher[i][j1]);
                }
            }
        }
        return msg.toString();
    }

    public static void main(String[] args) {
        String msg = "Open Source is Fun";

        setPermutationOrder();

        // Calling encryption function
        String cipher = encryptMessage(msg);
        System.out.println("Encrypted Message: " + cipher);

        // Calling Decryption function
        String decryptedMessage = decryptMessage(cipher);
        System.out.println("Decrypted Message: " + decryptedMessage);
    }
}
