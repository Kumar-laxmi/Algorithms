import java.util.Arrays;
import java.util.Scanner;

class Dutch_National_Flag {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of an array: ");
        int n = sc.nextInt();
        int [] arr = new int[n];
        
        // Storing an array from user
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        DNF(arr);

        // Printing an answer
        System.out.println("Answer : "+ Arrays.toString(arr));
    }

    public static void DNF(int[] arr) {
        // It will first count number of 0,1 and 2.
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0)
                zero++;
            if (arr[i] == 1)
                one++;
            if (arr[i] == 2)
                two++;
        }

        // Now set accordingly number of zero's first then 1 and 2.
        for(int i=0;i<zero;i++){
            arr[i] = 0;
        }
        for(int i=zero;i<zero+one;i++){
            arr[i] = 1;
        }
        for(int i=zero+one;i<arr.length;i++){
            arr[i] = 2;
        }
    }
}