#include<stdio.h>

void dnfSort(int arr[],int n){
    int t1,t2;
    int s = 0;
    int mid = 0;
    int e = n-1;
    while(mid<=e){
        // shifting all the zeros to the front
        if(arr[mid] == 0){  
            t1=arr[mid];
            arr[mid]=arr[s];
            arr[s]=t1;
            s++;
            mid++;
        }
        
        // when the array encounters 1, the position dosen't change
        else if(arr[mid] == 1){ 
            mid++;
        }
        
        // shifting all 2s to the end
        else if(arr[mid] == 2){
            t2=arr[mid];
            arr[mid]=arr[e];
            arr[e]=t2;
            e--;
        }
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[1000];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&arr[i]);
    }
    dnfSort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d",arr[i]);
        printf(" ");
    }
    return 0;
}
