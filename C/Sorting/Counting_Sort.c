/* Counting sort is a sorting algorithm that sorts the elements of an array
by counting the number of occurrences of each unique element in the array.
Best case : O(n)
Average case : O(n + k)
Worst case : O(k)

Where n is the number of elements and k is the range of elements

Working of counting sort
The function Counting_sort mainly takes 'array' of 'size' for the input . 
The first goal is to find the maximum value in the array given by the user
and store in the 'Max' varaible .  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Counting_Sort(int array[], int size) {
  int Max = 0 ; 
  int i , j; 
  for ( i = 0; i < size; i++) {
    if (array[i] > Max) {
      Max = array[i];
    }
  } 
 
  int count[Max + 1];  //To store the count of each integer in the input array.

//Here it counts the frequency of each integer in the given array , so that later it can sort
  for (i = 0; i <= Max; i++) {
    count[i] = 0;
  }
  
  for (i = 0; i < size; i++) {
    count[array[i]] = count[array[i]] + 1;
  }
  
  int k = 0 ;    //The sorted elemtnes are added to the input array with 'k' as index of position of input array
  for (i = 0; i <= Max; i++) {
    for ( j = 0; j < count[i]; j++) {  //'i' element is inserted to array including its frequency
      array[k] = i; 
      k++;  
    }
  }
}
 

int main() {
  int size , st , et , tt ;
  double total_t ; 
  printf("Enter the number of elements : ");
  scanf("%d", &size);
  
  int array[size];
  printf("Enter the elements to be sorted :");
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
  st = clock();
  Counting_Sort(array,size);
  et = clock();
  tt = et - st ;
  total_t = (double)(et - st)/CLOCKS_PER_SEC ;
  
  
  printf("The sorted array elements are: ");
  for(int i = 0; i < size; i++) {
		printf("%d ", array[i]);
  }
  
  printf("\n\nStart time: %d\n",st);
  printf("End time: %d\n",et);
  printf("Number of clock ticks elapsed: %d\n",tt);
  printf("Total time taken(in seconds): %f\n ",total_t);
  return 0 ;

}
