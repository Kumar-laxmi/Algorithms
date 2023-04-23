#include <stdio.h>
#include <stdlib.h>
int fib(int n, int dp[])
{
    if (n == 2)
    {
        printf("%d %d ", n - 2, n - 1);
        dp[n - 2] = (n - 2);
        dp[n - 1] = (n - 1);
        return (n - 1);
    }
    if (n == 1)
    {
        printf("%d ", n - 1);
        dp[n - 1] = n - 1;
        return (n - 1);
    }
    int f1 = -1, f2 = -1;
chk:
    for (int i = 0; i < n; i++)
    {
        if (dp[i] != -1 && i == (n - 2))
        {
            f1 = dp[i];
        }
        if (dp[i] != -1 && i == (n - 3))
        {
            f2 = dp[i];
        }
    }
    if (f1 == -1)
    {
        f1 = fib(n - 1, dp);
        dp[n - 2] = f1;
        goto chk;
    }
    if (f2 == -1)
    {
        f2 = fib(n - 2, dp);
        dp[n - 3] = f2;
    }
    dp[n - 1] = (f1 + f2);
    printf("%d ", (f1 + f2));
    return (f1 + f2);
}
int main()
{
    int n;
    printf("Enter a Number : ");
    scanf("%d", &n);
    int *dp = NULL;
    dp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    fib(n, dp);

    return 0;
}