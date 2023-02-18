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
// Java program to check is binary tree is symmetric or not
// Construct a Binary Tree Node
class Node 
{
	int key;
	Node left, right;
	Node(int item)
	{
		key = item;
		left = right = null;
	}
}
    // function to create a new Node
public class Symmetric_Tree 
{
	Node root;
	// Returns true if trees with roots as childL and childR are mirror image of each other
	boolean isMirror(Node node1, Node node2)
	{
	// If both trees are empty, then they are mirror images
		if (node1 == null && node2 == null)
			return true;
	// For two trees to be mirror images, the following 3 conditions must be true
	// a) Their root node's key must be same
	// b) left subtree of left tree and right subtree of right tree have to be mirror images
	// c) right subtree of left tree and left subtree of right tree have to be mirror images
		if (node1 != null && node2 != null
			&& node1.key == node2.key)
			return (isMirror(node1.left, node2.right)
					&& isMirror(node1.right, node2.left));
	// if none of above conditions is true then childL and childR are not mirror images
		return false;
	}
	// Returns true if a tree is symmetric.
	boolean isSymmetric()
	{
	// Check if tree is mirror of itself
		return isMirror(root, root);
	}
	// Main Function
	public static void main(String args[])
	{
		Symmetric_Tree tree = new Symmetric_Tree();
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(2);
		tree.root.left.left = new Node(3);
		tree.root.left.right = new Node(4);
		tree.root.right.left = new Node(4);
		tree.root.right.right = new Node(3);
		boolean output = tree.isSymmetric();
		if (output == true)
			System.out.println("Is Symmetric");
		else
			System.out.println("Is Not symmetric");
	}
}