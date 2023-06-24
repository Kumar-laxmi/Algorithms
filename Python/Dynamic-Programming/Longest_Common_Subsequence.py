string1 = input("Enter first string:") 
string2 = input("Enter second string:") 

n, m = len(string1), len(string2)
lcs = []
for i in range(n+1):
    lst = []
    for j in range(m+1):
        lst.append(0)
    lcs.append(lst)
print(lcs)

for i in range(n+1):
    for j in range(m+1):
        if i == 0 or j == 0:
            lcs[i][j] = 0
        elif string1[i-1] == string2[j-1]:
            lcs[i][j] = lcs[i-1][j-1]+1
        else:
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1])
print(lcs)

print("Longest Common Subsequence: ", lcs[m][n])

i = n
j = m
temp = ""
while i >= 1 and j >= 1:
    if string1[i-1] == string2[j-1]:
        temp += string1[i-1]
        i -= 1
        j -= 1
    elif lcs[i-1][j] > lcs[i][j-1]:
        i -= 1
    else:
        j -= 1
print("LCS is: ",temp[::-1])
