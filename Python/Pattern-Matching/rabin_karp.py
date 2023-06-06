# Rabin Karp algorithm in python

def rabinKarp(inputString, pattern, m, n):

    hashf = 1  # hash value
    p = 0  # hash value of pattern
    t = 0  # hash value of string

    for i in range(m - 1):
        hashf = (hashf * d) % q

    for i in range(m):  # hash values of pattern and string respectively
        p = (d * p + ord(pattern[i])) % q
        t = (d * t + ord(inputString[i])) % q

    # Matching pattern with string
    for i in range(n - m + 1):
        flag = 0
        if(p == t):
            for j in range(m):
                if(inputString[i + j] != pattern[j]):
                    break
            j += 1
            if(j == m):
                flag = 1
                print("Pattern found at Index: ", i)
        if(i < n - m):
            t = (d * (t - ord(inputString[i]) *
                 hashf) + ord(inputString[i + m])) % q
            if(t < 0):  # t might have -ve value, making it +ve
                t = t + q
    if(flag == 0):
        print("Pattern not present in string")
inputString = input("Enter string: ")
pattern = input("Enter pattern to find: ")

m = len(pattern) # length of string
n = len(inputString) # length of pattern

d = 26  # no of alphabets
q = 101  # prime no

# calling pattern search function
rabinKarp(inputString, pattern, m, n)