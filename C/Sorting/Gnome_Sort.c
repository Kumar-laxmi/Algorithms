#include  <stdio.h>  
#include <stdlib.h>
#include <time.h>
 
void Gnome_Sort(int array[50], int size ){ 
    int i = 0;   //"i" represents position
    int temp ;
    while (i < size)  //"size" represents length of an array 
    {
        if (i == 0 || array[i] >= array[i-1]) //if the value of ith element is greater than i-1th element ... 
            i++;                             //...  increment the pointer
        else
        {
            temp = array[i-1];  //else swap the ith element with previous element
            array[i - 1] = array[i];
            array[i] = temp;
            i = i - 1;
        }
    }
}
 
int main() {
	int array[50] , size , i , st , et , tt;
	printf("Enter the number of elements:\n");
	scanf("%d", &size);
    printf("Enter the elements:\n");
    for (i = 0; i < size; i++) {
    scanf("%d", &array[i]);
    }
    st = clock();
	Gnome_Sort(array, size);
	et = clock();
	tt = et - st ; 
	double total_t = (double)(et - st)/CLOCKS_PER_SEC ;
    printf("\nThe sorted array elements are\n");
    for ( i = 0; i < size; ++i) {
	    printf("%d ", array[i]);   
    }
    printf("\nStart time: %d \nEnd Time: %d " , st , et );
    printf("\nNumber of clock ticks elapsed: %d\n" , tt) ;
    printf("\nTotal time taken(in seconds): %f\n ",total_t);
	return 0;
}
