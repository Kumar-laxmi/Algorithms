
#include <bits/stdc++.h>
using namespace std;
 
// Utility function to find minimum of two elements
int min(int x, int y) { return (x <= y) ? x : y; }
  
/* Returns index of x if present,  else returns -1 */
int fibMonaccianSearch(int array[], int x, int n)
{
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci
  
    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
  
    // Marks the eliminated range from front
    int offset = -1;
  
    /* while there are elements to be inspected. Note that
       we compare array[fibMm2] with x. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1) {
        // Check if fibMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);
  
        /* If x is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (array[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
  
        /* If x is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (array[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
  
        /* element found. return index */
        else
            return i;
    }
  
    /* comparing the last element with x */
    if (fibMMm1 && array[offset + 1] == x)
        return offset + 1;
  
    /*element not found. return -1 */
    return -1;
}
 
// Driver Code
int main()
{
    int array[]
        = { 8,5,7,3,88,61,99,2,675,23,34,97};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 22;
      int ind = fibMonaccianSearch(array, x, n);
  if(ind>=0)
    cout << "Found at index: " << ind;
  else
    cout << x << " isn't present in the array";
 
    return 0;
}