#include <stdio.h>

/*
<----------------------------------PROBLEM------------------------------------>
Given an array arr[] of n elements, write a function to search a given element el in arr[].

Variables used:
n = total number of elements in array
arr = array initialized with the input size
el = element to be searched in the array. 
*/

int main()
{
    int n=0;
    printf("Enter total no. of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    int el;
    scanf("%d", &el);

    // Flag variable to keep a check if the element is found till then.
    int flag=0;
    for(int i=0; i<n; i++){
        if(arr[i]==el){
            flag=1;
        }
    }
    if(flag){
        printf("Element found:)\n");
    }
    else{
        printf("Element not found:(\n");
    }
    return 0;
}
