/*-----------------------------------------------------Introduction------------------------------------------------------------------------*/
    /*The Chinese Remainder Theorem is used to solve modular arithmetic problems efficiently.Modular arithmetic involves performing 
    arithmetic operations on remainders. For example, if we divide 13 by 5, the remainder is 3. In modular arithmetic notation, we 
    would write this as 13 ≡ 3 (mod 5), which means that 13 is congruent to 3 modulo 5.*/
/*-----------------------------------------------------Algorithm----------------------------------------------------------------------------*/
      /*start with 1 and one by one increment it and check if dividing it with given elements in
     num[] produces corresponding remainders in rem[]. Once we find such an x, we return it. */

public class Chinese_remainder {
  

        // Function to find  smallest no that will produce respective remainder.
        static int findMinX(int num[], int rem[], int k)
    {
        int x = 1; // Initialize result
       
       
        while (true)
        {
            // Check if remainder of x % num[j] is 
            // rem[j] or not (for all j from 0 to k-1)
            int j;
            for (j=0; j<k; j++ )
                if (x%num[j] != rem[j])
                   break;
       
            // If all remainders matched, we found x
            if (j == k)
                return x;
       
            // Else try next number
            x++;
        }
       
    }
       
    // Driver method
    public static void main(String args[])
    {
        int num[] = new int[100];
            int rem[] = new int[100];
            Scanner sc = new Scanner(System.in);
    
            System.out.println("Enter the number of elements:");
            int n = sc.nextInt();
    
            // values of num array
            System.out.println("Enter the elements of num array:");
            for (int i = 0; i < n; i++) {
                num[i] = sc.nextInt();
            }
    
            // values for rem array.
            System.out.println("Enter the elements of rem array:");
            for (int i = 0; i < n; i++) {
                rem[i] = sc.nextInt();
            }
    
            int k = n;
            System.out.println("x is " + findMinX(num, rem, k));
    }
}
    
    

