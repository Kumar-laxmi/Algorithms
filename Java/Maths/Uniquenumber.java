//Takes INPUT as an array with elements of duplicate type and 1 unique number 

//OUTPUT : unique number that is not repeating 

//explanation : It XOR the array 
//            : (a xor a) = 0
//            : (a xor 0) = a

//Time complexity : O(N)

public class Uniquenumber {
    public static void main(String[] args) {
        int[] arr = {2,3,3,4,2,6,4};
        System.out.println(ans(arr));
    }

    private static int ans(int[] arr) {
        int unique = 0;
        for(int n : arr){
            unique ^= n ;
        }
        return unique;
    }
    
}
