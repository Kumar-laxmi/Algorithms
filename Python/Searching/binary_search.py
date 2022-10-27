'''
<----------------------------------PROBLEM------------------------------------>
Given a sorted array arr[] of n elements, write a function to search a given 
element x in arr[] and return the index of x in the array.

Variables used:
n = total number of elements in array.
arr = array initialized with the input size.
el = element to be searched in the array.
lt = left-most index of the search space.
rt = right-most index of the search space.
'''

n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)

el = int(input())

lt, rt = 0, n-1
# to keep a track if the element has been found till then.
flag=False
while lt<=rt:
    # in order to prevent overflow of `int`, it has been written lt + (rt-lt)/2 instead of (lt+rt)/2
    mid = int(lt + (rt-lt)/2)
    # element is equal to mid, return the index
    if arr[mid] == el:
        flag=True
        break
    # element is larger than mid, then shift search space to right.
    elif arr[mid] < el:
        lt = mid + 1
    # element is smaller than mid, then shift search space to left.
    else:
        rt = mid - 1

if flag:
    print("Element found:)")
else:
    print("Element not found:(")