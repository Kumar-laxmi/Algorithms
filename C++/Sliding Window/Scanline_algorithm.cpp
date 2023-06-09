/*

=============================Problem Statement=============================
We are given an array and n queries, in each query we are provided with the range (start and end index) along with the value which needs to be added in the given range
in array.

Example:

Input: 

7               (size of the input array)
1 2 3 4 5 6 7     (given array)
2               (number of queries)
1 3 4           (Add 4 to positions 1 to 3 in the array)
2 4 2           (Add 2 to positions 2 to 4 in the array)

Output:

1 6 9 10 7 6 7  


============================LOGIC============================

The problem can be solved by using Scanline algorithm.

Time complexity: O(n + q), where n is the size of the input array and q is the number of queries.
Space Complexity: O(n), where n is the size of the array.

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    //Size of the input array
    cout << "Enter the size of the array" << endl;
    int n;
    cin >> n;

    // Dynamically allocate an array of size n
    int* arr = new int[n];

    // Read input values into the array
    cout << "Enter the array elements" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create a dummy vector of size n+1 initialized with 0
    vector<int> dummyArray(n + 1, 0);

    //Number of queries
    cout << "Enter the number of queries" << endl;
    int q;
    cin >> q;

    int queryCnt = 1;

    // Process the queries
    while (q--) {
        cout << "Query " << queryCnt << ":" << endl;

        //range (start and end index)
        cout <<"Enter the starting index of the range" << endl;
        int s; 
        cin >> s;

        cout << "Enter the ending index of the range" << endl;
        int e;
        cin >> e;

        //value to be added in the given range
        cout <<"Enter the value to be added in the given range" << endl;
        int val; 
        cin >> val;

        // Add the value to the starting position 's' in dummy array
        dummyArray[s] += val;

        // Subtract the value from the next position after ending position 'e' in dummy array
        dummyArray[e + 1] -= val;

        queryCnt++;
    }

    // Compute cumulative sum of the dummy array
    for (int i = 1; i <= n; i++) {
        dummyArray[i] += dummyArray[i - 1];
    }

    // Add the corresponding values from dummy array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] += dummyArray[i];
    }

    // Print the updated array
    cout << "Output:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Deallocate the dynamically allocated array
    delete[] arr;
}

/*

Summary: The code basically updates the array based on the queries by using a dummy array to track the changes at specific positions. By calculating the prefix sum of the 
dummy array and adding it to the original array, the final output is obtained.

*/ 
