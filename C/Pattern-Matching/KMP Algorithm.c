#include <stdio.h>
#include <string.h>

int length(char str[])
{
    return strlen(str);
}

void piTable(char pattern[], int pi[])
{
    int i = 0;
    int j = 0;
    int len = length(pattern);
    i = 1;
    j = 0;
    pi[0] = 0;
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

bool kmp(char text[], char pattern[])
{
    int t_len = strlen(text);
    int p_len = strlen(pattern);
    int pi[p_len];
    piTable(pattern, pi);

    int i = 0;
    int j = 0;

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

        if (j == p_len)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    char text[] = "aabacabadb";
    char pattern[] = "bacak";

    if (kmp(text, pattern))
        printf("Pattern Found in the Text\n");
    else
        printf("Pattern does not found in Text\n");

    return 0;
}
