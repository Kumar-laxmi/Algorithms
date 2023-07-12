"""This code takes input of three sides of a traingle from the user and returns it's are which is calculated using Heron's Formula. In symbols, if a, b, and c are the lengths of the sides: Area = Square root of√s(s - a)(s - b)(s - c) where s is half the perimeter, or (a + b + c)/2."""


import math

s1 = float(input("Enter side 1 of triangle: "))
s2 = float(input("Enter side 2 of triangle: "))
s3 = float(input("Enter side 3 of triangle: "))

S = (s1 + s2 + s3) / 2
area = math.sqrt(S * (S - s1) * (S - s2) * (S - s3))

print(f"The area of the triangle is: {area:.2f}")

