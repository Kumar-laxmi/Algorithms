# Ternary Search Tree (TST) implementation in Python

#  The algorithm of the Ternary Search Tree (TST) 
# 1.) Create a TST node class with character data, left, middle, and right pointers, and an end-of-word flag.
# 2.) Implement an insert() function that recursively inserts characters into the TST based on comparisons.
# 3.) Implement a search() function that recursively searches for a string in the TST by comparing characters.
# 4.) Initialize an empty TST and use the insert() function to add strings to the TST.
# 5.) Use the search() function to check if a string exists in the TST!.

# Node class represents a node in the TST
class Node:
    def __init__(self, data):
        self.data = data                # The character stored in the node
        self.isEndOfWord = False        # Flag to indicate if the node represents the end of a word
        self.left = None                # Pointer to the left child node
        self.middle = None              # Pointer to the middle child node
        self.right = None               # Pointer to the right child node

# Ternary Search Tree class
class TernarySearchTree:
    def __init__(self):
        self.root = None                # Root node of the TST

    # Method to insert a string into the TST
    def insert(self, word):
        self.root = self._insert(self.root, word, 0)

    # Recursive method to insert a character into the TST
    def _insert(self, node, word, index):
        # If the current node is None, create a new node
        if node is None:
            node = Node(word[index])

        # Compare the current character with the character in the node
        if word[index] < node.data:
            node.left = self._insert(node.left, word, index)
        elif word[index] > node.data:
            node.right = self._insert(node.right, word, index)
        else:
            # If the characters match, move to the next character
            if index + 1 < len(word):
                node.middle = self._insert(node.middle, word, index + 1)
            else:
                # Mark the node as the end of a word
                node.isEndOfWord = True

        return node

    # Method to search for a string in the TST
    def search(self, word):
        return self._search(self.root, word, 0)

    # Recursive method to search for a character in the TST
    def _search(self, node, word, index):
        # If the current node is None, the word does not exist in the TST
        if node is None:
            return False

        # Compare the current character with the character in the node
        if word[index] < node.data:
            return self._search(node.left, word, index)
        elif word[index] > node.data:
            return self._search(node.right, word, index)
        else:
            # If the characters match, move to the next character
            if index + 1 == len(word):
                # Check if the node represents the end of a word
                return node.isEndOfWord
            else:
                return self._search(node.middle, word, index + 1)

# Main function to test the TernarySearchTree implementation
if __name__ == "__main__":
    tst = TernarySearchTree()

    # Insert some words into the TST
    tst.insert("apple")
    tst.insert("banana")
    tst.insert("carrot")
    s = input("Enter String ")

    # Search for words in the TST
    if(tst.search("apple") == True):
        print(s , " is present") # Output: True (exists)
    else:
        print(s , " is not present") # Output: False (does not exist)