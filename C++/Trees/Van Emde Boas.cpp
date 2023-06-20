#include <iostream>
#include <cmath>
#include <vector>

class VEBTree {
private:
    int universeSize;
    int minimum;
    int maximum;
    VEBTree* summary;
    std::vector<VEBTree*> cluster;

public:
    VEBTree(int size) : universeSize(size), minimum(-1), maximum(-1), summary(nullptr) {
        if (size > 2) {
            int upperSize = static_cast<int>(std::ceil(std::sqrt(size)));
            int lowerSize = static_cast<int>(std::floor(std::sqrt(size)));

            summary = new VEBTree(upperSize);
            cluster.resize(upperSize, nullptr);

            for (int i = 0; i < upperSize; i++)
                cluster[i] = new VEBTree(lowerSize);
        }
    }

    ~VEBTree() {
        if (summary != nullptr)
            delete summary;

        for (VEBTree* subTree : cluster) {
            if (subTree != nullptr)
                delete subTree;
        }
    }

    void insert(int key) {
        if (minimum == -1) {
            minimum = key;
            maximum = key;
            return;
        }

        if (key < minimum) {
            std::swap(key, minimum);
        }

        if (universeSize > 2) {
            int high = key / static_cast<int>(std::ceil(std::sqrt(universeSize)));
            int low = key % static_cast<int>(std::ceil(std::sqrt(universeSize)));

            if (cluster[high] == nullptr) {
                cluster[high] = new VEBTree(static_cast<int>(std::sqrt(universeSize)));
                summary->insert(high);
            }

            cluster[high]->insert(low);
        }

        if (key > maximum)
            maximum = key;
    }

    void remove(int key) {
        if (minimum == maximum) {
            minimum = -1;
            maximum = -1;
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
            int firstCluster = summary->minimum;
            key = firstCluster * static_cast<int>(std::ceil(std::sqrt(universeSize))) + cluster[firstCluster]->minimum;
            minimum = key;
        }

        int high = key / static_cast<int>(std::ceil(std::sqrt(universeSize)));
        int low = key % static_cast<int>(std::ceil(std::sqrt(universeSize)));

        cluster[high]->remove(low);

        if (cluster[high]->minimum == -1) {
            summary->remove(high);
        }

        if (key == maximum) {
            if (summary->minimum == -1)
                maximum = minimum;
            else {
                int lastCluster = summary->maximum;
                maximum = lastCluster * static_cast<int>(std::ceil(std::sqrt(universeSize))) + cluster[lastCluster]->maximum;
            }
        }
    }

    int successor(int key) {
        if (universeSize == 2) {
            if (key == 0 && maximum == 1)
                return 1;
            else
                return -1;
        }

        if (minimum != -1 && key < minimum)
            return minimum;

        int high = key / static_cast<int>(std::ceil(std::sqrt(universeSize)));
        int low = key % static_cast<int>(std::ceil(std::sqrt(universeSize)));

        if (cluster[high] != nullptr && low < cluster[high]->maximum) {
            int offset = cluster[high]->successor(low);
            return high * static_cast<int>(std::ceil(std::sqrt(universeSize))) + offset;
        }

        int succCluster = summary->successor(high);

        if (succCluster == -1)
            return -1;

        int offset = cluster[succCluster]->minimum;
        return succCluster * static_cast<int>(std::ceil(std::sqrt(universeSize))) + offset;
    }

    int predecessor(int key) {
        if (universeSize == 2) {
            if (key == 1 && minimum == 0)
                return 0;
            else
                return -1;
        }

        if (maximum != -1 && key > maximum)
            return maximum;

        int high = key / static_cast<int>(std::ceil(std::sqrt(universeSize)));
        int low = key % static_cast<int>(std::ceil(std::sqrt(universeSize)));

        if (cluster[high] != nullptr && low > cluster[high]->minimum) {
            int offset = cluster[high]->predecessor(low);
            return high * static_cast<int>(std::ceil(std::sqrt(universeSize))) + offset;
        }

        int predCluster = summary->predecessor(high);

        if (predCluster == -1) {
            if (minimum != -1 && key > minimum)
                return minimum;
            else
                return -1;
        }

        int offset = cluster[predCluster]->maximum;
        return predCluster * static_cast<int>(std::ceil(std::sqrt(universeSize))) + offset;
    }

    bool contains(int key) {
        if (key == minimum || key == maximum)
            return true;

        if (universeSize == 2)
            return false;

        int high = key / static_cast<int>(std::ceil(std::sqrt(universeSize)));
        int low = key % static_cast<int>(std::ceil(std::sqrt(universeSize)));

        if (cluster[high] != nullptr)
            return cluster[high]->contains(low);

        return false;
    }
};

int main() {
    VEBTree vebTree(16);
    vebTree.insert(4);
    vebTree.insert(1);
    vebTree.insert(8);
    vebTree.insert(10);

    std::cout << vebTree.contains(4) << std::endl;  // Output: 1 (true)
    std::cout << vebTree.contains(5) << std::endl;  // Output: 0 (false)

    std::cout << vebTree.successor(4) << std::endl;  // Output: 8
    std::cout << vebTree.predecessor(4) << std::endl;  // Output: 1

    vebTree.remove(4);
    std::cout << vebTree.contains(4) << std::endl;  // Output: 0 (false)

    return 0;
}
