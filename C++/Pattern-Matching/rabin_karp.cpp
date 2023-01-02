#include <bits/stdc++.h>
using namespace std;
// d is the number of characters in the input alphabet
#define d 256
/* pat -> pattern
txt -> text
q -> A prime number
*/
void search(string pat, string txt, int q)
{
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    bool check_pattern_found = true;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t)
        {
            bool flag = true;
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
                // if (flag)
                //     cout << i << " ";
            }
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
            {
                check_pattern_found = false;
                cout << i << " ";
            }
        }
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
    if (check_pattern_found)
    {
        cout << "----Pattern match not found at any index----";
    }
}

int main()
{
    string txt = "social winter of Code is an open-source program envisioned by the social. It aims to bring students into the world of open source development and see the power of unified problem-solving in real time. The projects that we will host have been carefully hand-picked to invigorate creative thinking and encourage collaboration among all participants.";
    string pat = "social";
    // A prime number
    int q = 101;
    cout << "All index numbers where pattern found:" << endl;
    search(pat, txt, q);
    return 0;
}
