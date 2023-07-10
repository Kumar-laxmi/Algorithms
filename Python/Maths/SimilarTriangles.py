# Similar Triangles Program
# It can be used to check whether the two triangles are similar or not.
# Author: @swastik-akhil


# SSS property

a1, b1, c1 = 3, 4, 5
a2, b2, c2 = 6, 8, 10
if a1/a2 == b1/b2 == c1/c2:
    print("The triangles are similar")
else:
    print("The triangles are not similar")


# AA property

x1, x2 = 40, 70
y1, y2 = 40, 70
if x1 == y1 and x2 == y2:
    print("The triangles are similar")
else:
    print("The triangles are not similar")


# SAS property

a3, m, b3 = 3, 50, 4
a4, n, b4 = 6, 50, 8
if a3/a4 == b3/b4 and m == n:
    print("The triangles are similar")
else:
    print("The triangles are not similar")
