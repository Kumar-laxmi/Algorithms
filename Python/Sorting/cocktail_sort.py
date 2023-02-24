# Function that performs cocktail sorting

def cocktailSort(arr):
    beg = 0 # points to start of array
    last = len(arr) - 1 # points to end of array
    flag = 1 # determines swapping has take place
    
    while(flag != 0):
        flag = 0 # reset value of flag
        
        # traversing from left to right,
        # swap if left<right, flag = 1
        for i in range(beg,last):
            if(arr[i] > arr[i+1]):
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp
                flag = 1 # means swapping happened 
                
        if(flag == 0): break # means already sorted
        else: flag = 0 # reset value of flag
        
        last -= 1 # decrease end point because element already placed
        
        # traversing from right to left,
        # swap if left>right, flag = 1
        for j in range(last-1, beg-1, -1):
            if(arr[j] > arr[j+1]):
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
                flag = 1 # means swapping happened 
                
        beg += 1 # increase beginning point because element already placed
        
    return arr

# Original array
arr = [6, 2, 5, 3, 9, 1, 3]

# printing original array
print("Before sorting:", arr)

# calling cocktail function
arr = cocktailSort(arr)

# printing sorted array
print("After sorting:", arr)
