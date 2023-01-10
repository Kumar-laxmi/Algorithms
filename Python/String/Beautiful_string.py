# Name :  Atul Kumar
# Github username : atul1510
# Repositary name : Algorithms

# Problem Statement: Atul has been given a binary string ‘STR’ containing either ‘0’ or ‘1’. A binary string is called beautiful if it contains alternating 0s and 1s.
# For Example:‘0101’, ‘1010’, ‘101’, ‘010’ are beautiful strings.
# He wants to make ‘STR’ beautiful by performing some operations on it. In one operation, Atul can convert ‘0’ into ‘1’ or vice versa.
# Your task is to determine the minimum number of operations Atul should perform to make ‘STR’ beautiful.

# Time Complexity:- O(n) 


def Beautiful(str):
    m = len(str)
    x1 = 0
    x2 = 0
    s1 = '0'
    s2 = '1'
    for i in range(m):
        if str[i] == '1':
            if s1 == '0':
                x1 += 1
            else:
                x2 += 1
        else:
            if s1 == '1':
                x1 += 1
            else:
                x2 += 1
        if s1 == '1':
            s1 = '0'
            s2 = '1'
        else:
            s1 = '1'
            s2 = '0'
    return min(x1, x2)

test = int(input("Enter total testcases: "))
while test:
    str = input()
    print(Beautiful(str))
    test -= 1