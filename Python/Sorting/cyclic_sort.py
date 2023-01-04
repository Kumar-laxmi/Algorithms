#Approach: in-place swapping takes place by the formation of cycles.
# Time Complexity: O(n2)



#function to sort elements
def cyclic_sort(arr):
    count = 0
   # cycles to be rotated
    for start in range(0, len(arr)-1):
        item = arr[start]
      #position to place the item
        pos = start
        for i in range(start+1,len(arr)):
            if arr[i] < item:
                pos += 1
      # if item exits, it is not a cycle
        if pos == start:
            continue
      # Otherwise, place the item
        while item == arr[pos]:
            pos += 1
        arr[pos], item = item, arr[pos]
        count += 1
      # rotation continued
        while pos != start:
         # Find a position to place the item
            pos = start
            for i in range(start + 1, len(arr)):
                if arr[i] < item:
                    pos += 1            
         # place the item
            while item == arr[pos]:
                pos += 1
            arr[pos], item = item, arr[pos]
            count += 1
        return count


# Total number of elements in array
print("Enter the number of elements in an array : ")
n = int(input())
arr = []
print("Enter the elements in an array : ")
for i in range(n):
    x = int(input())
    arr.append(x)

#call the sort function
cyclic_sort(arr)
print("Sorted array is : ")
for i in range(0, n) :
   print(arr[i], end = " ")
