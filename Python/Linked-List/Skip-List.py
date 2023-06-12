import random

class SkipListNode:
    def __init__(self, value, level):
        self.value = value
        self.forward = [None] * (level + 1)

class SkipList:
    MAX_LEVEL = 16

    def __init__(self):
        self.level = 0
        self.header = SkipListNode(0, self.MAX_LEVEL)
        self.random = random.Random()

    def random_level(self):
        level = 0
        while self.random.random() < 0.5 and level < self.MAX_LEVEL:
            level += 1
        return level

    def insert(self, value):
        update = [None] * (self.MAX_LEVEL + 1)
        current = self.header

        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].value < value:
                current = current.forward[i]
            update[i] = current

        current = current.forward[0]

        if current and current.value == value:
            print(f"Value already exists: {value}")
            return

        new_node_level = self.random_level()

        if new_node_level > self.level:
            for i in range(self.level + 1, new_node_level + 1):
                update[i] = self.header
            self.level = new_node_level

        new_node = SkipListNode(value, new_node_level)

        for i in range(new_node_level + 1):
            new_node.forward[i] = update[i].forward[i]
            update[i].forward[i] = new_node

        print(f"Inserted value: {value}")

    def search(self, value):
        current = self.header

        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].value < value:
                current = current.forward[i]

        current = current.forward[0]

        if current and current.value == value:
            print(f"Value found: {value}")
            return True

        print(f"Value not found: {value}")
        return False


skip_list = SkipList()

skip_list.insert(3)
skip_list.insert(6)
skip_list.insert(2)
skip_list.insert(9)

skip_list.search(6)
skip_list.search(5)
