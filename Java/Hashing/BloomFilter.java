import java.util.BitSet;

public class BloomFilter {
    private BitSet bitArray;
    private int size;
    private int hashFunctions;

    public BloomFilter(int size, int hashFunctions) {
        this.size = size;
        this.hashFunctions = hashFunctions;
        this.bitArray = new BitSet(size);
    }

    public void add(Object element) {
        for (int i = 0; i < hashFunctions; i++) {
            int index = hash(element, i) % size;
            bitArray.set(index);
        }
    }

    public boolean query(Object element) {
        for (int i = 0; i < hashFunctions; i++) {
            int index = hash(element, i) % size;
            if (!bitArray.get(index)) {
                return false; // Definitely not in the set
            }
        }
        return true; // Probably in the set
    }

    private int hash(Object element, int seed) {
        int hashValue = seed;
        byte[] bytes = elementToBytes(element);
        for (byte b : bytes) {
            hashValue = (hashValue * 65599) ^ (b & 0xFF);
        }
        return Math.abs(hashValue);
    }

    private byte[] elementToBytes(Object element) {
        if (element instanceof String) {
            return ((String) element).getBytes();
        } else if (element instanceof Integer) {
            return intToBytes((Integer) element);
        } else if (element instanceof Float) {
            return floatToBytes((Float) element);
        } else if (element instanceof Byte) {
            return new byte[]{(Byte) element};
        } else if (element instanceof Double) {
            return doubleToBytes((Double) element);
        } else if (element instanceof Long) {
            return longToBytes((Long) element);
        } else {
            throw new IllegalArgumentException("Unsupported element type");
        }
    }

    private byte[] intToBytes(int value) {
        return new byte[]{
                (byte) (value >>> 24),
                (byte) (value >>> 16),
                (byte) (value >>> 8),
                (byte) value
        };
    }

    private byte[] floatToBytes(float value) {
        return intToBytes(Float.floatToIntBits(value));
    }

    private byte[] doubleToBytes(double value) {
        return longToBytes(Double.doubleToLongBits(value));
    }

    private byte[] longToBytes(long value) {
        return new byte[]{
                (byte) (value >>> 56),
                (byte) (value >>> 48),
                (byte) (value >>> 40),
                (byte) (value >>> 32),
                (byte) (value >>> 24),
                (byte) (value >>> 16),
                (byte) (value >>> 8),
                (byte) value
        };
    }

    public static void main(String[] args) {
        BloomFilter filter = new BloomFilter(100, 2);

        int intValue = 42;
        filter.add(intValue);

        String stringValue = "example";
        filter.add(stringValue);

        // Querying for membership
        System.out.println("Querying 42: " + filter.query(intValue)); // Output: true (probably in the set)
        System.out.println("Querying 'example': " + filter.query(stringValue)); // Output: true (probably in the set)
        System.out.println("Querying 'world': " + filter.query("world")); // Output: false (definitely not in the set)
         System.out.println("Querying 'worldd': " + filter.query("worldd")); // Output: false (definitely not in the set -> false positive)
    }
}


