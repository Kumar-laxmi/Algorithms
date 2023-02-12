/*
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

    Since first and third conditions are doing the same job we can combine it as a single if block to reduce the code redundancy like this,

            if(pointer == 0 || array[pointer] < array[pointer-1]) { pointer++; }

    We can use "Ternary Operator" to implement the above if statement too like this.
    
    		pointer = (pointer == 0 || gnome_sort[pointer] >= gnome_sort[pointer-1]) ? pointer+1 : pointer;

   ----------------------------------------------- Complexities ----------------------------------------------------------

       Time Complexity  :- BigO(n^2)
       Space Complexity :- BigO(1)
       Space Complexity :- BigO(n) --> If you used recursion for sorting.

 */


// Importing the neccesary things.
#include<bits/stdc++.h>
using namespace std;

// Starting of main function
int main()
{
	// Declaring the size of the array
	int size;
	
	// Reading the size of the array to be sorted
	cout<<"Enter Size of the Array = ";
	cin>>size;
	
	// Declaring the gnome_sort array
	int gnome_sort[size];
	
	// Reading elements from user using for loop and putting it into the gnome_sort array
	for(int i=0;i<size;i++)
	{
		cout<<"Enter Array Element " << i+1 << " = ";
		cin>>gnome_sort[i];
	}
	
	// Printing the array elements before sorting.
	cout<<"\nBefore Gnome sorting the array elements are \n";
	for(int i=0;i<size;i++)
	{
		cout<<gnome_sort[i] << " ";
	}
	
	// For iterating the gnome_sort array we need a variable that is called as pointer variable
	int pointer =0;
	
	// Gnome sorting starts
	// Here I implemented gnome sort using do-while you can use while loop too.
	do
	{
		// pointer == 0 --> It is the starting of the array so no elements on left side of the array it is the greatest we can increment.
    	// gnome_sort[pointer] >= gnome_sort[pointer-1] --> The elements are already in sorted position so no need to swap, we can increment.
    	// Here we used ternary operator to combine the two cases of pointer.
		pointer = (pointer == 0 || gnome_sort[pointer] >= gnome_sort[pointer-1]) ? pointer+1 : pointer;
		
		// gnome_sort[pointer] < gnome_sort[pointer-1] --> List element in left side is higher than the right side so we need to swap.
        if (pointer < size && gnome_sort[pointer] < gnome_sort[pointer-1])
        {
			// Swapping the elements because the list element in left side is higher than the right side.
            swap(gnome_sort[pointer],gnome_sort[pointer-1]);
            pointer--;
        }
	} while(pointer<size); // The BASE Condition or the starting and breaking point of the program.
	
	// Printing the array elements after gnome sorting
	cout<<"\nAfter Gnome sorting the array elements are \n";
	for(int i=0;i<size;i++)
	{
		cout<<gnome_sort[i] << " ";
	}
}
