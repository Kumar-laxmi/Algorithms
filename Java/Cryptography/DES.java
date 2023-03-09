#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/des.h>

using namespace std;

// Define a function to convert byte arrays to hexadecimal strings
string bytesToHex(const unsigned char* bytes, size_t length) {
ostringstream os;
os << hex << setfill('0');
for(size_t i = 0; i < length; i++) {
os << setw(2) << static_cast<unsigned>(bytes[i]);
}
return os.str();
}

// Define a function to convert hexadecimal strings to byte arrays
vector<unsigned char> hexToBytes(const string& hex) {
vector<unsigned char> bytes;
for (unsigned int i = 0; i < hex.length(); i += 2) {
string byteString = hex.substr(i, 2);
unsigned char byte = (unsigned char) strtol(byteString.c_str(), NULL, 16);
bytes.push_back(byte);
}
return bytes;
}

// Define a function to generate a random key using 24 bytes
vector<unsigned char> generateKey() {
vector<unsigned char> key(24);
if (!RAND_bytes(key.data(), key.size())) {
throw runtime_error("Failed to generate random key");
}
return key;
}

// Define a function to generate a random initialization vector (IV) using 8 bytes
vector<unsigned char> generateIV() {
vector<unsigned char> iv(8);
if (!RAND_bytes(iv.data(), iv.size())) {
throw runtime_error("Failed to generate random IV");
}
return iv;
}

// Define a function to encrypt a message using 3DES
vector<unsigned char> encrypt(const string& plaintext, const vector<unsigned char>& key, const vector<unsigned char>& iv) {
EVP_CIPHER_CTX* ctx;
if (!(ctx = EVP_CIPHER_CTX_new())) {
throw runtime_error("Failed to create encryption context");
}
if (EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key.data(), iv.data()) != 1) {
EVP_CIPHER_CTX_free(ctx);
throw runtime_error("Failed to initialize encryption");
}
// Determine the maximum size of the output buffer
int maxOutputLength = plaintext.size() + EVP_CIPHER_CTX_block_size(ctx);
vector<unsigned char> ciphertext(maxOutputLength);

int actualOutputLength = 0;
if (EVP_EncryptUpdate(ctx, ciphertext.data(), &actualOutputLength, (const unsigned char*) plaintext.c_str(), plaintext.size()) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    throw runtime_error("Failed to encrypt message");
}

int finalOutputLength = 0;
if (EVP_EncryptFinal_ex(ctx, ciphertext.data() + actualOutputLength, &finalOutputLength) != 1) {
    EVP_CIPHER_CTX_free(ctx);
    throw runtime_error("Failed to finalize encryption");
}

EVP_CIPHER_CTX_free(ctx);

// Resize the output buffer to the actual size of the ciphertext
ciphertext.resize(actualOutputLength + finalOutputLength);

return ciphertext;
}