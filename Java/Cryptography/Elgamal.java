import java.math.BigInteger;
import java.security.SecureRandom;

public class Elgamal {
    private static BigInteger TWO = BigInteger.valueOf(2);

   public static void main(String[] args) {
    BigInteger p = generateLargePrime();
    BigInteger g = generateGenerator(p);
    BigInteger privateKey = generatePrivateKey(p);
    BigInteger publicKey = generatePublicKey(g, p, privateKey);
    
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter the message: ");
    String message = scanner.nextLine();
    scanner.close();    
    System.out.println("Original Message: " + message);    
    ElGamalCipher cipher = encrypt(message, publicKey, p, g);
    String decryptedMessage = decrypt(cipher, privateKey, p);    
    System.out.println("Decrypted Message: " + decryptedMessage);
   }

    private static BigInteger generateLargePrime() {
        return BigInteger.probablePrime(512, new SecureRandom());
    }

    private static BigInteger generateGenerator(BigInteger p) {
        BigInteger g;
        do {
            g = randomBigInteger(TWO, p.subtract(BigInteger.ONE));
        } while (!isGenerator(g, p));
        return g;
    }

    private static BigInteger randomBigInteger(BigInteger min, BigInteger max) {
        BigInteger range = max.subtract(min).add(BigInteger.ONE);
        BigInteger result;
        do {
            result = new BigInteger(range.bitLength(), new SecureRandom());
        } while (result.compareTo(range) >= 0);
        return result.add(min);
    }

    private static boolean isGenerator(BigInteger g, BigInteger p) {
        BigInteger groupOrder = p.subtract(BigInteger.ONE);
        BigInteger power = g.modPow(groupOrder, p);
        return power.equals(BigInteger.ONE);
    }

    private static BigInteger generatePrivateKey(BigInteger p) {
             return randomBigInteger(TWO, p.subtract(TWO));
    }

    private static BigInteger generatePublicKey(BigInteger g, BigInteger p, BigInteger privateKey) {
   
        return g.modPow(privateKey, p);
    }

    private static ElGamalCipher encrypt(String message, BigInteger publicKey, BigInteger p, BigInteger g) {
        byte[] messageBytes = message.getBytes();
        ElGamalCipher cipher = new ElGamalCipher();

        for (byte b : messageBytes) {
            BigInteger k = generatePrivateKey(p);
            BigInteger r = g.modPow(k, p);
            BigInteger m = BigInteger.valueOf(b).multiply(publicKey.modPow(k, p)).mod(p);
            cipher.addEncryptedValues(r, m);
        }

        return cipher;
    }

    private static String decrypt(ElGamalCipher cipher, BigInteger privateKey, BigInteger p) {
        StringBuilder decryptedMessage = new StringBuilder();

        for (int i = 0; i < cipher.getSize(); i++) {
            BigInteger r = cipher.getR(i);
            BigInteger m = cipher.getM(i);
            BigInteger s = r.modPow(privateKey, p);
            BigInteger originalMessage = m.multiply(s.modInverse(p)).mod(p);
            decryptedMessage.append((char) originalMessage.intValue());
        }

        return decryptedMessage.toString();
    }

    static class ElGamalCipher {
        private final BigInteger[] rValues;
        private final BigInteger[] mValues;
        private int index;

        public ElGamalCipher() {
            rValues = new BigInteger[100];
            mValues = new BigInteger[100];
            index = 0;
        }

        public void addEncryptedValues(BigInteger r, BigInteger m) {
            rValues[index] = r;
            mValues[index] = m;
            index++;
        }

        public BigInteger getR(int i) {
            return rValues[i];
        }

        public BigInteger getM(int i) {
            return mValues[i];
        }

        public int getSize() {
            return index;
        }
    }
}
