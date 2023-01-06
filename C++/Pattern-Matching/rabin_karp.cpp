#include <bits/stdc++.h>
using namespace std;
#define d 256
#define q 101
void searchString(string pattern, char text[], int patLength, int txtLength)
{
    int i, j;
    int pat = 0;
    int txt = 0;
    int h = 1; // hash value
    bool check_pattern_found = true;
    for (i = 0; i < patLength - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < patLength; i++)
    {
        pat = (d * pat + pattern[i]) % q;
        txt = (d * txt + text[i]) % q;
    }
    i = 0;
    while (i <= txtLength - patLength)
    {
        if (pat == txt)
        {
            bool flag = true;
            for (j = 0; j < patLength; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    flag = false;
                    break;
                }
            }
            if (j == patLength)
            {
                check_pattern_found = false;
                cout << i << " ";
            }
        }
        if (i < txtLength - patLength)
        {
            txt = (d * (txt - text[i] * h) + text[i + patLength]) % q;

            if (txt < 0)
                txt = (txt + q);
        }
        i++;
    }
    if (check_pattern_found)
    {
        cout << "----Pattern match not found at any index----";
    }
}

int main()
{
    char txt[d];
    string pat;
    cout << "Please Enter text string - ";
    cin.getline(txt, d);
    cout << endl
         << "Please Enter pattern string - ";
    cin >> pat;
    cout << endl
         << "All index numbers where pattern found:" << endl;
    searchString(pat, txt, pat.length(), strlen(txt));
    return 0;
}
