/*------------------------------------------------INTRODUCTION-------------------------------------------------------------------------*/
/*Boyer-Moore-Horspool is an algorithm for finding substrings into strings. This algorithm compares each characters of substring to find 
a word or the same characters into the string from right to left. When characters do not match, the search jumps to the next matching 
position in the pattern by the value indicated in the Bad Match Table.
value is calculated using 
"value=length(substring)-index(last occurance)-1."

The Bad Match Table indicates how many jumps should it move from the current position to the next.*/

/*----------------------------------------------ALGORITHM-----------------------------------------------------------------------------
1.first it finds out the lenght of both the strings.
2.bad match table is prepared using the value formula for substring and it include characters only once no repeated element is 
  considered elements out of the substring that are present in main string are considered under *.
3.now it compares each char of substring from right to left with parent string if not found moves from the current position to next 
  by the corresponding value of that character in bad match table.
4.after all successful comparisions the index is returned at which is was matched.
*/
#include <bits/stdc++.h>
using namespace std;

//creating a vector with inputs as text and substring(pattern)
vector<int> boyerMooreHorspool(const string& text, const string& pattern) {
//vector occurences is created to represent the indices where the pattern occurs in the text.
    vector<int> occurrences;
    int textLength = text.length();
    int patternLength = pattern.length();

    // If the pattern is empty, return an empty occurrences vector
    if (patternLength == 0) {
        return occurrences;
    }

    // Preprocessing: Generate the bad character shift table
    vector<int> shiftTable(256, patternLength);
    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable[pattern[i]] = patternLength - 1 - i;
    }

    int i = 0;
    while (i <= textLength - patternLength) {
        int j = patternLength - 1;

        // Compare the pattern characters from right to left with the corresponding text characters
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        // If a match is found, record the occurrence and move to the next position in the text
        if (j == -1) {
            occurrences.push_back(i);
            i++;
        } else {
            // Move i by the shift amount based on the last character of the current window
            int shift = shiftTable[text[i + patternLength - 1]];
            i += shift;
        }
    }

    return occurrences;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    // Call the Boyer-Moore-Horspool function to find occurrences
    vector<int> occurrences = boyerMooreHorspool(text, pattern);

    // Print the indices where the pattern occurs in the text
    cout << "Occurrences found at indices: ";
    for (int i : occurrences) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

