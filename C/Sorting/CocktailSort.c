/*  Cocktail Sort
The given code is a modified version of the bubble sort algorithm to sort an integer array in ascending order. Here's a brief explanation of the code:
1. The `printarr` function is defined to print the elements of an integer array.
2. In the `main` function:
   - An integer array `arr` is initialized with some values.
   - The length of the array is calculated by dividing the total size of the array by the size of a single element.
   - The `printarr` function is called to display the initial array.
   - Variables `k_start` and `k_end` are initialized to track the starting and ending indices for the second pass of the bubble sort.
   - A boolean variable `swapped` is set to `false` to keep track of whether any swaps have been made during the sorting process.
3. The code then determines the number of iterations required for the bubble sort loop based on the length of the array. If the length is even, the number of iterations is half the length; otherwise, it is half the length plus one.
4. The first pass of the bubble sort begins with a nested loop. It compares adjacent elements and swaps them if the preceding element is greater than the succeeding element. If a swap occurs, the `swapped` variable is set to `true`.
5. After completing the first pass, the code checks if any swaps were made during the pass. If no swaps occurred, it means the array is already sorted, and the loop is terminated.
6. The second pass of the bubble sort starts, iterating in reverse from `k_end` to `k_start+1`. It compares adjacent elements and swaps them if the preceding element is greater than the succeeding element.
7. The values of `k_end` and `k_start` are adjusted to narrow down the range of elements that need to be sorted in the next iteration.
8. Steps 4 to 7 are repeated until the array is fully sorted.
9. Finally, the `printarr` function is called again to display the sorted array.
The code aims to sort the array using a modified bubble sort approach that includes a bidirectional pass to improve the efficiency of the algorithm.
*/
#include <stdio.h>
#include <stdbool.h>
void printarr(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(void) {
    int arr[] = { 5, 1, 4, 2, 8, 0, 2, 3, 9, 7 };
    int len = sizeof(arr)/sizeof(arr[0]);
    printarr(arr,len);
    int k_start = 0;
    int k_end =len-1;
    bool swapped= false;
    if(len%2==0){
        len = len/2;
    }
    else{
        len = len/2 + 1;
    }
    for(int i = 0; i < len; i++){
        for(int j =0 ; j < sizeof(arr)/sizeof(arr[0]) - i - 1 - k_start; j++){
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
    printarr(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
