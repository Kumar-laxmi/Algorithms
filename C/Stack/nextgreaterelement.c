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
struct Stack {
    int top;
    int array[MAXSIZE];
} st;

void initialize() {
 st.top = -1;
}
  
int isFull() {   
    if(st.top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}
  
int isEmpty() {
 if(st.top == -1)
     return TRUE;
 else
     return FALSE;
}

void push(int num) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.array[st.top + 1] = num;
        st.top++;
    }
}
  

int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     st.top = st.top - 1;
        return st.array[st.top+1];
    }
}

void printNextBigElement(int *array, int size) {
    initialize();
    int top, current, i;
  
    push(array[0]);
  
    for(i = 1; i < size; i++){
        current = array[i];
  
        if (!isEmpty()) {
            top = pop();
    
            while(top < current) {
                printf("%d  %d\n", top, current);
                if(isEmpty())
                     break;
                top = pop();
            }
  
            if (top >= current)
                push(top);
        }
  
        push(current);
    }
  
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
