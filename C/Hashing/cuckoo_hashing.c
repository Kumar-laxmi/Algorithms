#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define MAX_KICK_COUNT 5

typedef struct {
    int key;
    bool occupied;
} Entry;

Entry table[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

bool insert(int key) {
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

bool search(int key) {
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

int main() {
    // Initialize the table
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].occupied = false;
    }

    // Get the number of keys to insert
    int numKeys;
    printf("Enter the number of keys to insert: ");
    scanf("%d", &numKeys);

    // Insert the keys
    for (int i = 0; i < numKeys; i++) {
        int key;
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }

    // Get the key to search
    int keyToSearch;
    printf("Enter the key to search: ");
    scanf("%d", &keyToSearch);

    // Search for the key
    if (search(keyToSearch)) {
        printf("Key %d is present\n", keyToSearch);
    } else {
        printf("Key %d is not present\n", keyToSearch);
    }

    return 0;
}
