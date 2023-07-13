//Program for sentinel linear Search
import java.util.*;
import java.lang.*;
import java.io.*;
class SentinelLinearSearch {
	//function to search x in the given array
	static void sentinelSearch(int arr[], int n, int key)
	{
        // Last element of the array
		int last = arr[n - 1];
		// Element to be search and placed at the last index
		arr[n - 1] = key;
		int i = 0;
		while (arr[i] != key)
    			i++;
		// Putting the last element back
		arr[n - 1] = last;
		if ((i < n - 1) || (arr[n - 1] == key))
		{
      	System.out.println(key + " present at the index "+ i);
    }
    else
			{
        System.out.println("Element Not found");	
     }
  }
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
    //arr size
    System.out.println("enter the element size");
    int n = sc.nextInt();
    //arr declares 
    int arr[] = new int[n];
  //arr input values are taken
  System.out.println("enter the element");
    for(int i=0;i<n;i++)
    {
      arr[i]=sc.nextInt();
    }
    //key value is taken
    System.out.println("enter the key value");
    int key = sc.nextInt();    
		sentinelSearch(arr, n, key);
	}
}


