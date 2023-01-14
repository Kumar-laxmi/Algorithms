# Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

# You have the following 3 operations permitted on a word:

# 1. Insert a character
# 2. Delete a character
# 3. Replace a character

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:

        b = len(word1)  # length of first string
        a = len(word2)  # length of second string

        dp = [([0] * (b + 1)) for _ in range(a + 1)]

        # Case 1: if first string is empty, insert all characters of second string into first.
        for i in range(1, a + 1):
            dp[i][0] = i

        # Case 2: if second string is empty, remove all characters of first string.
        for j in range(1, b + 1):
            dp[0][j] = j

        # Case 3: if strings are non-empty
        for i in range(1, a + 1):
            for j in range(1, b + 1):
                dp[i][j] = min(
                    dp[i - 1][j] + 1, # delete operation
                    dp[i][j - 1] + 1, # insert operation
                    dp[i - 1][j - 1] + (0 if word1[j - 1] == word2[i - 1] else 1), #if both the strings are same, then no changes else replace operation
                )

        return dp[a][b] # min no of operations to convert word1 to word2

# Driver program

word1 = input("Enter first string: ") 
word2 = input("Enter second string: ")

sol = Solution()
ans = sol.minDistance(word1, word2) # calling the function

print("No. of Operations required :", ans) # output
