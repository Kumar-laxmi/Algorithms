import java.util.Scanner;

class splayTree {
    class Node {
        int key;
        Node left, right;

        public Node(int key) {
            this.key = key;
            left = right = null;
        }
    }

    Node root;

    public SplayTree() {
        root = null;
    }

    public Node search(int key) {
        return search(root, key);
    }

    private Node search(Node root, int key) {
        if (root == null || root.key == key) {
            return root;
        }

        if (root.key > key) {
            return search(root.left, key);
        } else {
            return search(root.right, key);
        }
    }

    public void insert(int key) {
        root = insert(root, key);
    }

    private Node insert(Node root, int key) {
        if (root == null) {
            return new Node(key);
        }

        root = splay(root, key);

        if (key < root.key) {
            Node newNode = new Node(key);
            newNode.right = root;
            newNode.left = root.left;
            root.left = null;
            root = newNode;
        } else if (key > root.key) {
            Node newNode = new Node(key);
            newNode.left = root;
            newNode.right = root.right;
            root.right = null;
            root = newNode;
        }

        return root;
    }

    public void delete(int key) {
        root = delete(root, key);
    }

    private Node delete(Node root, int key) {
        Node temp;
        if (root == null) {
            return null;
        }

        root = splay(root, key);

        if (key == root.key) {
            if (root.left == null) {
                temp = root;
                root = root.right;
            } else {
                temp = root;
                root = splay(root.left, key);
                root.right = temp.right;
            }
            temp = null;
        }

        return root;
    }

    private Node splay(Node root, int key) {
        if (root == null || root.key == key) {
            return root;
        }

        if (key < root.key) {
            if (root.left == null) {
                return root;
            }

            if (key < root.left.key) {
                root.left.left = splay(root.left.left, key);
                root = rightRotate(root);
            } else if (key > root.left.key) {
                root.left.right = splay(root.left.right, key);
                if (root.left.right != null) {
                    root.left = leftRotate(root.left);
                }
            }
            return root.left == null ? root : rightRotate(root);
        } else {
            if (root.right == null) {

                return root;
            }
    
            if (key > root.right.key) {
                root.right.right = splay(root.right.right, key);
                root = leftRotate(root);
            } else if (key < root.right.key) {
                root.right.left = splay(root.right.left, key);
                if (root.right.left != null) {
                    root.right = rightRotate(root.right);
                }
            }
    
            return root.right == null ? root : leftRotate(root);
        }
    
        private Node leftRotate(Node x) {
            Node y = x.right;
            x.right = y.left;
            y.left = x;
            return y;
        }
    
        private Node rightRotate(Node x) {
            Node y = x.left;
            x.left = y.right;
            y.right = x;
            return y;
        }
    
        public void inOrder() {
            inOrder(root);
        }
    
        private void inOrder(Node root) {
            if (root != null) {
                inOrder(root.left);
                System.out.print(root.key + " ");
                inOrder(root.right);
            }
        }
    }
    
    public class Main {
        public static void main(String[] args) {
            SplayTree spt = new SplayTree();
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int num = sc.nextInt();
                spt.insert(num);
            }
            spt.inOrder();
        }
    }
}
    
