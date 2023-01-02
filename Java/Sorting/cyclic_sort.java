/* 
Cylic Sort is a sorting algorithm ideally used if the question
reads "given range of numbers from 0 to N or 1 to N" 
*/

/*
Approach used : 
Check if the number is in the correct index, if not swap, and then continue iterating
*/ 
import java.util.*;
public class cyclic_sort{

    //swapping
    public static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
    
    public static void cycleSort(int[] arr){
        int i = 0;
        while(i < arr.length){
            int correctIndex = arr[i] - 1;
            /*if the question reads 1 to N, correctIndex = arr[i] - 1;
            if the question reads from 0 to N, correctIndex = arr[i]; */

            if(arr[i] != arr[correctIndex]){
                swap(arr, i, correctIndex);
            }
            else{
                i++;
            }
        }
    }
    public static void main(String[] args){
        int[] arr = {3, 5, 2, 1, 4};
        cycleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}