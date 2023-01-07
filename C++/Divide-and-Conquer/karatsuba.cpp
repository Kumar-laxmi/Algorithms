// =========================== Problem Statement ========================
/*
The problem that the above code is solving is to multiply two 
large integers using the Karatsuba algorithm. The Karatsuba 
algorithm is a fast multiplication algorithm that uses a divide 
and conquer strategy to compute the product of two numbers. It is 
based on the observation that the product of two numbers can be 
computed more efficiently by recursively computing the product of 
their halves and then using these partial products to compute the final result.

Here is the formal problem statement:

Input: Two integers a and b with at most n digits, where n is a power of 2.

Output: The product of a and b.

The Karatsuba algorithm has a time complexity of O(n^1.585), which is 
faster than the traditional O(n^2) time complexity of simple multiplication 
algorithms. This makes it especially useful for multiplying very large integers 
or for applications where performance is critical.

*/

// =========================== CODE with C++ ========================
#include <iostream>
#include <algorithm>
#include <cstring>
#include<math.h>

using namespace std;

// Function to compute a*b using Karatsuba algorithm
long long karatsuba(long long a, long long b)
{
    // Base case: return a*b if a or b is less than 10
    // This is the stopping condition for the recursive calls
    if (a < 10 || b < 10)
        return a*b;

    // Calculate the length of the two numbers
    int n = max(to_string(a).length(), to_string(b).length());

    // Divide n by 2
    int n2 = n / 2;

    // Split the numbers into high and low digits
    // x and z are the high digits, y and w are the low digits
    long long x = a / (long long)pow(10, n2);
    long long y = a % (long long)pow(10, n2);
    long long z = b / (long long)pow(10, n2);
    long long w = b % (long long)pow(10, n2);

    // Recursively compute p, q, and r
    // p = x*z
    // q = (x+y)*(z+w)
    // r = y*w
    long long p = karatsuba(x, z);
    long long q = karatsuba(x + y, z + w);
    long long r = karatsuba(y, w);

    // Return the final result using the Karatsuba formula
    // a*b = (10^(2*n2))*p + (10^n2)*(q-p-r) + r
    return (long long)pow(10, 2 * n2) * p + (long long)pow(10, n2) * (q - p - r) + r;
}

int main()
{
    // Read in the two numbers to be multiplied
    long long a, b;
    cin >> a >> b;

    // Call the karatsuba function and print the result
    cout << karatsuba(a, b) << endl;
    return 0;
}
