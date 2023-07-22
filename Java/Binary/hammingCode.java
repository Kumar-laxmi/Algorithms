import java.util.ArrayList;
import java.util.List;

public class hammingCode {
    public static int calculateParityBits(int m, int low, int high) {
        // Binary algorithm to find the required number of bits
        if (high == 0) {
            high = m + 1;
        }

        int r = (low + high) / 2;

        if (low == high) {
            return low;
        } else if (Math.pow(2, r) >= r + m + 1) { // r = redundant bit, m = data bit
            return calculateParityBits(m, low, r);
        } else {
            return calculateParityBits(m, r + 1, high);
        }
    }

    public static boolean isPowerOfTwo(int num) {
        // Performs a bitwise AND operation between num and num - 1.
        // This operation turns off the rightmost set bit in num (i.e., the least significant bit).
        // If the result of the bitwise AND operation is zero, it means that num had only one set bit (power of 2)
        // before the bitwise operation, and that bit was turned off. In this case, the number is considered a power of 2.
        return (num & (num - 1)) == 0;
    }

    public static int calculateParityValue(List<Character> encodedBlock, int pos) {
        // Count the number of ones corresponding to the parity bit
        int count = 0;
        for (int i = 0; i < encodedBlock.size(); i++) {
          int bit =  encodedBlock.get(i);
            if (bit == '1' && (((i + 1) & pos) != 0)) {
                count++;
            }
        }
        return count % 2;
    }

    public static String hammingEncode(String message) {
        int m = message.length(); // Length of the message
        int r = calculateParityBits(m, 0, 0); // Calculate the number of parity bits

        int blockLength = m + r; // Total length of the encoded block

        // Create a list to store the encoded bits
        List<Character> encodedBlock = new ArrayList<>();

        int dataBit = 0;

        // Iterate over the block and copy the data
        for (int position = 1; position <= blockLength; position++) {
            if (isPowerOfTwo(position)) {
                encodedBlock.add('P'); // Mark as parity bit
            } else {
                encodedBlock.add(message.charAt(dataBit)); // Data bit, copy from the message
                dataBit++;
            }
        }

        // Iterate over the parity bits in the encoded block
        for (int position = 1; position <= blockLength; position++) {
            if (encodedBlock.get(position - 1) == 'P') {
                // Calculate and assign the required parity value
                int parity = calculateParityValue(encodedBlock, position);
                encodedBlock.set(position - 1, (parity % 2 == 0) ? '0' : '1');
            }
        }

        // Convert the list of characters to a string
        StringBuilder encodedMessage = new StringBuilder();
        for (char bit : encodedBlock) {
            encodedMessage.append(bit);
        }

        return encodedMessage.toString();
    }

    public static void main(String[] args) {
        String message = "11110010010"; // Example message
        String encodedMessage = hammingEncode(message);
        System.out.println("Message entered: " + message);
        System.out.println("Encoded Message: " + encodedMessage);
    }
}
