/*
    Boyer Moore Voting Algorithm is a majority element problem where majority element is that element 
    which occurs in total of n/2 times in the set of elements where n is the total number of elements 
    given.
*/
#include<stdio.h>
int main(){
    int numbers,array[1000],count=0,element=0;
    printf("Enter the total numbers to be entered: ");
    scanf("%d",&numbers);
    printf("Enter the %d numbers: ",numbers);
    for(int i=0;i<numbers;i++){
        scanf("%d",&array[i]);
    }
    //Extracting majority element where if that variable is same as the value in variable element then count+1 but if not then count-1 and if count is zero then element value will be change to current number pointed by i
    for(int i=0;i<numbers;i++){
        if(count==0){
            element=array[i];
        }
        if(array[i]==element){
            count+= 1;
        }
        else{
            count-= 1;
        }
    }
    count=0;
    //Now after getting the final value then checking whether that particular value is present in the set of element >n/2 times.
    for(int i=0;i<numbers;i++){
        if(array[i]==element){
            count++;
        }
    }
    if(count>numbers/2){
        printf("The majority element is: %d",element);
    }
    else{
        printf("Majority element not present");
    }
}