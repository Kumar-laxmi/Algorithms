// Bloom Filter Implementation


// Approach and Explanation

// 1. **Hash Functions**: The Bloom filter uses four hash functions (`h1`, `h2`, `h3`, `h4`) to map input strings to positions in the bit array. These hash functions generate different indexes based on the input string and the size of the bit array.

// 2. **Bit Array**: The Bloom filter uses a `std::bitset<1000000>` called `bitarray` to represent the filter. It is a fixed-size bit array where each bit represents a position that can be set (1) or unset (0).

// 3. **Lookup Operation**: The `lookup` function takes a reference to the `bitarray` and a string `s` as input. It calculates the hash values for `s` using the four hash functions and checks if the corresponding positions in the `bitarray` are all set (1). If all positions are set, it returns `true`, indicating that the element is possibly present in the filter. Otherwise, it returns `false`.

// 4. **Insert Operation**: The `insert` function takes a reference to the `bitarray` and a string `s` as input. It first checks if the element is already present in the filter by calling the `lookup` function. If the element is already present, it prints a message indicating that it is probably already present. Otherwise, it calculates the hash values for `s` using the four hash functions and sets the corresponding positions in the `bitarray` to 1, indicating the insertion of the element.

// 5. **Main Function**: In the `main` function, a `bitarray` of size 1000000 is created. A set of strings (`sarray`) is defined, representing the elements to be added to the filter. For each string `s` in `sarray`, it checks if `s` is already present in the filter using the `lookup` function. If it is present, it prints a message indicating that it is already present. Otherwise, it inserts `s` into the filter using the `insert` function.

// The Bloom filter provides a probabilistic way to test whether an element is possibly in a set. It may return false positives, indicating that an element is possibly in the set when it's not, but it will never give false negatives. The accuracy of the filter depends on the size of the bit array, the number of hash functions used, and the number of elements inserted.

// In this implementation, the size of the bit array is fixed at 1000000, and four hash functions are used. The elements are inserted by setting the corresponding positions in the bit array to 1. The `lookup` function checks if all the positions for an element are set (1), indicating its possible presence in the filter.

// Time Complexity->	O(1) on average, O(n) in the worst case
// Space Complexity->	O(n)

#include <iostream>
#include <bitset>
#include <cmath>
#define ll long long

// Hash function 1
// This function calculates the hash value of a string using a simple additive approach.
int h1(std::string s, int arrSize)
{
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i])); // Add the ASCII value of each character to the hash
        hash = hash % arrSize;       // Take the modulus to ensure the hash value is within the array size
    }
    return hash;
}

// Hash function 2
// This function calculates the hash value of a string using an exponential approach.
int h2(std::string s, int arrSize)
{
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + pow(19, i) * s[i]; // Multiply each character by a power of 19 and add to the hash
        hash = hash % arrSize;           // Take the modulus to ensure the hash value is within the array size
    }
    return hash % arrSize;
}

// Hash function 3
// This function calculates the hash value of a string using a polynomial approach.
int h3(std::string s, int arrSize)
{
    ll int hash = 7;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 31 + s[i]) % arrSize; // Multiply the hash by 31, add the character, and take the modulus
    }
    return hash % arrSize;
}

// Hash function 4
// This function calculates the hash value of a string using a combination of multiplication and exponentiation.
int h4(std::string s, int arrSize)
{
    ll int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++)
    {
        hash += hash * 7 + s[i] * pow(p, i); // Multiply the hash by 7, add the character multiplied by a power of 7
        hash = hash % arrSize;               // Take the modulus to ensure the hash value is within the array size
    }
    return hash;
}

// Lookup operation
// This function checks if a given string is present in the bit array.
bool lookup(std::bitset<1000000> &bitarray, std::string s)
{
    int a = h1(s, bitarray.size()); // Calculate hash using h1
    int b = h2(s, bitarray.size()); // Calculate hash using h2
    int c = h3(s, bitarray.size()); // Calculate hash using h3
    int d = h4(s, bitarray.size()); // Calculate hash using h4

    return bitarray[a] && bitarray[b] && bitarray[c] && bitarray[d]; // Check if all corresponding bits are set in the bit array
}

// Insert operation
// This function inserts a string into the bit array.
void insert(std::bitset<1000000> &bitarray, std::string s)
{
    // Check if the element is already present or not
    if (lookup(bitarray, s))
    {
        std::cout << s << " is probably already present" << std::endl;
    }
    else
    {
        int a = h1(s, bitarray.size()); // Calculate hash using h1
        int b = h2(s, bitarray.size()); // Calculate hash using h2
        int c = h3(s, bitarray.size()); // Calculate hash using h3
        int d = h4(s, bitarray.size()); // Calculate hash using h4

        bitarray[a] = true; // Set corresponding bit in the bit array for hash a
        bitarray[b] = true; // Set corresponding bit in the bit array for hash b
        bitarray[c] = true; // Set corresponding bit in the bit array for hash c
        bitarray[d] = true; // Set corresponding bit in the bit array for hash d

        std::cout << s << " inserted" << std::endl;
    }
}

int main()
{
    std::bitset<1000000> bitarray;
    std::string sarray[] = {"apple", "banana", "cherry", "orange", "grape", "kiwi"};

    for (const auto &s : sarray)
    {
        if (lookup(bitarray, s))
        {
            std::cout << s << " is already present" << std::endl;
        }
        else
        {
            insert(bitarray, s);
        }
    }

    return 0;
}
