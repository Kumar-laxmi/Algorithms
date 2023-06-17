import java.util.*;
import java.util.Scanner;

class Binary_Tree_View {
    static Scanner scanner = new Scanner(System.in);

    static class Node {
        int key;
        Node left, right;
        int level;

        // Constructor
        Node(int k) {
            key = k;
            left = right = null;
        }
    }

    static Node insert(Node root) {
        System.out.print("Enter value to be entered: ");
        int val = scanner.nextInt();
        root = new Node(val);

        if (val == -1)
            return null;

        System.out.print("Enter value to left of " + val + ": ");
        root.left = insert(root.left);
        System.out.print("Enter value to right of " + val + ": ");
        root.right = insert(root.right);

        return root;
    }

    static void display(List<Integer> V) {
        for (int i : V) {
            System.out.print(i + " ");
        }
    }

    static class Pair<T, U> {
        public T first;
        public U second;

        public Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static List<Integer> leftView(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        // initialising variables
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        root.level = 0;
        int level;

        // Tree Map keeps entries of Map sorted by key
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        
        while (!q.isEmpty()) 
        {
            Node temp = q.peek();
            level = temp.level;

            if(!mp.containsKey(level))
                mp.put(level, temp.key);
            
            q.poll();

            if (temp.left != null) 
            {
                temp.left.level = level + 1;
                q.add(temp.left);
            }
            if (temp.right != null) 
            {
                temp.right.level = level + 1;
                q.add(temp.right);
            }    
        }
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            res.add(entry.getValue());
        }
        return res;
    }

    static List<Integer> rightView(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        Queue<Node> q = new LinkedList<>();
        q.add(root);
        root.level = 0;
        int level;
        TreeMap<Integer, Integer> mp = new TreeMap<>();

        while (!q.isEmpty()) 
        {
            Node temp = q.peek();
            level = temp.level;

            mp.put(level, temp.key);
            q.poll();

            if (temp.left != null) 
            {
                temp.left.level = level + 1;
                q.add(temp.left);
            }
            if (temp.right != null) 
            {
                temp.right.level = level + 1;
                q.add(temp.right);
            }   
        }
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            res.add(entry.getValue());
        }
        return res;
    }

    static List<Integer> topView(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        Queue<Node> q = new LinkedList<>();
        q.add(root);
        root.level = 0;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        int level;

        while (!q.isEmpty()) 
        {
            Node temp = q.peek();
            level = temp.level;

            if (!mp.containsKey(level))
                mp.put(level, temp.key);
            q.poll();

            if (temp.left != null) 
            {
                temp.left.level = level - 1;
                q.add(temp.left);
            }
            if (temp.right != null) 
            {
                temp.right.level = level + 1;
                q.add(temp.right);
            }
        }
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            res.add(entry.getValue());
        }
        return res;
    }

    static List<Integer> bottomView(Node root) {
        List<Integer> res = new ArrayList<>();
        
        if (root == null)
            return res;

        Queue<Node> q = new LinkedList<>();
        q.add(root);
        root.level = 0;
        int level;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
       
        while (!q.isEmpty()) 
        {
            Node temp = q.peek();
            level = temp.level;

            mp.put(level, temp.key);
            q.poll();

            if (temp.left != null) 
            {
                temp.left.level = level - 1;
                q.add(temp.left);
            }
            if (temp.right != null) 
            {
                temp.right.level = level + 1;
                q.add(temp.right);
            }
        }
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            res.add(entry.getValue());
        }

        return res;
    }

    public static void main(String[] args) {
        Node root = null;
        System.out.println("Enter binary tree nodes, and for no node enter -1\n");
        root = insert(root);
        List<Integer> L = new ArrayList<>();
        List<Integer> R = new ArrayList<>();
        List<Integer> T = new ArrayList<>();
        List<Integer> B = new ArrayList<>();
        int usrchoice = 0;

        while (true) {
            System.out.println("\n\n1.Left View\n2.Right View\n3.Top View\n4.Bottom View\n5.Exit");
            System.out.print("Enter the choice of operation to be implemented: ");
            usrchoice = scanner.nextInt();

            switch (usrchoice) {
                case 1:
                    L=leftView(root);
                    display(L);
                    break;

                case 2:
                    R=rightView(root);
                    display(R);
                    break;

                case 3:
                    T = topView(root);
                    display(T);
                    break;

                case 4:
                    B = bottomView(root);
                    display(B);
                    break;

                case 5:
                    System.exit(0);

                default:
                    System.out.print("Enter a valid choice: ");
                    break;
            }
        }
    }
}