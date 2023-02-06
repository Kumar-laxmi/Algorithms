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
	
    int i;
    int array[MAX_SIZE];
     for(int i = 0; i <MAX_SIZE ; ++i) {
     scanf("%d", &array[i]);
  }
    printNextBigElement(array, sizeof(array));
 
    return 0;
}
