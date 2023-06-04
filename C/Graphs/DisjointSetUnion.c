#include <stdio.h>
#include <stdlib.h>

struct DisjointSet {
    int* parent;
    int* rank;
    int size;
};

struct DisjointSet* createSet(int size) {
    struct DisjointSet* ds = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    ds->size = size;
    ds->parent = (int*)malloc(size * sizeof(int));
    ds->rank = (int*)malloc(size * sizeof(int));

    // Initialize each element as a separate set
    for (int i = 0; i < size; ++i) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }

    return ds;
}

int find(struct DisjointSet* ds, int x) {
    if (ds->parent[x] != x) {
        // Path compression: make the found root the parent of 'x' to flatten the tree
        ds->parent[x] = find(ds, ds->parent[x]);
    }
    return ds->parent[x];
}

void unite(struct DisjointSet* ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);

    if (rootX == rootY) {
        // 'x' and 'y' already belong to the same set
        return;
    }

    // Union by rank: attach the smaller rank tree under the root of the larger rank tree
    if (ds->rank[rootX] < ds->rank[rootY]) {
        ds->parent[rootX] = rootY;
    } else if (ds->rank[rootX] > ds->rank[rootY]) {
        ds->parent[rootY] = rootX;
    } else {
        ds->parent[rootY] = rootX;
        ds->rank[rootX]++;
    }
}

int main() {
    int size = 10;
    struct DisjointSet* ds = createSet(size);

    unite(ds, 0, 1);
    unite(ds, 2, 3);
    unite(ds, 4, 5);
    unite(ds, 6, 7);

    printf("%d\n", find(ds, 1)); // Output: 0 (both 0 and 1 are in the same set)
    printf("%d\n", find(ds, 3)); // Output: 2 (both 2 and 3 are in the same set)
    printf("%d\n", find(ds, 4)); // Output: 4 (each number is its own set)
    printf("%d\n", find(ds, 7)); // Output: 6 (each number is its own set)

    free(ds->parent);
    free(ds->rank);
    free(ds);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct DisjointSet {
    int* parent;
    int* rank;
    int size;
};

struct DisjointSet* createSet(int size) {
    struct DisjointSet* ds = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    ds->size = size;
    ds->parent = (int*)malloc(size * sizeof(int));
    ds->rank = (int*)malloc(size * sizeof(int));

    // Initialize each element as a separate set
    for (int i = 0; i < size; ++i) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }

    return ds;
}

int find(struct DisjointSet* ds, int x) {
    if (ds->parent[x] != x) {
        // Path compression: make the found root the parent of 'x' to flatten the tree
        ds->parent[x] = find(ds, ds->parent[x]);
    }
    return ds->parent[x];
}

void unite(struct DisjointSet* ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);

    if (rootX == rootY) {
        // 'x' and 'y' already belong to the same set
        return;
    }

    // Union by rank: attach the smaller rank tree under the root of the larger rank tree
    if (ds->rank[rootX] < ds->rank[rootY]) {
        ds->parent[rootX] = rootY;
    } else if (ds->rank[rootX] > ds->rank[rootY]) {
        ds->parent[rootY] = rootX;
    } else {
        ds->parent[rootY] = rootX;
        ds->rank[rootX]++;
    }
}

int main() {
    int size = 10;
    struct DisjointSet* ds = createSet(size);

    unite(ds, 0, 1);
    unite(ds, 2, 3);
    unite(ds, 4, 5);
    unite(ds, 6, 7);

    printf("%d\n", find(ds, 1)); // Output: 0 (both 0 and 1 are in the same set)
    printf("%d\n", find(ds, 3)); // Output: 2 (both 2 and 3 are in the same set)
    printf("%d\n", find(ds, 4)); // Output: 4 (each number is its own set)
    printf("%d\n", find(ds, 7)); // Output: 6 (each number is its own set)

    free(ds->parent);
    free(ds->rank);
    free(ds);

    return 0;
}
