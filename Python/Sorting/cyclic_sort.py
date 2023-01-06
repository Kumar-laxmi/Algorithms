#Approach: in-place swapping takes place by the formation of cycles.
# Time Complexity: O(n2)

# defination of an array
def cyclic_sort(array,temp,place):
    count=0
    # increment count 
    for num in array:
        if num < temp:
            count+=1

    # if the number is not sorted
    if temp != array[count]:
        x=array[place]
        array[place] = array[count]
        array[count]= x
        #recursively call function until sorted
        cyclic_sort(array,array[place],place)

    else:
        if place <=(n-2):
            cyclic_sort(array,array[place+1],place+1)
        # print if sorted
        else:
            print("Sorted array is : ")
            for i in range(0, n) :
                print(array[i], end = " ")
                

if __name__=="__main__":
    # Enter the number of elements
    print("Enter the number of elements in an array : ")
    n = int(input())
    array = []
    # Append the elements in the array
    print("Enter the elements in an array : ")
    for i in range(n):
        x = int(input())
        array.append(x)

    # function call
    cyclic_sort(array,array[0],0)
