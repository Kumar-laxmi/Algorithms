import java.util.Scanner;

public class merge_sort {
    public void merge(int[] arr, int l, int mid, int r){
        int i = l, j = mid+1, k=0;
        int[] b = new int[r-l+1];
        // Compares the elements of the two arrays and sorts them
        while (i<=mid && j<=r)
        {
            if (arr[i]>arr[j]){
                b[k] = arr[j];
                j++;
                k++;
            }
            else{
                b[k] = arr[i];
                i++;
                k++;
            }
        }
        // If the 1st array is exhausted, then copies the remaining elements of the 2nd array to the 1st array
        while (j<=r){
            b[k] = arr[j];
            j++;
            k++;
        }
        // If the 2nd array is exhausted, then copies the remaining elements of the 1st array to the 2nd array
        while (i<=mid){
            b[k] = arr[i];
            i++;
            k++;
        }
        // Copies all the elements of the array 'b' to array 'arr'
        for (int x = l; x <= r; x++){
            arr[x] = b[x-l];
        }
    }

    // Function that divides the array into half at each step and sorts them
    void mergeSort(int[] arr, int l, int r){
        if (l<r)
        {
            int mid = l + (r-l)/2;
            // Sorts the left array
            mergeSort(arr, l, mid);
            // Sorts the right array
            mergeSort(arr, mid+1, r);
            // Merges the left and the right array
            merge(arr, l, mid, r);
        }
    }

    public static void main(String args[])
	{
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) arr[i] = s.nextInt();

        // function call
        merge_sort hs = new merge_sort();
        hs.mergeSort(arr, 0, n-1);
        // display sorted array
        System.out.print("After sorting:\n");
        for(int i : arr) System.out.print(i + " ");		
	}
}
