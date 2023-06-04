## Explanation
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#In this code, the longest_common_subsequence function takes two strings, s1 and s2, as input and returns the longest common subsequence between them.It uses dynamic programming to fill a 2D array (dp) where dp[i][j] represents the length of the LCS between s1[:i] and s2[:j].It then constructs the LCS string by backtracking through the dp array. Finally, it returns the LCS.

## Code
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
def longest_common_subsequence(s1, s2):
    m = len(s1)
    n = len(s2)

    #Create a 2D array to store the lengths of LCS
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    #Iterate through the strings and fill the dp array
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    #Construct the LCS from the dp array
    lcs = ""
    i = m
    j = n
    while i > 0 and j > 0:
        if s1[i - 1] == s2[j - 1]:
            lcs = s1[i - 1] + lcs
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1

    return lcs

s1 = input()
s2 = input()
result = longest_common_subsequence(s1, s2)
print("Longest Common Subsequence:", result)

## Time Complexity: O(m * n)
----------------------------------------------------------------------------------------------------------------------------------------------------
#Here, 'm' and 'n' are the lengths of the input strings 's1' and 's2' respectively.
#The code uses nested loops to iterate through all possible combinations of characters in 's1' and 's2', resulting in a time complexity of O(m * n).

## Space Complexity: O(m * n)
-----------------------------------------------------------------------------------------------------------------------------------------------------
#The code uses a 2D array 'dp' of size (m+1) x (n+1) to store the lengths of LCS for all possible substrings of 's1' and 's2'.
#Therefore, the space complexity is proportional to the size of this array, which is O(m * n).
