import java.util.Arrays;
import java.util.Random;

class SkipListNode {
    int value;
    SkipListNode[] forward;

    SkipListNode(int level, int value) {
        this.value = value;
        forward = new SkipListNode[level + 1];
        Arrays.fill(forward, null);
    }
}

class SkipList {
    private static final int MAX_LEVEL = 16;
    private int level;
    private SkipListNode header;
    private Random random;

    SkipList() {
        level = 0;
        header = new SkipListNode(MAX_LEVEL, 0);
        random = new Random();
    }

    int randomLevel() {
        int level = 0;
        while (random.nextInt() < Integer.MAX_VALUE / 2 && level < MAX_LEVEL) {
            level++;
        }
        return level;
    }

    void insert(int value) {
        SkipListNode[] update = new SkipListNode[MAX_LEVEL + 1];
        SkipListNode current = header;

        for (int i = level; i >= 0; i--) {
            while (current.forward[i] != null && current.forward[i].value < value) {
                current = current.forward[i];
            }
            update[i] = current;
        }

        current = current.forward[0];

        if (current != null && current.value == value) {
            System.out.println("Value already exists: " + value);
            return;
        }

        int newNodeLevel = randomLevel();

        if (newNodeLevel > level) {
            for (int i = level + 1; i <= newNodeLevel; i++) {
                update[i] = header;
            }
            level = newNodeLevel;
        }

        SkipListNode newNode = new SkipListNode(newNodeLevel, value);

        for (int i = 0; i <= newNodeLevel; i++) {
            newNode.forward[i] = update[i].forward[i];
            update[i].forward[i] = newNode;
        }

        System.out.println("Inserted value: " + value);
    }

    boolean search(int value) {
        SkipListNode current = header;

        for (int i = level; i >= 0; i--) {
            while (current.forward[i] != null && current.forward[i].value < value) {
                current = current.forward[i];
            }
        }

        current = current.forward[0];

        if (current != null && current.value == value) {
            System.out.println("Value found: " + value);
            return true;
        }

        System.out.println("Value not found: " + value);
        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        SkipList skipList = new SkipList();

        skipList.insert(3);
        skipList.insert(6);
        skipList.insert(2);
        skipList.insert(9);

        skipList.search(6);
        skipList.search(5);
    }
}
