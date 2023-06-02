import java.util.*;

class Item {
    int weight;
    int value;

    public Item(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }
}

class KnapsackComparator implements Comparator<Item> {
    public int compare(Item item1, Item item2) {
        double ratio1 = (double) item1.value / item1.weight;
        double ratio2 = (double) item2.value / item2.weight;
        if (ratio1 < ratio2)
            return 1;
        else if (ratio1 > ratio2)
            return -1;
        else
            return 0;
    }
}

public class FractionalKnapsack {
    public static double getMaxValue(Item[] items, int capacity) {
        Arrays.sort(items, new KnapsackComparator());

        double totalValue = 0;
        int currentWeight = 0;

        for (Item item : items) {
            if (currentWeight + item.weight <= capacity) {
                currentWeight += item.weight;
                totalValue += item.value;
            } else {
                int remainingCapacity = capacity - currentWeight;
                totalValue += (double) item.value / item.weight * remainingCapacity;
                break;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();

        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter weight and value for item " + (i + 1) + ": ");
            int weight = scanner.nextInt();
            int value = scanner.nextInt();
            items[i] = new Item(weight, value);
        }

        System.out.print("Enter the knapsack capacity: ");
        int capacity = scanner.nextInt();

        scanner.close();

        double maxValue = getMaxValue(items, capacity);
        System.out.println("The maximum value that can be obtained is: " + maxValue);
    }
}
