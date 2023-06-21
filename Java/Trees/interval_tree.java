public class interval_tree {
    static class Interval {
        int low, high;

        Interval(int low, int high) {
            this.low = low;
            this.high = high;
        }
    }

    static class Node {
        Interval interval;
        int maxHigh;
        Node left;
        Node right;

        Node(Interval interval) {
            this.interval = interval;
            this.maxHigh = interval.high;
            this.left = null;
            this.right = null;
        }
    }

    static Node insert(Node root, Interval interval) {
        if (root == null)
            return new Node(interval);

        int low = root.interval.low;

        if (interval.low < low)
            root.left = insert(root.left, interval);
        else
            root.right = insert(root.right, interval);

        if (root.maxHigh < interval.high)
            root.maxHigh = interval.high;

        return root;
    }

    static boolean overlap(Interval i1, Interval i2) {
        return i1.low <= i2.high && i2.low <= i1.high;
    }

    static Interval search(Node root, Interval interval) {
        if (root == null)
            return null;

        if (overlap(root.interval, interval))
            return root.interval;

        if (root.left != null && root.left.maxHigh >= interval.low)
            return search(root.left, interval);

        return search(root.right, interval);
    }

    static void inorder(Node root) {
        if (root == null)
            return;

        inorder(root.left);
        System.out.println("[" + root.interval.low + ", " + root.interval.high + "] max = " + root.maxHigh);
        inorder(root.right);
    }

    public static void main(String[] args) {
        Interval[] intervals = { new Interval(15, 20), new Interval(10, 30), new Interval(17, 19),
                new Interval(5, 20), new Interval(12, 15), new Interval(30, 40) };

        Node root = null;
        for (Interval interval : intervals)
            root = insert(root, interval);

        System.out.println("Inorder traversal of constructed Interval Tree is:");
        inorder(root);

        Interval searchInterval = new Interval(6, 7);
        System.out.println("\nSearching for interval [" + searchInterval.low + ", " + searchInterval.high + "]");
        Interval result = search(root, searchInterval);
        if (result != null)
            System.out.println("Overlaps with [" + result.low + ", " + result.high + "]");
    }
}
