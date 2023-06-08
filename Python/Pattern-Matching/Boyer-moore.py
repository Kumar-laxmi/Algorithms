"""------------------------------------------------INTRODUCTION-------------------------------------------------------------------------*/
/*Boyer-Moore-Horspool is an algorithm for finding substrings into strings. This algorithm compares each characters of substring to find 
a word or the same characters into the string from right to left. When characters do not match, the search jumps to the next matching 
position in the pattern by the value indicated in the Bad Match Table.
value is calculated using 
"value=length(substring)-index(last occurance)-1."

The Bad Match Table indicates how many jumps should it move from the current position to the next."""

"""----------------------------------------------ALGORITHM-----------------------------------------------------------------------------
1.first it finds out the lenght of both the strings.
2.bad match table is prepared using the value formula for substring and it include characters only once no repeated element is 
  considered elements out of the substring that are present in main string are considered under *.
3.now it compares each char of substring from right to left with parent string if not found moves from the current position to next 
  by the corresponding value of that character in bad match table.
4.after all successful comparisions the index is returned at which is was matched.
"""
#function to create bad character table.
def bad_character_table(pattern):
    table = {}
    pattern_length = len(pattern)
    for i in range(pattern_length - 1):
 #calculated the value of characters.
        table[pattern[i]] = pattern_length - 1 - i
    return table
#function for boyer_moore patter matching.
def boyer_moore(text, pattern):
    n = len(text)
    m = len(pattern)
    if m == 0:
        return []

    bad_char = bad_character_table(pattern)
    occurrences = []

    i = 0
    while i <= n - m:
        j = m - 1

        while j >= 0 and pattern[j] == text[i + j]:
            j -= 1

        if j == -1:
            occurrences.append(i)
            i += 1
        else:
            char_shift = bad_char.get(text[i + m - 1], m)
            i += char_shift

    return occurrences

# Example usage
text = "ABABDABACDABABCABAB"
pattern = "ABABCABAB"
# calling boyer-moore method
result = boyer_moore(text, pattern)
print("Occurrences found at indices:", result)
