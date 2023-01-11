/*Sieve of Eratosthenes
  In this method first we create an array of n number and then we start traversing it and the numbers 
  which encounters its multiple is marked and the left out numbers are prime numbers*/

#include<stdio.h>

int main(){
    int n;
    printf("Enter the number till where prime is required: ");
    scanf("%d",&n);

    int arr[10000]={0};
    for(int i=2;i<=n;i++){
        if(arr[i]==0){         //Markiong the numbers
            for(int j=i*i;j<=n;j+=i){
                arr[j]=1;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            printf("%d\n",i);
        }
    }
    return 0;
}