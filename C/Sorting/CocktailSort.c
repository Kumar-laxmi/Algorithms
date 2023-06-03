#include <stdio.h>
#include <stdbool.h>
void printarr(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(void) {
    int arr[] = { 5, 1, 4, 2, 8, 0, 2, 3, 9, 7 };
    int len = sizeof(arr)/sizeof(arr[0]);
    printarr(arr,len);
    int k_start = 0;
    int k_end =len-1;
    bool swapped= false;
    if(len%2==0){
        len = len/2;
    }
    else{
        len = len/2 + 1;
    }
    for(int i = 0; i < len; i++){
        for(int j =0 ; j < sizeof(arr)/sizeof(arr[0]) - i - 1 - k_start; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp; 
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
        for(int x =k_end ;x>k_start+1 ;x--){
            if(arr[x-1] > arr[x]){
                int temp = arr[x-1];
                arr[x-1] = arr[x];
                arr[x] = temp;     
            }
            
        }
        k_end--;
        k_start++;
    }
    printarr(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}