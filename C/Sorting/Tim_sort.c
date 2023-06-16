#include <stdio.h>

void insertsort(int start, int end, int arr[])
{
    for (int i = start + 1; i <= end; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (temp < arr[j] && j >= start)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
// Merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{
 
    // Original array is broken in two
    // parts left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of
    // left, if any
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of
    // right, if any
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

int main()
{
    // input code
    int n;
    printf("TIM SORT\nEnter array size : ");
    scanf("%d", &n);
    int ar[n];
    printf("\nEnter array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    // function call
    // insertsort(2,89,ar);
    //  display sorted array
    int runsize = 4;
    for (int start = 0; start < n; start = start + runsize)
    {
        int end;
        if (start + runsize - 1 < n - 1)
        {
            end = start + runsize - 1;
        }
        else
        {
            end = n - 1;
        }
      insertsort(start,end,ar);
    }for(int rs=runsize;rs<n;rs*=2){
    for(int left=0;left<n;left+=2*rs){
        int mid= left+rs-1;
        int right;
        if(left+2*rs-1<n-1){
            right=left+2*rs-1;
        }
        else{
            right=n-1;
        }if(mid<right){
            merge(ar,left,mid,right);
        }



    }
    }
    printf("\nSORTED ARRAY : ");
        for (int i = 0; i < n; i++)
            printf("%d ", ar[i]);

        return 0;
}