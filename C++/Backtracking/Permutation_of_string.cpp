#include <iostream>
#include <string>

using namespace std;

// Function to generate all permutations of a given string
// str: input string
// l: starting index of the string
// r: ending index of the string
void permute(string str, int l, int r) {
  // If the starting index is equal to the ending index,
  // we have reached the last character of the string
  // and can print the permutation
  if (l == r) {
    cout << str << endl;
  } else {
    // Iterate over all characters in the string
    for (int i = l; i <= r; i++) {
      // Swap the current character with the first character
      swap(str[l], str[i]);
      // Recursively call permute on the substrings to the right of the current character
      permute(str, l+1, r);
      // Swap the characters back to their original positions
      swap(str[l], str[i]);
    }
  }
}

int main() {
  cout << "Enter a string: ";
  string str;
  cin >> str;
  // Call permute on the entire string, with the starting and ending indices as arguments
  permute(str, 0, str.length()-1);
  return 0;
}
