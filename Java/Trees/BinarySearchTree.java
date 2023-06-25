public class BinarySearchTree { 

    // Root of Binary Tree 
    Node root; 

    BinarySearchTree() { 
        root = null; 
    } 

    void insert(int key) { 
       root = insertRec(root, key); 
    } 

    // A recursive function to insert a new key 
    // in BST 
    Node insertRec(Node root, int key) { 

        // If the tree is empty, return a new node 
        if (root == null) { 
            root = new Node(key); 
            return root; 
        } 

        // Otherwise, recur down the tree 
        if (key < root.key) 
            root.left = insertRec(root.left, key); 
        else if (key > root.key) 
            root.right = insertRec(root.right, key); 

        // return the (unchanged) node pointer 
        return root; 
    } 

    // This method mainly calls InorderRec() 
    void inorder()  { 
       inorderRec(root); 
    } 

    // A utility function to do inorder traversal of BST 
    void inorderRec(Node root) { 
        if (root != null) { 
            inorderRec(root.left); 
            System.out.print(root.key + " "); 
            inorderRec(root.right); 
        } 
    } 

    // Driver Program to test above functions 
    public static void main(String[] args) { 
       int n,n1;
        Scanner in=new Scanner(System.in);
        BinarySearchTree tree = new BinarySearchTree(); 
        System.out.println("Enter the number of nodes you want:");
        n=in.nextInt();
        System.out.println("Enter the elements:");
        for(int i=1;i<=n;i++)
        {
            n1=in.nextInt();
            tree.insert(n1);//entering the node given by the user
        }
        // print inorder traversal of the BST 
        tree.inorder(); 
    } 
} 

// A binary Tree node 
class Node { 
    int key; 
    Node left, right; 

    public Node(int item) { 
        key = item; 
        left = right = null; 
    } 
}
