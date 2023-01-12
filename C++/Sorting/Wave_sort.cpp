/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
#include<iostream>
using namespace std;
void swap(int arr[], int a, int b)   // A utility method to swap two numbers.

{     
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void waveSort(int arr[], int n)
{
    for (int i = 1; i < n; i+=2)   // Traverse all even elements

    {  
        if(arr[i]>arr[i-1]) swap(arr, i, i-1);            // If current even element is smaller than previous
        if(arr[i]>arr[i+1] && i<=n-2) swap(arr, i, i+1);  // If current even element is smaller than next
    }
}
int main()                                               // Driver program to test above function

{
    int arr[5] = {5, 4, 3, 2, 1};   
    waveSort(arr, 5);               
    for (int i = 0; i < 5; i++) {
        cout<<arr[i]<<" ";
    } 
    cout<<endl; 
    return 0;
}