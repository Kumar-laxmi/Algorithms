//Problem statement :- Calculate Interquartile range from given number series 

#include<stdio.h>
#include<stdlib.h>

int comp(const void* start , const void* last)
{
    return (*(int*)start - *(int*)last);
}
int main()
{
    int n;
    printf("Enter the size\n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the array element\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),comp);   // Here we sort our array

    int start = 0  , last = n-1;  // we assign 0 and n-1 as the index value for start and last index

    int Quartile1 , Quartile2 , Quartile3;

     int mid = (last - start)/2;   // Here we calculate median of our series

    printf("Median of series as Quartile2 %d : \n", arr[mid]);

    Quartile1 =arr[(mid-0)/2];  //Here we calculate first half Quartile

    printf("The Median of first half as Quartile1 %d: \n",Quartile1);

    Quartile3 = arr[mid+1+(last-mid)/2];   //Here we calculate second half Quartile

    printf("The Median of Second half as Quartile3 %d:\n ",Quartile3);

    printf("The IQR value is %d\n",Quartile3 - Quartile1);
}

// Case 1: INPUt :- 1  3  5  2  4  6

//        OUTPUT:- Median of series as Quartile2 : 3
//                 The Median of first half as Quartile1 : 2
//                 The Median of second half as Quartile2 : 5
//                 The IQR value is : 3