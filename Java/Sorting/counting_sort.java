public class counting_sort {
    // We will be using counting sort.
    // Efficient for smaller range.
    // Time Complexity - O(n+k) | Space Complexity - O(n+k)

    public static void Sort(int[] nums) {

        //STEP 1 : largest element in the array.
        int largest = Integer.MIN_VALUE;

        for(int i=0; i<nums.length; i++){
          largest = Math.max(largest, nums[i]);
        }

        //STEP 2 : making our count array
        int count[] = new int[largest+1]; //this array keeps track of the coutn frequency of numbers equal to its index

        for(int i=0;i<nums.length;i++){
            count[nums[i]]++;  //writing the frequncy in coutn array
        }

        //STEP 3 : Sorting
        for(int i=0,j=0;i<count.length;i++){
            while(count[i]>0){
                nums[j]=i;
                j++;
                count[i]--;
            }
        }
    }

    static void Printarr(int arr[]) 
    {
        for (int i = 0; i < arr.length; i++) 
        {
            System.out.print(arr[i] + ", ");
        }
    
    }

    public static void main(String args[]) {
        int nums[] = { 1, 4, 3, 2, 4, 3, 7 };
        System.out.println("Original Array : ");
        Printarr(nums);
        System.out.println();
        System.out.println("Sorted Array : ");
        Sort(nums);
        Printarr(nums);
    }
}