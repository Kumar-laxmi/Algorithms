// Ternary Search Tree (TST) implementation in Java
import java.util.Scanner;  // Import the Scanner class

// The algorithm of the Ternary Search Tree (TST) 
//1.) Create a TST node class with character data, left, middle, and right pointers, and an end-of-word flag.
//2.) Implement an insert() function that recursively inserts characters into the TST based on comparisons.
//3.) Implement a search() function that recursively searches for a string in the TST by comparing characters.
//4.) Initialize an empty TST and use the insert() function to add strings to the TST.
//5.) Use the search() function to check if a string exists in the TST.

// Main class
public class TernarySearchTree {
    // Node class represents a node in the TST
static class Node {
    char data;                  // The character stored in the node
    boolean isEndOfWord;        // Flag to indicate if the node represents the end of a word
    Node left, middle, right;   // Pointers to the left, middle, and right child nodes

    // Constructor to initialize the node
    Node(char data) {
        this.data = data;
        this.isEndOfWord = false;
        this.left = this.middle = this.right = null;
    }
}

// Ternary Search Tree class
static class ternarySearchTree {
    Node root;  // Root node of the TST

    // Method to insert a string into the TST
    void insert(String word) {
        root = insert(root, word, 0);
    }

    // Recursive method to insert a character into the TST
    Node insert(Node node, String word, int index) {
        // If the current node is null, create a new node
        if (node == null) {
            node = new Node(word.charAt(index));
        }

        // Compare the current character with the character in the node
        if (word.charAt(index) < node.data) {
            node.left = insert(node.left, word, index);
        } else if (word.charAt(index) > node.data) {
            node.right = insert(node.right, word, index);
        } else {
            // If the characters match, move to the next character
            if (index + 1 < word.length()) {
                node.middle = insert(node.middle, word, index + 1);
            } else {
                // Mark the node as the end of a word
                node.isEndOfWord = true;
            }
        }
        return node;
    }

    // Method to search for a string in the TST
    boolean search(String word) {
        return search(root, word, 0);
    }

    // Recursive method to search for a character in the TST
    boolean search(Node node, String word, int index) {
        // If the current node is null, the word does not exist in the TST
        if (node == null) {
            return false;
        }

        // Compare the current character with the character in the node
        if (word.charAt(index) < node.data) {
            return search(node.left, word, index);
        } else if (word.charAt(index) > node.data) {
            return search(node.right, word, index);
        } else {
            // If the characters match, move to the next character
            if (index + 1 == word.length()) {
                // Check if the node represents the end of a word
                return node.isEndOfWord;
            } else {
                return search(node.middle, word, index + 1);
            }
        }
    }
}


    // Main method
    public static void main(String[] args) {
        ternarySearchTree tst = new ternarySearchTree();

        // Insert some words into the TST
        tst.insert("apple");
        tst.insert("banana");
        tst.insert("carrot");

        // Search for words in the TST
        Scanner myObj = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter string");
        String s = myObj.nextLine();
        if(tst.search(s) == true){System.out.println(s + " is present");}// Output: true (exists)
        else {System.out.println(s + " is not present");} // Output: false (does not exist)
    }
}