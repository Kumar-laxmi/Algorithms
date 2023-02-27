#!/usr/bin/env python

"""Knuth-Morris-Pratt String Matching algorithm

This script demonstrates the KMP string matching algorithm for searching a
given Pattern in given Text. The Pattern is preprocessed to determine how many
characters can be skipped depending on the search position, which is improves
upon naive string search.

Time complexity: O(m + n)
Space complexity: O(m)

where,
    m = length of Pattern string
    n = length of Text string

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""


def preprocess(pattern: str) -> list:
    """Computes the longest proper prefix which is also a suffix for substrings
    of the pattern. It determines how many characters can be skipped while
    matching the pattern with the text, for the current position in the pattern.

    Args:
        pattern (str): Pattern string which must be preprocessed

    Returns:
        list: Lengths of longest-prefix-suffix for each position in the Pattern.
    """
    pattern_len = len(pattern)
    longest_prefix_suffix = [0] * pattern_len
    prev = 0  # length of previous longest-prefix-suffix, initially = 0
    i = 1
    while i < pattern_len:
        if pattern[i] == pattern[prev]:
            prev += 1
            longest_prefix_suffix[i] = prev
            i += 1
        else:
            if prev != 0:  # reset to previous longest instead of 0
                prev = longest_prefix_suffix[prev - 1]
            else:  # first two characters did not match
                longest_prefix_suffix[prev] = 0
                i += 1
    return longest_prefix_suffix


def kmp_matching(text: str, pattern: str) -> list:
    """Searches for the pattern string in the text string using the KMP algorithm.
    Pattern string is preprocessed to determine how many characters can be skipped
    depending on the position of the search in the pattern. This is an optimization
    over naive string searching where position only moves forward by one character.

    Args:
        text (str): Text string in which search is performed
        pattern (str): Pattern string which must be searched in the Text

    Returns:
        list: List of indices where the Pattern was found in the Text.
            Empty list if pattern not found.
    """
    found_idx = []
    text_len = len(text)
    pattern_len = len(pattern)
    longest_prefix_suffix = preprocess(pattern)

    i, j = 0, 0
    while (text_len - i) >= (pattern_len - j):  # pattern should not overflow text
        if text[i] == pattern[j]:  # current characters are matching
            i += 1
            j += 1
            if j == pattern_len:  # complete pattern matched
                found_idx.append(i - j)
                # reset pattern index using preprocessed prefixes
                j = longest_prefix_suffix[j - 1]
        # pattern and text characters not matching
        elif i < text_len:
            if j > 0:
                j = longest_prefix_suffix[j - 1]
            else:
                i += 1  # trivial case when first character does not match

    return found_idx


if __name__ == "__main__":
    text = input("Enter source text: ").strip()
    pattern = input("Enter pattern to be searched: ").strip()
    found_idx = kmp_matching(text, pattern)
    if found_idx:  # non-empty
        print(f"Pattern found at indices: {found_idx}")
    else:
        print("Pattern not found.")
