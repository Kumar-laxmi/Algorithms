# Sorting
Sorting is the process of arranging elements in a specific order, usually in ascending or descending order. It is an essential operation in computer science and is used to organize data for efficient searching, analysis, and manipulation.
You will learn about various sorting algorithms in this repository. Here is an overview of the most popular sorting
techniques, their advnatages and disadvantages and comparison of their time & space complexity. 

1. Bubble Sort: It repeatedly compares adjacent elements and swaps them if they are in the wrong order, iterating through the list until no more swaps are needed.
- Advantage: Simple implementation and easy to understand.
- Limitation: Inefficient for large datasets and has a worst-case and average-case time complexity of O(n^2).

2. Selection Sort: It divides the array into a sorted and an unsorted region, repeatedly finding the minimum element from the unsorted region and swapping it with the first element of the unsorted region.
- Advantage: Simple implementation and requires fewer swaps compared to other sorting algorithms.
- Limitation: Inefficient for large datasets and has a worst-case and average-case time complexity of O(n^2).

3. Insertion Sort: It builds the final sorted array one element at a time by inserting each element into its correct position within the already sorted part of the array.
- Advantage: Efficient for small datasets and performs well when the input array is partially sorted or nearly sorted.
- Limitation: Inefficient for large datasets and has a worst-case and average-case time complexity of O(n^2).

4. Merge Sort: It divides the array into two halves, recursively sorts each half, and then merges the sorted halves to obtain the final sorted array.
- Advantage: Provides a stable sorting solution with a worst-case time complexity of O(n log n).
- Limitation: Requires additional space for the temporary arrays during the merging phase.

5. Quick Sort: It selects a pivot element, partitions the array into two sub-arrays such that elements smaller than the pivot are placed before it, and elements larger than the pivot are placed after it. It then recursively sorts the sub-arrays.
- Advantage: Efficient in practice, particularly for large datasets, and has a worst-case time complexity of O(n log n) on average.
- Limitation: Not a stable sorting algorithm and can have a worst-case time complexity of O(n^2) in rare cases.

6. Tim Sort: It is a hybrid sorting algorithm derived from merge sort and insertion sort. It divides the array into small chunks, sorts them using insertion sort, and then merges them using merge sort.
- Advantage: Combines the advantages of merge sort and insertion sort, making it suitable for both small and large datasets.
- Limitation: Requires additional space for the temporary arrays during the merging phase

7. Heap Sort: It builds a max heap from the array and repeatedly extracts the maximum element from the heap, placing it at the end of the sorted array.
- Advantage: Provides an in-place sorting solution with a worst-case time complexity of O(n log n).
- Limitation: Not a stable sorting algorithm.

8. Tree Sort: It builds a binary search tree from the elements of the array and performs an in-order traversal of the tree to obtain the sorted sequence.
- Advantage: Provides a stable sorting solution with efficient average-case time complexity of O(n log n).
- Limitation: Requires additional space for the binary search tree structure.

9. Shell Sort: It is an extension of insertion sort that divides the array into multiple smaller sub-arrays and sorts them independently using insertion sort, gradually reducing the gap between elements to be compared.
- Advantage: Provides a faster variation of insertion sort and performs well on average.
- Limitation: Not as efficient as other advanced sorting algorithms for large datasets.

10. Bucket Sort: It divides the range of input elements into a set of buckets, distributes the elements into the buckets based on their values, sorts each bucket individually, and then combines the sorted buckets to obtain the final sorted array.
- Advantage: Efficient for uniformly distributed data and can achieve linear time complexity for certain scenarios.
- Limitation: Requires extra space for maintaining buckets and may not be suitable for datasets with non-uniform distributions.

11. Radix Sort: It sorts the elements by processing individual digits or groups of digits from least significant to most significant. It can be performed using either the LSD (Least Significant Digit) or MSD (Most Significant Digit) approach.
- Advantage: Efficient for sorting integers with fixed-length keys and provides linear time complexity.
- Limitation: Requires additional space for the buckets and can be complex to implement for variable-length keys.

12. Counting Sort: It counts the number of occurrences of each distinct element in the array, calculates the cumulative sums of the counts, and then uses these sums to place the elements in their correct positions.
- Advantage: Efficient for sorting integers with a small range of values and provides linear time complexity.
- Limitation: Requires additional space for the count array and is not suitable for sorting arbitrary data types.

13. Cubesort: It partitions the array into a three-dimensional cube, repeatedly performs sorting operations along different dimensions of the cube, and finally flattens the cube to obtain the sorted array.
- Advantage: Can be efficient for certain types of multidimensional data and provides a stable sorting solution.
- Limitation: Requires additional space for the three-dimensional cube structure and may have higher complexity compared to other sorting algorithms.

### Comparison of Time Complexities and Space Complexities

![image](https://github.com/harshita-kaushik2/Algorithms/assets/112249538/03fa244a-b660-4c5e-b5d2-dee097618fcd)


