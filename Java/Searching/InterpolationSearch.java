public class InterpolationSearch {
    // Interpolation Search algorithm
    public static int interpolationSearch(int[] arr, int x) {
        int low = 0;
        int high = arr.length - 1;
 
        while (low <= high && x >= arr[low] && x <= arr[high]) {
            // Estimate the position of x in the array
            int pos = low + (((high - low) / (arr[high] - arr[low])) * (x - arr[low]));
 
            // If x is found at position pos
            if (arr[pos] == x)
                return pos;
 
            // If x is greater, ignore the left half
            if (arr[pos] < x)
                low = pos + 1;
            // If x is smaller, ignore the right half
            else
                high = pos - 1;
        }
 
        // Element not found
        return -1;
    }
 
    public static void main(String[] args) {
        int[] arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        int x = 14;
 
        // Perform interpolation search
        int result = interpolationSearch(arr, x);
 
        // Check if the element was found or not
        if (result == -1)
            System.out.println("Element not found.");
        else
            System.out.println("Element found at index " + result + ".");
    }
}
