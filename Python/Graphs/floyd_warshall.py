INF = float('inf')

def printmatrix(m):
    r, c = len(m), len(m[0])
    for i in range(r):
        for j in range(c):
            print(m[i][j], end=" ")
        print()

v, e = map(int, input().split())
m = [[None]*v for i in range(v)]
for i in range(v):
    for j in range(v):
        # when source = destination
        if i == j:
            m[i][j] = 0
        # when edge doesn't exist
        else:
            m[i][j] = INF

# Taking input from user
for i in range(e):
    src, dst, wt = map(int, input().split())
    m[src][dst] = wt

print("MATRIX BEFORE USING FLOYD WARSHALL: \n")
printmatrix(m)
print("\n\n")
for k in range(v):
    for i in range(v):
        for j in range(v):
            if m[i][j] + m[k][j] < m[i][j]:
                m[i][j] = m[i][j] + m[k][j]
print("MATRIX AFTER USING FLOYD WARSHALL: \n")
printmatrix(m)
