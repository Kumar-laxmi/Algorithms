// Java implementation of intro_sort algorithm

import java.util.Scanner;

public class intro_sort {
    private int a[];
    private int n;

    intro_sort(int n) {
        a = new int[n];
        this.n = 0;
    }

    private void dataAppend(int temp) {
        a[n] = temp;
        n++;
    }

    private void swap(int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private void maxHeap(int i, int heapN, int begin) {
        int temp = a[begin + i - 1];
        int child;

        while (i <= heapN / 2) {
            child = 2 * i;

            if (child < heapN
                    && a[begin + child - 1] < a[begin + child])
                child++;

            if (temp >= a[begin + child - 1])
                break;

            a[begin + i - 1] = a[begin + child - 1];
            i = child;
        }
        a[begin + i - 1] = temp;
    }

    private void heapify(int begin, int end, int heapN) {
        for (int i = (heapN) / 2; i >= 1; i--)
            maxHeap(i, heapN, begin);
    }

    // Heap Sort
    private void heapSort(int begin, int end) {
        int heapN = end - begin;
        this.heapify(begin, end, heapN);
        for (int i = heapN; i >= 1; i--) {

            // Move current root to end
            swap(begin, begin + i);
            maxHeap(1, i, begin);
        }
    }

    // Insertion Sort
    private void insertionSort(int left, int right) {

        for (int i = left; i <= right; i++) {
            int key = a[i];
            int j = i;
            while (j > left && a[j - 1] > key) {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = key;
        }
    }

    private int findPivot(int a1, int b1, int c1) {
        int max = Math.max(Math.max(a[a1], a[b1]), a[c1]);
        int min = Math.min(Math.min(a[a1], a[b1]), a[c1]);
        int median = max ^ min ^ a[a1] ^ a[b1] ^ a[c1];
        if (median == a[a1])
            return a1;
        if (median == a[b1])
            return b1;
        return c1;
    }

    private int partition(int low, int high) {

        // pivot
        int pivot = a[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (a[j] <= pivot) {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return (i + 1);
    }

    private void sortDataUtil(int begin, int end, int depthLimit) {
        if (end - begin > 16) {
            if (depthLimit == 0) {
                this.heapSort(begin, end);
                return;
            }

            depthLimit = depthLimit - 1;
            int pivot = findPivot(begin,
                    begin + ((end - begin) / 2) + 1,
                    end);
            swap(pivot, end);
            int p = partition(begin, end);
            sortDataUtil(begin, p - 1, depthLimit);
            sortDataUtil(p + 1, end, depthLimit);
        }

        else {
            // if the data set is small,
            // call insertion sort
            insertionSort(begin, end);
        }
    }

    private void sortData() {

        // Initialise the depthLimit
        int depthLimit = (int) (2 * Math.floor(Math.log(n) /
                Math.log(2)));

        this.sortDataUtil(0, n - 1, depthLimit);
    }

    private void printData() {
        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = s.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter the elements: ");
        for (int i = 0; i < n; i++)
            arr[i] = s.nextInt();

        // function call
        intro_sort is = new intro_sort(n);
        for (int i = 0; i < n; i++) {
            is.dataAppend(arr[i]);
        }
        is.sortData();
        System.out.print("Sorted array: ");
        is.printData();
    }
}