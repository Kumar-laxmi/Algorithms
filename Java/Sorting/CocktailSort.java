/*
  This JAVA code can sort any array.
  Characteristics: Cocktail Sort is an improvement over Bubble Sort by allowing bidirectional passes and early termination when the array is already sorted or no swaps are made.
  -author~ Akhil Agrawal
  Github :- @swastik-akhil
This code implements the Cocktail Sort algorithm to sort an integer array in ascending order.

1. The `CocktailSort` class is defined, which contains the `main` method.

2. In the `main` method:
   - An integer array `arr` is initialized with some values.
   - The initial array is printed using a for-each loop and `System.out.print`.
   - Variables `k_start` and `k_end` are initialized to track the starting and ending indices for the second pass of the Cocktail Sort.
   - The length of the array is stored in the variable `len`.
   - A boolean variable `swapped` is set to `false` to keep track of whether any swaps have been made during the sorting process.

3. The code then determines the number of iterations required for the Cocktail Sort loop based on the length of the array. If the length is even, the number of iterations is half the length; otherwise, it is half the length plus one.

4. The first pass of the Cocktail Sort begins with a nested loop. It compares adjacent elements and swaps them if the preceding element is greater than the succeeding element. If a swap occurs, the `swapped` variable is set to `true`.

5. After completing the first pass, the code checks if any swaps were made during the pass. If no swaps occurred, it means the array is already sorted, and the loop is terminated.

6. The second pass of the Cocktail Sort starts, iterating in reverse from `k_end` to `k_start+1`. It compares adjacent elements and swaps them if the preceding element is greater than the succeeding element.

7. The values of `k_end` and `k_start` are adjusted to narrow down the range of elements that need to be sorted in the next iteration.

8. Steps 4 to 7 are repeated until the array is fully sorted.

9. The sorted array is printed using a for-each loop and `System.out.print`.

The code effectively demonstrates the Cocktail Sort algorithm by sorting the given integer array in ascending order.
*/
public class CocktailSort {
    public static void main(String[] args) {
        int[] arr = { 5, 1, 4, 2, 8, 0, 2, 3, 9, 7 };
        for (int i : arr) {
            System.out.print(i + " ");
        }
        int k_start = 0;
        int k_end =arr.length-1;
        int len = arr.length;
        boolean swapped= false;
        if(len%2==0){
            len = len/2;
        }
        else{
            len = len/2 + 1;
        }
        for(int i = 0; i < len; i++){
            for(int j =0 ; j < arr.length - i - 1 - k_start; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp; 
                    swapped = true;
                }
            }
            if(swapped == false){
                break;
            }
            for(int x =k_end ;x>k_start+1 ;x--){
                if(arr[x-1] > arr[x]){
                    int temp = arr[x-1];
                    arr[x-1] = arr[x];
                    arr[x] = temp;     
                }
                
            }
            k_end--;
            k_start++;
        }
        System.out.println();
        for (int i : arr) {
            System.out.print(i + " ");
        }

    }
}
