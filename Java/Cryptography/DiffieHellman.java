// Time complexity:

// Generating a random private key: O(n)
// Calculating the public key: O(n^3) using the naive algorithm, or O(n^2) using fast modular exponentiation algorithms such as the binary method or Montgomery ladder.
// Calculating the shared secret: O(n^3) using the naive algorithm, or O(n^2) using fast modular exponentiation algorithms.
// Space complexity:

// Storing the prime, primitive root, private key, and public key each require O(n) bits of memory.
import java.math.BigInteger;
import java.security.SecureRandom;

public class DiffieHellman {
  // prime is a large prime number used as the modulus in the calculation
  private BigInteger prime;
  // primitive root is a number that generates all non-zero residues modulo prime
  private BigInteger primitiveRoot;
  // private key is a randomly generated number used to calculate the public key
  private BigInteger privateKey;
  // public key is calculated from the primitive root, private key, and prime
  private BigInteger publicKey;
  
  // constructor that sets up the prime and primitive root for the calculation
  public DiffieHellman(BigInteger prime, BigInteger primitiveRoot) {
    this.prime = prime;
    this.primitiveRoot = primitiveRoot;
    // generate a random private key using SecureRandom for added security
    SecureRandom random = new SecureRandom();
    privateKey = new BigInteger(prime.bitLength(), random);
    // calculate the public key using the primitive root, private key, and prime
    publicKey = primitiveRoot.modPow(privateKey, prime);
  }
  
  // returns the public key
  public BigInteger getPublicKey() {
    return publicKey;
  }
  
  // calculates the shared secret using the other party's public key
  public BigInteger getSharedSecret(BigInteger otherPublicKey) {
    // returns the result of raising the other party's public key to the power of the private key, modulo prime
    return otherPublicKey.modPow(privateKey, prime);
  }
}
