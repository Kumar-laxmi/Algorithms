import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Huffman {
  // A node of the Huffman tree
  public static class Node implements Comparable<Node> {
    public int value;
    public char character;
    public Node left;
    public Node right;

    public Node(int value, char character) {
      this.value = value;
      this.character = character;
    }

    public int compareTo(Node other) {
      return this.value - other.value;
    }
  }

  public static Map<Character, String> huffman(int[] frequencies, char[] characters) {
    // Create a priority queue to hold the nodes of the Huffman tree
    PriorityQueue<Node> queue = new PriorityQueue<>();

    // Create a leaf node for each character and add it to the queue
    for (int i = 0; i < frequencies.length; i++) {
      queue.add(new Node(frequencies[i], characters[i]));
    }

    // Repeatedly merge the lowest-frequency nodes until there is only one node left
    while (queue.size() > 1) {
      Node left = queue.poll();
      Node right = queue.poll();
      Node parent = new Node(left.value + right.value, '*');
      parent.left = left;
      parent.right = right;
      queue.add(parent);
    }

    // The remaining node is the root of the Huffman tree
    Node root = queue.poll();

    // Use a map to store the Huffman codes for each character
    Map<Character, String> codes = new HashMap<>();
    assignCodes(codes, root, "");
    return codes;
  }

  // Recursively visit the nodes of the tree and assign codes to the characters
  public static void assignCodes(Map<Character, String> codes, Node node, String prefix) {
    if (node.character != '*') {
      codes.put(node.character, prefix);
    } else {
      assignCodes(codes, node.left, prefix + "0");
      assignCodes(codes, node.right, prefix + "1");
    }
  }

  public static void main(String[] args) {
    // Test the Huffman coding algorithm
    int[] frequencies = {45, 13, 12, 16, 9, 5};
    char[] characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    Map<Character, String> codes = huffman(frequencies, characters);
    for (Map.Entry<Character, String> entry : codes.entrySet()) {
      System.out.println(entry.getKey() + ": " + entry.getValue());
    }
  }
}
