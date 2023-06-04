/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Each number in the triangle is the sum of the two numbers directly above it.

we take number of rows as input
And we know that to find any element at particular position (i.e at ith row and cth column) we can use the combination formula nCr.
  nCr=factorial(n)/(factorial(r)*factorial(n-r))
*/
#include <stdio.h>
 
long factorial(int n)
{
  int c;
  long result = 1;
 
  for (c = 1; c <= n; c++)
    result = result*c;
 
  return result;
}
 
int main()
{
  int i, n, c;
 
  printf("Enter the number of rows you wish to see in pascal triangle:\n");
  scanf("%d",&n);
 
  for (i = 0; i < n; i++)
  {
    for (c = 0; c <= (n - i - 2); c++)
      printf(" ");
 
    for (c = 0 ; c <= i; c++)
      printf("%ld ",factorial(i)/(factorial(c)*factorial(i-c)));
 
    printf("\n");
  }
 
  return 0;
}