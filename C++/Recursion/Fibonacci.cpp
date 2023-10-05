#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;
int fib(int n) {
  // Base case: Returns 1 as the first two dogits of the series
  if (n < 2) {
    return 1;
  }

  // Check if value is already calculated
  if (memo.at(n) != -1)
    return memo.at(n);
  else {
    memo.at(n) = fib(n - 1) + fib(n - 2);
    return memo.at(n);
  }
}

int main() {
  int n;
  cin >> n;
  memo.resize(n + 1, -1);
  cout << fib(n);
  return 0;
}
