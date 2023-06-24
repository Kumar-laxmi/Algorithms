// SHA-224 is part of the SHA-2 family of hash functions. It works by iteratively processing input data in fixed-size blocks and updating the internal state of the hash algorithm until all data has been processed.
// Working of SHA 224 :-
// Message Padding: SHA-224 processes input messages in blocks of 512 bits (64 bytes). If the message length is not a multiple of 64 bytes, it needs to be padded.

// Initial Hash Values: SHA-224 initializes its internal state with specific constant values.

// Processing the Message: The block is divided into 32-bit words, and the internal state is updated.
// The message block undergoes several rounds of transformations, including bitwise operations , logical functions , and cyclic shifts.
// The internal state is updated after each round of processing to incorporate the current block.

// Finalization: After processing all the message blocks, the resulting internal state represents the hash value (a Hexa decimal string).

// Output: The resulting digest is the SHA-224 hash of the input message. It is typically used as a compact representation of the input data, and even a small change in the input will produce a significantly different hash value.

import java.security.MessageDigest;    //java.security.MessageDigest class provides the functionality for calculating SHA-224 hashes

public class SHA224 {

    public static void main(String[] args) {
        String message = "This message is to be hashed";

        MessageDigest msgDigest = MessageDigest.getInstance("SHA-224");    // Create a MessageDigest object for the SHA-224 algorithm.
        
        msgDigest.update(message.getBytes());    // Update the message digest with the message.
        
        byte[] hash = msgDigest.digest();    // Calculate the hash value.
        
        String hashString = new String(hash);    // Convert the hash value to a hexadecimal string.
        
        System.out.println(hashString);
    }
}