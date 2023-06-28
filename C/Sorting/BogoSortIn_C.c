#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void RandomShuffle(int *arr, int sizeOfArray) {
  int i, j;
  for (i = 0; i < sizeOfArray; i++) {
    j = rand() % sizeOfArray;
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
  }
}

int is_sorted(int *arr, int sizeOfArray) {
  int i;
  for (i = 1; i < sizeOfArray; i++) {
    if (arr[i] < arr[i - 1]) {
      return 0;
    }
  }
  return 1;
}

void bogosort(int *arr, int sizeOfArray) {
  while (!is_sorted(arr, sizeOfArray)) {
    RandomShuffle(arr, sizeOfArray);
  }
}

int main() {
  int arr[SIZE];
  int i;

  for (i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100;
  }

  printf("The unsorted arr is:\t");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bogosort(arr, SIZE);

  printf("The sorted arr is:\t");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
