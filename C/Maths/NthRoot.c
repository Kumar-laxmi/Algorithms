#include <stdio.h>

// multiplying a given number 'm' , 'n' times
double product(double m, int n)
{
    double p = 1.0;
    for (int i = 1; i <= n; i++)
        p = p * m;
    return p;
}

// returns the nth root using binary search
double NthRoot(int n, int x)
{
    double low = 1;
    double high = x;
    // loop runs until the difference between high and low reduces to 5 decimal
    // places
    while (high - low > 0.000001)
    {
        double mid = (high + low) / 2;
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
int main()
{
    int n, x;
    printf("Enter the value of n and the number whose nth root has to be calculated:\n");
    scanf("%d%d", &n, &x);
    double r = NthRoot(n, x);
    printf("%d th root of %d is : %.5lf\n", n, x, r);
    return 0;
}