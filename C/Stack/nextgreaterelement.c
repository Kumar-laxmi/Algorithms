// Approach for solving 
// Initialize the stack with a dummy element with a value of -1.
// For each element in the input array, pop elements from the stack while they are smaller than the current element. The popped elements are paired with the current element as they are the next greater elements.
// Push the current element into the stack.
// Repeat steps 2 and 3 for all elements in the input array.
// After all elements are processed, the elements remaining in the stack have no next greater elements, so they are paired with -1.





#include <stdio.h>
#include <string.h>
  
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
#define MAX_SIZE 1000
// Structure defining Stack data structure
struct Stack {
    int top;
    int array[MAXSIZE];
} st;
  
/*
Initializes the top index to -1
*/
void initialize() {
 st.top = -1;
}
  
/*
 Checks if Stack is Full or not 
*/
int isFull() {   
    if(st.top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}
  
/*
 Checks if Stack is Empty or not
*/
int isEmpty() {
 if(st.top == -1)
     return TRUE;
 else
     return FALSE;
}
  
/*
 Adds an element to stack and then increment top index 
*/
void push(int num) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.array[st.top + 1] = num;
        st.top++;
    }
}
  
/*
 Removes top element from stack and decrement top index
*/
int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     st.top = st.top - 1;
        return st.array[st.top+1];
    }
}
 
/* This program prints the next bigger 
element for every element of array */
void printNextBigElement(int *array, int size) {
    initialize();
    int top, current, i;
  
    /* Initialize stack with first element of array */
    push(array[0]);
  
    /* Traverse whole array from  left to right */
    for(i = 1; i < size; i++){
        current = array[i];
  
        if (!isEmpty()) {
            /* Pop Top element of Stack */
            top = pop();
  
            /* If top element is smaller than current, then
            current is NBE of top. COntinue poping elements 
   till top is smaller than current  
             */
            while(top < current) {
                printf("%d  %d\n", top, current);
                if(isEmpty())
                     break;
                top = pop();
            }
  
            /* If top is greater than current than push top again */
            if (top >= current)
                push(top);
        }
  
        /* push curret to stack */
        push(current);
    }
  
    /* Afer complete traversal, the left over elements 
 on stack don't have any Next Bigger Element */
    while (!isEmpty()){
        top = pop();
        printf("%d  %d\n", top, -1);
    }
}
int main() {
   int array[1000];   // array
  int i,n; // loop var
   printf("\nArray size input\n");
  scanf("%d",&n);
   printf("\nArray element\n");
  for(i=0;i<n;i++)
  {
      scanf("%d",&array[i]);
  }
 
    printf("\nNext Bigger Element Mapping\n");
    printNextBigElement(array, n);
 
    return 0;
}

