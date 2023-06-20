import java.util.Arrays;

public class MyVEBTree {
    private int universeSize;
    private int minimum;
    private int maximum;
    private MyVEBTree summary;
    private MyVEBTree[] cluster;

    public MyVEBTree(int size) {
        universeSize = size;
        minimum = -1;
        maximum = -1;

        if (size > 2) {
            int upperSize = (int) Math.ceil(Math.sqrt(size));
            int lowerSize = (int) Math.floor(Math.sqrt(size));

            summary = new MyVEBTree(upperSize);
            cluster = new MyVEBTree[upperSize];

            for (int i = 0; i < upperSize; i++)
                cluster[i] = new MyVEBTree(lowerSize);
        }
    }

    public void insert(int key) {
        if (minimum == -1) {
            minimum = maximum = key;
            return;
        }

        if (key < minimum) {
            int temp = key;
            key = minimum;
            minimum = temp;
        }

        if (universeSize > 2) {
            if (cluster[key / (int) Math.sqrt(universeSize)].minimum == -1)
                summary.insert(key / (int) Math.sqrt(universeSize));

            cluster[key / (int) Math.sqrt(universeSize)].insert(key % (int) Math.sqrt(universeSize));
        }

        if (key > maximum)
            maximum = key;
    }

    public void remove(int key) {
        if (minimum == maximum) {
            minimum = maximum = -1;
            return;
        }

        if (universeSize == 2) {
            if (key == 0)
                minimum = 1;
            else
                minimum = 0;

            maximum = minimum;
            return;
        }

        if (key == minimum) {
            int firstCluster = summary.minimum;
            key = firstCluster * (int) Math.sqrt(universeSize) + cluster[firstCluster].minimum;
            minimum = key;
        }

        cluster[key / (int) Math.sqrt(universeSize)].remove(key % (int) Math.sqrt(universeSize));

        if (cluster[key / (int) Math.sqrt(universeSize)].minimum == -1)
            summary.remove(key / (int) Math.sqrt(universeSize));

        if (key == maximum) {
            if (summary.minimum == -1)
                maximum = minimum;
            else {
                int lastCluster = summary.maximum;
                maximum = lastCluster * (int) Math.sqrt(universeSize) + cluster[lastCluster].maximum;
            }
        }
    }

    public int successor(int key) {
        if (universeSize == 2) {
            if (key == 0 && maximum == 1)
                return 1;
            else
                return -1;
        }

        if (minimum != -1 && key < minimum)
            return minimum;

        int maxLow = cluster[key / (int) Math.sqrt(universeSize)].maximum;

        if (maxLow != -1 && key % (int) Math.sqrt(universeSize) < maxLow) {
            int offset = cluster[key / (int) Math.sqrt(universeSize)].successor(key % (int) Math.sqrt(universeSize));
            return key / (int) Math.sqrt(universeSize) * (int) Math.sqrt(universeSize) + offset;
        }

        int succCluster = summary.successor(key / (int) Math.sqrt(universeSize));

        if (succCluster == -1)
            return -1;

        int offset = cluster[succCluster].minimum;
        return succCluster * (int) Math.sqrt(universeSize) + offset;
    }

    public int predecessor(int key) {
        if (universeSize == 2) {
            if (key == 1 && minimum == 0)
                return 0;
            else
                return -1;
        }

        if (maximum != -1 && key > maximum)
            return maximum;

        int minLow = cluster[key / (int) Math.sqrt(universeSize)].minimum;

        if (minLow != -1 && key % (int) Math.sqrt(universeSize) > minLow) {
            int offset = cluster[key / (int) Math.sqrt(universeSize)].predecessor(key % (int) Math.sqrt(universeSize));
            return key / (int) Math.sqrt(universeSize) * (int) Math.sqrt(universeSize) + offset;
        }

        int predCluster = summary.predecessor(key / (int) Math.sqrt(universeSize));

        if (predCluster == -1) {
            if (minimum != -1 && key > minimum)
                return minimum;
            else
                return -1;
        }

        int offset = cluster[predCluster].maximum;
        return predCluster * (int) Math.sqrt(universeSize) + offset;
    }

    public boolean contains(int key) {
        if (key == minimum || key == maximum)
            return true;

        if (universeSize == 2)
            return false;

        return cluster[key / (int) Math.sqrt(universeSize)].contains(key % (int) Math.sqrt(universeSize));
    }

    public static void main(String[] args) {
        MyVEBTree vebTree = new MyVEBTree(16);
        vebTree.insert(4);
        vebTree.insert(1);
        vebTree.insert(8);
        vebTree.insert(10);

        System.out.println(vebTree.contains(4)); // Output: true
        System.out.println(vebTree.contains(5)); // Output: false

        System.out.println(vebTree.successor(4)); // Output: 8
        System.out.println(vebTree.predecessor(4)); // Output: 1

        vebTree.remove(4);
        System.out.println(vebTree.contains(4)); // Output: false
    }
}

}
