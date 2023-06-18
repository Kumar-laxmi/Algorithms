import math


class VEBTree:
    def __init__(self, size):
        self.universe_size = size
        self.minimum = -1
        self.maximum = -1
        self.summary = None
        self.cluster = []

        if size > 2:
            upper_size = math.ceil(math.sqrt(size))
            lower_size = math.floor(math.sqrt(size))

            self.summary = VEBTree(upper_size)
            self.cluster = [VEBTree(lower_size) for _ in range(upper_size)]

    def insert(self, key):
        if self.minimum == -1:
            self.minimum = self.maximum = key
            return

        if key < self.minimum:
            key, self.minimum = self.minimum, key

        if self.universe_size > 2:
            if self.cluster[key // int(math.sqrt(self.universe_size))].minimum == -1:
                self.summary.insert(key // int(math.sqrt(self.universe_size)))

            self.cluster[key // int(math.sqrt(self.universe_size))].insert(key % int(math.sqrt(self.universe_size)))

        if key > self.maximum:
            self.maximum = key

    def remove(self, key):
        if self.minimum == self.maximum:
            self.minimum = self.maximum = -1
            return

        if self.universe_size == 2:
            if key == 0:
                self.minimum = 1
            else:
                self.minimum = 0

            self.maximum = self.minimum
            return

        if key == self.minimum:
            first_cluster = self.summary.minimum
            key = first_cluster * int(math.sqrt(self.universe_size)) + self.cluster[first_cluster].minimum
            self.minimum = key

        self.cluster[key // int(math.sqrt(self.universe_size))].remove(key % int(math.sqrt(self.universe_size)))

        if self.cluster[key // int(math.sqrt(self.universe_size))].minimum == -1:
            self.summary.remove(key // int(math.sqrt(self.universe_size)))

        if key == self.maximum:
            if self.summary.minimum == -1:
                self.maximum = self.minimum
            else:
                last_cluster = self.summary.maximum
                self.maximum = last_cluster * int(math.sqrt(self.universe_size)) + self.cluster[last_cluster].maximum

    def successor(self, key):
        if self.universe_size == 2:
            if key == 0 and self.maximum == 1:
                return 1
            else:
                return -1

        if self.minimum != -1 and key < self.minimum:
            return self.minimum

        max_low = self.cluster[key // int(math.sqrt(self.universe_size))].maximum

        if max_low != -1 and key % int(math.sqrt(self.universe_size)) < max_low:
            offset = self.cluster[key // int(math.sqrt(self.universe_size))].successor(
                key % int(math.sqrt(self.universe_size)))
            return key // int(math.sqrt(self.universe_size)) * int(math.sqrt(self.universe_size)) + offset

        succ_cluster = self.summary.successor(key // int(math.sqrt(self.universe_size)))

        if succ_cluster == -1:
            return -1

        offset = self.cluster[succ_cluster].minimum
        return succ_cluster * int(math.sqrt(self.universe_size)) + offset

    def predecessor(self, key):
        if self.universe_size == 2:
            if key == 1 and self.minimum == 0:
                return 0
            else:
                return -1

        if self.maximum != -1 and key > self.maximum:
            return self.maximum

        min_low = self.cluster[key // int(math.sqrt(self.universe_size))].minimum

        if min_low != -1 and key % int(math.sqrt(self.universe_size)) > min_low:
            offset = self.cluster[key // int(math.sqrt(self.universe_size))].predecessor(
                key % int(math.sqrt(self.universe_size)))
            return key // int(math.sqrt(self.universe_size)) * int(math.sqrt(self.universe_size)) + offset

        pred_cluster = self.summary.predecessor(key // int(math.sqrt(self.universe_size)))

        if pred_cluster == -1:
            if self.minimum != -1 and key > self.minimum:
                return self.minimum
            else:
                return -1

        offset = self.cluster[pred_cluster].maximum
        return pred_cluster * int(math.sqrt(self.universe_size)) + offset

    def contains(self, key):
        if key == self.minimum or key == self.maximum:
            return True

        if self.universe_size == 2:
            return False

        return self.cluster[key // int(math.sqrt(self.universe_size))].contains(
            key % int(math.sqrt(self.universe_size)))


veb_tree = VEBTree(16)
veb_tree.insert(4)
veb_tree.insert(1)
veb_tree.insert(8)
veb_tree.insert(10)

print(veb_tree.contains(4))  # Output: True
print(veb_tree.contains(5))  # Output: False

print(veb_tree.successor(4))  # Output: 8
print(veb_tree.predecessor(4))  # Output: 1

veb_tree.remove(4)
print(veb_tree.contains(4))  # Output: False
