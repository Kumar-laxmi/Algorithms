#include<stdio.h>
// swap max element with 2nd array element
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int *ar, int n, int i) {
    int max = i, leftChild = 2 * i + 1, rightChild = 2 * i + 2;
    // left child greater than root
    if(leftChild < n && ar[leftChild] > ar[max]) max = leftChild;
    // right child greater than root
    if(rightChild < n && ar[rightChild] > ar[max]) max = rightChild;
    
    // swap and heapify until max ele not found
    if(max != i) {
        swap(&ar[i], &ar[max]);
        heapify(ar, n, max);
    }
}

void heapSort(int *ar, int n) {
    // max heapify
    for(int i = n / 2 - 1; i >= 0; i--) heapify(ar, n, i);
    // heap sort
    for(int i = n - 1; i >= 0; i--) {
        swap(&ar[0], &ar[i]);
        // heapify root element
        heapify(ar, i, 0);
    }
}

int main() {
    // input code
    int n;
    printf("HEAP SORT\nEnter array size : ");
    scanf("%d", &n);
    int ar[n];
    printf("\nEnter array : ");
    for(int i = 0; i < n; i++) scanf("%d", &ar[i]);

    // function call
    heapSort(ar, n);
    // display sorted array
    printf("\nSORTED ARRAY : ");
    for(int i = 0; i < n; i++) printf("%d ", ar[i]);
    return 0;
}