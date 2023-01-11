# This Algorithm is modification over the Insertion Sort
# uses a gap value (greater than 1) to move elements to ahead

def shell_Sort(arr):
    n= len(arr)  # size of array
    # define the gap
    gap = n//2

    while gap > 0:  # loop will run until gap becomes 0
                  # gap == 1, shell sort becomes insertion sort  
        j = gap
        # Check the array from left to right
        # till last index of j
        while j < n:  
            i = j-gap 
              
            while i >= 0:
                #checking values at index i and (i+gap)
                # If value on right side is already greater than left side value
                # We don't have to do swap else we will swap
                if arr[i+gap] > arr[i]:
  
                    break
                else:
                    arr[i+gap],arr[i] = arr[i],arr[i+gap]
  
                i = i-gap  #To check element on left side also
            j +=1 

        gap = gap//2 #reducing the gap by half in subsequent iterations

#main function
arr = [12, 34, 54, 2, 3, 7, 9]
print("input array:",arr)
  
shell_Sort(arr)
print("sorted array",arr)

# Time Complexity Analysis
#       Best Case    - Ω(n*log n)
#       Average Case - θ(n*log n)
#       Worst case   - O(n^2)
# Space Complexity Analysis - O(1)
# Inplace Sorting Algorithm