#include<iostream>
using namespace std;
void fib(int n) {
   int f[n];
   int i;
   f[0] = 0;
   f[1] = 1;
   for (i = 2; i < n; i++) {
      f[i] = f[i-1] + f[i-2];
   }
   for (i = 0; i < n; i++) {
      cout<<f[i]<<" ";
   }
}
int main () {
   int n = 10;
   fib(n);
   return 0;
}