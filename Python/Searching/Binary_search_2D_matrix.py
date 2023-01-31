
    # Binary Search is usally done on a 1D array but there can be multiple approaches to conduct a binary search in a 2D array. For eg,
    # 1. Convert the 2D array into a 1D array and conduct the search. 
    #     Time Complexity: O(Logm+Logn)
    #     Space Complexity: O(m+n)

    # 2. Another efficient approach is to virtualize the 2D array into a 1D array by using % and / operators to determine the indexes, and then 
    #     apply Binary Search in that virtual 1D array. 
    #     The following code follows this approach.
    #     Time Complexity: O(Logmn)
    #     Space Complexity : O(1).


def binarySearch(arr,target,r,c):
    s=0
    e=r*c -1
    # Preventing integer overflow
    mid=s+(e-s)/2

    while(s<=e):
        e=arr[int(mid/c)][int(mid%c)]#[mid/c][mid%c] will give the middle index of the virtual 1D array 

        if(target==e):
            print("Element found")
            return
        elif(target>e): #Target is in the lower half of the matrix so starting index updates.
            s=mid+1
        else:#Target is in the upper half of the matrix so ending index updates.
            e=mid-1
    
    print("Element not found")
    return


r=4
c=5
arr=[[ 0, 6, 8, 9, 11], [20, 22, 28, 29, 31], [36, 38, 50, 61, 63 ], [64, 66, 100, 122, 128]]
target=31
binarySearch(arr,target,r,c)
