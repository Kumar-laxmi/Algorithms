SIZE = 100000 + 1
P = [0] * (SIZE * 2)


# Transform S into new string Q with special characters inserted to avoid bound checking.
def convertToNewString(s):
    newString = '@'

    for i in range(len(s)):
        newString += '#' + s[i]

    newString += '#$'
    return newString


def longestPalindromeSubstring(s):
    Q = convertToNewString(s)
    c, r = 0, 0  # current center, right limit

    for i in range(1, len(Q) - 1):
        # find the corresponding letter in the palindrome substring
        iMirror = c - (i - c)

        if r > i:
            P[i] = min(r - i, P[iMirror])

        # expanding around center i
        while Q[i + 1 + P[i]] == Q[i - 1 - P[i]]:
            P[i] += 1

        # Update c, r in case if the palindrome centered at i expands past r
        if i + P[i] > r:
            c = i  # next center = i
            r = i + P[i]

    # Find the longest palindrome length in P
    maxPalindrome = 0
    centerIndex = 0

    for i in range(1, len(Q) - 1):
        if P[i] > maxPalindrome:
            maxPalindrome = P[i]
            centerIndex = i

    return s[(centerIndex - 1 - maxPalindrome) // 2: (centerIndex - 1 - maxPalindrome) // 2 + maxPalindrome]


s = input()
print(longestPalindromeSubstring(s))
