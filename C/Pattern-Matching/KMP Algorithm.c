#include <stdio.h>
#include <string.h>

void piTable(char pattern[], int pi[], int len)
{
    int i = 0;
    int j = 0;
    i = 1;
    j = 0;
    pi[0] = 0;

    //the loop will iterate the pattern and find the longest prefix and suffix at every index
    while (i < len)
    {
        if (pattern[i] == pattern[j])
        {
            pi[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = pi[j - 1];
        }
        else
        {
            pi[i] = 0;
            i++;
        }
    }
}

//kmp function to find if pattern exists or not
bool kmp(char text[], char pattern[])
{
    //finding length of the text
    int t_len = strlen(text);
    //finding length of the pattern
    int p_len = strlen(pattern);
    //array in which we store the longest prefix and suffix at every index in pattern
    int pi[p_len];
    //calling function to calculate pi table for pattern
    piTable(pattern, pi, p_len);

    int i = 0;
    int j = 0;

    //this loop will iterate over text and find the pattern in it the pi table is used to eliminate duplicate comparisons
    while (i < t_len)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = pi[j - 1];
        }
        else
        {
            j = 0;
            i++;
        }

        //if j reaches the end of the pattern which means pattern exists in the text
        if (j == p_len)
        {
            return true;
        }
    }

    return false;
}

int main()
{ 
    //text in which we have to search the pattern
    char text[] = "aabacabadb";

    //pattern we need to search
    char pattern[] = "bacab";

    //if we get true from kmp() then pattern found else pattern not found
    if (kmp(text, pattern))
        printf("Pattern Found in the Text!\n");
    else
        printf("Pattern does not found in Text!\n");

    return 0;
}
