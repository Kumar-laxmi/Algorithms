/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LEN 100
bool isIsomorphic(char s[], char t[]) 
{
    // Create two arrays to store the mappings between s and t, and t and s
    char s_to_t[256] = {0};
    char t_to_s[256] = {0};
    // Iterate through each character in the strings and compare their corresponding mappings
    for (int i = 0; s[i] != '\0'; i++) {
        // If there is a mismatch in either of the arrays, the strings are not isomorphic
        if (s_to_t[s[i]] && s_to_t[s[i]] != t[i]) 
        {
            return false;
        }
        if (t_to_s[t[i]] && t_to_s[t[i]] != s[i]) 
        {
            return false;
        } 
        // Add the new mappings to both arrays
        s_to_t[s[i]] = t[i];
        t_to_s[t[i]] = s[i];
    }
    // If we reach the end of the strings without finding a mismatch, the strings are isomorphic
    return true;
}
int main() 
{
    char s[MAX_LEN], t[MAX_LEN];
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("Enter the second string: ");
    scanf("%s", t);
    // Check if the strings are isomorphic and print the result
    if (isIsomorphic(s, t)) {
        printf("The strings are isomorphic.\n");
    } else {
        printf("The strings are not isomorphic.\n");
    }
    return 0;
}