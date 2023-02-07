#Time Complexity - O(N)
#Space Complexity - O(1)

def sort012(arr, n):

    #start left pointer from 0
    #start right pointer from n-1
    
    left = 0
    right = n-1
    i=0

    # If the ith element is 0 then we will swap the element with the low range.
    # Similarly, if the ith element is 1 then keep it as it is.
    # If the element is 2 then we swap it with an element in the high range.

    while i<=right:
        if arr[i] == 0:
            arr[left], arr[i] = arr[i], arr[left]
            left+=1
        elif arr[i] == 2:
            arr[right], arr[i] = arr[i], arr[right]
            right-=1
            i-=1
            
        i+=1

print('Enter the number of elements in array:')
n = int(input())

print('Enter the array values (in space separated format):')
arr = [int(i) for i in input().split(' ')]

sort012(arr, n)

print('Sorted array is:')
print(' '.join([str(i) for i in arr]))
                