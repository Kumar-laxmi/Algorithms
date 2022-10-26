public class insertion_sort
{
    public static void sort(int a[],int n) {
         for (int j = 1; j < n; j++) {  
            int k = a[j];  
            int i = j-1;  
            while ( (i > -1) && ( a [i] > k ) ) {  
                a [i+1] = a [i];  
                i--;  
            }  
            a[i+1] = k;  
        }  
        for(int i:a){    
            System.out.print(i+" ");    
        }    
        System.out.println(); 
    }

	public static void main(String[] args) {
		int[] arr = {45, 3, 2, 89,77};
         int n = arr.length;
         sort(arr, n);  
	}
}