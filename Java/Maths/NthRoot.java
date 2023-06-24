import java.util.*;
import java.util.Scanner;

class NthRoot {

    // multiplying a given number 'm' , 'n' times
    float product(float m, int n) {
        float p = 1;
        for (int i = 1; i <= n; i++)
            p = p * m;
        return p;
    }

    // returns the nth root using binary search
    float Nthroot(int n, int x) {
        float low = 1;
        float high = x;
        // loop runs until the difference between high and low reduces to 5 decimal
        // places
        while (high - low > 0.000001) {
            float mid = (high + low) / 2;
            // If on multiplying middle value n times we get a value
            // which is greater than x then that implies the answer lies
            // before the middle value (hence high=mid)
            if (product(mid, n) > x)
                high = mid;
            else
                low = mid;
        }
        return high;
    }

    public static void main(String[] args) {
        NthRoot obj = new NthRoot();
        Scanner sc = new Scanner(System.in);
        int n, x;
        System.out.println("Enter the value of n and the number whose nth root has to be calculated:");
        n = sc.nextInt();
        x = sc.nextInt();
        System.out.print(n + "th root of " + x + " is : ");
        // Formats the number result upto 5 decimal places
        System.out.format("%.5f", obj.Nthroot(n, x));
        sc.close();
    }
}