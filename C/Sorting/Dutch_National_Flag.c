/*Description:
An array of 0s, 1s, and 2s is sorted using the Dutch National Flag algorithm in linear time and constant area complexity.
In order to split the array into the three components 0s, 1s, and 2s, the algorithm keeps track of three pointers: low, mid, and high.
The low and mid pointers initially refer to the array's first element, while the high pointer initially points to the array's final element.
This is how the program operates:

1. Do the following when mid is lower than or equivalent to high:
    a. Increment the low and mid pointers if the element at a[mid] is 0, then exchange it with the element at a[low].
    b. Shift the mid marker to the subsequent element if the element at a[mid] is 1.
    c. Decrement the high pointer and replace the element at a[mid] with the element at a[high] if the element at a[mid] is 2.

This allows the algorithm to sort the array in a single pass after splitting it into three sections.*/


#include <stdio.h>

// Function to sort an array of 0s, 1s, and 2s using Dutch National Flag algorithm
void sort012(int a[], int n) {
   int low = 0, mid = 0, high = n-1;
   while (mid <= high) { // Loop until mid becomes greater than high
      switch (a[mid]) {
         case 0: // If the element is 0, swap it with the element at the low end of the array
            a[mid] = a[low];
            a[low] = 0;
            low++; // Increment low and mid pointers
            mid++;
            break;
         case 1: // If the element is 1, move mid pointer to the next element
            mid++;
            break;
         case 2: // If the element is 2, swap it with the element at the high end of the array
            a[mid] = a[high];
            a[high] = 2;
            high--; // Decrement high pointer
            break;
      }
   }
}

int main() {
   int n, i;
   printf("Enter the size of the array: ");
   scanf("%d", &n);
   int a[n];
   printf("Enter the elements of the array (0s, 1s, and 2s only):\n");
   for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }
   sort012(a, n); // Call the function to sort the array
   printf("The sorted array is:\n");
   for (i = 0; i < n; i++) {
      printf("%d ", a[i]);
   }
   return 0;
}
