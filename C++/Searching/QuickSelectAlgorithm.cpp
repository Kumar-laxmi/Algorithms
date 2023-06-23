// CPP program to implement QuickSelect
    
    #include <bits/stdc++.h>
    using namespace std;
    
    // Partition i.e considering the last element as pivot and move all smaller element to left of it and greater elements to right
    int partition(int arr[], int l, int r)
    {
    	int x = arr[r], i = l;
    	for (int j = l; j <= r - 1; j++) {
    		if (arr[j] <= x) {
    			swap(arr[i], arr[j]);
    			i++;
    		}
    	}
    	swap(arr[i], arr[r]);
    	return i;
    }
    
    // Function which returns k'th smallest element in arr[l..r] using QuickSort
    // Assume: ALL ELEMENTS IN ARR[] ARE DISTINCT
    int kthsmallest(int arr[], int l, int r, int k)
    {
    	// If k is smaller than number of elements in array
    	if (k > 0 && k <= r - l + 1) {
    		// Partition the array around last element and get position of pivot element in sorted array
    		int index = partition(arr, l, r);
    		// If position is same as k
    		if (index - l == k - 1)
    			return arr[index];
    		// If position is more, recur for left subarray
    		if (index - l > k - 1)
    			return kthsmallest(arr, l, index - 1, k);
            // Else recur for right subarray
            return kthSmallest(arr, index + 1, r,
                                            k - index + l - 1);
    	}
    
    	// If k is more than number of elements in array
    	else cout << "index is out of bound";
    	exit(0);
    }
    
    // Driver program 
    int main()
    {
        //taking the input array and the value of k from the user
    	int n;
        cout << "Enter the number of elements (n): ";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cout << "Enter element " << i+1 << ": ";
            cin >> arr[i];
        }
    
        cout << "Array:  ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    	int m = sizeof(arr) / sizeof(arr[0]);
    	int k;
    	cout << "Enter the value of k: ";
        cin >> k;
    	cout << "k'th smallest element is "
    		<< kthsmallest(arr, 0, m - 1, k);
    	return 0;
    }
