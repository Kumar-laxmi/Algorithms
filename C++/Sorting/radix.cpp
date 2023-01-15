#include <iostream>
using namespace std; 
  
// Function which gives maximum value in array.
int getMaximum(int arr[], int n) 
{ 
    int my = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > my) 
            my = arr[i]; 
    return my; 
} 
void countSor(int arr[], int n, int exp) 
{ 
    int out[n]; 
    int i, count[10] = { 0 }; 
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    
    for (i = n - 1; i >= 0; i--) { 
        out[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = out[i]; 
} 
  
 
// Radix code
void radix(int arr1[], int n) 
{     
    int a = getMaximum(arr1, n); 
    for (int exp = 1; a / exp > 0; exp *= 10) 
        countSor(arr1, n, exp); 
} 
  
// Printing the elements.
void print(int arr[], int m) 
{ 
    for (int i = 0; i < m; i++) 
        cout << arr[i] << " "; 
} 
  
// Main code. 
int main() 
{ 
    int arry[] = { 43,78,62,89,21,39,87 }; 
    int total = sizeof(arry) / sizeof(arry[0]); 
      
    //Radix function calling 
    radix(arry, total); 
    print(arry, total); 
    return 0; 
}