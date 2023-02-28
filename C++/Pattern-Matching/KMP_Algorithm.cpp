// C++ program for implementation of KMP pattern searching algorithm
#include <bits/stdc++.h>
using namespace std;

// Fills lps array for given pattern pat[0..m-1]
void computeLPSArray(string pat, vector<int> &lps, int m)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to m-1
    int i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            //  The idea is similar to search step.
            if (len != 0)
            {
                len = lps[len - 1];
                // Also, note that we do not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Finds occurrences of pat in txt
void KMPSearch(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    // create lps array that will hold the longest prefix suffix values for pattern
    vector<int> lps(m);

    // Preprocess the pattern (calculate lps array)
    computeLPSArray(pat, lps, m);

    int i = 0; // index for txt
    int j = 0; // index for pat

    while ((n - i) >= (m - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < n && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
}

int main()
{
    cout << "Enter the text: " << endl;
    string txt;
    cin >> txt; // taking input of text

    cout << "Enter the pattern: " << endl;
    string pat;
    cin >> pat; // taking input of pattern

    // function call
    KMPSearch(txt, pat);
    return 0;
}

// Time Complexity:- O(n)
// Space Complexity:- O(m)
