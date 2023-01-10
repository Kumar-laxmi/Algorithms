def shell_Sort(arr):
    n= len(arr)
    # define the gap
    gap = n//2

    while gap>0:
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
            
        gap=gap//2