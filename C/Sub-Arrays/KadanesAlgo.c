// Program to implement Kadanes Algorithm in C
/* 
    Kadanes Algorithm is Basically used to find the maximum sum which can be associated in a subarray.

    Approach : It simply starts with traversing your array.
               Whenever your subarray sum is postive it goes on adding the next element to your array.
               Whenever your subarray sum is negative it simply discards that subarray checks with the next subarray.
               It always keeps note of the maximum sum of the subarray.

               
    Time Complexity : O(N)
    Space Complexity : O(1)
*/
#include<stdio.h>
#include<stdlib.h>
int kadanes_maxsum_negative(int [],int);
int kadanes_maxsum_positive(int [],int);
void main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements : ");
    int negative = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i] < 0)
            negative++;
    }
    int ans = 0;
    if(negative == n)
    {
        // It simply represents that there exist negative elements in the array.
        ans = kadanes_maxsum_negative(arr,n);
    }
    else
    {
        ans = kadanes_maxsum_positive(arr,n);
    }
    printf("Maximum Sum of the Subarray is : %d\n",ans);
}
int kadanes_maxsum_positive(int arr[],int n)
{
    int sum = 0,maxsum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)
            sum = 0;
        if(sum > maxsum)
            maxsum = sum;
    }
    return maxsum;
}
int kadanes_maxsum_negative(int arr[],int n)
{
    /*
        When there is only negative numbers present in my array then it is easy to find maximum sum of the subarray.
        then maximum element of my subarray becomes the maximum sum of the subarray.
    */ 
   int ans = -32767;
   for(int i=0;i<n;i++)
   {
        if(arr[i]>ans)
            ans = arr[i];
   }
   return ans;
}