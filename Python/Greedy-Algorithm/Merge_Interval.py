#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
#Problem Statement : Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
#and return an array of the non-overlapping intervals that cover all the intervals in the input.
def MI(arr):
    # Sorting based on the increasing order
    # of the start intervals
    arr.sort(key=lambda x: x[0])
    # Stores index of last element
    # in output array (modified arr[])
    index = 0
    # Traverse all input Intervals starting from
    # second interval
    for i in range(1, len(arr)):
        # If this is not first Interval and overlaps
        # with the previous one, Merge previous and
        # current Intervals
        if (arr[index][1] >= arr[i][0]):
            arr[index][1] = max(arr[index][1], arr[i][1])
        else:
            index = index + 1
            arr[index] = arr[i]
    print("The Merged Intervals are :", end=" ")
    for i in range(index+1):
        print(arr[i], end=" ")
# Main Finction
arr = [[1, 3], [2, 6], [8, 10], [15, 18]]
MI(arr)