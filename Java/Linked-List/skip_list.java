import java.util.Arrays;
import java.util.Random;

class SkipNode {
    int value;
    SkipNode[] forward;

    SkipNode(int level, int value) {
        this.value = value;
        this.forward = new SkipNode[level + 1];
    }
}

class SkipList {
    private static final int MAX_LEVEL = 6; // Maximum level for skip list
    private SkipNode header; // Pointer to the header node
    private int level; // Current level of the skip list

    SkipList() {
        this.header = new SkipNode(MAX_LEVEL, 0); // Create the header node with maximum level
        this.level = 0; // Set the initial level to 0
    }

    // Generate random level for a node
    private int randomLevel() {
        int level = 0;
        Random random = new Random();
        while (random.nextDouble() < 0.5 && level < MAX_LEVEL) // Randomly increase the level with a probability of 1/2
            level++;
        return level;
    }

    // Insert a value into the skip list
    void insert(int value) {
        SkipNode[] update = new SkipNode[MAX_LEVEL + 1]; // Array to store the update nodes at each level
        Arrays.fill(update, null); // Initialize all update nodes to null
        SkipNode current = header; // Start from the header node

        // Find the appropriate position to insert the value
        for (int i = level; i >= 0; i--) {
            while (current.forward[i] != null && current.forward[i].value < value)
                current = current.forward[i];
            update[i] = current; // Store the update nodes
        }

        current = current.forward[0];

        // If the value is already present, return
        if (current == null || current.value != value) {
            int newLevel = randomLevel(); // Generate a random level for the new node
            if (newLevel > level) {
                for (int i = level + 1; i <= newLevel; i++)
                    update[i] = header; // Update the pointers in the update array for the new level
                level = newLevel; // Update the current level
            }
            current = new SkipNode(newLevel, value); // Create a new node
            for (int i = 0; i <= newLevel; i++) {
                current.forward[i] = update[i].forward[i]; // Update the forward pointers
                update[i].forward[i] = current;
            }
            System.out.println("Inserted " + value + " into the skip list.");
        }
    }

    // Search for a value in the skip list
    boolean search(int value) {
        SkipNode current = header; // Start from the header node
        for (int i = level; i >= 0; i--) {
            while (current.forward[i] != null && current.forward[i].value < value)
                current = current.forward[i]; // Move forward at each level until the value is found or surpassed
        }
        current = current.forward[0]; // Move to the next node at the lowest level
        if (current != null && current.value == value) {
            System.out.println(value + " found in the skip list.");
            return true;
        }
        System.out.println(value + " not found in the skip list.");
        return false;
    }

    // Display the skip list
    void display() {
        System.out.println("Skip List:");
        for (int i = 0; i <= level; i++) {
            SkipNode node = header.forward[i];
            System.out.print("Level " + i + ": ");
            while (node != null) {
                System.out.print(node.value + " ");
                node = node.forward[i];
            }
            System.out.println();
        }
    }
}

public class skip_list {
    public static void main(String[] args) {
        SkipList skipList = new SkipList();

        skipList.insert(3);
        skipList.insert(7);
        skipList.insert(2);
        skipList.insert(9);

        skipList.display();

        skipList.search(2);
        skipList.search(5);
    }
}
