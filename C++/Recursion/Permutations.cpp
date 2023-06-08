#include <iostream>
#include <string>
using namespace std;

void permutations(string p, string up) {
    // Base case: If the remaining characters to be permuted is empty, print the permutation
    if (up.empty()) {
        cout << p << endl;
        return;
    }
    
    char ch = up[0];

    for (int i = 0; i <= p.length(); i++) {
        // Split the permutation string into two parts
        string f = p.substr(0, i); // First part
        string s = p.substr(i, p.length()); // Second part
        
        // Recursive call: Generate permutations by inserting the current character at each possible position
        permutations(f + ch + s, up.substr(1));
    }
}

int main() {
    permutations("", "abc");
    return 0;
}
