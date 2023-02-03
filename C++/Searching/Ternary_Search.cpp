/* 
   -> Ternary search is a technique for finding the minimum or maximum value of a unimodal function and it can be useful in optimization problems.
   -> It is somehow similiar to binary search but here search space is divided into 3 part
  
    * The search space is divided into three space:
        -> First part - [l,m1]
        -> Middle part - [m1,m2]
        -> Third part - [m2,r]
        
     Here l=left index, r=right index, m1=middle 1 and m2=middle 2 
     
    * Steps to perform Ternary Search: 
      1. First, we compare the key with the element at mid1. If found equal, we return mid1.
      2. If not, then we compare the key with the element at mid2. If found equal, we return mid2.
      3. If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
      4. If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
      5. If not, then we recur to the second (middle) part.
      
      For more reference visit: https://www.geeksforgeeks.org/ternary-search/
                                https://cp-algorithms.com/num_methods/ternary_search.html  
*/
#include <bits/stdc++.h>
using namespace std;

class Ternary_Search{
 public:
       int Rec_ternarySearch(int,int,int,int arr[]);
       int Iter_ternarySearch(int,int,int,int arr[]);
};

// Recursive approach
// time complexity : O(log3n)
// space complexity : O(log3n)
int Ternary_Search::Rec_ternarySearch(int l, int r, int key, int ar[])
{
	if (r >= l) {
         	// Find the mid1 and mid2
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		// Check if key is present at any mid
		if (ar[mid1] == key) {
			return mid1;
		}
		if (ar[mid2] == key) {
			return mid2;
		}
		// Since key is not present at mid, check in which region it is present
		// then repeat the Search operation in that region
		if (key < ar[mid1]) {
			// The key lies in [l,mid1]
			return Rec_ternarySearch(l, mid1 - 1, key, ar);
		}
		else if (key > ar[mid2]) {
                       // The key lies in between [mid2,r]
			return Rec_ternarySearch(mid2 + 1, r, key, ar);
		}
		else {
			// The key lies in between [mid1,mid2]
			return Rec_ternarySearch(mid1 + 1, mid2 - 1, key, ar);
		}
	}

	// Key not found
	return -1;
}

// Iterrative Approach
// time complexity : O(log3n)
// space complexity : O(1)  
int Ternary_Search::Iter_ternarySearch(int l, int r, int key, int ar[])
{
    while (r >= l) {
        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
        if (key < ar[mid1]) {
            // The key lies in between l and mid1
            r = mid1 - 1;
        }
        else if (key > ar[mid2]) {
           // The key lies in between mid2 and r
            l = mid2 + 1;
        }
        else {
            // The key lies in between mid1 and mid2
            l = mid1 + 1;
            r = mid2 - 1;}
    }
   // Key not found
    return -1;
}

// Driver code
int main()
{
  Ternary_Search ts;
	int l, r, p, key;
	// since ternary Search can only be applied in sorted array
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// Starting index and ending index
	l = 0 , r = 9;
	// Checking for 5 in the array
	key = 5;   
	// Search the key using ternarySearch - recursive approach
	p = ts.Rec_ternarySearch(l, r, key, ar);
	// Print the result
	cout << "Index of " << key<< " is " << p << endl;
	// Checking for 50 in the array
	key = 50;
	// Search the key using ternarySearch - iterative approach
	p = ts.Iter_ternarySearch(l, r, key, ar);
	// Print the result
	cout << "Index of " << key<< " is " << p << endl;		
    return 0;		
}
/*
When to use:
       * When you have a large ordered array or list and need to find the position of a specific value.
       * When you need to find the maximum or minimum value of a function.
       * When you need an alternative algorithm for binary search with an efficient time complexity.
       * When you are interested in reducing the number of comparisons.

 Note : It is efficient than linear search and in some cases better than binary seach.
*/ 
