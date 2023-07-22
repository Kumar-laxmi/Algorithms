// =========================== Problem Statement ==============================================================
/*
Rabin-Karp algorithm is an algorithm used for searching/matching patterns in the text using a hash function.
Unlike Naive string matching algorithm, it does not travel through every character in the initial phase rather
it filters the characters that do not match and then performs the comparison.

Rabin-Karp Algo using C

Example:-

Input:
Text: "AABAACAADAABAABA"
Pattern: "AABA"

Output:
Occurrences found at indices: 0, 9, 12
*/

#include <stdio.h>
#include <string.h>

// in order to prevent spurious hits
#define d 5

void rabinKarp(char pattern[], char text[], int q)
{
    int sizep = strlen(pattern);
    int sizet = strlen(text);

    int p = 0, t = 0, h = 1;

    // h=d^(sizep-1) to calculate the rolling hash
    for (int i = 0; i < sizep - 1; i++)
    {
        h = (h * d) % q;
    }

    // calculating the hash values of pattern and portions of text
    for (int i = 0; i < sizep; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // checking for the presence of pattern within the text
    printf("Occurences found at indices : ");
    int check = 0;
    for (int i = 0; i <= sizet - sizep; i++)
    {
        if (p == t)
        {
            int j = 0;
            while (j < sizep)
            {
                // checking for spurious hits
                if (text[i + j] != pattern[j])
                    break;
                j++;
            }

            // printing the index of starting of pattern within text
            if (j == sizep)
            {
                printf("%d ", i);
                check = 1;
            }
        }

        // calculating the rolling hash for next set of characters
        if (i < sizet - sizep)
        {
            t = (d * (t - text[i] * h) + text[i + sizep]) % q;
            if (t < 0)
                t += q;
        }
    }
    if (check == 0)
        printf("NULL");
}

void main()
{
    // inputs:
    char pattern[]="AABAACAADAABAABA";
    char text[]="AABA";

    // taking q as a large prime number to prevent hash value from becoming too large a value
    int q = 19;

    rabinKarp(pattern, text, q);
}