#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
}mystack;

int stackTop(mystack* sp){
    return sp->arr[sp->top];
}

int isEmpty(mystack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(mystack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(mystack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(mystack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

char* infixToPostfix(char infix[]) {
    mystack* sp = (mystack*) malloc(sizeof(mystack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char* postfix = (char *) malloc(100 * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            if (precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp->arr);
    free(sp);
    return postfix;
}

int evaluate(char op, int op1, int op2){
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    default:
        return 0;
    }
}

int postfixEvaluate(char postfix[])
{
    mystack *sp = (mystack *)malloc(sizeof(mystack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i = 0; // Track postfix traversal
    while (postfix[i] != '\0')
    {
        if (!isOperator(postfix[i]))
        {
            push(sp, postfix[i] - '0'); // convert char to int and push to stack
            i++;
        }
        else
        {
            int op2 = pop(sp);
            int op1 = pop(sp);
            int result = evaluate(postfix[i], op1, op2);
            push(sp, result);
            i++;
        }
    }
    int finalResult = pop(sp);
    free(sp->arr);
    free(sp);
    return finalResult;
}

int main()
{
    char infix[100];
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // remove the newline character

    char *postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);

    int result = postfixEvaluate(postfix);
    printf("Result: %d\n", result);

    return 0;

}





