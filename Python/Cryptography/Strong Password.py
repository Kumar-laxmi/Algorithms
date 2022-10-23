import math
import os
import random
import re
import sys


def minimumNumber(n, password):
    nums = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special = "!@#$%^&*()-+"
    counts = 4
    if any(list(map(lambda x: x in nums,password))):
        counts -= 1
    if any(list(map(lambda x: x in lower_case,password))):
        counts -= 1
    if any(list(map(lambda x: x in upper,password))):
        counts -= 1 
    if any(list(map(lambda x: x in special,password))):
        counts -= 1
    if n+counts < 6:
        return (6-n)
    else:
        return counts

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()
