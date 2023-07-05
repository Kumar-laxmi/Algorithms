#include <stdio.h>
#include <stdlib.h>
 
#define SWAP(x, y) { int temp = x; x = y; y = temp; }
#define N (sizeof(nums)/sizeof(nums[0]))
 
int partition(int a[], int left, int right, int pIndex)
{
    
    int pivot = a[pIndex];
    SWAP(a[pIndex], a[right]);
    pIndex = left;
    for (int i = left; i < right; i++)
    {
        if (a[i] <= pivot)
        {
            SWAP(a[i], a[pIndex]);
            pIndex++;
        }
    }
 

    SWAP(a[pIndex], a[right]);
    return pIndex;
}
 
int quickselect(int nums[], int left, int right, int k)
{
    if (left == right) {
        return nums[left];
    }
 
    int pIndex = left + rand() % (right - left + 1);
 
    pIndex = partition(nums, left, right, pIndex);
    if (k == pIndex) {
        return nums[k];
    }
    else if (k < pIndex) {
        return quickselect(nums, left, pIndex - 1, k);
    }
 
    else {
        return quickselect(nums, pIndex + 1, right, k);
    }
}
 
int main()
{
    int nums[] = { 7, 4, 6, 3, 9, 1 };
    int k = 2;
    printf("k'th smallest element is %d\n", quickselect(nums, 0, N - 1, k - 1));
    return 0;
}