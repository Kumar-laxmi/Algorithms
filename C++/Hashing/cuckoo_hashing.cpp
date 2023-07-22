#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;
const int MAX_KICK_COUNT = 5;

struct Entry {
    int key;
    bool occupied;

    Entry() {
        occupied = false;
    }
};

vector<Entry> table(TABLE_SIZE);

int hashFunc(int key) {
    return key % TABLE_SIZE;
}

bool insert(int key) {
    int index1 = hashFunc(key);
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
            index1 = hashFunc(kickedKey);
        } else {
            index2 = hashFunc(kickedKey);
        }

        table[kickIndex].key = key;
        key = kickedKey;
    }

    return false;
}

bool search(int key) {
    int index1 = hashFunc(key);
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
    // Get the number of keys to insert
    int numKeys;
    cout << "Enter the number of keys to insert: ";
    cin >> numKeys;

    // Insert the keys
    for (int i = 0; i < numKeys; i++) {
        int key;
        cout << "Enter key " << (i + 1) << ": ";
        cin >> key;
        insert(key);
    }

    // Get the key to search
    int keyToSearch;
    cout << "Enter the key to search: ";
    cin >> keyToSearch;

    // Search for the key
    if (search(keyToSearch)) {
        cout << "Key " << keyToSearch << " is present" << endl;
    } else {
        cout << "Key " << keyToSearch << " is not present" << endl;
    }

    return 0;
}
