def find_minimum_insertions(s):
    n = len(s)
    dp = [[0 for _ in range(n)] for _ in range(n)]

    # Fill the dp array using bottom-up approach
    for gap in range(1, n):
        for i in range(n - gap):
            j = i + gap
            if s[i] == s[j]:
                dp[i][j] = dp[i + 1][j - 1] # Characters match, no extra insertion needed
            else:
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1 # Characters don't match, add one insertion

    return dp[0][n - 1] # Minimum number of insertions required to make the entire string palindrome

if __name__ == "__main__":
    string = "abcde"
    min_insertions = find_minimum_insertions(string)
    print("Minimum insertions to make the string palindrome:", min_insertions)
