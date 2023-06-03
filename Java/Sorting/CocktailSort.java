/*
  This JAVA code can sort any array.
  Characteristics: Cocktail Sort is an improvement over Bubble Sort by allowing bidirectional passes and early termination when the array is already sorted or no swaps are made.
  -author~ Akhil Agrawal
  Github :- @swastik-akhil

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
