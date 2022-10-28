#include <stdio.h>

/*
<----------------------------------PROBLEM------------------------------------>
Given a sorted array arr[] of n elements, write a function to search a given 
element x in arr[] and return the index of x in the array.

Variables used:
n = total number of elements in array.
arr = array initialized with the input size.
el = element to be searched in the array.
lt = left-most index of the search space.
rt = right-most index of the search space. 
*/

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int el;
    scanf("%d", &el);

    int lt=0, rt=n-1;
    while(lt<=rt){
        // in order to prevent overflow of `int`, it has been written lt + (rt-lt)/2 instead of (lt+rt)/2;
        int mid = lt + (rt-lt)/2;
        // element is equal to mid, return the index
        if(arr[mid]==el){
            printf("Element found:)\n");
            return 0;
        }
        // element is larger than mid, then shift search space to right.
        else if(arr[mid]<el){
            lt=mid+1;
        }
        // element is smaller than mid, then shift search space to left.
        else{
            rt=mid-1;
        }
    }
    printf("Element not found:(\n");
    return 0;
}
