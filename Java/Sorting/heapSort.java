import java.util.*;

public class HeapSort {
    public void heapify(int[] ar, int n, int i) {
        int max = i, leftChild = 2 * i + 1, rightChild=  2 * i + 2;
        // left child greater than root
        if(leftChild < n && ar[leftChild] > ar[max]) max = leftChild;
        // right child greater than root
        if(rightChild < n && ar[rightChild] > ar[max]) max = rightChild;

        // swap and heapify until max ele not found
        if(max != i) {
            int x = ar[i];
            ar[i] = ar[max];
            ar[max] = x;
            heapify(ar, n, max);
        }
    }

    public void heapSort(int[] ar) {
        int n = ar.length;
        // max heap
        for(int i = n / 2 - 1; i >= 0; i--) heapify(ar, n, i);
        // heap sort
        for(int i = n - 1; i > 0; i--) {
            int x = ar[0];
            ar[0] = ar[i];
            ar[i] = x;
            heapify(ar, i, 0);
        }
    }

    public static void main(String[] args) {
        // input code
        Scanner s = new Scanner(System.in);
        System.out.print("Enter Array Size : ");
        int n = s.nextInt();
        int[] ar = new int[n];
        System.out.print("\nEnter Array Elements : ");
        for(int i = 0; i < n; i++) ar[i] = s.nextInt();

        // function call
        HeapSort hs = new HeapSort();
        hs.heapSort(ar);
        // display sorted array
        System.out.print("\nSorted Array : ");
        for(int i : ar) System.out.print(i + " ");
    }
}
