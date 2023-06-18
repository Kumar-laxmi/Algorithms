#include <stdio.h>

/*

---------------------

problem - Given a sorted integer array and a target, 
determine if the target exists in the array or not using an interpolation search algorithm. 
If the target exists in the array, return the index of it.

----------------------

it is same as binary search but it use this formula to calculate mid -
  mid = low + ((target – A[low]) * (high – low) / (A[high] – A[low]));


-------------------

variables - 
start - starting index also know as low or low (low most element )
end - ending index also know as high or right ( right most element)
target - element to be search in the array
size - size of the array 

--------------------

*/

//Function to determine if target exists in a sorted array `array` or not

int interpolationSearch(int array[], int start, int end, int target)
{
	int mid;
	    // search space is array[low…high]
  if (start <= end && target >= array[start] && target <= array[end]) {
	 // estimate mid
    mid = start+ (((long long)(end - start) / (array[end] - array[start]))
				* (target - array[start]));

	//target value found
    if (array[mid] == target)
			return mid;

	//target is big then  discard all elements in the left search space, including the middle element
    if (array[mid] < target)
			return interpolationSearch(array, mid + 1, end, target);
	
    //target is small then  discard all elements in the right search space, including the middle elemen
    if (array[mid] > target)
			return interpolationSearch(array, start, mid - 1, target);
	}
  //if target is not found
	return -1;
}


int main()
{

  
  int array[] = {2, 5, 10, 14, 21, 26, 32, 37, 42, 49};
	int size = sizeof(array) / sizeof(array[0]);

  	//value you want to search in the array
	int target = 21; 
  //function call for inpterpolationSearch
	int index = interpolationSearch(array, 0, size - 1, target);

	
  if (index != -1)
		printf("Element found at index %d", index);
	else
		printf("Element not found.");
	return 0;
}
//code is contributed by rajendra mandliya