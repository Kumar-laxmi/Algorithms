import java.util.*;

class interpolation_search {

/*

-------------------------

problem - Given a sorted integer array and a target, 
determine if the target exists in the array or not using an interpolation search algorithm. 
If the target exists in the array, return the index of it.

------------------

it is same as binary search but it use this formula to calculate mid -
  mid = low + ((target – A[low]) * (high – low) / (A[high] – A[low]));

------------------

variables - 
start - starting index also know as low or low (low most element )
end - ending index also know as high or right ( right most element)
target - element to be search in the array
size - size of the array 

----------------------

*/
  
  
//Function to determine if target exists in a sorted array `array` or not
  public static int interpolationSearch(int array[], int start,
										int end, int target)
	{
		int mid;
	    // search space is array[low…high]
  if (start <= end && target >= array[start] && target <= array[end]) {
	 // estimate mid
    mid = start+ (((end - start) / (array[end] - array[start]))
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

	// Driver Code
	public static void main(String[] args)
	{

		// Array of items on which search will
		// be conducted.
		int arr[] = { 2, 5, 10, 14, 21, 26, 32, 37, 42, 49};

		int size= arr.length;

		// Element to be searched
		int target = 18;
		int index = interpolationSearch(arr, 0, size - 1, target);

		// If element was found
		if (index != -1)
			System.out.println("Element found at index "
							+ index);
		else
			System.out.println("Element not found.");
	}
}

//code is contributed by rajendra mandliya