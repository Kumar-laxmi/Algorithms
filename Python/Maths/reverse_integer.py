#!/usr/bin/env python

"""Reverse Integer

This script reverses an integer entered by the user. Input is validated
and reversal is done only for integer values. Negative integers are reversed
just like positive integers, but with the '-' sign maintained. Leading zeros
are dropped in the reversed number.
Input -> output samples:
    123 -> 321
    -123 -> -321
    3210 -> 123
    123.4 -> 'Only integer values can be reversed.'
    22a -> 'Only integer values can be reversed.'
    <blank> -> 'Argument missing. Enter an integer for reversal.'

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys


def reverse_digits(num: str) -> int:
    """Reverses the input if it is an integer.

    1. Converts string input to integer if valid.
    2. Removes '-' sign for negative integers and stores it for later.
    3. Extracts one digit at a time from the units position of original number
       using modulo division.
    4. Push in the extracted digit into units position of reverse number.
    5. Repeat steps 3 and 4 until all digits are extracted.
    6. Multiply by -1 if the number was originally negative.

    Args:
        num (str): The integer to be reversed, as a string.
            Validated before reversal.

    Returns:
        int: Reversed integer
    """
    reverse = 0
    negative_flag = False
    try:
        original = int(num)
    except ValueError:
        sys.exit("Only integer values can be reversed.")

    # negative integer handled as positive and converted later
    if original < 0:
        negative_flag = True
        original *= -1

    while original > 0:
        digit = original % 10  # extract last digit
        # push in the extracted digit at units position of reverse number
        reverse = reverse * 10 + digit
        original //= 10  # remove last digit from original number

    if negative_flag:
        reverse *= -1
    return reverse


if __name__ == "__main__":
    try:
        num = sys.argv[1]
    except IndexError:
        sys.exit("Argument missing. Enter an integer for reversal.")

    print(f"Reversed integer: {reverse_digits(num)}")
