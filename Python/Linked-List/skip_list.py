import random

class SkipNode:
    def __init__(self, level, value):
        self.value = value
        self.forward = [None] * (level + 1)

class SkipList:
    def __init__(self):
        self.MAX_LEVEL = 6  # Maximum level for skip list
        self.header = SkipNode(self.MAX_LEVEL, 0)  # Create the header node with maximum level
        self.level = 0  # Current level of the skip list

    # Generate random level for a node
    def random_level(self):
        level = 0
        while random.random() < 0.5 and level < self.MAX_LEVEL:  # Randomly increase the level with a probability of 1/2
            level += 1
        return level

    # Insert a value into the skip list
    def insert(self, value):
        update = [None] * (self.MAX_LEVEL + 1)  # Array to store the update nodes at each level
        current = self.header  # Start from the header node

        # Find the appropriate position to insert the value
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].value < value:
                current = current.forward[i]
            update[i] = current  # Store the update nodes

        current = current.forward[0]

        # If the value is already present, return
        if not current or current.value != value:
            new_level = self.random_level()  # Generate a random level for the new node
            if new_level > self.level:
                for i in range(self.level + 1, new_level + 1):
                    update[i] = self.header  # Update the pointers in the update array for the new level
                self.level = new_level  # Update the current level
            current = SkipNode(new_level, value)  # Create a new node
            for i in range(new_level + 1):
                current.forward[i] = update[i].forward[i]  # Update the forward pointers
                update[i].forward[i] = current
            print("Inserted", value, "into the skip list.")

    # Search for a value in the skip list
    def search(self, value):
        current = self.header  # Start from the header node
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].value < value:
                current = current.forward[i]  # Move forward at each level until the value is found or surpassed
        current = current.forward[0]  # Move to the next node at the lowest level
        if current and current.value == value:
            print(value, "found in the skip list.")
            return True
        print(value, "not found in the skip list.")
        return False

    # Display the skip list
    def display(self):
        print("Skip List:")
        for i in range(self.level + 1):
            node = self.header.forward[i]
            print("Level", i, end=": ")
            while node:
                print(node.value, end=" ")
                node = node.forward[i]
            print()

# Example usage:
skip_list = SkipList()
skip_list.insert(3)
skip_list.insert(7)
skip_list.insert(2)
skip_list.insert(9)

skip_list.display()

skip_list.search(2)
skip_list.search(5)
