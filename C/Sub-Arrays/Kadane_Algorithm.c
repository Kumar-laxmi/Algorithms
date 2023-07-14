#include <stdio.h>

// function for kadane's algorithm
int kadane(int Array[], int n) {
  int max_sum = 0;
  int current_sum = 0;

  for(int i=0; i<n; i++) {
    current_sum = current_sum + Array[i];
    if (current_sum < 0)
      current_sum = 0; 
    if(max_sum < current_sum)
      max_sum = current_sum; 
  }
  return max_sum;
}

int main() {
    int size,i;
    printf("Enter the size of the array ");
    scanf("%d",&size);
    int MyArray[size];
    printf("Enter the elements of the array ");
    for(i=0; i<size; i++){
		
		scanf("%d",&MyArray[i]);		
	}
  printf("Maximum SubArray is: %i", kadane(MyArray, size));
  return 0;
}
