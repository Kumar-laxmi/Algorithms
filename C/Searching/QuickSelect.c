// C program to implement QuickSelect

#include <stdio.h>

//Swapping varible function
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* Partition function i.e all smaller element will be placed to left of the pivot element and the greater elements to right of pivot
 */
int partition (int arr[], const int left, const int right)
{
    int pivot = arr[right]; 
    int i = (left - 1);
    int j = left;
    for (j = left; j <= (right - 1); j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}
// Function returns the k'th smallest element in the array
int quickselect(int arr[], const int left, const int right, const int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= (right - left + 1))
    {
        // Partition the array around last element and get the position of pivot element in  the sorted array
        int index = partition(arr, left, right);
        // If position is same as k
        if (index - left == k - 1)
            return arr[index];
        // If position is more, recur for left subarray
        if (index - left > k - 1)
            return quickselect(arr, left, index - 1, k);
        // Else recur for right subarray
        return quickselect(arr, index + 1, right,
                           k - index + left - 1);
    }
    //If k is more than the number of elements of the array
    else 
    printf(" Index is out of bound.");
    abort();

}

//Driver code
int main()
{
    //taking the input array and the value of k from the user.
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]); 
        
    }
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    const  int arr_size = sizeof(arr) / sizeof(arr[0]);
    const int k= printf("\nEnter the value of k: ");
    scanf("%d", &k);
    const int smallestElement = quickselect(arr, 0, arr_size - 1, k);
    printf("k'th smallest element is %d\n",smallestElement);
    return 0;
}
