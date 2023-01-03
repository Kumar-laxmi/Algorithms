#include<stdio.h>
#include<limits.h>

int main(){
    int size,i,k;
    int a[10],b[10],c[10];
    k=INT_MIN;
    printf("Enter size of array : ");
    scanf("%d",&size);
    printf("Enter elements of array : ");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
        if(a[i]>k)
        k=a[i];
    }
    for(i=0;i<=k;i++){
        c[i]=0;
    }
    for(i=0;i<size;i++){
        ++c[a[i]];
    }
    for(i=1;i<=k;i++){
        c[i]+=c[i-1];
    }
    for(i=0;i<size;i++){
        b[c[a[i]] - 1]=a[i];
        --c[a[i]];
    }
    printf("Sorted Array : ");
    for(i=0;i<size;i++){
        printf("%d ",b[i]);
    }


}