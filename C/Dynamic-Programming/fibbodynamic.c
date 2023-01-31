#include <stdio.h>
#include <conio.h> 
int main()
{
  int n, first = 0, second = 1, result, i;
  printf("Please give an input upto you want to print series : ");
  scanf("%d", &n);
  printf("Fibonacci Series is: ");
  for (i = 0; i < n; i++)
  {
    if (i <= 1)
      result = i;
    else
    {
      result = first + second;
      first = second;
      second = result;
    }
    printf("%d\t", result);
  } 
  return 0;
} 