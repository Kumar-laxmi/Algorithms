TABLE_SIZE = 10
MAX_KICK_COUNT = 5

class Entry:
    def __init__(self, key):
        self.key = key
        self.occupied = False

table = [Entry(None) for _ in range(TABLE_SIZE)]

def hash_func(key):
    return key % TABLE_SIZE

def insert(key):
    index1 = hash_func(key)
    index2 = (index1 + 1) % TABLE_SIZE

    for _ in range(MAX_KICK_COUNT):
        if not table[index1].occupied:
            table[index1].key = key
            table[index1].occupied = True
            return True

        if not table[index2].occupied:
            table[index2].key = key
            table[index2].occupied = True
            return True

        kick_index = index1 if _ % 2 == 0 else index2
        kicked_key = table[kick_index].key

        if kick_index == index1:
            index1 = hash_func(kicked_key)
        else:
            index2 = hash_func(kicked_key)

        table[kick_index].key = key
        key = kicked_key

    return False

def search(key):
    index1 = hash_func(key)
    index2 = (index1 + 1) % TABLE_SIZE

    if table[index1].occupied and table[index1].key == key:
        return True

    if table[index2].occupied and table[index2].key == key:
        return True

    return False

# Get the number of keys to insert
num_keys = int(input("Enter the number of keys to insert: "))

# Insert the keys
for i in range(num_keys):
    key = int(input("Enter key {}: ".format(i+1)))
    insert(key)

# Get the key to search
key_to_search = int(input("Enter the key to search: "))

# Search for the key
if search(key_to_search):
    print("Key {} is present".format(key_to_search))
else:
    print("Key {} is not present".format(key_to_search))
