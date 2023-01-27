"""
  ------------------------------------------- The Problem Statement ------------------------------------------------------

    Given a unsorted array of size "n" we have to sort the array using Gnome sort.
    The first line of input is the size of the array going to be given and second line represents the array elements of size "n"

       INPUT :-  4
                  [5,3,4,2]

       OUTPUT :-  [2,3,4,5]

  ----------------------------------------------- Gnome Algorithm --------------------------------------------------------

    Gnome Algorithm will be as insertion sort but not the exact same.

    Firstly sorting an array in ascending order means the elements on the left side of an element should be less than the
    element we choosen.

    Lets take a pointer "pointer" which will be used to iterate the array whose current position is 0

    1) since there is no element on left side we can move to next element by incrementing pointer by 1
       to compare to say whether the array is sorted or not.

          if(pointer==0) { pointer++; }

    2) If the element on the left side is greater than the pointer element we need to swap.

           if(array[pointer] < array[pointer-1]) { swap(array[pointer] < array[pointer-1]); pointer--; }

    3) If the pointer element is equal or greater than the left side element we have to do nothing with the array just
       increment the pointer by 1, so it points to the next element.

            if(array[pointer] >= array[pointer-1]) { pointer++; }

    Since first and third conditions are doing the same job we can combine it as a single if block using "OR" operator to reduce the code redundancy like this,

            if(pointer == 0 or array[pointer] < array[pointer-1]) { pointer++; }

   ----------------------------------------------- Complexities ----------------------------------------------------------

       Time Complexity  :- BigO(n^2)
       Space Complexity :- BigO(1)
       Space Complexity :- BigO(n) --> If you used recursion for sorting.

"""
# Declaring that gnome_sort is of type list
gnome_sort =[]

# Getting size of the list from the user using input method
size = int(input("Enter size of array = "))

# Reading elements from user using for loop and putting it into the gnome_sort list
for i in range(0,size) :
    b = int(input("Enter array elements = "))
    gnome_sort.append(b);

# Printing the list elements before sorting.
print("\nBefore Gnome sorting the srray elements are ")
for i in range (0,size) :
    print(gnome_sort[i], end=" ")

# For iterating the gnome_sort list we need a variable that is called as pointer variable
pointer = 0

# Gnome Sorting Algorithm starts
# The starting and ending condition of the loop
while(pointer < size) :

    # pointer == 0 --> It is the starting of the list so no elements on left side of the list it is the greatest we can increment.
    if pointer ==0 :

        pointer = pointer+1

    # gnome_sort[pointer] < gnome_sort[pointer-1] --> List element in left side is higher than the right side so we need to swap.
    if gnome_sort[pointer] < gnome_sort[pointer-1] :

        # Swapping the elements because the list element in left side is higher than the right side.
        gnome_sort[pointer] = gnome_sort[pointer] + gnome_sort[pointer-1]
        gnome_sort[pointer-1] = gnome_sort[pointer] - gnome_sort[pointer-1]
        gnome_sort[pointer] = gnome_sort[pointer] - gnome_sort[pointer-1]

        pointer=pointer-1

    # gnome_sort[pointer] >= gnome_sort[pointer-1] --> The elements are already in sorted position so no need to swap, we can increment.
    if gnome_sort[pointer] >= gnome_sort[pointer-1] :

        pointer =pointer+1


# Printing the list elements after gnome sorting
print("\nAfter Gnome Sorting the array Elements are")
for i in range(0,size) :
    print(gnome_sort[i], end=" ")