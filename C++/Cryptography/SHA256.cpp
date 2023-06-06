/*
Definition:
    SHA-256 (Secure Hash Algorithm 256) is a widely-used cryptographic hashing 
    algorithm that produces a fixed-size 256-bit (32-byte) hash value. The 
    SHA-256 algorithm takes an input message of any length and processes it in 
    512-bit (64-byte) blocks. The message is first padded with a 1-bit followed 
    by zeros to make it a multiple of 512 bits. The last 64 bits of the padded 
    message are used to store the length of the original message in bits. The 
    output of the SHA-256 algorithm is a 256-bit hash value that is typically 
    represented as a sequence of 64 hexadecimal digits. The hash value is unique 
    to the input message, and even a small change to the message will result 
    in a completely different hash value. This makes the SHA-256 algorithm useful 
    for verifying the integrity of data, as well as for password hashing and 
    digital signatures.
Input:
    Option: the code asks the user if they want to encrypt or verify a hash
    Message: in case the user wants to encrypt, the code asks the user for a message to encrypt.
    Hash: if the user wants to verify a hash, then the code asks the user for the original 
    hash and the original message.
Output:
    Hash: If the user wants to encrypt a message, the code gives a hash as the output.
    Verification: If the user wanted to verify a hash and has given the necessary inputs, the code 
    will either say the hash is verified in case of successful verification or it will say that 
    the hash does not match, indicating the hash or message for this hash is invalid.
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <openssl/sha.h>

using namespace std;

int main() {
    """Ask the user whether to encrypt a message or verify a hash"""
    while (true) {
        char action;
        cout << "Do you want to encrypt or verify a hash? (e/v): ";
        cin >> action;

        if (action == 'e') {
            """Here the Encryption of a string is being done."""
            string input_str;
            cout << "Enter a string to hash: ";
            cin.ignore();
            getline(cin, input_str);
            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256(reinterpret_cast<const unsigned char*>(input_str.c_str()), input_str.length(), hash);
            stringstream ss;
            for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
                ss << hex << setw(2) << setfill('0') << static_cast<unsigned int>(hash[i]);
            }
            cout << "The SHA-256 hash of the input string is: " << ss.str() << endl;
            break;
        }
        else if (action == 'v') {
            """Here a hash is being Verified"""
            string input_str;
            cout << "Enter the original string: ";
            cin.ignore();
            getline(cin, input_str);
            string original_hash;
            cout << "Enter the original hash: ";
            cin >> original_hash;
            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256(reinterpret_cast<const unsigned char*>(input_str.c_str()), input_str.length(), hash);
            stringstream ss;
            for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
                ss << hex << setw(2) << setfill('0') << static_cast<unsigned int>(hash[i]);
            }
            string verify_result = ss.str();
            if (verify_result == original_hash) {
            """ Hash verification successful"""
                cout << "The hash is verified." << endl;
            }
            else {
                """Hash verification is unsuccessful"""
                cout << "The hash does not match." << endl;
            }
            break;
        }
        else {
            cout << "Invalid input. Please enter 'e' or 'v'." << endl;
        }
    }
    return 0;
}
