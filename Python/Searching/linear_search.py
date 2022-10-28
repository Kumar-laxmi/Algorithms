'''
<----------------------------------PROBLEM------------------------------------>
Given an array arr[] of n elements, write a function to search a given element el in arr[].

Variables used:
n = total number of elements in array
arr = list of elements
el = element to be searched in the array.
'''

n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)
el = int(input())
# Flag variable to keep a check if the element is found till then.
flag = False
for i in arr:
    if i == el:
        flag = True

if flag:
    print("Element found:)\n")
else:
    print("Element not found:(\n")