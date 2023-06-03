#include <bits/stdc++.h>
using namespace std;

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