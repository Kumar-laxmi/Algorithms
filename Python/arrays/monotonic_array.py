def isMonotonic(nums):
    s = 0
    n = len(nums)
    e = n-1
    while (s < e):
        if (nums[s]<=nums[s+1] and nums[s]<=nums[e] and e==n-1):
            s += 1

        elif (nums[e]<=nums[e-1] and nums[e]<=nums[s] and s==0):
            e -= 1

        else:
            break
    
    if(s==n-1 or e==0):
        return True
    return False

def main():
    nums = []
    n = int(input("Enter no of elements in array:"))
    print("Enter elements of array:")
    for i in range(n):
        element = input()
        nums.append(element)
        
    if isMonotonic(nums):
        print("The array is Monotonic")
    else:
        print("The array is not monotonic")
        
main()
# MONOTONIC ARRAY IN python
# This Program Tells if an array is monotonic or not.
