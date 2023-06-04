// ====================== Problem Statement ==========================
/*
Menu-Driven application to convert->
1.Infix to Postfix
2.Infix to Prefix
3.Prefix to Postfix
4.Prefix to Infix
5.Postfix to Prefix
6.Postfix to Infix

Algorithm -

--- Infix to Postfix---
1)Scan the infix expression from left to right. 
2)If the scanned character is an operand, append it to postfix variable. 
  Else, 
3)If the precedence of the scanned operator are greater than the precedence of the operator on top of the stack(or the stack is empty or the stack contains a ‘(‘ ), then push it.
4)Else,
  Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
5)If the scanned character is an ‘(‘, push it to the stack. 
6)If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
7)Repeat until the infix expression is scanned. 
8)Pop and append from the stack until it is not empty.
9)Return the postfix var 


--- Infix to Prefix---
1) Reverse the infix expression,while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
2) Apply postfix converison of the modified expression.
3) Reverse the postfix expression.


---Prefix to Postfix/Infix---
1)Read the Prefix expression from right to left
2)If the element is an operand, then push it onto the Stack
  If the element is an operator, then pop two operands from the Stack 
3)Create a string as shown below- 
string = operand1 + operand2 + operator (Prefix to Postfix) 
string = operand1 + operator + operand2(Prefix to Infix) 

push the resultant string to Stack
4)The remaining string at top of stack is the required expression.


---Postix to Prefix/Infix---
1)Read the Postfix expression.
2)If the element is an operand, then push it onto the Stack
  If the element is an operator, then pop two operands from the Stack 
3)Create a string as shown below-
string = operator + operand1 + operand2 (Postfix to Prefix) 
string = operand1 + operator + operand2 (Postfix to Infix) 

push the resultant string back to Stack
4)The remaining string at top of stack is the required expression.
*/

// // ====================== Code with C ==========================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return;
            else
                pop(stack);
        }
        else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack))
        exp[++k] = pop(stack);
    exp[++k] = '\0';
    printf("Postfix Expression: %s\n", exp);
}

void infixToPrefix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    struct Stack* resultStack = createStack(strlen(exp));
    if (!stack || !resultStack)
        return;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                push(resultStack, pop(stack));
            if (!isEmpty(stack) && peek(stack) != '(')
                return;
            else
                pop(stack);
        }
        else if (isOperand(exp[i]))
            push(resultStack, exp[i]);
        else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                push(resultStack, pop(stack));
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack))
        push(resultStack, pop(stack));
    while (!isEmpty(resultStack))
        exp[++k] = pop(resultStack);
    exp[++k] = '\0';
    printf("Prefix Expression: %s\n", exp);
}

void prefixToPostfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;
    for (i = strlen(exp) - 1, k = -1; i >= 0; --i) {
        if (isOperand(exp[i]))
            push(stack, exp[i]);
        else {
            char op1 = pop(stack);
            char op2 = pop(stack);
            exp[++k] = op1;
            exp[++k] = op2;
            exp[++k] = exp[i];
        }
    }
    exp[++k] = '\0';
    printf("Postfix Expression: %s\n", exp);
}

void prefixToInfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;
    for (i = strlen(exp) - 1, k = -1; i >= 0; --i) {
        if (isOperand(exp[i]))
            push(stack, exp[i]);
        else {
            char op1 = pop(stack);
            char op2 = pop(stack);
            exp[++k] = '(';
            exp[++k] = op1;
            exp[++k] = exp[i];
            exp[++k] = op2;
            exp[++k] = ')';
        }
    }
    exp[++k] = '\0';
    printf("Infix Expression: %s\n", exp);
}

void postfixToPrefix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (isOperand(exp[i]))
            push(stack, exp[i]);
        else {
            char op2 = pop(stack);
            char op1 = pop(stack);
            exp[++k] = exp[i];
            exp[++k] = op1;
            exp[++k] = op2;
        }
    }
    exp[++k] = '\0';
    printf("Prefix Expression: %s\n", exp);
}

void postfixToInfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (isOperand(exp[i]))
            push(stack, exp[i]);
        else {
            char op2 = pop(stack);
            char op1 = pop(stack);
            exp[++k] = '(';
            exp[++k] = op1;
            exp[++k] = exp[i];
            exp[++k] = op2;
            exp[++k] = ')';
        }
    }
    exp[++k] = '\0';
    printf("Infix Expression: %s\n", exp);
}

int main() {
    char exp[100];
    int choice;

    do {
        printf("Enter expression: ");
        scanf("%s", exp);
        printf("---------------------------------------\n");
        printf("Press 1 for Infix to Postfix conversion\n");
        printf("Press 2 for Infix to Prefix conversion\n");
        printf("Press 3 for Prefix to Postfix conversion\n");
        printf("Press 4 for Prefix to Infix conversion\n");
        printf("Press 5 for Postfix to Prefix conversion\n");
        printf("Press 6 for Postfix to Infix conversion\n");
        printf("Press 0 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                infixToPostfix(exp);
                break;
            case 2:
                infixToPrefix(exp);
                break;
            case 3:
                prefixToPostfix(exp);
                break;
            case 4:
                prefixToInfix(exp);
                break;
            case 5:
                postfixToPrefix(exp);
                break;
            case 6:
                postfixToInfix(exp);
                break;
            case 0:
                exit(1);
        }
    } while (choice<7);

    return 0;
}


