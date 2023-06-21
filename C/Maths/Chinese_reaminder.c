
/*-----------------------------------------------------Introduction------------------------------------------------------------------------*/
    /*The Chinese Remainder Theorem is used to solve modular arithmetic problems efficiently.Modular arithmetic involves performing 
    arithmetic operations on remainders. For example, if we divide 13 by 5, the remainder is 3. In modular arithmetic notation, we 
    would write this as 13 ≡ 3 (mod 5), which means that 13 is congruent to 3 modulo 5.*/
/*-----------------------------------------------------Algorithm----------------------------------------------------------------------------*/
      /*start with 1 and one by one increment it and check if dividing it with given elements in
     num[] produces corresponding remainders in rem[]. Once we find such an x, we return it. */

#include <stdio.h>



//Function to find the smallest no that will produce respective remainder.
long long findMinX(int num[], int rem[], int k)
{
    long long x = 1; // Initialize result

    // As per the Chinese remainder theorem, this loop will always break.
    while (1)
    {
        // Check if remainder of x % num[j] is rem[j] or not (for all j from 0 to k-1)
        int j = 0;
        while (j < k)
        {
            if (x % num[j] != rem[j])
                break;
            j++;
        }

        // If all remainders matched, we found x
        if (j == k)
            return x;

        // Else try next number
        x++;
    }
}

int main()
{
    int num[100];
    int rem[100];
    int k;

    printf("Enter the number of elements: ");
    scanf("%d", &k);

    printf("Enter elements of num array: ");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &num[i]);
    }

    printf("Enter elements of rem array: ");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &rem[i]);
    }

    printf("x is %lld\n", findMinX(num, rem, k));

    return 0;
}
