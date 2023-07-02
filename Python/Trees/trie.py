# Path: C/Trees/trie.c
# C program to implement trie.

# A prefix trie is an ordered tree data structure used in the representation of a set of strings over a finite alphabet set,
# which allows efficient storage of words with common prefixes.

class TrieNode:
    # Trie node
    def __init__(self):
        # 26 lowercase alphabets
        self.children = [None] * 26
        self.isEndOfWord = False


# Creates a new Trie node
def createNode():
    return TrieNode()


# Inserts a word into the Trie
def insert(root, word):
    currentNode = root

    for char in word:
        ind = ord(char) - ord('a')

        if currentNode.children[ind] is None:
            currentNode.children[ind] = createNode()

        currentNode = currentNode.children[ind]

    currentNode.isEndOfWord = True


# Searches for a word in the Trie
def search(root, word):
    currentNode = root

    for char in word:
        ind = ord(char) - ord('a')

        if currentNode.children[ind] is None:
            return False

        currentNode = currentNode.children[ind]

    return currentNode is not None and currentNode.isEndOfWord


# Checks if a Trie node has any children
def hasChildren(node):
    for child in node.children:
        if child is not None:
            return True

    return False


# Deletes a word from the Trie
def deleteWord(root, word, level):
    if root is None:
        return False

    if level == len(word):
        if root.isEndOfWord:
            root.isEndOfWord = False

            if not hasChildren(root):
                root = None

            return True

        return False

    ind = ord(word[level]) - ord('a')
    deleted = deleteWord(root.children[ind], word, level + 1)

    if deleted and not hasChildren(root.children[ind]):
        root.children[ind] = None

    return deleted


# Deletes the entire Trie
def deleteTrie(root):
    if root is None:
        return

    for child in root.children:
        if child is not None:
            deleteTrie(child)

    del root


# Program starts here
if __name__ == "__main__":
    root = createNode()

    # Inserting words into the Trie
    insert(root, "apple")
    insert(root, "banana")
    insert(root, "car")
    insert(root, "cat")
    insert(root, "cart")
    insert(root, "candid")
    print("Words: apple, banana, car, cat, cart, candid are Inserted.\n")

    print("Search results:")

    # Searching for words in the Trie
    print("apple:", "Found" if search(root, "apple") else "Not found")
    print("banana:", "Found" if search(root, "banana") else "Not found")
    print("care:", "Found" if search(root, "care") else "Not found")
    print("cat:", "Found" if search(root, "cat") else "Not found")
    print("cart:", "Found" if search(root, "cart") else "Not found")
    print("dog:", "Found" if search(root, "dog") else "Not found")

    # Deleting words from the Trie
    deleteWord(root, "banana", 0)

    print("\nAfter deleting 'banana':")
    print("banana:", "Found" if search(root, "banana") else "Not found")

    deleteWord(root, "car", 0)

    print("\nAfter deleting 'car':")
    print("car:", "Found" if search(root, "car") else "Not found")
    print("cart:", "Found" if search(root, "cart") else "Not found")

    # Deleting the entire Trie
    deleteTrie(root)
