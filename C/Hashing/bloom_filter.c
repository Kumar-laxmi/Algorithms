#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 100

typedef struct {
    uint8_t* bitArray;
    int size;
    int hashFunctions;
} BloomFilter;

BloomFilter* createBloomFilter(int size, int hashFunctions) {
    BloomFilter* filter = (BloomFilter*)malloc(sizeof(BloomFilter));
    filter->size = size;
    filter->hashFunctions = hashFunctions;
    filter->bitArray = (uint8_t*)calloc((size + 7) / 8, sizeof(uint8_t));
    return filter;
}

void destroyBloomFilter(BloomFilter* filter) {
    free(filter->bitArray);
    free(filter);
}

void setBit(uint8_t* bitArray, int index) {
    bitArray[index / 8] |= (1 << (index % 8));
}

int getBit(uint8_t* bitArray, int index) {
    return (bitArray[index / 8] & (1 << (index % 8))) != 0;
}

unsigned int hash(const void* element, int size, int seed) {
    unsigned int hashValue = seed;
    const unsigned char* bytes = (const unsigned char*)element;
    for (int i = 0; i < size; i++) {
        hashValue = (hashValue * 65599) ^ bytes[i];
    }
    return hashValue;
}

void add(BloomFilter* filter, const void* element, int size) {
    for (int i = 0; i < filter->hashFunctions; i++) {
        unsigned int index = hash(element, size, i) % filter->size;
        setBit(filter->bitArray, index);
    }
}

int query(BloomFilter* filter, const void* element, int size) {
    for (int i = 0; i < filter->hashFunctions; i++) {
        unsigned int index = hash(element, size, i) % filter->size;
        if (!getBit(filter->bitArray, index)) {
            return 0; // Definitely not in the set
        }
    }
    return 1; // Probably in the set
}

int main() {
    BloomFilter* filter = createBloomFilter(SIZE, 2);

    int intValue = 42;
    add(filter, &intValue, sizeof(int));

    char stringValue[] = "example";
    add(filter, stringValue, sizeof(stringValue));

    // Querying for membership
    printf("Querying 42: %d\n", query(filter, &intValue, sizeof(int))); // Output: 1 (probably in the set)
    printf("Querying 'example': %d\n", query(filter, stringValue, sizeof(stringValue))); // Output: 1 (probably in the set)
    printf("Querying 'world': %d\n", query(filter, "world", sizeof("world"))); // Output: 0 (definitely not in the set)
     printf("Querying 'worldd': %d\n", query(filter, "worldd", sizeof("worldd"))); // Output: 0 (definitely not in the set -> false positive)

    destroyBloomFilter(filter);
    return 0;
}

