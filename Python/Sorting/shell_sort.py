def shell_Sort(arr):
    n= len(arr)  # size of array
    # define the gap
    gap = n//2

    while gap>0:  # loop will run until gap becomes 1
                  # gap = 1, shell sort becomes insertion sort  
        j=gap
        # Check the array from left to right
        
        while j<n:
            i=j-gap 
              
            while i>=0:
                # If value on right side is already greater than left side value
                # We don't have to do swap else we will swap
                if arr[i+gap]>arr[i]:
  
                    break
                else:
                    arr[i+gap],arr[i]=arr[i],arr[i+gap]
  
                i=i-gap # To check left side also
            j+=1

        gap=gap//2 #reducing the gap by half 

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