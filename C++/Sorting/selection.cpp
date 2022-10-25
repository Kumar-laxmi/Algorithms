#include<iostream>
using namespace std;

//Display function 
void display(int array[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++)
        cout << array[i] << "\t";
        
    cout << "\n"; 
} 

//Driver code
int main() 
{ 
    //Taking size of array as input
    int n;
    cout << "ENTER THE SIZE OF ARRAY: : ";
    cin >> n;

    //Taking elements of array as input
    int array[n];
    cout << "ENTER THE ELEMENTS: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    //Printing unsorted array
    cout << "UNSORTED ARRAY: " << endl;
    display(array, n);

    int i, j, smallest,temp;
    
    //Selection sort 
    for (i = 0; i < n-1; i++)  
    {  
        
        smallest= i;  
        for (j = i+1; j < n; j++){
            if (array[j] < array[smallest])  
                smallest = j;  
        }        
                    
        temp = array[smallest];
        array[smallest] = array[i]; 
        array[i] = temp;
    }

    //Printing sorted array   
    cout << "SORTED ARRAY: \n"; 
    display(array, n); 
    
    return 0;
}