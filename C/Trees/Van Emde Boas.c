#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

typedef struct VEBTree {
    int universeSize;
    int minimum;
    int maximum;
    struct VEBTree* summary;
    struct VEBTree** cluster;
} VEBTree;

VEBTree* createVEBTree(int size) {
    VEBTree* tree = (VEBTree*)malloc(sizeof(VEBTree));
    tree->universeSize = size;
    tree->minimum = -1;
    tree->maximum = -1;
    tree->summary = NULL;
    tree->cluster = NULL;

    if (size > 2) {
        int upperSize = (int)ceil(sqrt(size));
        int lowerSize = (int)floor(sqrt(size));

        tree->summary = createVEBTree(upperSize);
        tree->cluster = (VEBTree**)malloc(sizeof(VEBTree*) * upperSize);

        for (int i = 0; i < upperSize; i++)
            tree->cluster[i] = createVEBTree(lowerSize);
    }

    return tree;
}

void insert(VEBTree* tree, int key) {
    if (tree->minimum == -1) {
        tree->minimum = key;
        tree->maximum = key;
        return;
    }

    if (key < tree->minimum) {
        int temp = key;
        key = tree->minimum;
        tree->minimum = temp;
    }

    if (tree->universeSize > 2) {
        if (tree->cluster[key / (int)ceil(sqrt(tree->universeSize))]->minimum == -1)
            insert(tree->summary, key / (int)ceil(sqrt(tree->universeSize)));

        insert(tree->cluster[key / (int)ceil(sqrt(tree->universeSize))], key % (int)ceil(sqrt(tree->universeSize)));
    }

    if (key > tree->maximum)
        tree->maximum = key;
}

void remove(VEBTree* tree, int key) {
    if (tree->minimum == tree->maximum) {
        tree->minimum = -1;
        tree->maximum = -1;
        return;
    }

    if (tree->universeSize == 2) {
        if (key == 0)
            tree->minimum = 1;
        else
            tree->minimum = 0;

        tree->maximum = tree->minimum;
        return;
    }

    if (key == tree->minimum) {
        int firstCluster = tree->summary->minimum;
        key = firstCluster * (int)ceil(sqrt(tree->universeSize)) + tree->cluster[firstCluster]->minimum;
        tree->minimum = key;
    }

    remove(tree->cluster[key / (int)ceil(sqrt(tree->universeSize))], key % (int)ceil(sqrt(tree->universeSize)));

    if (tree->cluster[key / (int)ceil(sqrt(tree->universeSize))]->minimum == -1)
        remove(tree->summary, key / (int)ceil(sqrt(tree->universeSize)));

    if (key == tree->maximum) {
        if (tree->summary->minimum == -1)
            tree->maximum = tree->minimum;
        else {
            int lastCluster = tree->summary->maximum;
            tree->maximum = lastCluster * (int)ceil(sqrt(tree->universeSize)) + tree->cluster[lastCluster]->maximum;
        }
    }
}

int successor(VEBTree* tree, int key) {
    if (tree->universeSize == 2) {
        if (key == 0 && tree->maximum == 1)
            return 1;
        else
            return -1;
    }

    if (tree->minimum != -1 && key < tree->minimum)
        return tree->minimum;

    int maxLow = tree->cluster[key / (int)ceil(sqrt(tree->universeSize))]->maximum;

    if (maxLow != -1 && key % (int)ceil(sqrt(tree->universeSize)) < maxLow) {
        int offset = successor(tree->cluster[key / (int)ceil(sqrt(tree->universeSize))], key % (int)ceil(sqrt(tree->universeSize)));
        return key / (int)ceil(sqrt(tree->universeSize)) * (int)ceil(sqrt(tree->universeSize)) + offset;
    }

    int succCluster = successor(tree->summary, key / (int)ceil(sqrt(tree->universeSize)));

    if (succCluster == -1)
        return -1;

    int offset = tree->cluster[succCluster]->minimum;
    return succCluster * (int)ceil(sqrt(tree->universeSize)) + offset;
}

int predecessor(VEBTree* tree, int key) {
    if (tree->universeSize == 2) {
        if (key == 1 && tree->minimum == 0)
            return 0;
        else
            return -1;
    }

    if (tree->maximum != -1 && key > tree->maximum)
        return tree->maximum;

    int minLow = tree->cluster[key / (int)ceil(sqrt(tree->universeSize))]->minimum;

    if (minLow != -1 && key % (int)ceil(sqrt(tree->universeSize)) > minLow) {
        int offset = predecessor(tree->cluster[key / (int)ceil(sqrt(tree->universeSize))], key % (int)ceil(sqrt(tree->universeSize)));
        return key / (int)ceil(sqrt(tree->universeSize)) * (int)ceil(sqrt(tree->universeSize)) + offset;
    }

    int predCluster = predecessor(tree->summary, key / (int)ceil(sqrt(tree->universeSize)));

    if (predCluster == -1) {
        if (tree->minimum != -1 && key > tree->minimum)
            return tree->minimum;
        else
            return -1;
    }

    int offset = tree->cluster[predCluster]->maximum;
    return predCluster * (int)ceil(sqrt(tree->universeSize)) + offset;
}

bool contains(VEBTree* tree, int key) {
    if (key == tree->minimum || key == tree->maximum)
        return true;

    if (tree->universeSize == 2)
        return false;

    return contains(tree->cluster[key / (int)ceil(sqrt(tree->universeSize))], key % (int)ceil(sqrt(tree->universeSize)));
}

void destroyVEBTree(VEBTree* tree) {
    if (tree->summary != NULL)
        destroyVEBTree(tree->summary);

    if (tree->cluster != NULL) {
        int upperSize = (int)ceil(sqrt(tree->universeSize));

        for (int i = 0; i < upperSize; i++)
            destroyVEBTree(tree->cluster[i]);

        free(tree->cluster);
    }

    free(tree);
}

int main() {
    VEBTree* vebTree = createVEBTree(16);
    insert(vebTree, 4);
    insert(vebTree, 1);
    insert(vebTree, 8);
    insert(vebTree, 10);

    printf("%d\n", contains(vebTree, 4)); // Output: 1 (true)
    printf("%d\n", contains(vebTree, 5)); // Output: 0 (false)

    printf("%d\n", successor(vebTree, 4)); // Output: 8
    printf("%d\n", predecessor(vebTree, 4)); // Output: 1

    remove(vebTree, 4);
    printf("%d\n", contains(vebTree, 4)); // Output: 0 (false)

    destroyVEBTree(vebTree);

    return 0;
}
