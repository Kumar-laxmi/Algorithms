/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
Problem Description:
Given a binary tree, check whether it is a mirror of itself.
Examples:
1] INPUT:
1
/
2 2
/ \ /
3 4 4 3
OUTPUT: Symmetric
2] INPUT:
1
/
2 2
\
3 3
OUTPUT: Not symmetric */
import java.util.*;
public class Symmetric_Tree 
{
    // Function to create a new node
    public static Node newNode(int key) 
	{
        Node temp = new Node();
        temp.key = key;
        temp.left = temp.right = null;
        return temp;
    }
    // Returns true if trees with roots as childL and childR are mirror image of each other
    public static boolean isSymmetric(Node root1, Node root2) 
	{
        // If both trees are empty, then they are mirror images
        if (root1 == null && root2 == null) 
		{
            return true;
        }
        // For two trees to be mirror images, the following 3 conditions must be true
        // a) Their root node's key must be same
        // b) left subtree of left tree and right subtree of right tree have to be mirror images
        // c) right subtree of left tree and left subtree of right tree have to be mirror images
        if (root1 != null && root2 != null && root1.key == root2.key) 
		{
            return isSymmetric(root1.left, root2.right) && isSymmetric(root1.right, root2.left);
        }
        // if none of above conditions is true then childL and childR are not mirror images
        return false;
    }
    // Returns true if a tree is symmetric.
    public static boolean isSimilar(Node root) 
	{
        // Check if tree is mirror of itself
        return isSymmetric(root, root);
    }
    // Function to take input from user
    public static Node takeInput(Scanner sc) 
	{
        System.out.print("Enter root value (-1 for no node): ");
        int val = sc.nextInt();
        if (val == -1) {
            return null;
        }
        Node root = newNode(val);
        root.left = takeInput(sc);
        root.right = takeInput(sc);
        return root;
    }
    // Main function
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);
        // Take input for the binary tree
        System.out.println("Enter elements of the binary tree:");
        Node root = takeInput(sc);
        if (isSimilar(root)) {
            System.out.println("The tree is symmetric");
        } else {
            System.out.println("The tree is not symmetric");
        }
    }
}
