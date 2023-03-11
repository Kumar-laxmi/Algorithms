/*
 ---------------------------------------------- Problem Statement --------------------------------------------------------

    The input consist of an array elements of size n and the output should be sorted array elements using bucket sort.

    INPUT  :- 5                      --> Size of the array
              [1.0,1.3,1.0,1.1,1.6]  --> Array elements
    OUTPUT :- [1.0,1.0,1.1,1.3,1.6]  --> Sorted array

 --------------------------------------------- Bucket Sort Algorithm -----------------------------------------------------

    1) Find maximum element and minimum of the array.

            double maxElement = Arrays.stream(arr).max().getAsDouble();
            double minElement = Arrays.stream(arr).min().getAsDouble();

    2) Find the dispersion of array elements (ie, range between the maximum element and minimum element)

            double range = (maxElement - minElement) / noOfBuckets;

    3) Create n buckets of calculated range

            bucket.add(new ArrayList<>());

    4) Scattering the array elements to these buckets

            ((arr[i] - minElement) / range)

    5) Now sort each bucket individually,

            bucket.get(i).sort(Double::compare);

    6) Putting all the sorted elements in each buckets to a single array.

 ------------------------------------------------- Complexities ----------------------------------------------------------

    Time Complexity  :- BigO(n+b) --> n is the size of array and b is the bucket size.
    Space Complexity :- BigO(n+b) --> An additional array of size k to store the buckets
                                      and another array of size n to store the sorted elements.

 */
import java.util.*;
public class BucketSort
{
    public static void main(String[] args)
    {
        // Initializing the scanner class
        Scanner sc = new Scanner(System.in);

        // Reading the size of the array
        System.out.print("Enter the size of the array = ");
        int size = sc.nextInt();

        // Initializing the double array with its size
        double[] arr = new double[size];

        // Reading the elements of array from the user
        for(int i =0;i<size;i++)
        {
            System.out.print("Enter the array element = ");
            arr[i] =  sc.nextDouble();
        }

        // Calling the bucket sorting method to perform the bucket sort.
        BucketSorting(arr,size);
    }
    // Method which implements the bucket sort.
    private static void BucketSorting(double[] arr, int noOfBuckets)
    {
        // Find maximum element and minimum element using stream API
        double maxElement = Arrays.stream(arr).max().getAsDouble();
        double minElement = Arrays.stream(arr).min().getAsDouble();

        // find the dispersion of array elements (ie, range between the maximum element and minimum element)
        double range = (maxElement - minElement) / noOfBuckets;

        // Creating empty buckets of size array to store values based on their bucket's index.
        List<List<Double>> bucket = new ArrayList<>();
        for (int i = 0; i < noOfBuckets; i++)
        {
            bucket.add(new ArrayList<>());
        }
        // Putting the elements into the appropriate buckets based on the array value.
        for (double v : arr) {
            double difference = (v - minElement) / range - (int) ((v - minElement) / range);
            // Checking the element is not the min element and difference is = 0
            if (difference == 0 && v != minElement) {
                bucket.get((int) ((v - minElement) / range) - 1).add(v);
            } else {
                bucket.get((int) ((v - minElement) / range)).add(v);
            }
        }
        // Sorting each non-sorted bucket using built in method.
        for (List<Double> doubles : bucket) {
            // Conforming the bucket is not empty and then sorting
            if (!doubles.isEmpty()) {
                doubles.sort(Double::compare);
            }
        }
        // Temporary variable to store the elements to the array.
        int k = 0;
        System.out.println("The sorted array using bucket sort,");
        // Putting all the sorted elements in each buckets to a single array.
        for (List<Double> lst : bucket)
        {
            // Checking if the list empty or not.
            if (!lst.isEmpty())
            {
                // Adding all the bucket values to array arr[] using this for loop.
                for (double i : lst)
                {
                    arr[k] = i;
                    // Printing the sorted elements using bucket sort.
                    System.out.print(arr[k++] + " ");
                }
            }
        }
    }
}