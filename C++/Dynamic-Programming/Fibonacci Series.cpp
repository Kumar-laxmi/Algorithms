/*The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

Fn = Fn-1 + Fn-2
with seed values 

F0 = 0 and F1 = 1.

Given a number n, print n-th Fibonacci Number. 

Examples: 

Input  : n = 2
Output : 1

Input  : n = 9
Output : 34

Method:- Dynamic Programming

Time complexity: O(n) for given n
Auxiliary space: O(n)

Code is as follows:- */

// C++ program for Fibonacci Series
// using Dynamic Programming
#include<bits/stdc++.h>
using namespace std;

class GFG{
	
public:
int fib(int n)
{
	
	// Declare an array to store
	// Fibonacci numbers.
	// 1 extra to handle
	// case, n = 0
	int f[n + 2];
	int i;

	// 0th and 1st number of the
	// series are 0 and 1
	f[0] = 0;
	f[1] = 1;

	for(i = 2; i <= n; i++)
	{
		
	//Add the previous 2 numbers
	// in the series and store it
	f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
	}
};

// Driver code
int main ()
{
	GFG g;
	int n = 9;
	
	cout << g.fib(n);
	return 0;
}

/*
Output - 34
*/

