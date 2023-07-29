"""Congruency of Triangles Program
     It can be used to check whether the two traingles are congruent or not.
     Author: @swastik-akhil
"""

# SSS property
a1, b1, c1 = 3, 4, 5
a2, b2, c2 = 3, 4, 5

if a1 == a2 and b1 == b2 and c1 == c2:
    print("The triangles are congruent")
else:
    print("The triangles are not congruent")

# SAS property
a3, m, b3 = 3, 50, 4
a4, n, b4 = 3, 50, 4

if a3 == a4 and b3 == b4 and m == n:
    print("The triangles are congruent")
else:
    print("The triangles are not congruent")

# ASA property
m1, a5, m2 = 40, 3, 60
m3, a6, m4 = 40, 3, 60

if m1 == m3 and m2 == m4 and a5 == a6:
    print("The triangles are congruent")
else:
    print("The triangles are not congruent")

# AAS property
m5, m6, a7 = 40, 60, 6
m7, m8, a8 = 40, 60, 6

if m5 == m7 and m6 == m8 and a7 == a8:
    print("The triangles are congruent")
else:
    print("The triangles are not congruent")

# RHS property
a9, b5 = 3, 4
a10, b6 = 3, 4

if a9 == a10 and b5 == b6:
    print("The triangles are congruent")
else:
    print("The triangles are not congruent")
