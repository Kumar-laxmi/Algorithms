import java.util.Scanner;

class quick_sort{
	//function to swap values in array
	void swap_values(int[] arr, int i, int j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	//puts all the values<pivot to left of pivot
	//and greater to the left
	int partition(int[] arr, int low, int high){
		int pivot = arr[high];
		int i = (low - 1);
		for (int j = low; j <= high - 1; j++) {
			if (arr[j] < pivot) {
				i++;
				swap_values(arr, i, j);
			}
		}
		swap_values(arr, i + 1, high);
		return (i + 1);
	}
    //function for quick sort
	void quickSort(int[] arr, int low, int high){
		if (low < high) {
			int pivot = partition(arr, low, high);
			
			quickSort(arr, low, pivot - 1);
			quickSort(arr, pivot + 1, high);
		}
	}

	public static void main(String[] args)
	{
	    Scanner s = new Scanner(System.in);    
	    //enter array size
        int n = s.nextInt();
        //initialize array with size n
        int[] arr = new int[n];
        //input the array
        for(int i=0;i<n;i++){
            arr[i] = s.nextInt();   
        }
		s.close();

		quick_sort sortArray = new quick_sort();
        //call the quickSort function
		sortArray.quickSort(arr, 0, n - 1);
		//print the array after sorting
		System.out.println("Sorted array: ");
		for (int i = 0; i < n; i++){
			System.out.print(arr[i] + " ");
		}
	}
}