import java.util.Scanner;

public class cuckoo_hashing {
    private static final int TABLE_SIZE = 10;
    private static final int MAX_KICK_COUNT = 5;

    private static class Entry {
        private int key;
        private boolean occupied;

        Entry() {
            occupied = false;
        }
    }

    private static Entry[] table = new Entry[TABLE_SIZE];

    private static int hash(int key) {
        return key % TABLE_SIZE;
    }

    private static boolean insert(int key) {
        int index1 = hash(key);
        int index2 = (index1 + 1) % TABLE_SIZE;

        for (int i = 0; i < MAX_KICK_COUNT; i++) {
            if (!table[index1].occupied) {
                table[index1].key = key;
                table[index1].occupied = true;
                return true;
            }

            if (!table[index2].occupied) {
                table[index2].key = key;
                table[index2].occupied = true;
                return true;
            }

            int kickIndex = (i % 2 == 0) ? index1 : index2;
            int kickedKey = table[kickIndex].key;

            if (kickIndex == index1) {
                index1 = hash(kickedKey);
            } else {
                index2 = hash(kickedKey);
            }

            table[kickIndex].key = key;
            key = kickedKey;
        }

        return false;
    }

    private static boolean search(int key) {
        int index1 = hash(key);
        int index2 = (index1 + 1) % TABLE_SIZE;

        if (table[index1].occupied && table[index1].key == key) {
            return true;
        }

        if (table[index2].occupied && table[index2].key == key) {
            return true;
        }

        return false;
    }

    public static void main(String[] args) {
        // Initialize the table
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = new Entry();
        }

        Scanner scanner = new Scanner(System.in);

        // Get the number of keys to insert
        System.out.print("Enter the number of keys to insert: ");
        int numKeys = scanner.nextInt();

        // Insert the keys
        for (int i = 0; i < numKeys; i++) {
            System.out.print("Enter key " + (i + 1) + ": ");
            int key = scanner.nextInt();
            insert(key);
        }

        // Get the key to search
        System.out.print("Enter the key to search: ");
        int keyToSearch = scanner.nextInt();

        // Search for the key
        if (search(keyToSearch)) {
            System.out.println("Key " + keyToSearch + " is present");
        } else {
            System.out.println("Key " + keyToSearch + " is not present");
        }

        scanner.close();
    }
}
