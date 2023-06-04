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
#include <bits/stdc++.h>
using namespace std;

//function to find the factorial.
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
 
  cout<<"Enter the number of rows you wish to see in pascal triangle:\n";
  cin>>n;
 
  for (i = 0; i < n; i++)
  {
    for (c = 0; c <= (n - i - 2); c++)
      cout<<" ";
    for (c = 0 ; c <= i; c++)
      cout<< factorial(i)/(factorial(c)*factorial(i-c));

    cout<<endl;
  }
 
  return 0;
}