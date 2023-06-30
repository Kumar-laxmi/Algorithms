class FenwickTree:
    def __init__(self, size):
        self.tree = [0] * (size + 1)

    def next(self, index, delta):
        while index < len(self.tree):
            self.tree[index] += delta
            index += index & (-index)

    def get_prefix_sum(self, index):
        sum = 0
        while index > 0:
            sum += self.tree[index]
            index -= index & (-index)
        return sum

    def get_rangeSum(self, left, right):
        return self.get_prefix_sum(right) - self.get_prefix_sum(left - 1)


values = [1, 3, 2, -5, 6, 4, 2, 1]
n = len(values)

fenwick_tree = FenwickTree(n)

# building the Fenwick tree
for i in range(n):
    fenwick_tree.next(i + 1, values[i])

# get prefix sum at index 4
prefix_sum = fenwick_tree.get_prefix_sum(4)
print("Prefix Sum at index 5:", prefix_sum)

# get range sum from index 2 to 6
rangeSum = fenwick_tree.get_rangeSum(2, 6)
print("Range Sum from index 2 to 6:", rangeSum)
