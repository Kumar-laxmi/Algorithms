"""
  ------------------------------------------------- PREREQUISITE ---------------------------------------------------------

    --> The list should be sorted either in ascending order or descending order.

  ------------------------------------------- Order Agnostic Binary Search -----------------------------------------------

    The difference between the normal binary search and order agnostic binary search is, in normal we don't have a condition
    to check whether the list is sorted in ascending or descending but in order agnostic there will be a condition to check.

    1) Checking whether the list is in ascending order or in descending order.
                asc = list[start] < list[end] 

    2) Calculate the value of middle.
                middle = start + (end-start)//2

    3) If the searched value at the index middle we have to return it.
                return middle
    
    4) If the list is in ascending order then,

        i) If the current element is less than the element to be searched then we have to increment middle by 1
                start = middle + 1

        ii) If the current element is greater than the element to be searched then we have to decrement middle by 1
                end = middle - 1

    5) If the list is in descending order then,

        i) If the current element is greater than the element to be searched then we have to incrementt middle by 1
                start = middle + 1

        ii) If the current element is less than the element to be searched then we have to decrement middle by 1
                end = middle - 1

  ------------------------------------------------- Complexities ---------------------------------------------------------

    Time Complexity  --> BigO(log(n))
    Space Complexity --> BigO(1)
    Space Complexity --> BigO(n)

"""
# Function which performs the order agnostic binary search
def order_agnostic_binary_search(list,start,end,search) :

    # Checking whether the list is in ascending order or in descending order.
    asc = list[start] < list[end]

    # Starting and ending condition of the binary search
    while start<=end :
        # Calculating the value of middle.
        middle = start + (end-start)//2

        # If the searched value at the index middle we have to return it.
        if list[middle] == search :
            return middle
        
        # When the list is in ascending order the binary search will be
        if asc == True :

            # If the current element is less than the element to be searched then we have to increment middle by 1
            if list[middle] < search :
                start = middle + 1

            # If the current element is greater than the element to be searched then we have to decrement middle by 1
            else :
                end = middle - 1
        
        # When the list is in descending order the binary search will be
        else :

            #If the current element is greater than the element to be searched then we have to incrementt middle by 1
            if list[middle] > search :
                start = middle + 1

            # If the current element is less than the element to be searched then we have to decrement middle by 1
            else :
                end = middle - 1

    # If element is not present in the list then we have to return this
    return -0

# Declaring the list 
list = []

# Reading the size of the list
size = int(input("Enter the size of the list = "))

# Reading the list elements from the user
for i in range(0,size):
    list.append(int(input("Enter the list elements = ")))

# Reading the element to be searched inside the list
search = int(input("Enter the element to be searched = "))

# Calling the binary search function
searched = order_agnostic_binary_search(list,0,size-1,search)

# If the element is not found then it executes
if searched == -0 :
    print("Element not present in the list")
# Printing the index of the searched element
else :
    print("The element",search,"is found at the index",searched)