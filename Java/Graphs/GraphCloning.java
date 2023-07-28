import java.util.*;

public class GraphCloning {
    public static Node cloneGraph(Node node) {
        if (node == null)
            return node;

        Node nHead = new Node(node.val);

        Queue<Map.Entry<Node, Node>> q = new LinkedList<>();
        Map<Node, Node> mp = new HashMap<>();
        mp.put(node, nHead);
        q.add(new AbstractMap.SimpleEntry<>(node, nHead));

        while (!q.isEmpty()) {
            Map.Entry<Node, Node> entry = q.poll();
            Node old = entry.getKey();
            Node newNode = entry.getValue();

            for (Node it : old.neighbors) {
                if (!mp.containsKey(it)) {
                    Node newChild = new Node(it.val);
                    newNode.neighbors.add(newChild);
                    mp.put(it, newChild);
                    q.add(new AbstractMap.SimpleEntry<>(it, newChild));
                } else {
                    Node newNeighbor = mp.get(it);
                    newNode.neighbors.add(newNeighbor);
                }
            }
        }

        return nHead;
    }

    public static boolean compareMemAddresses(Node one, Node two) {
        System.out.println("Values for node in graph 1 & graph 2 are:");
        System.out.println(one.val + " " + two.val);

        return one == two;
    }

    public static void bfs(Node node, boolean compare) {
        Set<Node> vis = new HashSet<>();
        vis.add(node);
        Queue<Node> q = new LinkedList<>();
        q.add(node);

        while (!q.isEmpty()) {
            Node fr = q.poll();
            int nval = fr.val;

            if (compare) {
                if (compareMemAddresses(mp1.get(nval), fr))
                    System.out.println("The pointers are pointing to the same location in memory");
                else
                    System.out.println("The pointers are not pointing to the same location in memory");
                System.out.println();
            }

            for (Node it : fr.neighbors) {
                if (!vis.contains(it)) {
                    vis.add(it);
                    q.add(it);
                }
            }
        }
    }

    static Map<Integer, Node> mp1 = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the num of nodes & edges:");
        int n = sc.nextInt();
        int m = sc.nextInt();

        System.out.println("Enter the edges:");
        while (m-- > 0) {
            int u = sc.nextInt();
            int v = sc.nextInt();

            if (!mp1.containsKey(u))
                mp1.put(u, new Node(u));
            if (!mp1.containsKey(v))
                mp1.put(v, new Node(v));

            mp1.get(u).neighbors.add(mp1.get(v));
            mp1.get(v).neighbors.add(mp1.get(u));
        }

        System.out.println("Enter the root node:");
        int rt = sc.nextInt();

        Node root = mp1.get(rt);
        Node cpyNode = cloneGraph(root);
        bfs(root, false);
        bfs(cpyNode, true);

        sc.close();
    }
}

class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}