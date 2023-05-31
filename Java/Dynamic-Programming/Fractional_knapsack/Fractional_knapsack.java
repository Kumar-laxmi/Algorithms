import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Item {
    int weight;
    int value;
    double valuePerWeight;

    public Item(int weight, int value) {
        this.weight = weight;
        this.value = value;
        this.valuePerWeight = (double) value / weight;
    }
}

class KnapsackComparator implements Comparator<Item> {
    public int compare(Item item1, Item item2) {
        return Double.compare(item2.valuePerWeight, item1.valuePerWeight);
    }
}

public class FractionalKnapsack {
    public static double fractionalKnapsack(int capacity, Item[] items) {
        Arrays.sort(items, new KnapsackComparator());

        double totalValue = 0.0;
        int remainingCapacity = capacity;

        for (Item item : items) {
            if (remainingCapacity >= item.weight) {
                // Add the complete item if it can fit in the knapsack
                totalValue += item.value;
                remainingCapacity -= item.weight;
            } else {
                // Add a fraction of the item if it cannot fit completely
                double fraction = (double) remainingCapacity / item.weight;
                totalValue += fraction * item.value;
                break;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the capacity of the knapsack: ");
        int capacity = scanner.nextInt();

        System.out.print("Enter the number of items: ");
        int numItems = scanner.nextInt();

        Item[] items = new Item[numItems];

        for (int i = 0; i < numItems; i++) {
            System.out.print("Enter weight and value for item " + (i + 1) + ": ");
            int weight = scanner.nextInt();
            int value = scanner.nextInt();
            items[i] = new Item(weight, value);
        }

        scanner.close();

        double maxValue = fractionalKnapsack(capacity, items);

        System.out.println("Maximum value that can be obtained: " + maxValue);
    }
}
