import java.util.HashMap;

public class LoopDetection {

  public static boolean hasLoop(Node head) {
    HashMap<Integer, Node> hashTable = new HashMap<>();

    while (head != null) {
      if (hashTable.containsKey(head.data)) {
        return true;
      } else {
        hashTable.put(head.data, head);
        head = head.next;
      }
    }

    return false;
  }

  public static void main(String[] args) {
    Node head = new Node(1);
    head.next = new Node(2);
    head.next.next = new Node(3);
    head.next.next.next = head;

    if (hasLoop(head)) {
      System.out.println("The linked list has a loop.");
    } else {
      System.out.println("The linked list does not have a loop.");
    }
  }
}

class Node {

  int data;
  Node next;

  public Node(int data) {
    this.data = data;
    this.next = null;
  }
}
