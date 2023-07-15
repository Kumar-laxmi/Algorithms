/*
------------------------------------- Lucas Lehmer Series -------------------------------------

Approach
1. In this series, 4 is the starting term i.e., 0th term

2. By considering 4 as the 0th terms, then calculate the nth term of lucas-lehmer series.

3. To calculate the nth term use the formula, ``` nextTerm = currentTerm * currentTerm - 2 ```

4. Using this formula, we can find the nth term of lucas-lehmer series.

Below is the implementation of lucas-lehmer series in C++
*/

// Program starts
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the series upto the nth term
void LucasLehmer(int n) {
    // the 0th term of the series is 4.
    unsigned long long currentTerm = 4;

    // create an array to store the terms.
    vector<unsigned long long> series;

    // compute each term and add it to the array.
    series.push_back(currentTerm);
    for (int i = 0; i < n; i++) {
        currentTerm = currentTerm * currentTerm - 2;
        series.push_back(currentTerm);
    }

    // print out the terms one by one.
    for (int i = 0; i <= n; i++)
        cout << "Term " << i << ": " << series[i] << endl;
    cout << endl;
}

// Main driver function
int main() {
    // nth term upto which user want to display the lucas-lehmer series
    int n;

    // Taking input from the user
    cout << "\nEnter the value of n: ";
    cin >> n;

    cout << "\n######## Lucas-Lehmer Series ########\n\n";

    // Function triggered to calculate the lucas-lehmer series upto the nth term
    LucasLehmer(n);
    return 0;
}

// This code is contributed by Avdhesh Varshney (https://github.com/Avdhesh-Varshney)
