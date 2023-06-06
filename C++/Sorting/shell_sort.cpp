#include<iostream>

using namespace std;

int shellSort(int array[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Perform an insertion sort within the current gap size.
        // The first "gap" elements, a[0..gap-1], are already sorted with a gap between them.
        // Extend the sorted sequence by adding one more element at a time until the entire array is sorted 
        //with the current gap. 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = array[i];

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];

            //  put temp (the original a[i]) in its correct location
            array[j] = temp;
        }
    }
    return 0;
}

void displayArray(int array[], int n)
{
    for (int i=0; i<n; i++)
        cout << array[i] << " ";
}

int main(){
    int array[] = {9,8,1,7,4,3};
    int n = sizeof(array)/sizeof(array[0]);

    cout << "Array before sorting: \n";
    displayArray(array, n);

    shellSort(array, n);

    cout << "\nArray after sorting: \n";
    displayArray(array, n);
    return 0;
}