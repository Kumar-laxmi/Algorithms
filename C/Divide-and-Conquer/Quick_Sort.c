/*Quick Sort is a sorting algorithm which is based on  Divide and Conquer technique.
 A pivot element will be selected from the array of elements and based on the position of the pivot the array is divided into
  such a way that elements less than pivot are kept on the left side and elements that are greater than pivot are 
  kept on the right side of the pivot. The sub-arrays are then sorted recursively.
  
  Best Time Complexity : O(nlogn)
  Average Time Complexity : O(nlogn)
  Worst Time Complexity : O(n^2) */

 
#include <stdio.h>
#include <time.h>

int partition(int a[],int low,int high)
{
	
	int i,j,pivot,temp;
	pivot = low;
	i = low;
	j = high;
 
 	while(i < j)
	{
		while(a[i] <= a[pivot] && i < high) /*Look for the element that is that is bigger than the pivot
	                                          Because it should be in right side of the pivot */
			i++;
		while(a[j] > a[pivot])            /*Look for the element that is that is smaller than the pivot
	                                          Because it should be in left side of the pivot */
			j--;
		 
		if(i < j)
		{
			temp = a[i];        //Swapping
			a[i] = a[j];
			a[j] = temp;
		}
	}
			 
	temp = a[pivot];  
	a[pivot] = a[j];
	a[j] = temp;
			
	return j;
	
}

void quicksort(int a[],int low,int high) 
{
	int j;
	if(low < high)
	{
		j = partition(a,low,high); //It divides the array around the pivot and returns j which is index of pivot
		quicksort(a,low,j-1); //"The conquer part" where it recursively sorts the left subarray 
		quicksort(a,j+1,high); // Here, it recursively sorts the right subarray
	}
}

int main()
{
	int n,low,high;
	int st,et,tt;
	
    	
	   int a[] = {40,20,100,120,60,140,80,160,200,180};
	n = sizeof(a)/sizeof(a[0]);
	
	printf("The array elements are: ");
	for(int i = 0;i < n;i++)
	{
		printf("%d ",a[i]);
	}
		
	low = 0;
	high = n-1;
	
	st = clock(); //st stands for Start time 
	quicksort(a,low,high);
	et = clock(); // et stands for end time
	tt = et - st; // tt stands for total time (Time taken by the function)
	
	printf("\nThe sorted array elements are: ");
	for(int i = 0;i < n;i++)
		printf("%d ",a[i]);
	
	printf("\n\nStart time: %d\n",st);
	printf("End time: %d\n",et);
	printf("Total time taken: %d\n",tt);
	return 0;
}

/*
Output
The array elements are 40 20 100 120 60 140 80 160 200 180
The sorted array elements are 20 40 60 80 100 120 140 160 180 200

Start time : 570
End time : 572
Total time : 2      
 */
