# Bloom Filter Implementation


#  explanation of the approach:

# 1. The `BloomFilter` class is defined to encapsulate the functionality of the Bloom filter. It takes two parameters during initialization: `capacity` (expected number of elements to be added to the filter) and `false_positive_rate` (desired false positive rate).

# 2. The `calculate_size()` method is used to calculate the size of the bit array based on the capacity and false positive rate. It uses the formula `- (capacity * log(false_positive_rate)) / (log(2) ** 2)` to determine the size.

# 3. The `calculate_num_hashes()` method calculates the number of hash functions to be used based on the size of the bit array and the capacity. It uses the formula `(size / capacity) * log(2)` to determine the number of hashes.

# 4. The `bit_array` attribute is created using the `bitarray` library and initialized with the calculated size. All bits in the array are initially set to 0.

# 5. The `add()` method is used to add an item to the Bloom filter. It iterates over the range of `num_hashes` and calculates the index for each hash function using the `mmh3.hash()` function. The index is obtained by taking the modulo of the hash value with the size of the bit array. The corresponding bit in the bit array is set to 1.

# 6. The `contains()` method is used to check if an item is present in the Bloom filter. It follows a similar process as the `add()` method, iterating over the range of `num_hashes` and calculating the index for each hash function. If any of the corresponding bits in the bit array are 0, it indicates that the item is not present and False is returned. If all the bits are 1, it means the item might be present (false positive) and True is returned.

# 7. In the example usage, a `BloomFilter` object is created with a capacity of 1000 and a false positive rate of 0.01.

# 8. Three items ("apple", "banana", "cherry") are added to the Bloom filter using the `add()` method.

# 9. The `contains()` method is used to check if certain items ("apple", "banana", "cherry", "orange") are present in the Bloom filter. The result is printed for each item.

# The Bloom filter uses the MurmurHash3 hash function (`mmh3.hash()`) to generate hash values for the items. The number of hash functions and the size of the bit array are calculated based on the desired false positive rate and capacity. The Bloom filter provides a probabilistic check for membership, with a possibility of false positives but no false negatives.


import math
import mmh3
from bitarray import bitarray


class BloomFilter:
    def __init__(self, capacity, false_positive_rate):
        self.capacity = capacity
        self.false_positive_rate = false_positive_rate
        self.size = self.calculate_size()
        self.num_hashes = self.calculate_num_hashes()
        self.bit_array = bitarray(self.size)
        self.bit_array.setall(0)

    def calculate_size(self):
        # Calculate the size of the bit array based on the capacity and false positive rate
        size = - (self.capacity * math.log(self.false_positive_rate)
                  ) / (math.log(2) ** 2)
        return int(size)

    def calculate_num_hashes(self):
        # Calculate the number of hash functions based on the size and capacity
        num_hashes = (self.size / self.capacity) * math.log(2)
        return int(num_hashes)

    def add(self, item):
        # Add an item to the Bloom filter
        for seed in range(self.num_hashes):
            # Generate a hash value using the MurmurHash3 algorithm with different seeds
            index = mmh3.hash(item, seed) % self.size
            self.bit_array[index] = 1

    def contains(self, item):
        # Check if an item is possibly in the Bloom filter
        for seed in range(self.num_hashes):
            # Generate a hash value using the MurmurHash3 algorithm with different seeds
            index = mmh3.hash(item, seed) % self.size
            if self.bit_array[index] == 0:
                return False
        return True


# Create a Bloom filter with a capacity of 1000 items and a false positive rate of 0.01
bloom_filter = BloomFilter(capacity=1000, false_positive_rate=0.01)

# Add items to the filter
bloom_filter.add("apple")
bloom_filter.add("banana")
bloom_filter.add("cherry")

# Check if items are in the filter
print(bloom_filter.contains("apple"))    # Expected output: True
print(bloom_filter.contains("banana"))   # Expected output: True
print(bloom_filter.contains("cherry"))   # Expected output: True
print(bloom_filter.contains("orange"))   # Expected output: False
