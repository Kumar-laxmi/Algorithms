#include <iostream>
#include <random>

using namespace std;

const int sizeOfArray = 10;

void RandomShuffle(int *arr, int sizeOfArray) {
  for (int i = 0; i < sizeOfArray; i++) {
    int j = rand() % sizeOfArray;
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
  }
}

bool is_sorted(int *arr, int sizeOfArray) {
  for (int i = 1; i < sizeOfArray; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

void bogosort(int *arr, int sizeOfArray) {
  while (!is_sorted(arr, sizeOfArray)) {
    RandomShuffle(arr, sizeOfArray);
  }
}

int main() {
  int arr[sizeOfArray];
  for (int i = 0; i < sizeOfArray; i++) {
    arr[i] = rand() % 100;
  }

  cout << "The unsorted arr is:\t";
  for (int i = 0; i < sizeOfArray; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  bogosort(arr, sizeOfArray);

  cout << "The sorted arr is:\t";
  for (int i = 0; i < sizeOfArray; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
