// SHA-224 is part of the SHA-2 family of hash functions. It works by iteratively processing input data in fixed-size blocks and updating the internal state of the hash algorithm until all data has been processed.
// Working of SHA 224 :-
// Message Padding: SHA-224 processes input messages in blocks of 512 bits (64 bytes). If the message length is not a multiple of 64 bytes, it needs to be padded.

// Initial Hash Values: SHA-224 initializes its internal state with specific constant values.

// Processing the Message: The block is divided into 32-bit words, and the internal state is updated.
// The message block undergoes several rounds of transformations, including bitwise operations , logical functions , and cyclic shifts.
// The internal state is updated after each round of processing to incorporate the current block.

// Finalization: After processing all the message blocks, the resulting internal state represents the hash value (a Hexa decimal string).

// Output: The resulting digest is the SHA-224 hash of the input message. It is typically used as a compact representation of the input data, and even a small change in the input will produce a significantly different hash value.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <string>
using namespace std;
#include <openssl/sha.h>
// provides function for SHA hashing

std::string sha224(const string &message)
{
    unsigned char digest[SHA224_DIGEST_LENGTH]; // Array to store resulting hash digests.
    SHA224_CTX shaContext;                      // Context structure holds internal states while hashing process.
    std::stringstream ss;                       // This is stringstream object which will convert hash digests to hex string.

    // Initialize SHA-224 context using SHA224_Init.
    if (!SHA224_Init(&shaContext))
    {
        std::cerr << "Failed to initialize SHA-224" << std::endl;
        return "";
    }

    // Update the context with the message data
    SHA224_Update(&shaContext, message.c_str(), message.length());

    // Finalize the hash and store the digest
    SHA224_Final(digest, &shaContext);

    // Convert the digest to a hex string
    for (int i = 0; i < SHA224_DIGEST_LENGTH; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    // Convert each byte of digest array into 2 digit hex string
    //  std::setfill('0') to to pad with zeros if necessary
    //  then static_cast<int>(digest[i]) to convert byte value into integer

    return ss.str();
}

int main()
{
    string message = "This string is to be hashed";
    string hash = sha224(message);

    cout << "Message: " << message << endl;
    cout << "SHA-224 hash: " << hash << endl;

    return 0;
}